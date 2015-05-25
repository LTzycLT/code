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

int a[4];
char s[1000];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int l=0,r=0;
    for(int i=0;i<4;i++){
        scanf("%s",s);
        a[i]=strlen(s)-2;
        if(a[i]>a[r]) r=i;
        if(a[i]<a[l]) l=i; 
    }
    bool sm=true;
    for(int i=0;i<4;i++){
        if(i==l) continue;
        if(2*a[l]>a[i])
            sm=false;
    }
    bool bg=true;
    for(int i=0;i<4;i++){
        if(i==r) continue;
        if(2*a[i]>a[r])
            bg=false;
    }
    int ans=0;
    if(sm&&bg) ans=2;
    else if(sm) ans=l;
    else if(bg) ans=r;
    else ans=2;
    printf("%c\n",ans+'A');
    return 0;
}
