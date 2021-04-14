#include "AdjacencyListDirectedNetwork.h"
int main()
{
     int infity = DEFAULT_INFINITY;
     char vexs[] = {'A', 'B', 'C', 'D'};
     int m[4][4] = {
         {infity, 2, 3, 4},
         {2, infity, 5, 6},
         {3, 5, infity, 7},
         {4, 6, 7, infity}};
     char c = 0;
     char e, e1, e2;
     int n = 4, v, v1, v2, w;
     AdjacencyListDirectedNetwork<char, int> ALDN(vexs, n);
     for (int v = 0; v < n; v++)
     {
          for (int u = 0; u < n; u++)
          {
               if (m[v][u] != infity)
               {
                    ALDN.InsertSide(v, u, m[v][u]);
               }
          }
     }
     while (c != '0')
     {
          cout << endl
               << "1. 有向网清空.";
          cout << endl
               << "2. 显示有向网.";
          cout << endl
               << "3. 取指定顶点的值.";
          cout << endl
               << "4. 设置指定顶点的值.";
          cout << endl
               << "5. 删除顶点.";
          cout << endl
               << "6. 插入顶点.";
          cout << endl
               << "7. 删除边.";
          cout << endl
               << "8. 插入边.";
          cout << endl
               << "9. 设置指定边的权.";
          cout << endl
               << "0. 退出";
          cout << endl
               << "选择功能(0~9):";
          cin >> c;
          switch (c)
          {
          case '1':
               ALDN.Clear();
               break;
          case '2':
               if (ALDN.IsEmpty())
                    cout << "该有向网为空。" << endl;
               else
                    ALDN.Display();
               break;
          case '3':
               cout << endl
                    << "输入顶点序号（有向网的顶点序号从0开始）:";
               cin >> v;
               ALDN.GetElem(v, e);
               cout << "序号为" << v << "的顶点为" << e;
               break;
          case '4':
               cout << endl
                    << "输入顶点序号（有向网的顶点序号从0开始）:";
               cin >> v;
               cout << endl
                    << "输入" << v << "号顶点的值:";
               cin >> e;
               ALDN.SetElem(v, e);
               break;
          case '5':
               cout << endl
                    << "输入被删除顶点的值:";
               cin >> e;
               ALDN.DeleteVertex(e);
               break;
          case '6':
               cout << endl
                    << "输入插入顶点的值:";
               cin >> e;
               ALDN.AppendVertex(e);
               break;
          case '7':
               cout << endl
                    << "输入与被删除边关联的两个顶点值:";
               cin >> e1 >> e2;
               v1 = ALDN.GetIndex(e1);
               v2 = ALDN.GetIndex(e2);
               ALDN.DeleteSide(v1, v2);
               break;
          case '8':
               cout << endl
                    << "输入与插入边关联的两个顶点值和边的权值:";
               cin >> e1 >> e2 >> w;
               v1 = ALDN.GetIndex(e1);
               v2 = ALDN.GetIndex(e2);
               ALDN.InsertSide(v1, v2, w);
               break;
          case '9':
               cout << endl
                    << "输入与插入边关联的两个顶点值和边的权值:";
               cin >> e1 >> e2 >> w;
               v1 = ALDN.GetIndex(e1);
               v2 = ALDN.GetIndex(e2);
               ALDN.SetWeight(v1, v2, w);
               break;
          }
     }
     return 0;
}