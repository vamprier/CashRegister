////////////////////////////////////////////////////////////
//文 件 名：CashRegister.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：收银机类定义
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
#include "CashContext.h"
#include "goods.h"
#include "preferentialInfo.h"
#include "InputContext.h"


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
	void AddGoods(const string& fileName);
	//设置优惠活动信息
	void SetPreferential(const string& fileName);
	//输入购买的商品条码串
	void InputGoodsCode(const string& fileName);
	//打印小票
	void printItems(const vector<pair<goods,int> >& goodsInfo);

public:
	//测试
	void Test();

private:
	map<string,pair<goods,int> > perchaseGoods;		//购买的商品信息
	map<string,goods> stockGoods;						//总商品
	map<string,vector<preferentialInfo> > preferential;	//优惠信息

};

#endif /* CASHREGISTER_H_ */
