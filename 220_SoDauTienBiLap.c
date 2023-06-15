#include <stdio.h>
void swap(long long *a,long long *b){
	long long tmp=*a;
	*a=*b;
	*b=tmp;
}
int patrition(long long a[],int l,int r){
	int pivot=l,storeid=l+1,i;
	for(i=pivot+1;i<=r;i++) 
	  if(a[i]<a[pivot]) {swap(&a[i],&a[storeid]); storeid++;}
    swap(&a[pivot],&a[storeid-1]);
    return storeid-1;
	}
int quicksort(long long a[],int l,int r){
	if(l>=r) return 0;
	int p=patrition(a,l,r);
	quicksort(a,l,p-1);
	quicksort(a,p+1,r);
}
int bs(long long a[],int l,int r,long long x){
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
int main(){
    int tc; scanf("%d",&tc);
	 while(tc--){
	 int n,i; scanf("%d",&n);
     long long a[100002],b[100002];
	 for(i=0;i<n;i++){scanf("%lld",&a[i]); b[i]=a[i];}

	 quicksort(b,0,n-1);
	 int test=0;
	 for(i=0;i<n;i++){
       int vip=bs(b,0,n-1,a[i]);	
 	   if(bs(b,0,vip-1,a[i])!=-1||bs(b,vip+1,n-1,a[i])!=-1) {printf("%lld\n",a[i]); test=1; break;}}
     if(test==0) printf("NO\n"); 
	 }
}

