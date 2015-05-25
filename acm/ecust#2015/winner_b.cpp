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
#define ll unsigned long long
using namespace std;

ll a[100];
int n, c;

bool ok(ll x)
{
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += min(x, a[i]);
    }
    return sum >= x * c;
}
int main() {
    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d", &n, &c);
        ll all = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]); 
            all += a[i];
        }
        ll l = 0, r = all / c;
        while(r > l + 1)
        {
            ll mid = (l + r) / 2;
            if(ok(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if(ok(r))
        {
            printf("%lld\n", r);
        }
        else
        {
            printf("%lld\n", l);
        }
    }
    return 0;
}
