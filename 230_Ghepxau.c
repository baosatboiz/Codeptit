#include <stdio.h>
#include <string.h>
struct xau{               //Mot xau la mot tu, dau cuoi la dau cach
	int dau;
	int cuoi;
};
typedef struct xau xau;
int check(char a[],xau c[],int x, int y){
	int i,j=0,k=0;
	char d[11]={},e[11]={};
	char p[22]={},q[22]={};
	for(i=c[x].dau+1;i<c[x].cuoi;i++) {d[j]=a[i]; j++;}             //Copy 2 tu va so sanh thu tu tu dien cua chung(strcmp)
	for(i=c[y].dau+1;i<c[y].cuoi;i++) {e[k]=a[i]; k++;}
    strcat(p,d); strcat(p,e);
	strcat(q,e); strcat(q,d);
	if(strcmp(p,q)>0){xau tmp=c[x]; c[x]=c[y]; c[y]=tmp;}
}
int main(){
    int tc; scanf("%d",&tc);
	while(tc--){
	int m,i,j; scanf("%d",&m);
	char a[105]; gets(a);
	int b[10],n=0; 
	xau c[10];
	for(i=0;i<strlen(a);i++) if(a[i]==' '){b[n]=i; n++;}         //Mang b co tac dung tim cac vi tri dau cach
	b[n]=strlen(a);                                              //ta coi vi tri NULL cung la mot dau cach
	for(i=0;i<n;i++){ c[i].dau=b[i]; c[i].cuoi=b[i+1];}          //Xac dinh moi tu bang cach gan vi tri dau cach cho vi tri dau cuoi tu do
	for(i=0;i<=n-2;i++) 
	   for(j=i+1;j<=n-1;j++) check(a,c,i,j);                    //Thuc hien doi vi tri cac tu
	for(i=0;i<n;i++)
	for(j=c[i].dau+1;j<c[i].cuoi;j++) printf("%c",a[j]);       //in cac tu
	      printf("\n");
}
}










