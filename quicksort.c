#include <stdio.h>
void swap(int a[],int i, int j){
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	}
int partition(int a[],int l,int r){            
	int pivotid=l;
	int storeid=pivotid+1;
	int i;
	for(i=pivotid+1;i<=r;i++) 
	if (a[i]<a[pivotid]){
	    swap(a,i,storeid);
		storeid++;
	} 
   swap(a,pivotid,storeid-1); // dua pivot ve dung vi tri duoc sap xep cua no(trai pivot nho hon pivot, phai pivot lon hon pivot)
   return storeid-1;     // return ve vi tri pivot
}
void quicksort(int a[],int l, int r){
 if(l>=r) return;
 int p=partition(a,l,r);
 quicksort(a,l,p-1);                 // dua day so ve thu tu trai nho hon pivot, pivot,phai lon hon pivot roi tiep tuc quicksort ben trai pivot, quicksort ben phai pivot
 quicksort(a,p+1,r);                                    // (de quy den khi day so con 1 so)
 } 
int main(){
	int N; scanf("%d",&N);
	int a[N],i;
	for(i=0;i<N;i++) scanf("%d",&a[i]);
	quicksort(a,0,N-1);
	for(i=0;i<N;i++) printf("%d ",a[i]);
}

