#include<bits/stdc++.h>
std::mt19937 rnd(time(0));
const int N=1e5;
int main(){
	freopen("data.in","w",stdout);
	int n=1e5,m=100;printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) printf("%d ",rnd()%N+1);puts("");
	for(int i=1;i<=m;i++){
		int l=rnd()%n+1,r=rnd()%(n-l+1)+l;
		printf("%d %d %d %d\n",rnd()%2+1,l,r,rnd()%N+1);
	}
}
