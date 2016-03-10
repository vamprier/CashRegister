////////////////////////////////////////////////////////////
//文 件 名：CashRegister.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：收银机类实现
////////////////////////////////////////////////////////////

#include "CashRegister.h"
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
//参数：    fileName：文件路径
//函数返回： 无
//===========================================
void CashRegister::InputGoodsCode(const string& fileName)
{
	InputContext ic(fileName);
	vector<vector<string> > strVec = ic.readFile();
	int size = strVec.size();
	map<string,int> tempMap;
	for(int i=0;i<size;i++)
	{
		if(strVec[i].size() < 2)continue;
		tempMap[strVec[i][0]] = atoi(strVec[i][1].c_str());
	}
	map<string,int>::iterator tit = tempMap.begin();
	for( ; tit != tempMap.end();++tit)
	{
		perchaseGoods[tit->first] = make_pair(stockGoods[tit->first],tit->second);
	}
}

//===========================================
//AddGoods函数说明
//函数功能：添加商品
//参数：    fileName：文件路径
//函数返回： 无
//===========================================
void CashRegister::AddGoods(const string& fileName)
{
	InputContext ic(fileName);
	vector<vector<string> > strVec = ic.readFile();
	int size = strVec.size();
	for(int i=0;i<size;i++)
	{
		if(strVec[i].size() < 5)continue;
		goods g(strVec[i][0],strVec[i][1],atof(strVec[i][2].c_str()),strVec[i][3],strVec[i][4]);
		stockGoods[g.GetCode()] = g;
	}
}

//===========================================
//SetPreferential函数说明
//函数功能：设置优惠活动
//参数：    fileName：文件路径
//函数返回： 无
//===========================================
void CashRegister::SetPreferential(	const string& fileName)
{
	InputContext ic(fileName);
	vector<vector<string> > strVec = ic.readFile();
	int size = strVec.size();
	for(int i=0;i<size;i++)
	{
		if(strVec[i].size() < 7)continue;
		preferentialInfo p(strVec[i][1],strVec[i][2],atoi(strVec[i][3].c_str()),
							atof(strVec[i][4].c_str()),atoi(strVec[i][5].c_str()),atoi(strVec[i][6].c_str()));
		preferential[strVec[i][0]].push_back(p);
	}
}


//===========================================
//printItems函数说明
//函数功能：打印输出信息
//参数：    goodsInfo：购物信息
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


//===========================================
//Test函数说明
//函数功能：测试函数
//参数：    无
//函数返回： 无
//===========================================
void CashRegister::Test()
{
	//初始化商品
	AddGoods("file/goods.txt");
	//设置优惠活动信息
	SetPreferential("file/preferential.txt");
	//购物
	InputGoodsCode("file/purchase.txt");
	if( perchaseGoods.size() != 0)
	{
		vector<pair<goods,int> > goodsPre;
		//查询每个商品所属类别的优惠信息
		map<string,vector<preferentialInfo> >::iterator fit = preferential.begin(); //
		map<string,pair<goods,int> >::iterator it = perchaseGoods.begin();	//
		for(; it != perchaseGoods.end();++it)
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


