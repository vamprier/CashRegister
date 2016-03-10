////////////////////////////////////////////////////////////
//文 件 名：CashRate.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：打折类现金计算方式定义
////////////////////////////////////////////////////////////
#ifndef CASHRATE_H
#define CASHRATE_H

#include "CashSuper.h"


/**
 * 打折类
*/
class CashRate : public CashSuper
{
public:
	explicit CashRate(const float& rate);
	virtual ~CashRate();
public:
	virtual float accpetCash(int number,float money);
private:
	const float cashrate;
};

#endif