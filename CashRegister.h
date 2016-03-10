////////////////////////////////////////////////////////////
//�� �� ����CashRegister.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������ඨ��
////////////////////////////////////////////////////////////

#ifndef CASHREGISTER_H_
#define CASHREGISTER_H_

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "CashContext.h"
#include "goods.h"
#include "preferentialInfo.h"
#include "InputContext.h"


using namespace std;

/**
 * ��������
*/
class CashRegister
{
public:
	explicit CashRegister();
	~CashRegister();

private:
	//�����Ʒ
	void AddGoods(const string& fileName);
	//�����Żݻ��Ϣ
	void SetPreferential(const string& fileName);
	//���빺�����Ʒ���봮
	void InputGoodsCode(const string& fileName);
	//��ӡСƱ
	void printItems(const vector<pair<goods,int> >& goodsInfo);

public:
	//����
	void Test();

private:
	map<string,pair<goods,int> > perchaseGoods;		//�������Ʒ��Ϣ
	map<string,goods> stockGoods;						//����Ʒ
	map<string,vector<preferentialInfo> > preferential;	//�Ż���Ϣ

};

#endif /* CASHREGISTER_H_ */
