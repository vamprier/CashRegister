////////////////////////////////////////////////////////////
//文 件 名：CashContext.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：策略模式类实现
////////////////////////////////////////////////////////////
#include "CashContext.h"
#include "CashRate.h"
#include "CashBuyGifts.h"
#include "CashNomal.h"


/**
 * 策略模式类
*/
CashContext::CashContext(const string& name,const float& r,const int& buy,const int& gift)
{
	if( !name.compare("折扣"))
	{
		pcs = new CashRate(r);
	}
	else if( !name.compare("买赠"))
	{
		pcs = new CashBuyGifts(buy,gift);
	}
	else
	{
		pcs = new CashNomal(); //"正常收费"
	}
}

CashContext::~CashContext()
{
	delete pcs;
}

//===========================================
//accpetCash函数说明
//函数功能：计算总价格
//参数：    number：购买数量
//          money：单价
//函数返回： 总价格
//===========================================
float CashContext::GetResult(int number,float money)
{
	return pcs->accpetCash(number,money);
}