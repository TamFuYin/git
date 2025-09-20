const int N=1e3+10,T=9;
#include<bits/stdc++.h>
#define ckmin(a,b) a=std::min(a,b)
using ll=long long;
ll f[T][N];
ll binom2(int n){return (ll)n*(n-1)/2;}
int main(){
	for(int t=0;t<T;t++){
		for(int n=1;n<N;n++){
			if(t==0) f[t][n]=binom2(n);
			else{
				f[t][n]=f[t-1][n];
				for(int m=1;m<n;m++)
					ckmin(f[t][n],f[t-1][m]+(n%m)*binom2(n/m+1)+(m-n%m)*binom2(n/m));
			}
		}
	}
	printf("%lld",f[8][1'000]);
}
