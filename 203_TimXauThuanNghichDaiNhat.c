#include<stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct word{                             //Tao 1 struct word gom value,length,frequence(xau,chieu dai xau,tan suat xuat hien cua xau)
	char value[1005];
	int length;
	int frequence;
	};
typedef struct word word;
int n=0;                                 //n la tong so tu thuan nghich trong mang a(cac tu trong mang doi mot khac nhau)
word a[10000];                         
int tn(char x[]){                        //so sanh tu trai qua phai cua xau x, kiem tra co thuan nghich khong
	int l=0, r=strlen(x)-1;
	while(l<r){ if(x[l]!=x[r]) return 0;
	l++; r--;
    }
    return 1;
}
int find(char x[]){                     
	int i;
	for(i=0;i<n;i++) if(strcmp(x,a[i].value)==0) return i; // return i la return lai gia tri minh vua tim thay x trong mang a
	return -1;
	}
int main(){
	char x[10000];
	int p,i;
	while(scanf("%s",x)!=-1){    //nhap den cuoi file
		 if(tn(x)){        //neu x la xau thuan nghich thi co 2 truong hop
		 p=find(x);
		   if(p!=-1){      //Truong hop 1: x da xuat hien truoc do va duoc luu trong mang a, khi do ta chi tang frequence cua x truoc do len 1
		     a[p].frequence++;
             }
		      else{
		      	strcpy(a[n].value,x);      //Truong hop 2: x chua xuat hien, tuc la find(x) trong mang a tra ve gia tri -1, ta gan frequence cua x la 1
				a[n].frequence=1;          //Sau do tang gia tri len(vi co them 1 so thuan nghich moi vao mang), co the noi n la vi tri nhung xau moi tinh
				a[n].length=strlen(x);
                n++;			  
			  }
			 }
	      }
		 int max=-1;
	for(i=0;i<n;i++) if(a[i].length>max){max=a[i].length;}
	for(i=0;i<n;i++) if(a[i].length==max) printf("%s %d\n",a[i].value,a[i].frequence);
}
			
		
	
	
