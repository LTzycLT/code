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

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        n/=10;
        printf("Case #%d:\n",++cas);
        printf("*------------*\n");
        for(int i=0;i<10-n;i++){
            printf("|............|\n");
        }
        for(int i=10-n;i<10;i++){
            printf("|------------|\n");
        }
        printf("*------------*\n");
    }
    return 0;
}
