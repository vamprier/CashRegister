////////////////////////////////////////////////////////////
//�� �� ����CashSuper.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����ֽ����ӿ���
////////////////////////////////////////////////////////////
#ifndef CASHSUPER_H
#define CASHSUPER_H

/**
 * �ӿ���
*/
class CashSuper
{
public:
	virtual ~CashSuper();
public:
	virtual float accpetCash(int number,float money) = 0;
};

#endif
