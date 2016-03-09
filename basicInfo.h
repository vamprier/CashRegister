////////////////////////////////////////////////////////////
//�� �� ����basicInfo.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����Ż���Ϣ�����Ʒ��Ϣ��Ķ���
////////////////////////////////////////////////////////////
#ifndef GOODS_H
#define GOODS_H

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

/**
 * ��Ʒ��Ϣ
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
	string gname;					//����
	string gunit;					//������λ
	float gprice;					//�۸�
	string gcategory;				//���
	preferentialInfo gpreferential;			//�Żݻ
	string gbarCode;				//������
};

#endif
