////////////////////////////////////////////////////////////
//�� �� ����InputScaner.h
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����ļ���ȡ��ʽ��ӿ�
////////////////////////////////////////////////////////////
#ifndef INPUTSACNER_H
#define INPUTSACNER_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * �ӿ���
*/

class InputScaner
{
public:
	virtual ~InputScaner();
	virtual vector<vector<string> > readFile()=0;
};

#endif