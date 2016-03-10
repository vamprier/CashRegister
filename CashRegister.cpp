////////////////////////////////////////////////////////////
//�� �� ����CashRegister.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵������������ʵ��
////////////////////////////////////////////////////////////

#include "CashRegister.h"
//===========================================
//CashRegister����˵��
//�������ܣ����캯��
//===========================================
CashRegister::CashRegister() {
	// TODO Auto-generated constructor stub
}

//===========================================
//~CashRegister����˵��
//�������ܣ���������
//===========================================
CashRegister::~CashRegister() {
	// TODO Auto-generated destructor stub

}

//===========================================
//SetPreferential����˵��
//�������ܣ������Żݻ
//������    fileName���ļ�·��
//�������أ� ��
//===========================================
void CashRegister::InputGoodsCode(const string& fileName)
{
	InputContext ic(fileName);
	vector<vector<string> > strVec = ic.readFile();
	int size = strVec.size();
	map<string,int> tempMap;
	for(int i=0;i<size;i++)
	{
		if(strVec[i].size() < 2)continue;
		tempMap[strVec[i][0]] = atoi(strVec[i][1].c_str());
	}
	map<string,int>::iterator tit = tempMap.begin();
	for( ; tit != tempMap.end();++tit)
	{
		perchaseGoods[tit->first] = make_pair(stockGoods[tit->first],tit->second);
	}
}

//===========================================
//AddGoods����˵��
//�������ܣ������Ʒ
//������    fileName���ļ�·��
//�������أ� ��
//===========================================
void CashRegister::AddGoods(const string& fileName)
{
	InputContext ic(fileName);
	vector<vector<string> > strVec = ic.readFile();
	int size = strVec.size();
	for(int i=0;i<size;i++)
	{
		if(strVec[i].size() < 5)continue;
		goods g(strVec[i][0],strVec[i][1],atof(strVec[i][2].c_str()),strVec[i][3],strVec[i][4]);
		stockGoods[g.GetCode()] = g;
	}
}

//===========================================
//SetPreferential����˵��
//�������ܣ������Żݻ
//������    fileName���ļ�·��
//�������أ� ��
//===========================================
void CashRegister::SetPreferential(	const string& fileName)
{
	InputContext ic(fileName);
	vector<vector<string> > strVec = ic.readFile();
	int size = strVec.size();
	for(int i=0;i<size;i++)
	{
		if(strVec[i].size() < 7)continue;
		preferentialInfo p(strVec[i][1],strVec[i][2],atoi(strVec[i][3].c_str()),
							atof(strVec[i][4].c_str()),atoi(strVec[i][5].c_str()),atoi(strVec[i][6].c_str()));
		preferential[strVec[i][0]].push_back(p);
	}
}


//===========================================
//printItems����˵��
//�������ܣ���ӡ�����Ϣ
//������    goodsInfo��������Ϣ
//�������أ� ��
//===========================================
void CashRegister::printItems(	const vector<pair<goods,int> >& goodsInfo)
{
	//��ӡ�����Ϣ
	cout<<"***<ûǮ׬�̵�>�����嵥***"<<endl;
	int size = goodsInfo.size();
	float totalPrice = 0.0;	//�ܼ۸�
	float savePrice = 0.0;	//��ʡǮ��
	map<string,string> buyGiftsInfo;
	for( int i=0;i<size;i++)
	{
		//���ò���ģʽ�������Ʒ�ļ۸�
		CashContext cc(	(goodsInfo[i].first).GetPreferentialInfo().GetCate(),(goodsInfo[i].first).GetPreferentialInfo().GetRate(),
			(goodsInfo[i].first).GetPreferentialInfo().GetBuy(),(goodsInfo[i].first).GetPreferentialInfo().GetGitfs());
		float total = cc.GetResult(goodsInfo[i].second,(goodsInfo[i].first).GetPrice());
		//
		cout<<"���ƣ�"<<(goodsInfo[i].first).GetName()<<"��������"<<goodsInfo[i].second<<(goodsInfo[i].first).GetUnit()<<"�����ۣ�"<<(goodsInfo[i].first).GetPrice()<<"(Ԫ)��";
		//�����ܼ۸�
		totalPrice += total;
		savePrice +=  (goodsInfo[i].second*(goodsInfo[i].first).GetPrice()-total);
		//�����Ϣ
		cout<<"С�ƣ�"<<total<<"(Ԫ)";
		if( (goodsInfo[i].first).GetPreferentialInfo().GetCate() == "����")
		{
			int number = goodsInfo[i].second/((goodsInfo[i].first).GetPreferentialInfo().GetBuy()+(goodsInfo[i].first).GetPreferentialInfo().GetGitfs());
			if(number!=0)
			{
				char ch[256];
				sprintf(ch,"���ƣ�%s��������%d%s\n",(goodsInfo[i].first).GetName().c_str(),number,(goodsInfo[i].first).GetUnit().c_str());
				buyGiftsInfo[(goodsInfo[i].first).GetPreferentialInfo().GetName()] += ch;
			}
		}
		else if((goodsInfo[i].first).GetPreferentialInfo().GetCate() == "�ۿ�")
		{
			cout<<", ��ʡ��"<<(goodsInfo[i].second*(goodsInfo[i].first).GetPrice()-total)<<"(Ԫ)";
		}
		cout<<endl;
	}
	//������Ϣ��ӡ
	map<string,string>::const_iterator bit = buyGiftsInfo.begin();
	for( ;bit != buyGiftsInfo.end();++bit)
	{
		cout<<"-----------------------"<<endl;
		cout<<bit->first<<"��Ʒ��"<<endl;
		cout<<bit->second;
	}
	//�ܼ۴�ӡ
	cout<<"-----------------------"<<endl;
	cout<<"�ܼƣ�"<<totalPrice<<"(Ԫ)"<<endl;
	if( savePrice >0 )
	{
		cout<<"��ʡ��"<<savePrice<<"(Ԫ)"<<endl;
	}
	cout<<"*******************"<<endl;
}


//===========================================
//Test����˵��
//�������ܣ����Ժ���
//������    ��
//�������أ� ��
//===========================================
void CashRegister::Test()
{
	//��ʼ����Ʒ
	AddGoods("file/goods.txt");
	//�����Żݻ��Ϣ
	SetPreferential("file/preferential.txt");
	//����
	InputGoodsCode("file/purchase.txt");
	if( perchaseGoods.size() != 0)
	{
		vector<pair<goods,int> > goodsPre;
		//��ѯÿ����Ʒ���������Ż���Ϣ
		map<string,vector<preferentialInfo> >::iterator fit = preferential.begin(); //
		map<string,pair<goods,int> >::iterator it = perchaseGoods.begin();	//
		for(; it != perchaseGoods.end();++it)
		{
			fit = preferential.find((it->second).first.GetCategory());
			if( fit != preferential.end())
			{
				sort((fit->second).begin(),(fit->second).end(),greater<preferentialInfo>());
				(it->second).first.SetPreferentialInfo((fit->second)[0]);
			}
			goodsPre.push_back(it->second);
		}
		printItems(goodsPre);
	}
}


