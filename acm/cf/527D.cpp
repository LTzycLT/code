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
    ll x, w;
}a[200005];
int n;
ll dp[200005];

int cmp(const item &a, const item &b)
{
    return a.x < b.x;
}
int solve(int p)
{
   int l = 0, r = p; 
   while(r - l > 1)
   {
       int mid = (l + r) >> 1;
       int q = dp[mid];
       if(q != -1 && a[q].x + a[q].w <= a[p].x - a[p].w)
       {
           l = mid;
       }
       else
       {
           r = mid;
       }
   }
   int q = dp[r];
   if(q != -1 && a[q].x + a[q].w <= a[p].x - a[p].w)
   {
        return r;
   }
   else
   {
        return l;
   }
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i].x, &a[i].w);
    }
    memset(dp, -1, sizeof(dp));
    sort(a, a + n, cmp);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 1; i < n; i++)
    {
        int p = solve(i) + 1;
        int q = dp[p];
        if(q == -1 || a[q].x + a[q].w > a[i].x + a[i].w)
        {
            dp[p] = i;
        }
    }
    for(int i = n; i >= 1; i--)
    {
        if(dp[i] != -1)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
