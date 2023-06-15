#include <stdio.h>
int swap(int *a, int* b){
          int temp=*a;
		  *a=*b;
		  *b=temp;
}
int checkswap(int *a,int *b){
          if(*a<*b) {swap(a,b); return 1;};
		  if(*a==*b) return 2;
		  return 0;	
	}
int main(){
	int a1,a2,b1,b2,c1,c2;
	scanf("%d %d\n%d %d\n%d %d",&a1,&a2,&b1,&b2,&c1,&c2);
	checkswap(&a1,&a2);    //sap xep lai tung dong theo thu tu:  chieu dai - chieu rong
	checkswap(&b1,&b2);
	checkswap(&c1,&c2);
	if(checkswap(&a1,&b1)==1)  swap(&a2,&b2); 	   if(checkswap(&a1,&c1)==1) swap(&a2,&c2);       if(checkswap(&b1,&c1)==1) swap(&b2,&c2);    //Chuyen dong co chieu dai lon hon len tren
    if(checkswap(&a1,&b1)==2) checkswap(&a2,&b2);  if(checkswap(&a1,&c1)==2) checkswap(&a2,&c2);  if(checkswap(&b1,&c1)==2)  checkswap(&b2,&c2); //Neu 2 dong co cung chieu dai, chuyen dong co chieu rong lon hon len tren
	// Cac bien a1,a2,...,c2 duoc sap xep theo thu tu uu tien: Chieu dai, chieu rong
	int a=a1-a2,sum=0;  //a1 la canh lon nhat, a la canh ma 2 hinh chu nhat con lai phai co, neu 1 trong 2 hcn khong co xuat NO
	if((b1==a||b2==a)&&(c1==a||c2==a)){    //sum la ham tinh tong 2 canh cuoi cung chua xet, sum phai =a neu khong xuat NO
	if (b1==a) sum+=b2; else if(b2==a) sum+=b1;
    if(c1==a) sum+=c2; else if(c2==a) sum+=c1;
	if (sum==a1) printf("YES\n"); else printf("NO\n");
 } else printf("NO\n");
}



