//Co dinh vi tri cua i, chay den cuoi mang(de tìm min), thay the so do cho a[i], roi tang i len tiep tuc duyet den phan tu gan cuoi cung(n-2)
#include <stdio.h>
int main(){
	int n; scanf("%d",&n);
	int a[105],i=0,j;
	for(j=0;j<n;j++) scanf("%d",&a[j]);
	while(i<n-1){
		for(j=i+1;j<=n-1;j++) if(a[j]<a[i]){ int tmp=a[i]; a[i]=a[j];  a[j]=tmp;	}
		printf("Buoc %d: ",i+1);
		for(j=0;j<n;j++) printf("%d ",a[j]);
		printf("\n");
		i++;
	}
}
