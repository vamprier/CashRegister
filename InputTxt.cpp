////////////////////////////////////////////////////////////
//文 件 名：InputTxt.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：读取txt、csv文件类实现
////////////////////////////////////////////////////////////
#include "InputTxt.h"


//===========================================
//deleteSomeChar函数说明
//函数功能：删除字符串中的特定字符
//参数：    str：字符串
//          ch：特定字符
//函数返回：  无
//===========================================
void deleteSomeChar(string& str,char ch)
{
	for (string::iterator it = str.begin();it != str.end();)
	{
		if (*it == ch)
		{
			it = str.erase(it);
		}
		else
		{
			++it;
		}
	}
}


InputTxt::InputTxt(const string& name):fileName(name)
{
	//
}

InputTxt::~InputTxt()
{
	//
}

//===========================================
//readFile函数说明
//函数功能：读取文件
//参数：    无
//函数返回： 文件内容
//===========================================
vector<vector<string> > InputTxt::readFile()
{
	vector<vector<string> > strVec;
	ifstream fin;
	try
	{
		fin.open(fileName.c_str(),ifstream::in);
	}
	catch (exception* e)
	{
		return strVec;
	}
	string tempStr;
	while ( getline(fin,tempStr))
	{
		vector<string> num;
		char flag[] = ",";
		char *token;
		char* buffer = const_cast<char*>(tempStr.c_str());
		token = strtok( buffer, flag);
		while (token != NULL)
		{
			string temp = token;
			deleteSomeChar(temp,'"');
			num.push_back(temp);
			token = strtok(NULL,flag);
		}
		strVec.push_back(num);
	}
	return strVec;
}