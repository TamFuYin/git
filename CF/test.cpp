#include<cstdio>
int main(){
	int a=1e9,ans=0;
	while(ans<31){
		printf("%d ",a=(a+1)/2),++ans;
	}
	printf("\n%d",ans);
}
