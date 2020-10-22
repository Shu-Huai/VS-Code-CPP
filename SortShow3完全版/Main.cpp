// Main.cpp
#include "SortShow.h"
#include <conio.h>
#include <stdlib.h> // �� <cstdlib>
#include <time.h>   // �� <ctime>

int main()
{
    char text[100];
    const char *str[] = {"1 ---- ��������ԭʼ����(D)",
                         "2 ---- ð������........(B)",
                         "3 ---- ѡ������........(S)",
                         "4 ---- �鲢����........(M)",
                         "5 ---- ��������........(Q)",
                         "6 ---- �Ż���ð������..(C)",
                         "7 ---- �Ż���ѡ������..(T)",
                         "0 ---- �˳�..........(ESC)",
                         "��ѡ��: "};
    int choice, n = sizeof(str) / sizeof(*str);

    srand(time(NULL));

    Init();

    while (true)
    {
        SetConsoleTitle("SortShow������ - ������̿��ӻ�");
        system("cls");
        for (int i = 0; i < n; i++)
            ShowText(20, i + 2, 0, 7, str[i]); // ��ʾ�˵�
        choice = getch();
        if (choice == 27 || choice == '0')
            break;

        switch (choice)
        {
        case '1':
        case 'd':
        case 'D':
            ShowText(2, 10, 0, 7, "1.����; 2.����; 3.��� : ");
            SetData(getch() - '0');
            system("cls");
            ShowData();
            break;
        case '2':
        case 'b':
        case 'B':
            col1 = 30;
            SetConsoleTitle("ð������Bubble Sorting��");
            Start();
            Bubble_Sort(array, N);
            Finish();
            break;
        case '3':
        case 's':
        case 'S':
            col1 = 30;
            SetConsoleTitle("ѡ������Selection Sorting��");
            Start();
            Select_Sort(array, N);
            Finish();
            break;
        case '4':
        case 'm':
        case 'M':
            col1 = 5;
            col2 = col1 + 40;
            SetConsoleTitle("�鲢����Merge Sorting��");
            Start();
            Merge_Sort(array, N);
            Finish();
            break;
        case '5':
        case 'q':
        case 'Q':
            col1 = 40;
            SetConsoleTitle("��������Quick Sorting��");
            Start();
            Quick_Sort(array, N);
            Finish();
            break;
        case '6':
        case 'c':
        case 'C':
            col1 = 30;
            SetConsoleTitle("�Ż���ð������Optimized Bubble Sorting��");
            Start();
            Optimized_Bubble_Sort(array, N);
            Finish();
            break;
        case '7':
        case 't':
        case 'T':
            col1 = 30;
            SetConsoleTitle("�Ż���ѡ������Optimized Selection Sorting��");
            Start();
            Optimized_Select_Sort(array, N);
            Finish();
            break;
        }
        sprintf(text, "���س�������...");
        ShowText(79 - strlen(text), top + N + 6, 0, 7, text);
        while (getch() != '\r')
            ;
    }
    Quit();
    return 0;
}
