// Score.cpp
#include "MyRand.h"
#include "Score.h"
#include "Sorts.h"
#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;

void InitScore(Score *data, int n)
{
	double mean=72, variance=6*6;
	for(int i=0; i<n; i++)
	{
		sprintf(data[i].Id, "%08d", i+1);	// ����ѧ sprintf ��������ע�⣺ԭʼ�����У�ѧ������ȫ˳�����еģ�
		data[i].Total  = data[i].Chinese   = int(0.5+GaussRand(mean, variance));
		data[i].Total += data[i].Math      = int(0.5+GaussRand(mean, variance));
		data[i].Total += data[i].English   = int(0.5+GaussRand(mean, variance));
		data[i].Total += data[i].Physics   = int(0.5+GaussRand(mean, variance));
		data[i].Total += data[i].Chemistry = int(0.5+GaussRand(mean, variance));
	}
}

void ShowScore(const Score *data, int size, int last)
{
	int m;
	if(last<=0 || last>=size)
		m = 0;								// ��������
	else
		m = size-last;						// ���last������
	cout << "\t��������������ݣ����ܷ�ǰ�����������ݣ�" << endl;
	cout << "\t ѧ ��  �ܷ� �� �� �� �� ��" << endl;
	for(int i=size-1; i>=m; i--)
		cout << '\t' << data[i].Id << ' ' << data[i].Total << ' '
			 << data[i].Chinese << ' ' << data[i].Math << ' '
			 << data[i].English << ' ' << data[i].Physics << ' '
			 << data[i].Chemistry << endl;
}

void TestScore()
{
	Score *data0=NULL, *data=NULL;							// ����ָ���ʼ��ΪNULL�ǳ���Ҫ��
	char algo[][20] = {"ð������", "ѡ������", "��������"};	// C-�ַ�������
	void (*f[])(Score*, int) = {Bubble, Select, Qsort};		// ����ָ�����飨Ԫ��Ϊһϵ�к�������ڵ�ַ��
	int n, m = sizeof(f)/sizeof(*f);
	bool flag;
	double t;
	
	cout << "\nԭʼ���ݷֲ�: ��̬�ֲ�, �������� = " << typeid(Score).name() << endl;
	for(n=1024; n<=65536; n*=2)
	{
		GetMemory(data, data0, n);							// �������ѿռ�
		InitScore(data0, n);								// ����ԭʼ����
		for(int i=0; i<m; i++)
		{
			ReSet(data, data0, n);							// �ָ�ԭʼ����
			gettime(1);										// ���ü�ʱ���
			f[i](data, n);									// �� i �������㷨
			t = gettime();									// ���شӼ�ʱ��㵽Ŀǰ��������ʱ�䣨�룩
			flag = Check(data, n);							// �����������ȷ��
			cout << n << '\t' << t << '\t' << algo[i] << (flag?": ��ȷ":": ����") << endl;
			ShowScore(data, n, 10);							// ����������10����ڰ��������У���߷ֵ�һ�������
		}
		FreeMemory(data, data0);							// �ͷŶѿռ���Դ����ʹָ��Ϊ��
	}
}
