////////////////////////////////////////////////////////////
//�� �� ����InputTxt.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵������ȡtxt��csv�ļ��ඨ��
////////////////////////////////////////////////////////////
#ifndef INPUTTXT_H
#define INPUTTXT_H

#include "InputScaner.h"

class InputTxt : public InputScaner
{
public:
	explicit InputTxt(const string& name);
	virtual ~InputTxt();
public:
	virtual vector<vector<string> > readFile();
private:
	string fileName;
};

#endif