////////////////////////////////////////////////////////////
//文 件 名：CashSuper.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：现金计算接口类
////////////////////////////////////////////////////////////
#ifndef CASHSUPER_H
#define CASHSUPER_H

/**
 * 接口类
*/
class CashSuper
{
public:
	virtual ~CashSuper();
public:
	virtual float accpetCash(int number,float money) = 0;
};

#endif
