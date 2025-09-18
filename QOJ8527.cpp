#include<bits/stdc++.h>
#define ckmax(a,b) a=std::max(a,b)
const int N=1e5,M=1e6;
using ll=long long;
const ll MOD=1e18+7;
int a[N];
std::unordered_map<int,int> f[N];
ll pow2[M];
std::unordered_map<ll,int> rset;
void cdq(int l,int r){
    if(l==r){
        f[l][a[l]]=l+1;
        return;
    }
    static bool b[N];
    int mid=l+r>>1;
    cdq(l,mid),cdq(mid+1,r);
    ll hash=0;
    for(int i=mid+1;i<=r;i++){
        rset[hash]=i;
        hash=(hash+pow2[a[i]])%MOD;
    }
    rset[hash]=r+1;hash=0;
    int max=0;
    for(int i=mid;i>=l;i--){
        int j=a[i];
        while(b[j]){
            hash=(hash+MOD-pow2[j])%MOD;
            b[j]=0;
        }
        b[j]=1;
        hash=(hash+pow2[j])%MOD;
        ckmax(max,j);j=max+1;
        ll rh=(pow2[j]-hash+MOD)%MOD;
        if(rset.find(rh)!=rset.end()){
            int k=f[i][j]=rset[rh];
            while(f[k].find(j)!=f[k].end()) f[i][++j]=k=f[k][j];
        }
    }
    for(int i=l;i<=mid;i++) b[a[i]]=0;
}
int main(){
    int n;scanf("%d",&n);
    pow2[0]=1;for(int i=1;i<M;i++) pow2[i]=pow2[i-1]*2%MOD;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    cdq(1,n);
}