////////////////////////////////////////////////////////////
//文 件 名：InputContext.cpp
//开发人员：赵娟
//日    期：2016-03-09
//文件说明：读取文件策略模式类实现
////////////////////////////////////////////////////////////
#include "InputContext.h"
#include "InputTxt.h"

InputContext::InputContext(const string& name)
{
	size_t pos = name.find_last_of('.');
	string type = name.substr(pos+1,name.size()-(pos+1));
	if ( !type.compare("txt") || !type.compare("csv"))
	{
		pis = new InputTxt(name);
	}
}

InputContext::~InputContext()
{
	delete pis;
}

vector<vector<string> > InputContext::readFile()
{
	return pis->readFile();
}