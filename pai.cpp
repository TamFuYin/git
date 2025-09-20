#include<bits/stdc++.h>
const int N=1e5;
int a[N],m,t[N];
std::map<std::pair<int,int>,int> pto;
int ls[N],rs[N];
int build(int l,int r){
    int o=++m;
    pto[{l,r}]=o;
    if(l==r){
        t[o]=a[l];
        return o;
    }
    int mid;scanf("%d",&mid);
    ls[o]=build(l,mid);
    rs[o]=build(mid+1,r);
    t[o]=t[ls[o]]&t[rs[o]];
    return o;
}
void modify(int o,int opt,int v){
    if(!ls[o]){
        if(opt==1) t[o]&=v;
        else if(opt==2) t[o]|=v;
        else t[o]^=v;
        return;
    }
    modify(ls[o],opt,v);
    modify(rs[o],opt,v);
    t[o]=t[ls[o]]&t[rs[o]];
}
using ll=long long;
ll solve(int o){
    if(!o) return 0;
    if(__builtin_popcount(t[o])&1) return solve(ls[o])+t[o];
    else return solve(rs[o])+t[o];
}
int main(){
    freopen(".in","r",stdin);
    freopen(".ans","w",stdout);
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    build(1,n);
    while(q--){
        int opt,l,r,x;scanf("%d%d%d",&opt,&l,&r);
        if(opt<=3) scanf("%d",&x),modify(pto[{l,r}],opt,x);
        else printf("%lld\n",solve(pto[{l,r}]));
    }
}