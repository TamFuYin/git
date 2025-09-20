#include<bits/stdc++.h>
#define Assert(e,f,...) ({if(!(e)) fprintf(stderr,"Error on line: %d with: " f "\n",__LINE__,##__VA_ARGS__),exit(11514);})
bool a[10000];
char s[10000];
int main(){
	freopen("starmap2.ans","r",stdin);
	for(int i=0;scanf("%s",s)!=EOF;){
		if(s[0]=='Y') a[i++]=1;
		else if(s[0]=='N') a[i++]=0;
	}
	freopen("starmap2.out","r",stdin);
	for(int i=0;scanf("%s",s)!=EOF;){
		if(s[0]=='Y') Assert(a[i]==1,"%d",i),i++;
		else if(s[0]=='N') Assert(a[i]==0,"%d",i),i++;
	}
}
