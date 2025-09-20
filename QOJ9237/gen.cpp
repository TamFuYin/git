#include<bits/stdc++.h>
std::mt19937 rnd(time(0));
int c[40];
int s0[40];
int main(){
	freopen(".in","w",stdout);
	int s=1024;
	printf("%d\n%d\n",1,s);
	for(int i=1;i<=s;i++) printf("%d ",rnd()%2);
	puts("");
	for(int i=0;i<31;i++) s0[i]=i;
	for(int i=0;i<15;i++){
		int x=rnd()%(31-i);
		for(int j=0;j<31;j++){
			if(!c[j]&&s0[j]==x){
				c[j]=1;
				for(int k=j+1;k<31;k++) s0[k]--;
				break;
			}
		}
	}
	for(int i=0;i<31;i++) printf("%d ",c[i]);
}
