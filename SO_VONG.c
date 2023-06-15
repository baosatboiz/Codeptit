#include <stdio.h>
#include <string.h>
int check(char x[],char tmp[]){
	if(strlen(x)!=strlen(tmp)) return 0;           //Neu ket qua co chieu dai khac voi so ban dau thi return
	int i,j,k;
	for(i=0;i<strlen(tmp);i++) if(tmp[i]==x[0]) { j=i; break;}        //Tim vi tri cua chu so dau tien
	i=j+1;                                                                              
	   if(i<strlen(tmp)) {for(k=1;k<=strlen(tmp)-j;k++) if(tmp[i]!=x[k]) return 0; //Kiem tra cac chu so sau co giong ban dau khong 
	   else {i++; if(i>=strlen(tmp)) break;}}
	i=0;
	for(k=k+1;k<strlen(tmp);k++) 
	if(tmp[i]!=x[k]) return 0; else {i++; if(i>=j) break;	}
	return 1;
}
int nhan(char x[],int i){            //thuc hien nhan so nguyen lon 
	char tmp[100]={}; 
	int j,p=0,nho=0;
	for(j=strlen(x)-1;j>=0;j--){
	int k=(x[j]-'0')*i;
	tmp[p]=(k%10+nho)%10+48; 
	nho=k/10+(k%10+nho)/10; 
	p++;
	}
	char tmp2[100]={};             //bien tmp luu ket qua bi nguoc nen ta tao bien tmp2 de lat nguoc ket qua tmp lai
	j=0;
	for(i=strlen(tmp)-1;i>=0;i--)  
	{tmp2[j]=tmp[i]; 
	j++;}
	   if(check(x,tmp2)==0) return 0;
     return 1;
}
int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
	char x[100]; scanf("%s",&x);
	int i,test=0;
    for(i=1;i<=strlen(x);i++) if(nhan(x,i)==0) {printf("NO\n"); test=1; break;}
    if(test==0) printf("YES\n");
}
}

