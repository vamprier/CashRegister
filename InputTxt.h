////////////////////////////////////////////////////////////
//文 件 名：InputTxt.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：读取txt、csv文件类定义
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