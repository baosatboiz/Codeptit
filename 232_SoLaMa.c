#include <stdio.h>
#include <string.h>
int lama(char s[]){
	int sum=0,i=0;
	while(i<strlen(s)){
	if(i==strlen(s)-2){
	if(s[i]=='I'&&s[i+1]=='V') return sum+=4;
	if(s[i]=='I'&&s[i+1]=='X') return sum+=9;
	if(s[i]=='X'&&s[i+1]=='L') return sum+=40;
	if(s[i]=='X'&&s[i+1]=='C') return sum+=90;
	if(s[i]=='C'&&s[i+1]=='D') return sum+=400;
	if(s[i]=='C'&&s[i+1]=='M') return sum+=900;}
	if(s[i]=='I'){
	    if(s[i+1]!='\0'){
		if(s[i+1]=='V')	{sum+=4; i+=2;}
	     else if(s[i+1]=='X') {sum+=9; i+=2;}
	        else {sum+=1; i++;}
	    }
	    else {sum+=1; i++;}
    }
    if(s[i]=='X'){
	    if(s[i+1]!='\0'){
		if(s[i+1]=='L')	{sum+=40; i+=2;}
	     else if(s[i+1]=='C') {sum+=90; i+=2;}
	        else {sum+=10; i++;}
	    }
	    else {sum+=10; i++;}
    }
	if(s[i]=='C'){
	    if(s[i+1]!='\0'){
		if(s[i+1]=='D')	{sum+=400; i+=2;}
	     else if(s[i+1]=='M') {sum+=900; i+=2;}
	        else {sum+=100; i++;}
	    }
	    else {sum+=100; i++;}
    }	
    if(s[i]=='V') {sum+=5; i++;} 
    if(s[i]=='L') {sum+=50; i++;} 
	if(s[i]=='D') {sum+=500; i++;} 
	if(s[i]=='M') {sum+=1000; i++;} 
}
return sum;
}
struct s{
	char x[100];
};
struct s solama[1000];
int main(){
      int tc; scanf("%d",&tc);
      while(tc--){
	   char s[100];
	   scanf("%s",&s);
	   printf("%d\n",lama(s));

}
}
