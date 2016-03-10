////////////////////////////////////////////////////////////
//文 件 名：CashBuyGifts.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：买赠类现金计算方式实现
////////////////////////////////////////////////////////////
#include "CashBuyGifts.h"


/**
 * 买赠类
*/
CashBuyGifts::CashBuyGifts(const int& buy,const int& gift):buynumber(buy),giftnumber(gift)
{
	//
}

CashBuyGifts::~CashBuyGifts()
{
	//
}

//===========================================
//accpetCash函数说明
//函数功能：计算总价格
//参数：    number：购买数量
//          money：单价
//函数返回： 总价格
//===========================================
float CashBuyGifts::accpetCash(int number,float money)
{
	int realnumber = number - (number/(buynumber+giftnumber));
	return realnumber*money;
}