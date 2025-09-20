#include<bits/stdc++.h>
const int N=1e5+10;
int a[N];
int main(){
	freopen("data.in","r",stdin);
	freopen("pai.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++){
		int op,l,r,x;scanf("%d%d%d%d",&op,&l,&r,&x);
		if(op==1){
			for(int i=l;i<=r;i++) if(a[i]>x) a[i]-=x;
		}
		else{
			int ans=0;
			for(int i=l;i<=r;i++) ans+=a[i]==x;
			printf("%d\n",ans);
		}
	}
}
