////////////////////////////////////////////////////////////
//文 件 名：CashSuper.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：优惠活动策略类
////////////////////////////////////////////////////////////
#include "CashSuper.h"

/**
 * 接口类
*/
CashSuper::~CashSuper()
{
	//
}

/**
 * 正常销售
*/
CashNomal::CashNomal()
{
	//
}

CashNomal::~CashNomal()
{
	//
}

float CashNomal::accpetCash(int number,float money)
{
	return number*money;
}

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

float CashRate::accpetCash(int number,float money)
{
	return number*money*cashrate;
}

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

float CashBuyGifts::accpetCash(int number,float money)
{
	int realnumber = number - (number/(buynumber+giftnumber));
	return realnumber*money;
}

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

float CashContext::GetResult(int number,float money)
{
	return pcs->accpetCash(number,money);
}
