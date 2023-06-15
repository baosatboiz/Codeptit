#include <stdio.h>
#include <string.h>
int check(char x[],char tmp[]){
	if(strlen(x)!=strlen(tmp)) return 0;           //Neu ket qua co chieu dai khac voi so ban dau thi return
	int i,b[100],j=0,k,test=0,p,test2,test3=0;
	for(i=0;i<strlen(tmp);i++) if(tmp[i]==x[0]) {test=1; b[j]=i; j++;}        //Tim vi tri cua chu so dau tien (j),chu y: chu so dau tien trong so dang xet co the xuat hien 2 lan, neu ban chi xet vi tri dau tien tim duoc so giong x[0], co the sai bai toan vd: 0abx0 va x00ab
	                                                                          //Vi vay ta chi can tim dung vi tri so dau tien,sau do so sanh, bai toan coi nhu ket thuc, cac vi tri tim duoc so giong chu so dau tien x[0] ta luu vao mang b
	if(test==0) return 0;    //Neu test=0 tuc kh tim duoc vi tri cua chu so dau tien, duong nhien return ngay
	for(p=0;p<j;p++){ 
	test2=0;   //test2 co tac dung kiem tra so dang xet co cac chu so giong so ban dau va dung theo quy tac vòng hay khong 
	i=b[p]+1;                             //Kiem tra cac chu so tu j+1 den so cuoi cung cua tmp                                                             
	   k=0;
	   if(i<strlen(tmp)) {for(k=1;k<=strlen(tmp)-b[p];k++) if(tmp[i]!=x[k]) { test2=1; break;} 
	   else {i++; if(i>=strlen(tmp)) break;}} //Neu tmp[i]==x[k] ta tang i,k de tiep tuc so sanh  cho den khi i<strlen(tmp)
	   	if(test2==0) {test3=1; break;}    }      //neu trong vong for,so dang xet thoa man, test2=0-> test3=1 de kh bi return                         
	if(test3==0) return 0;             //neu het for test3!=1 tuc la test2 luon bang 1 sau moi vong lap, hay cac so deu khong thoa mãn,return
	i=0;                                 //Kiem tra cac so tu 0-> j-1 cua tmp co giong ban dau khong
	for(k=k+1;k<strlen(tmp);k++) 
	if(tmp[i]!=x[k]) return 0;              //Vi ta da tim duoc vi tri chu so dau tien x[0] trong tmp, vi vay ta khong can test2 hay test3 nua ma chi can kiem tra cac chu so con lai cua tmp
	 else {i++; if(i>=j) break;	}      
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

