// Test.cpp
#include "MyRand.h"
#include "Score.h"
#include "Sorts.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <typeinfo>
using namespace std;

double gettime(int restart) // ������Ĭ��ֵ�������ʾ���¼�ʱ
{                           // �����ۼƼ�ʱ
    const double c = 1.0 / CLOCKS_PER_SEC;
    static clock_t t = clock(); // ��̬�ֲ���������һ�ε���ʱ��ȷ����ʱ���
    if (restart)
        t = clock();          // ����ʵ�ξ����Ƿ�����ȷ����ʱ���
    return c * (clock() - t); // ����һ��ʱ�㵽������������ʱ��
}

template <typename T>
void InitData(T *data, int n, int flag)
{
    int i;
    switch (flag)
    {
    case -1:
        for (i = 0; i < n; i++)
            data[i] = n - 1 - i;
        break; // ���򣨴Ӵ�С��
    case 0:
        for (i = 0; i < n; i++)
            data[i] = i;
        break; // ˳�򣨴�С����
    case 1:
        for (i = 0; i < n; i++)
            data[i] = (T)UniformRand(54, 90);
        break; // [54,90]�ϵľ��ȷֲ�
    default:
        for (i = 0; i < n; i++)
            data[i] = (T)GaussRand(72, 6 * 6);
        break; // ��̬�ֲ�����ֵ72������36��������6��
    }
}

template <typename T>
void Test(const T &x) // ���ñ�������ʵ�ε�ֵ����Ҫ����Ҫ����ʵ�ε���������
{
    T *data0 = NULL, *data = NULL;                                          // ����ָ���ʼ��ΪNULL�ǳ���Ҫ��
    char InitConf[][20] = {"��ȫ����", "��ȫ˳��", "���ȷֲ�", "��̬�ֲ�"}; // C-�ַ�������
    char algo[][20] = {"ð������", "ѡ������", "��������"};                 // C-�ַ�������
    void (*f[])(T *, int) = {Bubble, Select, Qsort};                        // ����ָ�����飨Ԫ��Ϊһϵ�к�������ڵ�ַ��
    int i, j, n, m = sizeof(f) / sizeof(*f);
    bool flag[20]; // ������Ϊ������20�㹻���ڱ��� m����¼��ͬ�㷨ִ�е���ȷ��
    double t[20];  // ͬ�ϡ���¼��ͬ�㷨��ִ��ʱ��

    for (j = 2; j >= -1; j--) // ���ݷֲ�����
    {
        cout << "\n��������: " << typeid(T).name() << " (" << InitConf[j + 1] << ")" << endl;
        cout << "                                                                             "; // ������Ϊ��������������ʾ�ÿ����ĵ�
        for (i = 0; i < m; i++)
            cout << " " << algo[i]; // ������Ϊ��������������ʾ�ÿ����ĵ�
        cout << endl;
        for (n = 1024; n <= 65536; n *= 2)
        {
            GetMemory(data, data0, n);                      // �������ѿռ�
            InitData(data0, n, j);                          // ����ԭʼ����
            cout << setiosflags(ios::left) << setw(6) << n; // ������������Ϊ�̶�ռ��λ���
            for (i = 0; i < m; i++)
            {
                if (n == 65536 && j <= 0 && i == m - 1) // j<=0(��ȫ˳����ȫ����)��i==m-1(�������򣬵ݹ��㷨)
                    break;
                ReSet(data, data0, n);    // �ָ�ԭʼ����
                gettime(1);               // ���ü�ʱ���
                f[i](data, n);            // �� i �������㷨
                t[i] = gettime();         // ���شӼ�ʱ��㵽Ŀǰ��������ʱ�䣨�룩
                flag[i] = Check(data, n); // �����������ȷ��
            }
            for (i = 0; i < m; i++)
            {
                if (n == 65536 && j <= 0 && i == m - 1) // j<=0(��ȫ˳����ȫ����)��i==m-1(�������򣬵ݹ��㷨)
                    cout << "\t" << endl;
                else
                    cout << '\t' << t[i];
            }
            for (i = 0; i < m; i++)
            {
                if (n == 65536 && j <= 0 && i == m - 1) // j<=0(��ȫ˳����ȫ����)��i==m-1(�������򣬵ݹ��㷨)
                    cout << "\t�����������ڵݹ���̫����ܵ���ջ�������������";
                else
                    cout << '\t' << algo[i] << (flag[i] ? ": ��ȷ" : ": ����");
            }
            cout << endl;
            FreeMemory(data, data0); // �ͷŶѿռ���Դ����ʹָ��Ϊ��
        }
    }
}

int main() // ������
{
    srand(time(NULL)); // ���������������������

    Test(int(0));    // ����int��������
    Test(double(0)); // ����double��������
    TestScore();     // ����Score��������

    return 0;
}
