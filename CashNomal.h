////////////////////////////////////////////////////////////
//�� �� ����CashNomal.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵���������������ֽ���㷽ʽ����
////////////////////////////////////////////////////////////
#ifndef CASHNOMAL_H
#define CASHNOMAL_H

#include "CashSuper.h"

/**
 * ��������
*/
class CashNomal : public CashSuper
{
public:
	explicit CashNomal();
	virtual ~CashNomal();
public:
	virtual float accpetCash(int number,float money);
};

#endif