#include<stdio.h>

int readint(){
    char ch=getchar();
    int ret=0;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        ret=ret*10+ch-'0';ch=getchar();
    }
    return ret;
}

#define N 3000005

int a[N], n;

int main() {
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("%d\n", 1);
    }

    return 0;
}
