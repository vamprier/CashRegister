////////////////////////////////////////////////////////////
//文 件 名：preferentialInfo.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：优惠信息类的实现
////////////////////////////////////////////////////////////
#include "preferentialInfo.h"

/**
 * 优惠信息
*/
preferentialInfo::preferentialInfo(	const string& pc,
	const string& pn,
	const int& p,
	const float& r,
	const int& b,
	const int& g):
pcate(pc),
	pname(pn),
	prioprity(p),
	rate(r),
	buy(b),
	gitfs(g)
{

}

preferentialInfo& preferentialInfo::operator=(const preferentialInfo& lhs)
{
	pcate = lhs.pcate;
	pname = lhs.pname;
	prioprity = lhs.prioprity;
	rate = lhs.rate;
	buy = lhs.buy;
	gitfs = lhs.gitfs;
	return *this;
}

string preferentialInfo::GetCate()
{
	return pcate;
}
string preferentialInfo::GetName()
{
	return pname;
}
int preferentialInfo::GetPrioprity()
{
	return prioprity;
}

float preferentialInfo::GetRate()
{
	return rate;
}

int preferentialInfo::GetBuy()
{
	return buy;
}

int preferentialInfo::GetGitfs()
{
	return gitfs;
}