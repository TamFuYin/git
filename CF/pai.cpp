#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
#define fi first
#define se second
#define ep emplace
#define MISAKA main
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define _rep(i,a,b) for(int i=a;i>=b;--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define FIO(FILE) freopen(FILE".in","r",stdin),freopen(FILE".ans","w",stdout)
using namespace std;
bool __st;
inline int read(){
	char ch=getchar();int f=1,x=0;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=2e5+10,mod=998244353;
int n,m,a[N],cnt[26],s[N],top,sum;char S[N];
vector<pii> ans;
void misaka(){
	scanf("%s",S+1);n=strlen(S+1);
	memset(cnt,0,sizeof(cnt));ans.clear();top=sum=m=0;
	rep(i,1,n)if(S[i]==S[i-1]) cnt[S[i]-'a']++,sum++;
	rep(i,1,n){
		a[++m]=S[i]-'a';
		if(m==1||a[m]!=a[m-1]) continue;
		if(!top||a[m]==a[s[top]]){s[++top]=m;continue;}
		int mx=max_element(cnt,cnt+26)-cnt;
		if(2*cnt[mx]<sum||a[m]==mx||a[s[top]]==mx){
			sum-=2;cnt[a[s[top]]]--,cnt[a[m]]--;
			ans.eb(s[top],m-1);
			a[s[top]]=a[m];m=s[top--];
		}
		else s[++top]=m;
	}
	int lst=m;
	_rep(i,m,1)if(i==1||a[i]==a[i-1]) ans.eb(i,lst),lst=i-1;
	printf("%u\n",ans.size());
	for(auto [x,y]:ans) printf("%d %d\n",x,y);
}
bool __ed;
signed MISAKA(){
#ifdef LOCAL_MSK
	atexit([](){
		debug("\n%.3lfs  ",(double)clock()/CLOCKS_PER_SEC);
		debug("%.3lfMB\n",abs(&__st-&__ed)/1024./1024);});
#endif
	 FIO("");
	int T=read();
	while(T--) misaka();
	return 0;
}

