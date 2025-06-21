#include<stdio.h>
#include<string.h>

//char to int
int atoi(char s[]){
        int i,n;
        n=0;
        for(i=0;s[i]>='0' && s[i]<='9';++i){
                n=10*n+(s[i]-'0');
        }
        return n;

}
int main(){
        char s[10]="123";
        int n=atoi(s);
        printf("%d\n",n);
        return  0;
}
