////////////////////////////////////////////////////////////
//�� �� ����CashSuper.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����Żݻ������
////////////////////////////////////////////////////////////
#ifndef CASHSUPER_H
#define CASHSUPER_H

#include <string>
#include <vector>

using namespace std;

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

/**
 * ����ģʽ��
*/
class CashContext
{
public:
	explicit CashContext(const string& name,const float& r,const int& buy,const int& gift);
	~CashContext();
	float GetResult(int number,float money);
private:
	CashSuper* pcs;
};


#endif
