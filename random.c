#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void){
    int i;
    srand((unsigned int)time(NULL));
    for(i=0;i<81;i++){
        printf("%d\n",rand()%5);
    }    
	return 0;
}