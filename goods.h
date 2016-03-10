////////////////////////////////////////////////////////////
//�� �� ����goods.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵������Ʒ��Ϣ��Ķ���
////////////////////////////////////////////////////////////
#ifndef GOODS_H
#define GOODS_H

#include <string>
#include "preferentialInfo.h"

using namespace std;

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
