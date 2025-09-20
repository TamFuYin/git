#include<bits/stdc++.h>
#include<windows.h>
int main(){
	int x,y;
	while(1){
		system("generator.exe");
		system("pai.exe");
		system("1329D.exe");
		auto hd=freopen(".ans","r",stdin);
		scanf("%d",&x);
		fclose(hd);
		hd=freopen(".out","r",stdin);
		scanf("%d",&y);
		fclose(hd);
		if(x!=y) puts("Failed"),exit(-1);
		else puts("Success!");
	}
}
