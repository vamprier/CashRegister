////////////////////////////////////////////////////////////
//文 件 名：CashContext.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：策略模式类定义
////////////////////////////////////////////////////////////
#ifndef CASHCONTEXT_H
#define CASHCONTEXT_H

#include "CashSuper.h"
#include <string>

using namespace std;

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