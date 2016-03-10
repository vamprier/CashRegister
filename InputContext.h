////////////////////////////////////////////////////////////
//文 件 名：InputContext.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：读取文件策略模式类定义
////////////////////////////////////////////////////////////
#ifndef INPUTCONTEXT_H
#define INPUTCONTEXT_H

#include "InputScaner.h"

/**
 * 策略模式类
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