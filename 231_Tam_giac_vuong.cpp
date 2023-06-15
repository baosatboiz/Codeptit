#include <stdio.h>
#include <math.h>
void swap(long long a[],int i, int j){            //Ham hoan doi vi tri 2 phan tu cua mang a
	long long tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	}
int partition(long long a[],int l,int r){          // Thuat toan sap xep tang dan quicksort 
	int PivotIndex=l;
	int StoreIndex=PivotIndex+1;
	int i;
	for(i=PivotIndex+1;i<=r;i++) 
	if (a[i]<a[PivotIndex]){
	    swap(a,i,StoreIndex);
		StoreIndex++;
	} 
   swap(a,PivotIndex,StoreIndex-1); 
   return StoreIndex-1;     
}
void quicksort(long long a[],int l, int r){
 if(l>=r) return;
 int p=partition(a,l,r);
 quicksort(a,l,p-1);                 
 quicksort(a,p+1,r);                                    
 } 
int binarysearch(long long a[],int x,int N){      //Thuat toan tim kiem nhi phan
    int left=0;
    int right=N-1;
    while(left<=right){
    	int mid=(left+right)/2;
    	if (a[mid]==x) return mid;
    	else if(a[mid]>x) right=mid-1;
    	else left=mid+1;
    	}
   return -1;
}
void xuat(long long a[],int N){                                 //In YES NO ra man hinh  
	int i,j,k;
	for(i=0;i<N-1;i++) 
	    for(j=i+1;j<N;j++){
	        long long testnum= a[i]*a[i]+a[j]*a[j];  
	        k= (int)sqrt(testnum);                                  
			if((long long)k*k==testnum) if(binarysearch(a,k,N)!=-1){ printf("YES\n"); return;}} //neu so dang xet la binh phuong cua so nguyen, ta tim can bac 2 cua so do trong mang a bang binarysearch
		printf("NO\n"); return;	                                                     //Neu tim duoc in Yes roi return. Chay het vong lap khong in yes thì in No roi return
	}	
int main(){
	int tc; scanf("%d",&tc);
	while(tc){
	int N; scanf("%d",&N);
	long long a[N];
	int i,j;
	for(i=0;i<N;i++) scanf("%lld",&a[i]);
	quicksort(a,0,N-1);
	xuat(a,N);
	tc--;
	 }
}

