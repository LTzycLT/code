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

struct item
{
    int a, b;
}a[10000];
int n;

bool cmp(item a, item b)
{
    if(a.a == b.a)
        return a.b < b.b;
    else
        return a.a < b.a;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &a[i].a, &a[i].b);
    sort(a, a + n, cmp);
    int maxx = 0;
    for(int i = 0; i < n; i++)
        if(a[i].b >= maxx)
            maxx = a[i].b;
        else
            maxx = a[i].a;
    printf("%d\n", maxx);
    return 0;
}
