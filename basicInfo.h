////////////////////////////////////////////////////////////
//文 件 名：basicInfo.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：优惠信息类和商品信息类的定义
////////////////////////////////////////////////////////////
#ifndef GOODS_H
#define GOODS_H

#include <string>

using namespace std;

/**
 * 优惠信息
*/
class preferentialInfo
{
public:
	explicit preferentialInfo(const string& pc,const string& pn,const int& p,const float& r,const int& b,const int& g);
	preferentialInfo& operator=(const preferentialInfo&);
	string GetCate();
	string GetName();
	int GetPrioprity();
	float GetRate();
	int GetBuy();
	int GetGitfs();
	bool operator > (const preferentialInfo& s) const
	{
	     return (prioprity > s.prioprity);
	}
private:
	string pcate;
	string pname;
	int prioprity;
	float rate;
	int buy;
	int gitfs;
};

/**
 * 商品信息
*/
class goods
{
public:
	goods();
	explicit goods(const string& name,const string& unit,const float& price,const string& cate,const string& code);
	~goods();
public:
	void SetPreferentialInfo( const preferentialInfo& preferential);
	string GetName() const;
	string GetUnit() const;
	float GetPrice() const;
	string GetCategory() const;
	preferentialInfo GetPreferentialInfo() const;
	string GetCode() const;
private:
	string gname;					//名称
	string gunit;					//计量单位
	float gprice;					//价格
	string gcategory;				//类别
	preferentialInfo gpreferential;			//优惠活动
	string gbarCode;				//条形码
};

#endif
