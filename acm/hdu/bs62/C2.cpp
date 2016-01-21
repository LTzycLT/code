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

long long seed, n, q;
int rand(int l, int r) {
    static long long mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}

int a[10000005];

bool cal(int x)
{
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += (a[i] > x) ? (a[i] - x): 0;
        if(ans > q) return false;
    }
    return true;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%lld%lld", &n, &q, &seed);
        int sum=rand(q, 10000000);
        for(int i=1; i<=n; i++) {
            a[i]=rand(0, sum/(n-i+1));
            sum-=a[i];
        }
        a[rand(1, n)]+=sum;

        int minn = 0, maxx = 0;
        for(int i = 1; i <= n; i++) maxx = max(maxx, a[i]);

        while(maxx - minn > 0)
        {
            int mid = (maxx + minn) >> 1;
            if(cal(mid)) maxx = mid;
            else minn = mid + 1;
        }
        for(int i = 1; i <= n; i++)
        {
            q -= (a[i] > minn) ? (a[i] - minn): 0;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] > minn) a[i] = minn;
            if(a[i] == minn && q > 0) a[i] = minn - 1, q--;

            ans ^= (a[i] + i);
        }
        printf("%d\n", ans);

    }

    return 0;
}
