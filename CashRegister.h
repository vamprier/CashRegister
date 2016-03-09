////////////////////////////////////////////////////////////
//文 件 名：CashRegister.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：收银机类，添加商品、添加优惠活动，输入条码打印购买商品信息
////////////////////////////////////////////////////////////

#ifndef CASHREGISTER_H_
#define CASHREGISTER_H_

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "CashSuper.h"
#include "basicInfo.h"


using namespace std;

/**
 * 收银机类
*/
class CashRegister
{
public:
	explicit CashRegister();
	~CashRegister();

private:
	//添加商品
	void AddGoods(const goods& g);
	//设置优惠活动信息
	void SetPreferential(	const string& goodsCategory,
							const string& pcate,
							const string& pname,
							const int prioprity,
							const float& rate,
							const int& buy,
							const int& gitfs);
	//输入购买的商品条码串
	string InputGoodsCode(	const string& itemLists,
							const char* sperator,
							const char* start,
							const char* end);
	//打印小票
	void printItems(const vector<pair<goods,int> >& goodsInfo);

public:
	//测试
	void Test();

private:
	map<string,pair<goods,int> > PerchaseGoods;		//购买的商品信息
	map<string,goods> stockGoods;						//总商品
	map<string,vector<preferentialInfo> > preferential;	//优惠信息

};

#endif /* CASHREGISTER_H_ */
