//============================================================================
// Name        : ThoughtWorks.cpp
// Author      : zhaojuan
// Version     :
// Copyright   : Your copyright notice
// Description : main function in C++, Ansi-style
//============================================================================
#include "CashRegister.h"
#include <iostream>

using namespace std;

int main(int argv,char** argc)
{
	char str[256];
	//输入购买商品的条码
	cin>>str;
	//初始化收银机类对象
	CashRegister cg;
	//调用扫描函数
	cg.scanfItems(str,",");
	//调用打印函数
	cg.printItems();
	return 0;
}
