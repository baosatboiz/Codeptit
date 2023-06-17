#include <stdio.h>
#include <string.h>
struct xau{                //trong 1 xau(s1,s2) co nhieu tu va moi tu duoc luu vao 1 char val
	char val[100];    
	int danhdau;
};
typedef struct xau xau;
int main(){
	int tc; scanf("%d",&tc); getchar();
	while(tc--){
	xau s1[201];       
	xau s2[201];
	int k,h;
	for(k=0;k<201;k++)
	 for(h=0;h<100;h++) {s1[k].val[h]='\0'; s2[k].val[h]='\0';	}
	char y;
	int n1=-1,i; 
	do{
		n1++;
                                   //Nhap cac tu 
		do scanf("%c",&y); 
		while(y==' ');             //y se nhan ki tu ' '
	    if(y=='\n') break;
	      else scanf("%s",s1[n1].val);         //neu if sai tuc la y da nhan ki tu dau tien cua tu moi
	    for(i=strlen(s1[n1].val);i>0;i--) s1[n1].val[i]=s1[n1].val[i-1];
	    s1[n1].val[0]=y;
	}
	while(y!='\n');                 //den khi y='\n' thi break 
	int n2=-1;
	char c;
	do{
	    n2++;
		do scanf("%c",&c); 
		while(c==' ');             //y se nhan ki tu ' '
	    if(c=='\n') break;
	      else scanf("%s",s2[n2].val);
	    for(i=strlen(s2[n2].val);i>0;i--) s2[n2].val[i]=s2[n2].val[i-1];
	    s2[n2].val[0]=c;
	}
	while(c!='\n');
    int j; for(i=0;i<n1;i++) s1[i].danhdau=1;      //ban dau danh dau tat ca cac tu trong s1 la 1
	for(j=0;j<n2;j++) 
	    for(i=0;i<n1;i++) if(strcmp(s1[i].val,s2[j].val)==0)  s1[i].danhdau=0;   //Neu tu trong s1 giong voi tu trong s2 thi danh dau tu trong s1 do bang 0
	for(i=0;i<n1-1;i++)                                           //Duyet tu i=0->i<n1-1 va j=i+1->j<n1 de tim cac tu co danh dau bang 1 va sap xep chung theo thu tu tu dien
	 if(s1[i].danhdau==1){
	  for(j=i+1;j<n1;j++) if(s1[j].danhdau==1)    
        if(strcmp(s1[i].val,s1[j].val)==0) s1[j].danhdau=0;      //Neu tu thoa man do xuat hien 2 lan trong s1 thi danh dau tu xuat hien sau
         else if(strcmp(s1[i].val,s1[j].val)>0){ char tmp[201]; strcpy(tmp,s1[i].val); strcpy(s1[i].val,s1[j].val); strcpy(s1[j].val,tmp);}  //Neu tu thoa man truoc lon hon tu thoa man sau trong s1 theo thu tu tu dien thi swap chung cho nhau
	 printf("%s",s1[i].val);             //Sau moi vong lap cua i in ra tu co thu tu tu dien nho nhat 
	for(j=i+1;j<n1;j++) if(s1[j].danhdau==1) {printf(" "); break;}   //Neu sau do trong s1 van con tu thoa man thi in space
	}
	if(s1[n1-1].danhdau==1) printf("%s",s1[n1-1].val);              //vi vong lap chi chay den i=n1-2 nen co the tu thoa man co thu tu tu dien lon nhat bi swap xuong vi tri cuoi cung
	printf("\n");
 }
}
