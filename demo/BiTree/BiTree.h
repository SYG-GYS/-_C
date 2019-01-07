#ifndef __BITREE_H
#define __BITREE_H
#include <stdlib.h>
#include <malloc.h>

#define datatype char
#define elem char
typedef struct binode
{ //二叉树的二叉链表存储结构
    datatype data;
    struct binode *lchild, *rchild; //左右孩纸指针
} BiTNode, *BiTree;

BiTree Initiate(void);                                                          //初始化建立带头结点的二叉树
BiTree Initiate2(void);                                                         //初始化建立不带头结点的二叉树
BiTree CreateT(elem x, BiTree lbt, BiTree rbt);                                 //x为根节点
BiTree Insert_L(BiTree bt, elem x, BiTree parent);                              //将x插入二叉树的 bt作为parent的左孩子节点，依此类推
BiTree Insert_R(BiTree bt, elem x, BiTree parent);                              //将x插入二叉树的 bt作为parent的右孩子节点，依此类推
BiTree Delete_L(BiTree bt, BiTree parent);                                      //在二叉树 bt中删除parent的左子树
BiTree Delete_R(BiTree bt, BiTree parent);                                      //在二叉树 bt中删除parent的右子树
void PreOrder(BiTree bt);                                                       //二叉树 先序遍历 递归
void InOrder(BiTree bt);                                                        //二叉树 中序遍历 递归
void PostOrder(BiTree bt);                                                      //二叉树 后序遍历 递归
void NRPreOrder(BiTree bt);                                                     //二叉树 先序遍历 非递归
void NRInOrder(BiTree bt);                                                      //二叉树 中序遍历 非递归
void NRPostOrder(BiTree bt);                                                    //二叉树 后序遍历 非递归
void LevelOrder(BiTree bt);                                                     //层次遍历二叉树
void CreateBiTree(BiTree *T);                                                   //建立二叉树的二叉链表
BiTree Search(BiTree bt, datatype x);                                           //二叉树 查找 安值 X
int CountLeaf2(BiTree bt);                                                      //统计给定二叉树叶子节点数目
void ReBiTree(char preod[], char inod[], BiTree root);                          //根据先序序列 恢复 二叉树
void PreInOd(char preod[], int i, int j, char inod[], int k, int h, BiTree *t); //根据中序序列 恢复 二叉树
int Visit(BiTree p);                                                            //查看p对应的data
#endif
