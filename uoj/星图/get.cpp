#include<bits/stdc++.h>
char s[1000];
int main(){
	int t=58;
	freopen("starmap2.in","r",stdin);
	freopen("starmap.in","w",stdout);
	int T,O;scanf("%d%d",&T,&O);
	printf("%d %d\n",1,0);
	for(int i=0;i<T;i++){
		int n;scanf("%d",&n);
		if(i==t) printf("%d\n",n);
		while(--n){
			int u,v;
			scanf("%d%d",&u,&v);
			if(i==t) printf("%d %d\n",u,v);
		}
		scanf("%s",s);
		if(i==t) printf("%s\n",s);
	}
}
