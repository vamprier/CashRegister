////////////////////////////////////////////////////////////
//�� �� ����CashRate.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������ֽ���㷽ʽʵ��
////////////////////////////////////////////////////////////
#include "CashRate.h"


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

//===========================================
//accpetCash����˵��
//�������ܣ������ܼ۸�
//������    number����������
//          money������
//�������أ� �ܼ۸�
//===========================================
float CashRate::accpetCash(int number,float money)
{
	return number*money*cashrate;
}
