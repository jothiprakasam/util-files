/*
 * Author      : Jothi Prakasam R
 * Date        : 2025-06-22
 * Description : Implementation of linear memory allocator using character array.
 */

#include<stdio.h>
#include<string.h>

#define ALLOCSIZE 100

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; // or &allocbuf[0]

// memory allocator.
char *alloc(int n){
        if(allocbuf + ALLOCSIZE - allocp >= n){
                allocp+=n;       //allocate the chunk of memory 
                return allocp-n; //return the starting location of the allocated chunk  
        }else{
                return 0; //not have enough space and 0 is not a valid address
        }
}

// free the memory for reuse
void afree(char *p){
        if(p>=allocbuf && p<allocbuf + ALLOCSIZE) 
                allocp=p;  // pointing to the begining of the chunk ,making free
}

int main(void){
        //use it
        char *p=alloc(10);
        strcpy(p,"Hi There");
        printf(" %s\n",p);
        afree(p);
        // NOTE : Even You can print the value after the free operation 
        // So , When other alloc operation can overrite the values . 
        return 0;
}
