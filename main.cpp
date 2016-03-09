////////////////////////////////////////////////////////////
//文 件 名：main.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：主函数
////////////////////////////////////////////////////////////
#include "CashRegister.h"
#include <iostream>

using namespace std;

int main(int argv,char** argc)
{
	//收银机类
	CashRegister cg;
	//调用测试函数
	cg.Test();
	//
	cin.ignore();
	return 0;
}
