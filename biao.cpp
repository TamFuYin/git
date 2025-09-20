#include<bits/stdc++.h>
const int MOD=1e9+7;
const int N=1e5;
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=1ll*ret*a%MOD;
		a=1ll*a*a%MOD;b>>=1;
	}
	return ret;
}
int fac[N+1],ifac[N+1];
int binom(int n,int k){
	return 1ll*fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}
std::mt19937 rnd(time(0));
int a[4+6];
int cnt[1<<4];
void dfs(int x){
	if(x==4+6){
		if(a[4]+a[5]+a[9]==a[0]+1)
			if(a[4]+a[7]+a[8]==a[1]+1)
				if(a[5]+a[8]+a[6]==a[2]+1)
					if(a[6]+a[7]+a[9]==a[3]+1)
						++cnt[a[0]|a[1]<<1|a[2]<<2|a[3]<<3];
		return;
	}
	a[x]=0;
	dfs(x+1);
	a[x]=1;
	dfs(x+1);
}
int main(){
	int m=5e7;
	for(int i=2;i<=m;i++) printf("%d: %d\n",i,int(log(m)/log(i)));
}
