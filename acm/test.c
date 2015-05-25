#include <stdlib.h>


void fun(int *a)
{
    if(a == 0)
        puts("3");
    else
        puts("4");
}
int main(int argc, char* argv[])
{
    fun(NULL);
    return 0;
}
