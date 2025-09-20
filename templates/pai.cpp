#include<bits/stdc++.h>
#define lowbit(x) (x & (-x))
#define ls(k) k << 1
#define rs(k) k << 1 | 1
#define fi first
#define se second
#define open(s1, s2) freopen(s1, "r", stdin), freopen(s2, "w", stdout);
using namespace std;
typedef __int128 __;
typedef long double lb;
typedef double db;
typedef unsigned long long ull;
typedef long long ll;
bool Begin;
const int N = 16, M = 1 << N, MN = 205, mod = 1e9 + 7; 
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
int n, m, u, v;
int dp[M], g[M], poww[MN], F[M], G[M], cnt[M][N];
vector<int> E[N];
inline void add(int u, int v){
	E[u].push_back(v);
}
inline int calc(int T, int S){
	int sum = F[T] - F[S];
	for(int i = 1; i <= n; ++i)
		if(((S - T) >> (i - 1)) & 1)
			sum += cnt[S][i];
	return sum;
}
bool End;
int main(){
	poww[0] = 1;
	n = read(), m = read();
	for(int i = 1; i <= m; ++i){
		poww[i] = 2ll * poww[i - 1] % mod;
		u = read(), v = read();
		add(u, v);
	}
	for(int S = 1; S < (1 << n); ++ S){
		for(int u = 1; u <= n; ++u){
			if((S >> (u - 1)) & 1){
				for(auto v : E[u]){
					if((S >> (v - 1)) & 1){
						++G[S];
						continue;
					}
					++cnt[S][u];
				}
				F[S] += cnt[S][u];
			}
		}
		for(int T = (S - 1) & S; T; T = (T - 1) & S){
			if(lowbit(S) != lowbit(T))
				continue;
			g[S] = (g[S] - 1ll * dp[T] * g[S - T] % mod + mod) % mod;
		}
		dp[S] = poww[G[S]];
		for(int T = S; T; T = (T - 1) & S)
			dp[S] = (dp[S] - 1ll * g[T] * poww[G[S - T] + calc(T, S)] % mod + mod) % mod;
		g[S] = (g[S] + dp[S]) % mod;
		printf("%d %d %d\n",S,dp[S],g[S]);
	}
	write(dp[(1 << n) - 1]);
	cerr << '\n' << abs(&Begin - &End) / 1048576 << "MB";
	return 0;
}
