////////////////////////////////////////////////////////////
//�� �� ����CashRate.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������ֽ���㷽ʽ����
////////////////////////////////////////////////////////////
#ifndef CASHRATE_H
#define CASHRATE_H

#include "CashSuper.h"


/**
 * ������
*/
class CashRate : public CashSuper
{
public:
	explicit CashRate(const float& rate);
	virtual ~CashRate();
public:
	virtual float accpetCash(int number,float money);
private:
	const float cashrate;
};

#endif