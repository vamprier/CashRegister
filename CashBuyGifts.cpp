////////////////////////////////////////////////////////////
//�� �� ����CashBuyGifts.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������ֽ���㷽ʽʵ��
////////////////////////////////////////////////////////////
#include "CashBuyGifts.h"


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

//===========================================
//accpetCash����˵��
//�������ܣ������ܼ۸�
//������    number����������
//          money������
//�������أ� �ܼ۸�
//===========================================
float CashBuyGifts::accpetCash(int number,float money)
{
	int realnumber = number - (number/(buynumber+giftnumber));
	return realnumber*money;
}