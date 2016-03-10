////////////////////////////////////////////////////////////
//�� �� ����preferentialInfo.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����Ż���Ϣ��Ķ���
////////////////////////////////////////////////////////////
#ifndef PREFERENTIAL_H
#define PREFERENTIAL_H

#include <string>

using namespace std;

/**
 * �Ż���Ϣ
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

#endif