////////////////////////////////////////////////////////////
//�� �� ����InputTxt.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵������ȡtxt��csv�ļ���ʵ��
////////////////////////////////////////////////////////////
#include "InputTxt.h"


//===========================================
//deleteSomeChar����˵��
//�������ܣ�ɾ���ַ����е��ض��ַ�
//������    str���ַ���
//          ch���ض��ַ�
//�������أ�  ��
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
//readFile����˵��
//�������ܣ���ȡ�ļ�
//������    ��
//�������أ� �ļ�����
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