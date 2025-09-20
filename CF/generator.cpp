#include<bits/stdc++.h>
std::mt19937 rnd(time(0));
int main(){
	freopen(".in","w",stdout);
	printf("1\n");
	int n=15;
	char las;
	for(int i=1;i<=n;i++){
		if(i>1&&rnd()%3==0) putchar(las);
		else putchar(las='a'+rnd()%26);
	}
}
