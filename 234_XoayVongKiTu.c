#include <stdio.h>
#include <string.h>
struct xaulon{
	char xau[100];
};
struct xaulon s[100];
int check(char s[],char testchar[],int n){
	int i=0,j,dem=0;
	char scheck[100];
	strcpy(scheck,s);
	if(strcmp(scheck,testchar)==0) return 0;
	while(i<n){
		char tmp=scheck[0];
		for(j=0;j<=strlen(scheck)-2;j++) scheck[j]=scheck[j+1];
		scheck[strlen(scheck)-1]=tmp;
		dem++;
		if(strcmp(scheck,testchar)==0) return dem;
		i++;
	}
	return -1;
}
int main(){
	int n; scanf("%d",&n);
	int i,j,k;
	int step[100]={0};
	for(i=0;i<n;i++) scanf("%s",&s[i].xau);
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++){
	    k=check(s[j].xau,s[i].xau,strlen(s[i].xau));
	    if(k==-1){printf("-1"); return 0;}
	       else step[i]+=k;
	   }

	int min=step[0];
	for(i=1;i<n;i++) if(min>step[i]) min=step[i];
    printf("%d",min);
}
