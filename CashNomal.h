////////////////////////////////////////////////////////////
//文 件 名：CashNomal.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：正常销售类现金计算方式定义
////////////////////////////////////////////////////////////
#ifndef CASHNOMAL_H
#define CASHNOMAL_H

#include "CashSuper.h"

/**
 * 正常销售
*/
class CashNomal : public CashSuper
{
public:
	explicit CashNomal();
	virtual ~CashNomal();
public:
	virtual float accpetCash(int number,float money);
};

#endif