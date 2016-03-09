////////////////////////////////////////////////////////////
//�� �� ����CashSuper.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����Żݻ������
////////////////////////////////////////////////////////////
#include "CashSuper.h"

/**
 * �ӿ���
*/
CashSuper::~CashSuper()
{
	//
}

/**
 * ��������
*/
CashNomal::CashNomal()
{
	//
}

CashNomal::~CashNomal()
{
	//
}

float CashNomal::accpetCash(int number,float money)
{
	return number*money;
}

/**
 * ������
*/
CashRate::CashRate(const float& rate):cashrate(rate)
{
	//
}

CashRate::~CashRate()
{
	//
}

float CashRate::accpetCash(int number,float money)
{
	return number*money*cashrate;
}

/**
 * ������
*/
CashBuyGifts::CashBuyGifts(const int& buy,const int& gift):buynumber(buy),giftnumber(gift)
{
	//
}

CashBuyGifts::~CashBuyGifts()
{
	//
}

float CashBuyGifts::accpetCash(int number,float money)
{
	int realnumber = number - (number/(buynumber+giftnumber));
	return realnumber*money;
}

/**
 * ����ģʽ��
*/
CashContext::CashContext(const string& name,const float& r,const int& buy,const int& gift)
{
	if( !name.compare("�ۿ�"))
	{
		pcs = new CashRate(r);
	}
	else if( !name.compare("����"))
	{
		pcs = new CashBuyGifts(buy,gift);
	}
	else
	{
		pcs = new CashNomal(); //"�����շ�"
	}
}

CashContext::~CashContext()
{
	delete pcs;
}

float CashContext::GetResult(int number,float money)
{
	return pcs->accpetCash(number,money);
}
