/*
 * CashRegister.h
 *
 *  Created on: Mar 2, 2016
 *      Author: zhaojuan
 */

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
#include <mysql/mysql.h>

using namespace std;

#define hostName "10.21.5.106"
#define dbName "dbtest"
#define userName "root"
#define password "123456"
#define port 3306

/**
 * 商品信息
*/
struct goods
{
	string name;					//名称
	string unit;					//计量单位
	float price;					//价格
	string category;				//类别
	string barCode;					//条形码
	int totalNumber;				//购买数量
	vector<string> preferentialList;	//商品参加的优惠活动列表
	string preferentialName;		//优惠名称
	float totalPrice;				//总价格
	float preferentialPrice;		//优惠价格
};

/**
 * 买赠信息
*/
struct buyGifts
{
	string name;	//商品名称
	string unit;	//单位
	int number;		//数量
};

/**
 * 收银机类
*/
class CashRegister {
public:
	explicit CashRegister();
	~CashRegister();

private:
	string readData(	const string& query,
						vector<vector<string> >& dataSet);  //从数据库读取数据

	int readPreferential(const string& pname);	//获得优惠活动信息
public:

	string scanfItems(	const string& itemLists,
						const char* sperator,
						const char* start,
						const char* end);	//扫描购买的商品

	void printItems();	//打印小票

private:
	map<string,int> itemMap;		//商品的购买数量
	vector<goods> PerchaseGoods;	//购买的商品信息
	vector<buyGifts> bgVec;//买二赠一商品信息

};

#endif /* CASHREGISTER_H_ */
