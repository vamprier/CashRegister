////////////////////////////////////////////////////////////
//�� �� ����preferentialInfo.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����Ż���Ϣ���ʵ��
////////////////////////////////////////////////////////////
#include "preferentialInfo.h"

/**
 * �Ż���Ϣ
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