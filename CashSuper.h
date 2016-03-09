////////////////////////////////////////////////////////////
//文 件 名：CashSuper.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：优惠活动策略类
////////////////////////////////////////////////////////////
#ifndef CASHSUPER_H
#define CASHSUPER_H

#include <string>
#include <vector>

using namespace std;

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

/**
 * 策略模式类
*/
class CashContext
{
public:
	explicit CashContext(const string& name,const float& r,const int& buy,const int& gift);
	~CashContext();
	float GetResult(int number,float money);
private:
	CashSuper* pcs;
};


#endif
