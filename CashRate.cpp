////////////////////////////////////////////////////////////
//文 件 名：CashRate.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：打折类现金计算方式实现
////////////////////////////////////////////////////////////
#include "CashRate.h"


/**
 * 打折类
*/
CashRate::CashRate(const float& rate):cashrate(rate)
{
	//
}

CashRate::~CashRate()
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
float CashRate::accpetCash(int number,float money)
{
	return number*money*cashrate;
}
