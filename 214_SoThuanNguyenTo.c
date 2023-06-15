#include <stdio.h>
#include <math.h>
int checknt1(int a){
	int i;
	if(a==2|| a==3) return 1;                                        //Ta kiem tra so do co phai 0,1 ;so do co chia het cho 2,3 khong truoc de giam so lan vao vong lap 
	if(a<2||a%2==0||a%3==0) return 0;                               //Ta chi can kiem tra xem so do co chia het cho cac so nguyen to hay khong
	for(i=5;i<=sqrt(a);i+=6) if (a%i==0 || a%(i+2)==0) return 0;   //So nguyen to co dang 6k-1 hoac 6k+1, o day ta duyet tu i=5 (dang 6k-1) nen trong 
	return 1;                                                    //vong lap phai kiem tra i+2 ( tuc la dang 6k+1), vi vay trong 1 vong lap ta da duyet duoc het so nguyen to
}
int checknt2(int a){                                            //Kiem tra tong va tung so co phai so nguyen to khong
	int sum=0,tmp=a;
	while(a){
	   if(checknt1(a%10)==0) return 0;
	   sum+=a%10;
	   a/=10;	
	}
	if(checknt1(sum)==0) return 0;
	return 1;
}
int main(){
	int tc,a,b,i;
	scanf("%d",&tc);
	while(tc){
		int dem=0;
		scanf("%d %d",&a,&b);
		for(i=a;i<=b;i++) if(checknt1(i)&&checknt2(i)) dem++;
	    printf("%d\n",dem);
	    tc--;
	}
}
