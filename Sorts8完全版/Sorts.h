// Sorts.h		���֣�ð�ݡ�ѡ�񡢿��٣����������㷨������
#ifndef SORTS_H
#define SORTS_H
#include <iomanip>
#include <iostream>
using namespace std;

double gettime(int restart = 0);

template <typename T>
void GetMemory(T *&data, T *&data0, int n) // ������ڴ�ռ䣬ͨ������"����"�׵�ַ
{                                          // ����Լ����ָ��ǿվͱ�ʾָ��"ӵ��"�ѿռ���Դ
    if (data0 != NULL)
        delete[] data0; // ���ͷ�ԭ����"ӵ��"�Ķѿռ���Դ
    if (data != NULL)
        delete[] data;
    data0 = new T[n]; // ���������µģ���������Ҫ��ģ��ѿռ���Դ
    data = new T[n];
}

template <typename T>
void FreeMemory(T *&data, T *&data0) // �ͷ�ָ����"ӵ��"�Ķѿռ���Դ
{
    if (data0 != NULL)
        delete[] data0;
    if (data != NULL)
        delete[] data;
    data0 = data = NULL; // ��һ����ֵ���ǳ���Ҫ������"����Լ��"
}

template <typename T>
void ReSet(T *data, const T *data0, int n) // ���ڻָ�"ԭʼ����"���Ա�֤��ͬ�������㷨������ȫ��ͬ������
{
    for (int i = 0; i < n; i++)
        data[i] = data0[i];
}

template <typename T>
bool Check(const T *a, int size) // ��������Ԫ���Ƿ��Ѱ���������
{
    for (int i = 1; i < size; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

// ���ֻ����ģ��Ż��ģ������㷨
template <typename T>
void Bubble(T *a, int size) // ð������
{
    long long fuzhicishu = 0; // ���帳ֵ�����ͱȽϴ���
    long long bijiaocishu = 0;
    T temp; // ����һ���ֲ�������������������ʽ����������ͬ
    int i, j;
    int left = 0; // ͬʱ�����ֵ����С��Ҫ�����±����
    int right = size - 1;
    int tempPostion = 0;           // ��ʼ�Ƚϵ��±�
    for (i = 0; i < size - 1; i++) // ������ size-1 �ֱȽϺͽ���
    {
        int flag = 1; // ��ʼδ������
        tempPostion = 0;
        for (j = left; j < right; j++) // ����Ѱ�����ֵ
        {
            bijiaocishu++;       // �Ƚϴ���+1
            if (a[j] > a[j + 1]) // ����Ԫ��֮��Ƚϣ���Ҫʱ
            {
                temp = a[j]; // ���� a[j] �� a[j+1]
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 0; // ��¼�Ѿ�������
                tempPostion = j;
                fuzhicishu += 3; // ��ֵ����+3
            }
        }
        if (flag == 1) // �ж����û�н���������ѭ��
        {
            break;
        }
        right = tempPostion;
        for (j = right; j > left; j--) // ����Ѱ����Сֵ
        {
            bijiaocishu++;       // �Ƚϴ���+1
            if (a[j] < a[j - 1]) // ����Ԫ��֮��Ƚϣ���Ҫʱ
            {
                temp = a[j]; // ���� a[j] �� a[j+1]
                a[j] = a[j - 1];
                a[j - 1] = temp;
                flag = 0; // ��¼�Ѿ�������
                tempPostion = j;
                fuzhicishu += 3; // ��ֵ����+3
            }
        }
        left++;
        if (flag == 1) // �ж����û�н���������ѭ��
        {
            break;
        }
    }
    cout << "ð�ȣ�" << setw(12) << bijiaocishu << "ð����" << setw(12) << fuzhicishu; // ����Ƚϴ����͸�ֵ����
}

template <typename T>
void Select(T *a, int size) // ѡ������
{
    long long bijiaocishu = 0; // ���帳ֵ�����ͱȽϴ���
    long long fuzhicishu = 0;
    int i;
    int left = 0, right = size - 1;
    int min = left, max = left;
    while (left < right) // �����м�λ�ü�ֹͣ
    {
        min = left;
        max = left;
        for (i = left; i <= right; i++) // �趨Ѱ�������Сֵ�ķ�Χ
        {
            bijiaocishu++;     // �Ƚϴ���+1
            if (a[i] > a[max]) // Ѱ�����ֵ
            {
                max = i;
            }
            bijiaocishu++;     // �Ƚϴ���+1
            if (a[i] < a[min]) // Ѱ����Сֵ
            {
                min = i;
            }
        }
        if (max != right) // ������ֵ�������λ
        {
            swap(a[max], a[right]); // ���� a[max] �� a[right]
            fuzhicishu += 3;        // ��ֵ����+3
        }
        if (min == right) // ��ֹ��Сֵ�����ֵҪ�����λ��
        {
            min = max;
        }
        if (min != left) // �����Сֵ��������λ
        {
            swap(a[min], a[left]); // ���� a[min] �� a[left]
            fuzhicishu += 3;       // ��ֵ����+3
        }
        left++;
        right--;
    }
    cout << "�ȱȣ�" << setw(12) << bijiaocishu << "�ȸ���" << setw(12) << fuzhicishu; // ����Ƚϴ����͸�ֵ����
}

template <typename T>
int gepivot(T *a, int size) // ����ȡ��
{
    if (size < 3)
        return 0;
    int b[3];
    b[0] = 0;
    b[1] = size / 2;
    b[2] = size - 1;
    int seq[6][3] = {{0, 1, 2},
                     {2, 1, 0},
                     {0, 2, 1},
                     {1, 2, 0},
                     {1, 0, 2},
                     {2, 0, 1}};
    for (int i = 0; i < 6; i++) // �жϴ���
    {
        const int *s = seq[i];
        if (a[b[s[1]]] >= a[b[s[0]]] && a[b[s[2]]] >= a[b[s[1]]]) // �Ƚϴ�С
            return b[s[1]];                                       // ������λ��
    }
    return b[1];
}

template <typename T>
void Qsort(T *a, int size) // ��������
{
    T pivot, temp;                  // ����ֲ�������������������ʽ����������ͬ
    int left = 0, right = size - 1; // �±꣨������
    if (size <= 1)
        return;
    int TempTivot = gepivot(a, size); // ȡ�ֽ�ֵ
    if (TempTivot != right)
        swap(a[TempTivot], a[right]);
    pivot = a[right];
    do
    {
        while (left < right && a[left] <= pivot)
        {
            left++;
        } // �˴� "<=" ������ֽ�ֵ��ȵ�Ԫ����ʱ����ԭ��
        while (left < right && a[right] >= pivot)
        {
            right--;
        } // �˴� ">=" ������ֽ�ֵ��ȵ�Ԫ����ʱ����ԭ��
        if (left < right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp; // ����a[eft] �� a[right]
        }
    } while (left < right);
    a[size - 1] = a[left];
    a[left] = pivot;                        // �ҵ��ֽ�� left
    Qsort(a, right);                        // �ݹ����(��ಿ��)
    Qsort(a + right + 1, size - right - 1); // �ݹ����(�Ҳಿ��)
}

#endif
