////////////////////////////////////////////////////////////
//�� �� ����CashRegister.cpp
//������Ա���Ծ�
//��    �ڣ�2016-03-09
//�ļ�˵�����������࣬�����Ʒ������Żݻ�����������ӡ������Ʒ��Ϣ
////////////////////////////////////////////////////////////

#include "CashRegister.h"

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
//������    itemLists��������Ʒ�����ַ���
//		   sperator���ַ����ָ��
//		   start����ʼ�ַ�
//		   end����ֹ�ַ�
//�������أ� �ַ���
//===========================================
string CashRegister::InputGoodsCode(	const string& itemLists,
										const char* sperator,
										const char* start,
										const char* end)
{
	//���������ַ�����ȥ��ͷβ����
	size_t spos = itemLists.find(start);
	size_t epos = itemLists.find(end);
	if(spos == string::npos || epos == string::npos)
	{
			return "error:input string error";
	}
	string substr = itemLists.substr(spos+1,epos-(spos+2));
	//ʹ�÷ָ���ָ�������ַ���
	char* token = NULL;
	char* buffer = const_cast<char*>(substr.c_str());
	map<string,int> tempMap;
	token = strtok( buffer, sperator );
	while (token != NULL)
	{	
		//�����ַ���-��
		string tempStr = token;
		//ɾ��'�ַ�
		deleteSomeChar(tempStr,'\'');
		size_t pos = tempStr.find('-');
		if( pos != string::npos)
		{
			string code = tempStr.substr(0,pos);
			string numStr = tempStr.substr(pos+1,tempStr.size()-(pos+1));
			tempMap[code]+= atoi(numStr.c_str());
		}
		else
		{
			tempMap[tempStr]+=1;
		}
		token = strtok( NULL, sperator );	
	}
	map<string,int>::iterator tit = tempMap.begin();
	for( ; tit != tempMap.end();++tit)
	{
		PerchaseGoods[tit->first] = make_pair(stockGoods[tit->first],tit->second);
	}
	return "success";
}

//===========================================
//AddGoods����˵��
//�������ܣ������Ʒ
//������    g����Ʒ
//�������أ� ��
//===========================================
void CashRegister::AddGoods(const goods& g)
{
	stockGoods[g.GetCode()] = g;
}

//===========================================
//SetPreferential����˵��
//�������ܣ������Żݻ
//������    goodsCategory����Ʒ���
//		   pcate���Żݻ���
//		   pname���Żݻ����
//		   prioprity�����ȼ�
//		   rate���ۿ�ֵ
//		   buy��������
//		   gitfs��������
//�������أ� ��
//===========================================
void CashRegister::SetPreferential(	const string& goodsCategory,
									const string& pcate,
									const string& pname,
									const int prioprity,
									const float& rate,
									const int& buy,
									const int& gitfs)
{
	preferentialInfo p(pcate,pname,prioprity,rate,buy,gitfs);
	preferential[goodsCategory].push_back(p);

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
	goods g1("�ɿڿ���","ƿ",3.0,"����","ITEM000001");
	goods g2("��ë��","��",1.0,"������Ʒ","ITEM000007");
	goods g3("ƻ��","��",5.5,"ˮ��","ITEM000014");
	//�����Ʒ
	AddGoods(g1);
	AddGoods(g2);
	AddGoods(g3);
	//�����Żݻ��Ϣ
	SetPreferential("����","����","�����һ",2,0.0,2,1);
	SetPreferential("������Ʒ","����","�����һ",2,0.0,2,1);
	SetPreferential("ˮ��","�ۿ�","95��",1,0.95,0,0);
	//��������
	const string inputStr = "['ITEM000001','ITEM000001','ITEM000001','ITEM000007','ITEM000007','ITEM000007','ITEM000007','ITEM000007','ITEM000007','ITEM000014-2']";
	string info = InputGoodsCode(inputStr,",","[","]");
	if( !info.compare("success"))
	{
		vector<pair<goods,int> > goodsPre;
		//��ѯÿ����Ʒ���������Ż���Ϣ
		map<string,vector<preferentialInfo> >::iterator fit = preferential.begin(); //
		map<string,pair<goods,int> >::iterator it = PerchaseGoods.begin();	//
		for(; it != PerchaseGoods.end();++it)
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

//===========================================
//printItems����˵��
//�������ܣ���ӡ�����Ϣ
//������    ��
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


