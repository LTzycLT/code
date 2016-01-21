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

int a[100005], b[100005];
int n;

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int maxx = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        b[i] = max(0, maxx + 1 - a[i]);
        maxx = max(maxx, a[i]);
    }
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
    puts("");
    return 0;
}
