#include<cstdio>
#define TY int
#define MAXN 200002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
#define EDG(i,u) for(TY i=hed[u];i;i=nxt[i])
using namespace std;
typedef long long ll;
const TY M=998244353;
typedef unsigned long long ull;
TY _abs(TY a){return a<0?-a:a;}
TY maxn(TY a,TY b){return a>b?a:b;}
TY minn(TY a,TY b){return a<b?a:b;}
inline void updmx(TY &x,TY y){if(x<y)x=y;}
inline void updmn(TY &x,TY y){if(x>y)x=y;}
inline void add(TY &x,TY y){if((x+=y)>=M)x-=M;}
TY gcd(TY a,TY b){return b?gcd(b,a%b):a;}
TY qp(TY a,TY b){TY ans=1;do{if(1&b)ans=ans*a%M;a=a*a%M;}while(b>>=1);return ans;}
char getc(){char ch=getchar();while(ch==' '||ch=='\n'||ch=='\r')ch=getchar();return ch;}
TY qr(){
	char ch=getchar();TY s=0,x=1;
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(TY a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){a=-a;putchar('-');}
	if(a>9)qw(a/10);putchar(a%10+'0');if(ch)putchar(ch);
}TY T,n,u,v,hed[MAXN],nxt[MAXN<<1],to[MAXN<<1],sz[MAXN];
TY mx[MAXN],mn,p,q,a[MAXN],b[MAXN];char s[MAXN];bool fl;
void addedge(TY id){nxt[id]=hed[u];to[hed[u]=id]=v;}
void dfs(TY u,TY fa){
	sz[u]=1;mx[u]=0;EDG(i,u)if(to[i]!=fa){
		dfs(to[i],u);sz[u]+=sz[to[i]];
		updmx(mx[u],sz[to[i]]);
	}updmx(mx[u],n-sz[u]);
}void dfs1(TY u,TY fa){
	a[++p]=u;EDG(i,u)if(to[i]!=fa)dfs1(to[i],u);
}void dfs2(TY u,TY fa){EDG(i,u)if(to[i]!=fa)dfs2(b[++q]=to[i],u);}
int main(){
	freopen("starmap.in","r",stdin);
	T=qr();qr();while(T--){
		n=qr();FOR(i,1,n)hed[i]=0;
		fOR(i,1,n){
			u=qr();v=qr();addedge(i<<1);
			u^=v^=u^=v;addedge(i<<1|1);
		}scanf("%s",s+1);fl=false;
		for(TY i=1;i<=n;i+=2)if(s[i]=='0')fl=true;
		if(fl||s[2]=='1'){printf("NO\n");continue;}
		if(n==1){printf("YES\n1\n");continue;}
		if(n==2){printf("YES\n1 2\n");continue;}
		dfs(1,0);mn=n+1;
		FOR(i,1,n)if(nxt[nxt[hed[i]]])
			if(mn>mx[i]){mn=mx[i];u=i;}
		if(mn>n){
			for(TY i=4;i<=n;i+=2)if(s[i]=='1')fl=true;if(fl)printf("NO\n");
			else{printf("YES\n");FOR(i,1,n)qw(i,' ');putchar('\n');}continue;
		}FOR(i,n-mn,n>>1)if(s[i<<1]=='1')fl=true;
		FOR(i,mn+1,n>>1)if(s[i<<1]=='0')fl=true;
		if(fl){printf("NO\n");continue;}
		printf("YES\n");p=q=0;EDG(i,u){
			if(sz[to[i]]==mx[u])v=to[i];
			if(sz[to[i]]>sz[u]&&n-sz[u]==mx[u])v=to[i];
		}dfs1(v,u);EDG(i,u)if(to[i]!=v)dfs2(to[i],u);
		EDG(i,u)if(to[i]!=v)b[++q]=to[i];
		qw(u,' ');qw(a[p--],' ');fl=true;
		for(TY i=4;i<=n&&p&&q;i+=2){
			if((s[i]=='0')==fl){
				qw(a[p--],' ');qw(b[q--],' ');
			}else if(fl^=1){
				if(p<2)break;
				qw(a[p--],' ');qw(a[p--],' ');
			}else{
				if(q<2)break;
				qw(b[q--],' ');qw(b[q--],' ');
			}
		}FOR(i,1,p)qw(a[i],' ');
		FOR(i,1,q)qw(b[i],' ');putchar('\n');
	}return 0;
}
