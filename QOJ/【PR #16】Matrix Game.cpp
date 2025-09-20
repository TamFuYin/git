#include<bits/stdc++.h>
#define ckmax(a,b) a=std::max(a,b)
const int N=1e3+10;
char mp[N];
int a0[N],a1[N];
int solve(int a[],int n){
	std::copy(a+1,a+n+1,s+1);
	for(int i=1;i<=n;i++){
	}
}
int a[N],b[N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp+1);
		for(int j=1;j<=m;j++)
			a[i]+=mp[j]-'0',
			b[j]+=mp[j]-'0';
	}
	printf("%d",solve(a,n)+solve(b,m));
}
