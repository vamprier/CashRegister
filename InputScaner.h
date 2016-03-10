////////////////////////////////////////////////////////////
//文 件 名：InputScaner.h
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：文件读取方式类接口
////////////////////////////////////////////////////////////
#ifndef INPUTSACNER_H
#define INPUTSACNER_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * 接口类
*/

class InputScaner
{
public:
	virtual ~InputScaner();
	virtual vector<vector<string> > readFile()=0;
};

#endif