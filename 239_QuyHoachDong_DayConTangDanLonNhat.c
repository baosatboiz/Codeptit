#include <stdio.h>
#include <string.h>
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int main(){
	char s[51]; scanf("%s",&s);
	int L[51],i,j; for(i=0;i<strlen(s);i++) L[i]=1; //L[i] co tac dung luu so luong phan tu cua day tang dai nhat tinh tu dau den vi tri i
	                                                //ban dau moi phan tu deu la mot day con nen ta cho L[i]=1
	for(i=1;i<strlen(s);i++) 
	   for(j=0;j<i;j++)
	     if(s[i]>s[j]) L[i]=max(L[i],L[j]+1);      //Neu s[i]>s[j] ta se kiem tra do lon cua L[i] va L[j]+1
	                                          //Neu L[i]>L[j]+1 tuc la day con tang dan dai nhat truoc do co so phan tu lon hon day con tang dan dang xet hien tai
		                  //Nguoc lai neu L[j]+1>l[i] tuc la day con tang dan hien tai co so phan tu lon hon day con tang dan dai nhat truoc do,L[j]+1 tuc la them phan tu i vao day con dang xet 
                       //Ta uu tien day con tang dan co so phan tu lon nhat, vi vay ta chon day lon hon trong 2 day(max)
                       //Cu tiep tuc nhu vay, so lon duoc noi duoi vao so nho, va do dai cua day con tang dan duoc the hien tai L[i] cua so lon
   int maxnum=L[0];
   for(i=1;i<strlen(s);i++) if(L[i]>maxnum) maxnum=L[i];   //Tim max L[i], day chinh la day con tang dan co do dai lon nhat->26-maxnum se ra so phan tu can chen vi tri
   printf("%d",26-maxnum);
}
