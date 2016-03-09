////////////////////////////////////////////////////////////
//文 件 名：CashRegister.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：收银机类，添加商品、添加优惠活动，输入条码打印购买商品信息
////////////////////////////////////////////////////////////

#include "CashRegister.h"

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

}

//===========================================
//SetPreferential函数说明
//函数功能：设置优惠活动
//参数：    itemLists：购买商品条码字符串
//		   sperator：字符串分割符
//		   start：起始字符
//		   end：终止字符
//函数返回： 字符串
//===========================================
string CashRegister::InputGoodsCode(	const string& itemLists,
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
	map<string,int> tempMap;
	token = strtok( buffer, sperator );
	while (token != NULL)
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
			tempMap[code]+= atoi(numStr.c_str());
		}
		else
		{
			tempMap[tempStr]+=1;
		}
		token = strtok( NULL, sperator );	
	}
	map<string,int>::iterator tit = tempMap.begin();
	for( ; tit != tempMap.end();++tit)
	{
		PerchaseGoods[tit->first] = make_pair(stockGoods[tit->first],tit->second);
	}
	return "success";
}

//===========================================
//AddGoods函数说明
//函数功能：添加商品
//参数：    g：商品
//函数返回： 无
//===========================================
void CashRegister::AddGoods(const goods& g)
{
	stockGoods[g.GetCode()] = g;
}

//===========================================
//SetPreferential函数说明
//函数功能：设置优惠活动
//参数：    goodsCategory：商品类别
//		   pcate：优惠活动类别
//		   pname：优惠活动名称
//		   prioprity：优先级
//		   rate：折扣值
//		   buy：买数量
//		   gitfs：赠数量
//函数返回： 无
//===========================================
void CashRegister::SetPreferential(	const string& goodsCategory,
									const string& pcate,
									const string& pname,
									const int prioprity,
									const float& rate,
									const int& buy,
									const int& gitfs)
{
	preferentialInfo p(pcate,pname,prioprity,rate,buy,gitfs);
	preferential[goodsCategory].push_back(p);

}

//===========================================
//Test函数说明
//函数功能：测试函数
//参数：    无
//函数返回： 无
//===========================================
void CashRegister::Test()
{
	//初始化商品
	goods g1("可口可乐","瓶",3.0,"饮料","ITEM000001");
	goods g2("羽毛球","个",1.0,"体育用品","ITEM000007");
	goods g3("苹果","斤",5.5,"水果","ITEM000014");
	//添加商品
	AddGoods(g1);
	AddGoods(g2);
	AddGoods(g3);
	//设置优惠活动信息
	SetPreferential("饮料","买赠","买二赠一",2,0.0,2,1);
	SetPreferential("体育用品","买赠","买二赠一",2,0.0,2,1);
	SetPreferential("水果","折扣","95折",1,0.95,0,0);
	//输入条码
	const string inputStr = "['ITEM000001','ITEM000001','ITEM000001','ITEM000007','ITEM000007','ITEM000007','ITEM000007','ITEM000007','ITEM000007','ITEM000014-2']";
	string info = InputGoodsCode(inputStr,",","[","]");
	if( !info.compare("success"))
	{
		vector<pair<goods,int> > goodsPre;
		//查询每个商品所属类别的优惠信息
		map<string,vector<preferentialInfo> >::iterator fit = preferential.begin(); //
		map<string,pair<goods,int> >::iterator it = PerchaseGoods.begin();	//
		for(; it != PerchaseGoods.end();++it)
		{
			fit = preferential.find((it->second).first.GetCategory());
			if( fit != preferential.end())
			{
				sort((fit->second).begin(),(fit->second).end(),greater<preferentialInfo>());
				(it->second).first.SetPreferentialInfo((fit->second)[0]);
			}
			goodsPre.push_back(it->second);
		}
		printItems(goodsPre);
	}
}

//===========================================
//printItems函数说明
//函数功能：打印输出信息
//参数：    无
//函数返回： 无
//===========================================
void CashRegister::printItems(	const vector<pair<goods,int> >& goodsInfo)
{
	//打印输出信息
		cout<<"***<没钱赚商店>购物清单***"<<endl;
		int size = goodsInfo.size();
		float totalPrice = 0.0;	//总价格
		float savePrice = 0.0;	//节省钱数
		map<string,string> buyGiftsInfo;
		for( int i=0;i<size;i++)
		{
			//利用策略模式类计算商品的价格
			CashContext cc(	(goodsInfo[i].first).GetPreferentialInfo().GetCate(),(goodsInfo[i].first).GetPreferentialInfo().GetRate(),
							(goodsInfo[i].first).GetPreferentialInfo().GetBuy(),(goodsInfo[i].first).GetPreferentialInfo().GetGitfs());
			float total = cc.GetResult(goodsInfo[i].second,(goodsInfo[i].first).GetPrice());
			//
			cout<<"名称："<<(goodsInfo[i].first).GetName()<<"，数量："<<goodsInfo[i].second<<(goodsInfo[i].first).GetUnit()<<"，单价："<<(goodsInfo[i].first).GetPrice()<<"(元)，";
			//计算总价格
			totalPrice += total;
			savePrice +=  (goodsInfo[i].second*(goodsInfo[i].first).GetPrice()-total);
			//输出信息
			cout<<"小计："<<total<<"(元)";
			if( (goodsInfo[i].first).GetPreferentialInfo().GetCate() == "买赠")
			{
				int number = goodsInfo[i].second/((goodsInfo[i].first).GetPreferentialInfo().GetBuy()+(goodsInfo[i].first).GetPreferentialInfo().GetGitfs());
				if(number!=0)
				{
					char ch[256];
					sprintf(ch,"名称：%s，数量：%d%s\n",(goodsInfo[i].first).GetName().c_str(),number,(goodsInfo[i].first).GetUnit().c_str());
					buyGiftsInfo[(goodsInfo[i].first).GetPreferentialInfo().GetName()] += ch;
				}
			}
			else if((goodsInfo[i].first).GetPreferentialInfo().GetCate() == "折扣")
			{
				cout<<", 节省："<<(goodsInfo[i].second*(goodsInfo[i].first).GetPrice()-total)<<"(元)";
			}
			cout<<endl;
		}
		//买赠信息打印
		map<string,string>::const_iterator bit = buyGiftsInfo.begin();
		for( ;bit != buyGiftsInfo.end();++bit)
		{
			cout<<"-----------------------"<<endl;
			cout<<bit->first<<"商品："<<endl;
			cout<<bit->second;
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


