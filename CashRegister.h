////////////////////////////////////////////////////////////
//�� �� ����CashRegister.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������࣬�����Ʒ������Żݻ�����������ӡ������Ʒ��Ϣ
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
#include "CashSuper.h"
#include "basicInfo.h"


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
	void AddGoods(const goods& g);
	//�����Żݻ��Ϣ
	void SetPreferential(	const string& goodsCategory,
							const string& pcate,
							const string& pname,
							const int prioprity,
							const float& rate,
							const int& buy,
							const int& gitfs);
	//���빺�����Ʒ���봮
	string InputGoodsCode(	const string& itemLists,
							const char* sperator,
							const char* start,
							const char* end);
	//��ӡСƱ
	void printItems(const vector<pair<goods,int> >& goodsInfo);

public:
	//����
	void Test();

private:
	map<string,pair<goods,int> > PerchaseGoods;		//�������Ʒ��Ϣ
	map<string,goods> stockGoods;						//����Ʒ
	map<string,vector<preferentialInfo> > preferential;	//�Ż���Ϣ

};

#endif /* CASHREGISTER_H_ */
