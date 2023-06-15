//Bai toan nay ta thuc hien nhu tru lop 1, vi so nguyen rat lon, ta phai chon kieu xau, va thuc hien tru tung cot mot
#include <stdio.h>
#include <string.h>
char hieu[1005];
int check(char c){                          //Ham nay kiem tra xem ki tu ma ta dang xet la so may
	   int tmp;
	   switch(c){ 
	   	case '0': return tmp=0;     
		case '1': return tmp=1;
	   	case '2': return tmp=2;
	   	case '3': return tmp=3;
	   	case '4': return tmp=4;
	   	case '5': return tmp=5;
	   	case '6': return tmp=6;
	   	case '7': return tmp=7;
	   	case '8': return tmp=8;
	   	case '9': return tmp=9;
	   }
	}
int sosanh(char a[],char b[]){             //Ham so sanh 2 so a va b, xem so nao lon hon
	int i=0;
	if(strlen(a)>strlen(b)) return 1;
	else if(strlen(a)==strlen(b)){
	      while(i<=strlen(a)-1){if(a[i]>b[i]) return 1; i++;}
	      i=0;
		  while(i<=strlen(a)-1){if(b[i]>a[i]) return 0; i++;}
	  return 2;}
	  return 0;
}
void tru(char a[],char b[]){                        //Ham tru(tung cot), ta nhap vao 2 so a,b(a>b), thuc hien a-b,cot cua so bi tru(i) di toi dau thi cot cua hieu(k) di toi do
	int i=strlen(a)-1,j=strlen(b)-1,c,d,e,k=0,nho=0;
	while(j>=0){      //Tru den cot lon nhat cua so tru
		d=check(a[i]); e=check(b[j]);
		e+=nho;       //Nho 1 cong vao so tru
		nho=0;
		if(d<e){c=10+d-e; nho=1;}    //Neu chu so cua so bi tru nho hon chu so cua so tru, thi ta muon them 10 don vi va nho 1
		    else c=d-e;              //Nguoc lai ta tru luon ma khong can nho
		hieu[k]=48+c;                //(char)48(ASCII)=(number)0(he 10), 48+c tuc la gan hieu[k] cho so tu 0->0+c hay tu 0->9, ung voi tung c
        k++; i--; j--;               //Sau khi gan, tang k len 1 ô
		}
    if(nho)                          //Khi da tru xong cot lon nhat cua so tru, ta kiem tra xem con nho hay khong,neu con, ta lay cot tiep theo cua so bi tru tru 1
    {                            
    while(check(a[i])<nho&&i>=0){hieu[k]='9'; i--; k++;} //Neu so o cot tiep theo cua so bi tru la 0, thi gan hieu o vi tri tuong ung la 9 ,nho 1
	hieu[k]=check(a[i])-1+48;}                           //va lap lai cho den khi so o cot tiep theo lon hon hoac bang 1,neu no >=1 roi ta chi lay so do -1(khi do se het nho)
    if(i==0) return;                                     //Neu i=0,luc nay ta da duyet het so bi tru, so tru, tra het nho nen ta se thoat khoi ham, noi cach khac, ta da tra nho vao phan tu a[0] cua so bi tru nen het nho, thoat khoi ham
	for(i;i>=0;i--) {hieu[k]=check(a[i])+48;k++;}      // Neu i khac 0, nghia la tai vi tri i da tra het nho(tuong ung voi vi tri k cua hieu), ta copy phan con lai cua so bi tru vao hieu
}
int main(){
	int tc; scanf("%d",&tc);
	while(tc){
	char a[1005],b[1005],i; scanf("%s %s",a,b);
    int p=sosanh(a,b);
	if(p==1){tru(a,b); i=strlen(hieu)-1; while(hieu[i]=='0') i--; for(i;i>=0;i--) printf("%c",hieu[i]);}  //In nguoc lai xau hieu de in ket qua ra man hinh, dong thoi bo nhung so 0 phia truoc hieu
	else if(p==0){tru(b,a);  i=strlen(hieu)-1; while(hieu[i]=='0') i--; for(i;i>=0;i--) printf("%c",hieu[i]);}
	else printf("0");
	printf("\n");
	tc--;
	}
}
    
