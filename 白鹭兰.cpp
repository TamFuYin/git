/*
先缩点建圆方树，然后对每个点双双极定向。
然后跑一个树形 DP （
*/
#include<bits/stdc++.h>
#define ckmin(a,b) a=std::min(a,b)
#define ckmax(a,b) a=std::max(a,b)
#define Assert(A) if(!(A)) fprintf(stderr,"Error Line=%d with "#A,__LINE__),exit(1)
#define ALL(x) x.begin(),x.end()
#define insert_sort(a,x) a.insert(std::lower_bound(ALL(a),x),x)
#define mp std::make_pair
using vi=std::vector<int>;
const int N=1e5;
vi G[N],T[N];
void add(vi *to,int u,int v){
	to[u].push_back(v);
	to[v].push_back(u);
}
int dfn[N],low[N];
int sta[N],top;
int cnt;
void tarjan(int u){
	low[u]=dfn[u]=++dfn[0];
	sta[++top]=u;
	for(int v:G[u]){
		if(dfn[v]){
			ckmin(low[u],dfn[v]);
			continue;
		}
		tarjan(v);
		ckmin(low[u],low[v]);
		if(low[v]>=dfn[u]){
			add(T,u,++cnt);
			do add(T,sta[top],cnt);
			while(sta[top--]!=v);
		}
	}
}
int n,f[N];
int siz[N];
int rt;
void makesiz(int u,int fa=0){
	siz[u]=u<=n;
	for(int v:T[u]){
		if(v==fa) continue;
		makesiz(v,u);
		siz[u]+=siz[v];
	}
}
int rtc;
void getrt(){
	for(int u=n+1;u<=cnt;u++){
		int mxs=0;
		for(int v:T[u]){
			if(siz[v]>siz[u]) ckmax(mxs,n-siz[u]);
			else ckmax(mxs,siz[v]);
		}
		if(mxs<=n/2) rt=u,++rtc;
	}
	Assert(rtc<=2);
}
std::vector<vi> ans;
void dfs(vi& vec,int u,int fa=0){
	if(u<=n) vec.push_back(u);
	for(int v:T[u]){
		if(v==fa) continue;
		dfs(vec,v,u);
	}
}
auto grs=[](const int& a,const int& b){
	return siz[a]>siz[b];
};
vi nx,subt[N],tmp[2],chain;
int fr[N],to[N];
void rec(int u,int fa,bool type){
	nx.clear();
	for(int v:T[u]){
		if(v==fa) continue;
		nx.push_back(v);
	}
	std::sort(nx.begin(),nx.end(),grs);
	if(u>n){
		(type?fr[u]:to[u])=fa;
		(type?to[u]:fr[u])=nx[0];
		tmp[type].push_back(u);
		for(int i=1;i<nx.size();i++) dfs(subt[nx[i]],nx[i],u);
	}
	if(!nx.empty()) rec(nx[0],u,type);
}
void bipolar(vi& V,vi *E,int s,int t){
}
int main(){
	int m;scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),add(G,u,v);
	cnt=n;
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	makesiz(1);
	getrt();
	makesiz(rt);
//	for(int u=1;u<=cnt;u++)
//		for(int v:T[u])
//			printf("%d %d\n",u,v);
	printf("%d\n",rt);
	for(int v:T[rt]) nx.push_back(v);
	std::sort(nx.begin(),nx.end(),grs);
	printf("nx[rt]: ");
	for(int i=0;i<nx.size();i++) printf("%d ",nx[i]);
	puts("");
	for(int i=2;i<nx.size();i++) dfs(subt[nx[i]],nx[i],rt);
	rec(fr[rt]=nx[0],rt,0),rec(to[rt]=nx[1],rt,1);
	std::reverse(ALL(tmp[0]));
	chain.insert(chain.end(),ALL(tmp[0])),
	chain.insert(chain.end(),ALL(tmp[1]));
	for(int u:chain) bipolar(T[u],G,fr[u],to[u]);
	int k=0;
	for(auto i:ans) ckmax(k,(int)i.size());
	printf("%d %d\n",k,(int)ans.size());
	for(auto i:ans){
		printf("%d ",(int)i.size());
		for(auto j:i)
			printf("%d ",j);
		puts("");
	}
}
