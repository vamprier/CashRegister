/*
 * CashRegister.cpp
 *
 *  Created on: Mar 2, 2016
 *      Author: zhaojuan
 */

#include "CashRegister.h"

//===========================================
//Less函数说明
//函数功能：自定义比较函数
//参数：    s1：待比较对象1
//		   s2：待比较对象1
//函数返回： true/false
//===========================================
bool Less(const pair<string,int>& s1, const pair<string,int>& s2)
{
	return s1.second > s2.second; //可以自己设定
}

//===========================================
//deleteSomeChar函数说明
//函数功能：删除字符串中的特定字符
//参数：    str：字符串
//          ch：特定字符
//函数返回：  无
//===========================================
void deleteSomeChar(string& str,char ch)
{
	for (string::iterator it = str.begin();it != str.end();)
	{
		if (*it == ch)
		{
			it = str.erase(it);
		}
		else
		{
			++it;
		}
	}
}

//===========================================
//CashRegister函数说明
//函数功能：构造函数
//===========================================
CashRegister::CashRegister() {
	// TODO Auto-generated constructor stub
}

//===========================================
//~CashRegister函数说明
//函数功能：析构函数
//===========================================
CashRegister::~CashRegister() {
	// TODO Auto-generated destructor stub
	vector<goods>().swap(PerchaseGoods);	//
	vector<buyGifts>().swap(bgVec);
}

//===========================================
//readData函数说明
//函数功能：从mysql数据库中读数据
//参数：    query：查询语句
//		   dataSet：返回的结果集
//函数返回： 成功或者失败
//===========================================
string CashRegister::readData(	const string& query,
								vector<vector<string> >& dataSet)
{
	//定义
	MYSQL mysql;
	//初始化
	mysql_init(&mysql);
	//连接
	if(!mysql_real_connect(&mysql,hostName,userName,password,dbName,port,NULL,CLIENT_MULTI_STATEMENTS))
	{
		return "error:connect database error";
	}
	//设置查询时的编码格式
	mysql_query(&mysql,"set names utf8");
	//调用查询语句
	int ret = mysql_query(&mysql,query.c_str());
	if(ret)
	{
		//关闭数据库
		mysql_close(&mysql);
		return "error:excute sql error";
	}
	//获取结果集
	MYSQL_RES* result = mysql_store_result(&mysql);
	//获取字段数
	int number_fields = mysql_num_fields(result);
	//循环打印各行
	MYSQL_ROW row;
	while( (row = mysql_fetch_row(result)) != NULL)
	{
		vector<string> temp;
		for(int i=0;i<number_fields;i++)
		{
			char* ch = row[i];
			if( ch == NULL || !strcmp(ch," ") || !strcmp(ch,"(null)"))
			{
				ch = "";
			}
			string s = ch;
			temp.push_back(s);
		}
		dataSet.push_back(temp);
	}
	//释放结果集
	mysql_free_result(result);
	//关闭数据库
	mysql_close(&mysql);
	return "success";
}

//===========================================
//readPreferential函数说明
//函数功能： 获得商品的优惠信息
//参数：    无
//函数返回： 无
//===========================================
int CashRegister::readPreferential(const string& pname)
{
	char str[256];
	string query = "select prioprity from preferential where name = "+pname;
	vector<vector<string> > dataSet;
	string info = readData(query,dataSet);
	if( info.compare("success") || dataSet.size() == 0)
	{
		return 0;
	}
	return atoi(dataSet[0][0].c_str());
}

//===========================================
//scanfItems函数说明
//函数功能：扫描购买的商品，输入条码列表，获得购物信息
//参数：    itemLists：条码列表
//		   sperator：分割符
//函数返回： 无
//===========================================
string CashRegister::scanfItems(	const string& itemLists,
									const char* sperator,
									const char* start,
									const char* end)
{
	//处理输入字符串，去掉头尾符号
	size_t spos = itemLists.find(start);
	size_t epos = itemLists.find(end);
	if(spos == string::npos || epos == string::npos)
	{
		return "error:input string error";
	}
	string substr = itemLists.substr(spos+1,epos-(spos+2));
	//使用分割符分割输入的字符串
	char* token = NULL;
	char* buffer = const_cast<char*>(substr.c_str());
	while( (token = strsep(&buffer,sperator)) != NULL)
	{
		//查找字符‘-’
		string tempStr = token;
		//删除'字符
		deleteSomeChar(tempStr,'\'');
		size_t pos = tempStr.find('-');
		if( pos != string::npos)
		{
			string code = tempStr.substr(0,pos);
			string numStr = tempStr.substr(pos+1,tempStr.size()-(pos+1));
			itemMap[code] += atoi(numStr.c_str());
		}
		else
		{
			itemMap[tempStr]+=1;
		}
	}
	//查询商品信息
	map<string,int>::const_iterator it = itemMap.begin();
	for( ; it != itemMap.end();++it)
	{
		char str[256];
		sprintf(str,"select name,unit,price,category,barcode,preferentialList from goods where barcode = \"%s\"",(it->first).c_str());
		string query = str;
		vector<vector<string> > dataSet;
		string info = readData(query,dataSet);
		if( info.compare("success") || dataSet.size() == 0)
		{
			continue;
		}
		goods g;
		g.name = dataSet[0][0];
		g.unit = dataSet[0][1];
		g.price = atof(dataSet[0][2].c_str());
		g.category = dataSet[0][3];
		g.barCode = dataSet[0][4];
		g.totalNumber = it->second;
		char* token = NULL;
		char* buffer = const_cast<char*>(dataSet[0][5].c_str());
		while( (token = strsep(&buffer,",")) != NULL)
		{
			g.preferentialList.push_back(token);
		}
		//查询商品的优惠活动
		int size = g.preferentialList.size();
		//得到商品的优惠活动名称
		if( size == 0)
		{
			g.preferentialName = "";
		}
		else
		{
			vector<pair<string,int> > preVec;
			for( int i=0;i<size;i++)
			{
				preVec.push_back(make_pair(g.preferentialList[i],readPreferential(g.preferentialList[i])));
			}
			sort(preVec.begin(),preVec.end(),Less);
			g.preferentialName = preVec[0].first;
		}
		PerchaseGoods.push_back(g);
	}
	return "success";
}

//===========================================
//printItems函数说明
//函数功能：打印输出信息
//参数：    无
//函数返回： 无
//===========================================
void CashRegister::printItems()
{
	//打印输出信息
	cout<<"***<没钱赚商店>购物清单***"<<endl;
	int size = PerchaseGoods.size();
	float totalPrice = 0.0;	//总价格
	float savePrice = 0.0;	//节省钱数
	for(int i=0;i<size;i++)
	{
		cout<<"名称："<<PerchaseGoods[i].name<<"，数量："<<PerchaseGoods[i].totalNumber<<PerchaseGoods[i].unit<<"，单价："<<PerchaseGoods[i].price<<"(元)，";
		//买二赠一
		if( PerchaseGoods[i].preferentialName == "买二赠一")
		{
			int realnumber = PerchaseGoods[i].totalNumber - (PerchaseGoods[i].totalNumber/3);
			PerchaseGoods[i].totalPrice = realnumber*PerchaseGoods[i].price;
			buyGifts bg;
			bg.name = PerchaseGoods[i].name;
			bg.unit = PerchaseGoods[i].unit;
			bg.number = (PerchaseGoods[i].totalNumber/3);
			if(bg.number != 0)bgVec.push_back(bg);
			savePrice += bg.number*PerchaseGoods[i].price;
		}
		else if(PerchaseGoods[i].preferentialName == "95折") //95折
		{
			PerchaseGoods[i].totalPrice = (PerchaseGoods[i].totalNumber*PerchaseGoods[i].price)*0.95;
			PerchaseGoods[i].preferentialPrice = (PerchaseGoods[i].totalNumber*PerchaseGoods[i].price)*0.05;
			savePrice+=PerchaseGoods[i].preferentialPrice;
		}
		else //其他情况
		{
			PerchaseGoods[i].totalPrice = PerchaseGoods[i].totalNumber*PerchaseGoods[i].price;
		}
		//计算总价格
		totalPrice+=PerchaseGoods[i].totalPrice;
		//输出信息
		cout<<"小计："<<PerchaseGoods[i].totalPrice<<"(元)";
		if(PerchaseGoods[i].preferentialName == "95折")
		{
			cout<<", 节省："<<PerchaseGoods[i].preferentialPrice<<"(元)";
		}
		cout<<endl;
	}
	//买二赠一信息打印
	size = bgVec.size();
	if( size != 0)
	{
		cout<<"-----------------------"<<endl;
		cout<<"买二赠一商品："<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<"名称："<<bgVec[i].name<<"，数量："<<bgVec[i].number<<bgVec[i].unit<<endl;
		}
	}
	//总价打印
	cout<<"-----------------------"<<endl;
	cout<<"总计："<<totalPrice<<"(元)"<<endl;
	if( savePrice >0 )
	{
		cout<<"节省："<<savePrice<<"(元)"<<endl;
	}
	cout<<"*******************"<<endl;
}


