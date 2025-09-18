#include<bits/stdc++.h>
#define ckmax(a,b) a=std::max(a,b)
const int N=1e5,M=1e6;
using ll=long long;
const ll HMOD=1e18+7;
const int MOD=1e9+7;
int a[N];
ll pow2[M];
std::unordered_map<ll,int> set;
ll pref[N],suf[N];
std::stack<int> tocl;
int dp[N];
void cdq(int l,int r){
    if(l==r){
        dp[l]+=dp[l-1];
        return;
    }
    static bool b[N];
    int mid=l+r>>1;
    cdq(l,mid);
    suf[mid+1]=pref[mid]=0;
    for(int i=mid;i>=l;i--) suf[i]=(suf[i+1]+pow2[a[i]])%HMOD;
    for(int i=mid+1;i<=r;i++) pref[i]=(pref[i-1]+pow2[a[i]])%HMOD;
    set.clear();
    for(int i=mid+1;i<=r;i++) set[pref[i]]=i;
    for(int i=mid,max=0;i>=l;i--){
        int j=a[i];
        while(b[j]) b[j++]=0;
        b[j]=1;tocl.push(j);
        ckmax(max,j);
        ll rh=(pow2[max+1]-suf[i]+HMOD)%HMOD;
        if(suf[i]==pow2[max]) dp[mid]+=dp[i-1];
        if(set.find(rh)!=set.end()) dp[set[rh]]+=dp[i-1];
    }
    while(!tocl.empty()) b[tocl.top()]=0,tocl.pop();
    set.clear();
    for(int i=l;i<=mid;i++) set[suf[i]]=i;
    for(int i=mid+1,max=0;i<=r;i++){
        int j=a[i];
        while(b[j]) b[j++]=0;
        b[j]=1;tocl.push(j);
        ckmax(max,j);
        ll rh=(pow2[max+1]-pref[i]+HMOD)%HMOD;
        if(pref[i]==pow2[max]) dp[i]+=dp[mid];
        else if(set.find(rh)!=set.end()) dp[i]+=dp[set[rh]-1];
    }
    while(!tocl.empty()) b[tocl.top()]=0,tocl.pop();
    cdq(mid+1,r);
}
int main(){
    freopen(".in","r",stdin);
    int n;scanf("%d",&n);
    pow2[0]=1;for(int i=1;i<M;i++) pow2[i]=pow2[i-1]*2%HMOD;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    dp[0]=1;cdq(1,n);
    printf("%d",dp[n]);
}