////////////////////////////////////////////////////////////
//�� �� ����CashContext.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵��������ģʽ��ʵ��
////////////////////////////////////////////////////////////
#include "CashContext.h"
#include "CashRate.h"
#include "CashBuyGifts.h"
#include "CashNomal.h"


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

//===========================================
//accpetCash����˵��
//�������ܣ������ܼ۸�
//������    number����������
//          money������
//�������أ� �ܼ۸�
//===========================================
float CashContext::GetResult(int number,float money)
{
	return pcs->accpetCash(number,money);
}