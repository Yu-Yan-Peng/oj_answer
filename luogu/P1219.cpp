#include<bits/stdc++.h>
using namespace std;
#define N 15
bool used[N],cha[2*N],he[2*N];
int opt[N],n,ans=0;
void dfs(int u)
{
	if(u>n) //放置完毕 
	{
		if(ans<3) 
		{
			for(int i=1;i<=n;i++) 
				printf("%d ",opt[i]);
			puts(""); 
		}
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i] || cha[u-i+n] || he[i+u]) continue; //判断是否合法 
		used[i]=1,cha[u-i+n]=1,he[i+u]=1,opt[u]=i;//he数组记录右上到左下对角线的合法性，cha数组判断左上到右下对角线的合法性，used判断列的合法性
		dfs(u+1);
		used[i]=0,cha[u-i+n]=0,he[i+u]=0,opt[u]=0; //回溯 
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d\n",ans);
	return 0;
} 