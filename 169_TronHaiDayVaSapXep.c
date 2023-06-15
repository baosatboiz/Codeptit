#include <stdio.h>
void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void tangdan(int a[],int n){
	int i,j;
	for(i=0;i<n;i++){
 	for(j=i+1;j<n;j++)
	 if(a[i]>a[j]) swap(&a[i],&a[j]);
 }
}
void giamdan(int a[],int n){
	int i,j;
	for(i=0;i<n;i++){
 	for(j=i+1;j<n;j++)
	 if(a[i]<a[j]) swap(&a[i],&a[j]);
 }
}
 
int main(){
 int n,i,j,tc,demtc=1; 
 scanf("%d",&tc);
 while(tc){
 scanf("%d",&n);
 int a[n],b[n],tron[2*n],dem1=0,dem2=0;
 for(i=0;i<n;i++) scanf("%d",&a[i]); tangdan(a,n);
 for(i=0;i<n;i++) scanf("%d",&b[i]); giamdan(b,n);
 for(i=0;i<2*n;i++) 
    if(i%2==0)
	   { tron[i]=a[dem1];
	   dem1++;
       }
    else
       { tron[i]=b[dem2];
       dem2++;
	   }
 printf("Test %d:\n",demtc);
 for(i=0;i<2*n;i++) printf("%d ",tron[i]);
 printf("\n");
 tc--; demtc++; 
  } 
}

	
