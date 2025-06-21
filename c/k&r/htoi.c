#include<stdio.h>
#include<string.h>

//char to hex
int htoi(char s[]){
        int n=0;
        int digit=0;
        int i;
        if(s[0]='0' && (s[1]=='x' || s[1]=='X'))
                i=2;
        for(;s[i]!='\0';++i){
                if(s[i]>='0' && s[i]<='9')
                        digit=(s[i]-'0');
                else if(s[i]>='A' && s[i]<='F')
                        digit=10+(s[i]-'A');
                else if(s[i]>='a' && s[i]<='f')
                        digit=10+(s[i]-'a');
                else
                        break;
                n=n*16+digit; //hex -> 16
        }

        return n;
}

int main(){
        char s[]="0x122fe";
        int n;
        n=htoi(s);
        printf(" %d\n", n);

        return 0;

}
