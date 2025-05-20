#include<iostream>
using namespace std;
#define maxn 1000000
struct BTNode{
    int lchildid;
    int rchildid;
    int id;
    BTNode(){}
    BTNode(int idl,int idr,int idd):lchildid(idl),rchildid(idr),id(idd){}
}BTree[maxn];
int maxdep;
void dfs(BTNode*arr,int depth){
    if((arr->lchildid == 0) && (arr->rchildid == 0)){
        maxdep = max(maxdep,depth);
        return;
    }
    dfs(&BTree[arr->lchildid],depth + 1);
    dfs(&BTree[arr->rchildid],depth + 1);
}
int main(){
    int n;
    cin >> n;
    int x,y;
    for(int i = 1;i <= n;i++){
        cin >> x >> y;
        BTree[i] = BTNode(x,y,i);
    }
    dfs(&BTree[1],1);
    cout << maxdep << endl;
}