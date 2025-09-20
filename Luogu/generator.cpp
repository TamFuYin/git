#include<bits/stdc++.h>
bool vis[10];
int main(){
	freopen("input","w",stdout);
	std::mt19937 randn(time(0));
	int n=3,m=3,q=randn()%(n*m)+1;
	printf("1\n%d %d %d\n",n,m,q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			putchar('0'+randn()%4);
		}
		puts("");
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			putchar('0'+randn()%4);
		}
		puts("");
	}
	for(int i=1;i<=q;i++){
		int r=randn()%(n*m);
		while(vis[r]) r=randn()%(n*m);
		vis[r]=1;
		printf("%d %d %d %d\n",randn()%2,randn()%q+1,r/m+1,r%m+1);
	}
}
