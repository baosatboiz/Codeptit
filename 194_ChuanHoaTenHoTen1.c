#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	int tc; scanf("%d",&tc);
	getchar();
	while(tc){
		char a[100],b[100]={}; gets(a);         //b là 1 mang ki tu vi vay neu kh gan gia tri rong cho cac phan tu(gia tri null)
                                                //neu kh gan khi in ra man hinh xau b, no se in den gia tri null
												//(va cac gia tri truoc null chua duoc gan gi se co cac gia tri rac), dan den bai toan bi sai		
		int i=0,j=0;
		while(a[i]!='\0'){
			while(a[i]==' ') i++;
			b[j]=toupper(a[i]);  j++; i++;
			while(a[i]!=' '&&a[i]!='\0'){ b[j]=tolower(a[i]); j++; i++; }
			 if(a[i]!='\0'){b[j]=' '; j++;}
			}
        printf("%s\n",b);
	    tc--;
	}
}

