#include<stdio.h>

struct item{
    int a,b;
};


int main(){
    struct item a;
    a.a = 1;
    a.b = 2;
    struct item b;
    b = a;
    b.a = 100;
    printf("%d %d\n",a.a,a.b);
    return 0;
}
