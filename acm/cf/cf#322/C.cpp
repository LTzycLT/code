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

int a[100005];
int n, k;
int cmp(int a, int b)
{
    return a % 10 < b % 10;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] != 100 && k >= 10 - a[i] % 10)
        {
            k -= (10 - a[i] % 10);
            a[i] += (10 - a[i] % 10);
        }
        ans += a[i] / 10;
    }
    if(k > 0)
    {
       int l = 0; 
       for(int i = 0; i < n; i++)
           l += 100 - a[i];
       //printf("%d %d\n", k, l);
       ans += min(l, k) / 10;
    }
    printf("%d\n", ans);

    return 0;
}
