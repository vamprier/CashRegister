////////////////////////////////////////////////////////////
//�� �� ����CashContext.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵��������ģʽ�ඨ��
////////////////////////////////////////////////////////////
#ifndef CASHCONTEXT_H
#define CASHCONTEXT_H

#include "CashSuper.h"
#include <string>

using namespace std;

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