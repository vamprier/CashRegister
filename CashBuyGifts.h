////////////////////////////////////////////////////////////
//�� �� ����CashBuyGifts.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������ֽ���㷽ʽ����
////////////////////////////////////////////////////////////
#ifndef CASHBUYGIFTS_H
#define CASHBUYGIFTS_H

#include "CashSuper.h"


/**
 * ������
*/
class CashBuyGifts : public CashSuper
{
public:
	explicit CashBuyGifts(const int& buy,const int& gift);
	virtual ~CashBuyGifts();
public:
	virtual float accpetCash(int number,float money);
private:
	const int buynumber;
	const int giftnumber;
};

#endif