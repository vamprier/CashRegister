////////////////////////////////////////////////////////////
//�� �� ����InputContext.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵������ȡ�ļ�����ģʽ�ඨ��
////////////////////////////////////////////////////////////
#ifndef INPUTCONTEXT_H
#define INPUTCONTEXT_H

#include "InputScaner.h"

/**
 * ����ģʽ��
*/
class InputContext
{
public:
	explicit InputContext(const string& name);
	~InputContext();
	vector<vector<string> > readFile();
private:
	InputScaner* pis;
	string name;
};

#endif