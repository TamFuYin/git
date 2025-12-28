#include<bits/stdc++.h>
const int N=1e5;
char s[N];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d%s",&n,s);
        int l=0,r=n/2;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid)<check(mid+1))
        }
    }
}