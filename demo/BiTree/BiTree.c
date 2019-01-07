#include "BiTree.h"
#define MAXNODE 1024
BiTree Initiate(void)
{ //初始化建立带头结点的二叉树
    BiTNode *bt;
    bt = (BiTNode *)malloc(sizeof(BiTNode));
    bt->lchild = NULL;
    bt->rchild = NULL;
    return bt;
}
BiTree Initiate2(void)
{ //初始化建立不带头结点的二叉树
    BiTNode *bt;
    bt = NULL;
    return bt;
}
BiTree CreateT(elem x, BiTree lbt, BiTree rbt)
{ //x为根节点
    BiTree p;
    if ((p = (BiTNode *)malloc(sizeof(BiTNode))) == NULL)
        return NULL;
    p->data = x;
    p->lchild = lbt;
    p->rchild = rbt;
    return p;
}
BiTree Insert_L(BiTree bt, elem x, BiTree parent)
{ //将x插入二叉树的 bt作为parent的左孩子节点，依此类推
    BiTree p;
    if (parent == NULL)
    {
        printf("\nINSERT_L_error");
        return NULL;
    }
    if ((p = (BiTNode *)malloc(sizeof(BiTNode))) == NULL)
        return NULL;
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    if (parent->lchild == NULL)
        parent->lchild = p;
    else
    {
        p->lchild = parent->lchild;
        parent->lchild = p;
    }
    return bt;
}
BiTree Delete_L(BiTree bt, BiTree parent)
{ //在二叉树 bt中删除parent的左子树
    BiTree p;
    if (parent == NULL || parent->lchild == NULL)
    {
        printf("DELETE_L_error");
        return NULL;
    }
    p = parent->lchild;
    parent->lchild = NULL;
    free(p); /*当p为非叶子节点时，这样删除仅释放所删除子树根节点的空间
             若要删除子树分支的节点，需要后面介绍的遍历操作来实现*/
    return bt;
}
BiTree Delete_R(BiTree bt, BiTree parent)
{ //在二叉树 bt中删除parent的右子树
    BiTree p;
    if (parent == NULL || parent->rchild == NULL)
    {
        printf("DELETE_R_error");
        return NULL;
    }
    p = parent->rchild;
    parent->rchild = NULL;
    free(p); /*当p为非叶子节点时，这样删除仅释放所删除子树根节点的空间
             若要删除子树分支的节点，需要后面介绍的遍历操作来实现*/
    return bt;
}
void PreOrder(BiTree bt)
{ //二叉树 先序遍历 递归
    if (bt == NULL)
        return;           //递归调用的结束条件
    Visit(bt);            //访问根节点
    PreOrder(bt->lchild); //先序递归遍历 bt的左子树
    PreOrder(bt->rchild); //先序递归遍历 bt的右子树
}
void InOrder(BiTree bt)
{ //二叉树 中序遍历 递归
    if (bt == NULL)
        return;          //递归调用的结束条件
    InOrder(bt->lchild); //中序递归遍历 bt的左子树
    Visit(bt);           //访问根节点
    InOrder(bt->rchild); //中序递归遍历 bt的右子树
}
void PostOrder(BiTree bt)
{                   //二叉树 后序遍历 递归
    if (bt == NULL) //递归调用的结束条件
        return;
    PostOrder(bt->lchild); //后序递归遍历 bt的左子树
    PostOrder(bt->rchild); //后序递归遍历 bt的右子树
    Visit(bt);             //访问根节点
}
void NRPreOrder(BiTree bt)
{ //二叉树 先序遍历 非递归
    BiTNode *stack[MAXNODE],
        *p;       //规定栈空间
    int top = -1; //初始化栈为空
    if (bt == NULL)
        return;
    p = bt; //p指向根节点
    while (!(p == NULL && top == -1))
    {
        while (p != NULL)
        {
            Visit(p);
            top++;
            stack[top] = p; //将当前指针 p压栈
            p = p->lchild;  //指针指向p的左孩子
        }
        if (top < 0) //栈空时结束
            return;
        else
        {
            p = stack[top];
            top--;         //从栈中弹出栈顶元素
            p = p->rchild; //到栈顶元素右子树
        }
    }
}
void NRInOrder(BiTree bt)
{ //二叉树 中序遍历 非递归
    BiTNode *stack[MAXNODE],
        *p;       //规定栈空间
    int top = -1; //初始化栈为空
    if (bt == NULL)
        return;
    p = bt; //p指向根节点
    while (!(p == NULL && top == -1))
    {
        while (p != NULL)
        {
            top++;
            stack[top] = p; //将当前指针 p压栈
            p = p->lchild;  //指针指向p的左孩子
        }
        if (top < 0) //栈空时结束
            return;
        else
        {
            p = stack[top];
            top--; //从栈中弹出栈顶元素
            Visit(p);
            p = p->rchild; //到栈顶元素右子树
        }
    }
}
void NRPostOrder(BiTree bt)
{ //二叉树 后序遍历 非递归
    BiTNode *stack[MAXNODE],
        *p;       //规定栈空间
    int top = -1; //初始化栈为空
    if (bt == NULL)
        return;
    p = bt; //p指向根节点
    while (!(p == NULL && top == -1))
    {
        while (p != NULL)
        {
            top++;
            stack[top] = p; //将当前指针 p压栈
            p = p->lchild;  //指针指向p的左孩子
        }
        if (top > -1)           //栈不空
            if (stack[top] > 0) //第一次在栈中
            {
                p = stack[top]->rchild;  //转向右子树
                stack[top] = stack[top]; //?//相当于节点第一次出栈，第二次进栈
            }
            else
            {                   //第二次在栈中
                p = stack[top]; //?//出栈，访问
                top--;
                Visit(p);
                p = NULL;
            }
    }
}
void LevelOrder(BiTree bt)
{ //层次遍历二叉树
    BiTNode *queue[MAXNODE];
    int front, rear;
    if (bt == NULL)
        return;
    front = -1;
    rear = 0;
    queue[rear] = bt;
    while (front != rear)
    {
        front++;
        Visit(queue[front]);
        if (queue[front]->lchild != NULL)
        {
            rear++;
            queue[rear] = queue[front]->lchild;
        }
        if (queue[front]->rchild != NULL)
        {
            rear++;
            queue[rear] = queue[front]->rchild;
        }
    }
}
void CreateBiTree(BiTree *T)
{ //建立二叉树的二叉链表
    char ch;
    scanf("%c", &ch);
    if (ch == '\0')
        *T = NULL;
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}
BiTree Search(BiTree bt, datatype x)
{ //二叉树 查找 安值 X
    BiTree p;
    if (bt)
    {
        if (bt->data == x)
            return bt;
        if (bt->lchild)
            p = Search(bt->lchild, x);
        if (p)
            return p;
        if (bt->rchild)
            p = Search(bt->rchild, x);
        if (p)
            return p;
    }
    return NULL;
}
int CountLeaf2(BiTree bt)
{ //统计给定二叉树叶子节点数目
    if (bt == NULL)
        return 0;
    if (bt->lchild == NULL && bt->rchild == NULL)
        return 1;
    return (CountLeaf2(bt->lchild) + CountLeaf2(bt->rchild));
}
void ReBiTree(char preod[], char inod[], BiTree root)
{ //根据先序序列 恢复 二叉树
    if (n < 0)
        root = NULL;
    else
        PreInOd(preod, inod, 1, n, 1, n, &root);
}
void PreInOd(char preod[], int i, int j, char inod[], int k, int h, BiTree *t)
{ //根据中序序列 恢复 二叉树
    *t = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->data = preod[i];
    m = k;
    while (inod[m] != preod[i])
        m++;
    if (m == k)
        (*t)->lchild = NULL;
    else
        PreInOd(preod, i + 1, i + m - k, inod, k, m - 1, &((*t)->lchild));
    if (m == k)
        (*t)->rchild = NULL;
    else
        PreInOd(preod, i + 1, i + m - k, inod, k, m - 1, &((*t)->rchild));
}
int Visit(BiTree p)
{ //查看p对应的data
    if()
    printf("%c",p->data);
    return 1;

}
