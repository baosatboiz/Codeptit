#include <stdio.h>
#include <string.h>
struct xaulon{
	char xau[100];
};
struct xaulon s[100];
int check(char s[],char testchar[],int n){            //Moi vong lap ta se chon 1 xau testchar la constant, tuc la tu de cac tu khac xoay theo
	int i=0,j,dem=0;
	char scheck[100];                                //tao xau scheck de thay the cho xau s, vi ta dang truyen tham chieu xau s vao ham check
	                                                 //,neu thao tac thay doi truc tiep voi xau s trong ham check se lam thay doi xau s trong ham main
	strcpy(scheck,s);                                
	if(strcmp(scheck,testchar)==0) return 0;
	while(i<n){                                                   //Xoay tu: dua ki tu dau tien ve cuoi, copy doan sau len va so sanh, neu bang nhau return so lan xoay
	    char tmp=scheck[0];
		for(j=0;j<=strlen(scheck)-2;j++) scheck[j]=scheck[j+1];
		scheck[strlen(scheck)-1]=tmp;
		dem++;
		if(strcmp(scheck,testchar)==0) return dem;
		i++;
	}
	return -1;                         //Xoay scheck het n-1 lan: scheck ve giong nhu ban dau ma van khac testchar-> return -1
}
int main(){
	int n; scanf("%d",&n);
	int i,j,k;
	int step[100]={0};                       //tao bien step de luu tong so lan cac xau khac xoay ve xau constant
	for(i=0;i<n;i++) scanf("%s",&s[i].xau);
	for(i=0;i<n;i++)                          //Chon s[i] la xau constant(testchar)
	  for(j=0;j<n;j++){
	    k=check(s[j].xau,s[i].xau,strlen(s[i].xau));    //Xoay cac xau va dem so lan xoay, tong so lan xoay ve xau s[i] duoc luu tai step[i]
	    if(k==-1){printf("-1"); return 0;}
	       else step[i]+=k;
	   }

	int min=step[0];
	for(i=1;i<n;i++) if(min>step[i]) min=step[i];
    printf("%d",min);
}
