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

int n;
struct item{
    int d,h;
}a[100];

bool cmp(item a,item b){
    return a.h*b.d<a.d*b.h;
}
int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].d,&a[i].h);
        }
        sort(a,a+n,cmp);
        int ans=0,t=0;
        for(int i=0;i<n;i++){
            t+=a[i].h;
            ans+=t*a[i].d;
        }
        printf("%d\n",ans);

    }
    return 0;
}
