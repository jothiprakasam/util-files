#include<stdio.h>

#define MAX 10

///definition
int get_line(int lim,char s[]);
int main(){
        char s[100];
        get_line(MAX,s);
        printf("%s",s);
        return 0;
}

int get_line(int lim,char s[]){
        int i,loop=1;
        char c;
        i=0;
        while(loop){
                if(i>=lim-1)
                        loop=0;
                else if((c=getchar())==EOF)
                        loop=0;
                else if(c=='\n'){
                        loop=0;
                }
                else{
                        s[i]=c;
                        ++i;
                }

        }
        //null terminator
        s[i]='\0';
        return i;
}
