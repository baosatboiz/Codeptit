#include <stdio.h>
#include <math.h>
int dem=0;
int doben(int N){
	int product=1;
	while(N){
	    product*=N%10;
		N/=10;}
    if(product>=10){
	    dem++; 
	    doben(product);} 
	return dem+1;
}
int main(){
	long long N;
	int k,i,product=1;
	scanf("%lld",&N);
    int max=1;
	if(N<=10) printf("%d",N-1); 
//	else if(N>pow(10,8)){for(i=N-pow(10,7);i<N;i++){{
//    	if(i%10!=0) {int a=doben(i); if (a>=max) {max=a; k=i;} dem=0;}}}} //Neu muon test N=2*10^7-2*10^9 nhanh thi tat comment 2 dong else if nay
//	else if(N>pow(10,7)){for(i=N-pow(10,6);i<N;i++){{
//    	if(i%10!=0) {int a=doben(i); if (a>=max) {max=a; k=i;} dem=0;}}}}
	else{ for(i=10;i<N;i++){
		int a=doben(i); if (a>=max) {max=a; k=i;} dem=0;}}
    if(k!=0) printf("%d",k);}



