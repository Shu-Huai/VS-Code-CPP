#include "In Thread Binary Tree.h"
int main()
{
    BinaryTree<int> test0(0);
    BinaryTreeNode<int> *testnode0 = test0.GetRoot();
    test0.InsertLeftChild(testnode0, 1);
    test0.InsertRightChild(testnode0, 2);
    BinaryTreeNode<int> *testnode1 = testnode0->leftChild_;
    test0.InsertLeftChild(testnode1, 3);
    test0.InsertRightChild(testnode1, 4);
    testnode0 = testnode0->rightChild_;
    test0.InsertLeftChild(testnode0, 5);
    test0.InsertRightChild(testnode0, 6);
    char c = 0;
    int e = 0;
    ThreadBinaryTreeNode<int> *p;
    cout << endl
         << "中序索化后的线索二叉树：" << endl;
    InThreadBinaryTree<int> ITBT(test0);
    DisplayBTWithTreeShape<int>(ITBT);
    while (c != '0')
    {
        cout << endl
             << "1. 插入右孩子。";
        cout << endl
             << "2. 删除左子树。";
        cout << endl
             << "3. 中序遍历。";
        cout << endl
             << "4. 显示二叉树。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~4）：";
        cin >> c;
        switch (c)
        {
        case '1':
            cout << endl
                 << "输入被插入元素的值：";
            cin >> e;
            p = ITBT.Find(e);
            if (p == NULL)
                cout << "该结点不存在！" << endl;
            else
            {
                cout << endl
                     << "输入插入元素的值：";
                cin >> e;
                ITBT.InsertRightChild(p, e);
            }
            break;
        case '2':
            cout << endl
                 << "输入删除子树双亲元素的值：";
            cin >> e;
            p = ITBT.Find(e);
            if (p == NULL)
                cout << "该结点不存在！" << endl;
            else
                ITBT.DeleteLeftChild(p);
            break;
        case '3':
            cout << endl;
            ITBT.InOrderTraverse(Write<int>);
            break;
        case '4':
            cout << endl;
            DisplayBTWithTreeShape(ITBT);
            break;
        }
    }
    return 0;
}