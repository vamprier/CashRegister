////////////////////////////////////////////////////////////
//文 件 名：basicInfo.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：优惠信息类和商品信息类的实现
////////////////////////////////////////////////////////////
#include "basicInfo.h"

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

/**
 * 商品信息
*/

goods::goods():
				gname(""),
				gunit(""),
				gprice(0),
				gcategory(""),
				gbarCode(""),
				gpreferential("","",0,0.0,0,0)
{
	//
}

goods::goods(	const string& name,
				const string& unit,
				const float& price,
				const string& cate,
				const string& code):
				gname(name),
				gunit(unit),
				gprice(price),
				gcategory(cate),
				gbarCode(code),
				gpreferential("","",0,0.0,0,0)
{
	//
}

goods::~goods()
{
	//
}

void goods::SetPreferentialInfo( const preferentialInfo& preferential)
{
	gpreferential = preferential;
}

string goods::GetName() const
{
	return gname;
}

string goods::GetUnit() const
{
	return gunit;
}

preferentialInfo goods::GetPreferentialInfo() const
{
	return gpreferential;
}


float goods::GetPrice() const
{
	return gprice;
}

string goods::GetCategory() const
{
	return gcategory;
}


string goods::GetCode() const
{
	return gbarCode;
}
