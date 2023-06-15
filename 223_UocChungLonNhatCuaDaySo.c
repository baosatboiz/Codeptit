#include <stdio.h>
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int bcnn(int a,int b){
	return a*b/gcd(a,b);
}
int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
	int n; scanf("%d",&n);
	int a[n],i,b[10000],j; for(i=0;i<n;i++) scanf("%d",&a[i]);
	b[0]=a[0];
	i=1;
	while(i<n){
		b[i]=bcnn(a[i-1],a[i]);
		i++;
	}
    b[i]=a[n-1];
    for(j=0;j<=i;j++) printf("%d ",b[j]);
    printf("\n");
}
}
