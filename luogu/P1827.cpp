#include <iostream>
using namespace std;
struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode(char x) : data(x), lchild(NULL), rchild(NULL) {}
};
struct BTree
{
    BTNode *r;
    BTree() : r(NULL) {}
    BTNode *createBTree(const string &zx, int in_start, int in_end, const string &qx, int pre_start, int pre_end)
    {
        if (pre_start > pre_end)
            return NULL;
        BTNode *newNode = new BTNode(qx[pre_start]);
        int j = 0;
       for(int p = in_start;p <= in_end;++p){
        if(zx[p] == qx[pre_start]){
            j = p;
            break;
        }
       }
        int k = j - in_start; // 确定还有没有左子树,j-i为左子树的元素数量
        newNode->lchild = createBTree(zx, in_start, j - 1, qx, pre_start + 1, pre_start + j - in_start);
        newNode->rchild = createBTree(zx, j + 1, in_end, qx, pre_start + j - in_start + 1, pre_end);
        return newNode;
    }
    BTNode* buildTree(const string&inorder,const string&preorder){
        return createBTree(inorder,0,inorder.size() - 1,preorder,0,preorder.size() - 1);
    }
    void postOrder(BTNode*n){
        if(n){
            postOrder(n->lchild);
            postOrder(n->rchild);
            cout << n->data;
        }
    }
};
int main()
{
    string zx, qx;
    cin >> zx;
    cin >> qx;
    BTree t1;
    t1.r = t1.buildTree(zx,qx);
    t1.postOrder(t1.r);
    return 0;
}