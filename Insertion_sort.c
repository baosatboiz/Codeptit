//Thuat toan Insertion sort sap xep tang dan mang a[n]: duyet tung so trong mang(vi tri i),duyet tu i ve phan tu dau tien khi gap so nho hon no(tai vi tri k) thi dung
//                                          : chen so do vao vi tri k, thuc hien cau lenh copy cac phan tu tu k->i-1 paste vao k+1->i(sua mang) 
#include <stdio.h>
int main(){
     int n; scanf("%d",&n);
     int a[1000],i,j,x,test,tmp=0;
     for(i=0;i<n;i++) scanf("%d",&a[i]);
     for(i=0;i<n;i++){
     	printf("Buoc %d: ",i);
     	    j=i-1;
			while(a[i]<=a[j]&&j>=0) j--;
		    tmp=a[i];
			for(x=i;x>=j+1;x--) a[x]=a[x-1]; //thuc hien chen gia tri vao
			a[j+1]=tmp;
		for(j=0;j<=i;j++ )printf("%d  ",a[j]);
		printf("\n");
		} 
     		
		 
}
