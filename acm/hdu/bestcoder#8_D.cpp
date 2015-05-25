#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

bool flag[1000005];
int p[500000];
int phi[1000005];
int i,j,n;

void getphi(int n){
    flag[1]=true;
    for(i=2;i<=n;i++){
        if(!flag[i]){
            for(j=2;i*j<=n;j++)
                flag[i*j]=true;
        }
    }
    int k=0;
    for(i=1;i<=n;i++)
        if(!flag[i])
            p[++k]=i;           //ËØÊý±í
    for(i=1;i<=n;i++)
        phi[i]=i;
    for(i=1;i<=k;i++){
        for(j=1;p[i]*j<=n;j++){
            phi[p[i]*j]=phi[p[i]*j]/p[i]*(p[i]-1);
        }
    }
    phi[1]=0;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    getphi(1000000);
    printf("%d\n", phi[4]);
    printf("%d\n", phi[25]);
    return 0;
}
