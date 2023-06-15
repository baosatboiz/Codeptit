//Bubble sort: so sanh 2 phan tu ke nhau, dan dan dua phan tu lon nhat ve cuoi mang
#include <stdio.h>
int main(){
	int n; scanf("%d",&n);
	int a[105],i=0,j=1; for(i=0;i<n;i++) scanf("%d",&a[i]);
	int m=n;
	while(n>=1){
	   int test=0;
	   for(i=0;i<n-1;i++) 
	      if(a[i]>a[i+1]){
	      	  test=1;
	   	      int tmp=a[i+1];
	   	      a[i+1]=a[i];
	   	      a[i]=tmp;
			}	
        if(test==0) break;    //Mang da duoc sap xep -> break ra vong lap while
	    printf("Buoc %d: ",j); j++;
        for(i=0;i<m;i++) printf("%d ",a[i]);
        printf("\n");
	    n--;
 	}
 }
 
 
 
 

