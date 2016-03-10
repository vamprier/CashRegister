////////////////////////////////////////////////////////////
//�� �� ����goods.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵������Ʒ��Ϣ���ʵ��
////////////////////////////////////////////////////////////
#include "goods.h"

/**
 * ��Ʒ��Ϣ
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
