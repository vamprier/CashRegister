////////////////////////////////////////////////////////////
//文 件 名：CashBuyGifts.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：买赠类现金计算方式定义
////////////////////////////////////////////////////////////
#ifndef CASHBUYGIFTS_H
#define CASHBUYGIFTS_H

#include "CashSuper.h"


/**
 * 买赠类
*/
class CashBuyGifts : public CashSuper
{
public:
	explicit CashBuyGifts(const int& buy,const int& gift);
	virtual ~CashBuyGifts();
public:
	virtual float accpetCash(int number,float money);
private:
	const int buynumber;
	const int giftnumber;
};

#endif