#include<bits/stdc++.h>
using ull=unsigned long long;
bool ispow2(ull x){
    return x==(1ull<<std::__lg(x));
}
bool check1(ull m){
    return ispow2(m)&&m%3==1;
}
bool check3(ull m){
    if(check1(m)) return 1;
    for(int t=0;2*t<63;t++){
        ull k=m+(1llu<<2*t);
        if(ispow2(k)) return 1;
    }
    return 0;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;ull m;scanf("%d%llu",&n,&m);
        if(n&1^1) puts("NO");
        else if(n==1) puts(check1(m)?"YES":"NO");
        else if(n==3) puts(check3(m)?"YES":"NO");
        else puts("YES");
    }
}#include<bits/stdc++.h>
using ull=unsigned long long;
bool ispow2(ull x){
    return x==(1ull<<std::__lg(x));
}
bool check1(ull m){
    return ispow2(m)&&m%3==1;
}
bool check3(ull m){
    if(check1(m)) return 1;
    for(int t=0;2*t<63;t++){
        ull k=m+(1llu<<2*t);
        if(ispow2(k)) return 1;
    }
    return 0;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;ull m;scanf("%d%llu",&n,&m);
        if(n&1^1) puts("NO");
        else if(n==1) puts(check1(m)?"YES":"NO");
        else if(n==3) puts(check3(m)?"YES":"NO");
        else puts("YES");
    }
}