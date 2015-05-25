#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand1(int x){
	return 1+rand()%x;
}
int rand0(int x){
	return rand()%(x+1);
}
int main(){
    srand(time(NULL));
    printf("1\n");
    int n = 4;
    puts("4");
    for(int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", rand1(10), rand1(5), rand1(20));
    }    
    return 0;
}

