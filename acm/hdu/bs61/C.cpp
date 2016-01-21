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

const ll mod = 1e9 + 7;
int n;
ll a[100005], b[100005], l[100005], r[100005];
bool p[100005];
int q[100005];

ll power(ll a, ll idx)
{
    ll ans = 1;
    while(idx)
    {
        if(idx & 1) ans *= a;
        a *= a;
        idx >>= 1;

        a %= mod;
        ans %= mod;
    }
    return ans;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    for(int i = 2; i <= 100000; i++)
    {
        if(p[i] == 0)
        {
            for(int j = 2 * i; j <= 100000; j += i) 
            {
                p[j] = 1; 
                q[j] = i;
            }
        }
    }
    while(scanf("%d", &n) != EOF)
    {
        clr(a, 0);
        for(int i = 1; i <= n; i++) 
        {
            int w, t = i;
            scanf("%d", &w);
            if(i == 1) continue;
            while(p[t] == 1)
            {
                a[q[t]] += w; 
                t /= q[t];
            }
            a[t] += w;
        }
        for(int i = 1; i <= n; i++)
        {
            b[i] = a[i];
            a[i] = (a[i] + 1) % (mod - 1);
        }
        l[0] = 1;
        for(int i = 1; i <= n; i++) l[i] = l[i - 1] * a[i] % (mod - 1);

        r[n + 1] = 1;
        for(int i = n; i >= 1; i--) r[i] = r[i + 1] * a[i] % (mod - 1);

        ll ans = 1;
        for(int i = 2; i <= n; i++)
        {
            if(b[i] > 0)
            {
                ll tmp;
                if(b[i] % 2 == 0) tmp = b[i] / 2 % (mod - 1) * ((b[i] + 1) % (mod - 1));
                else tmp = (b[i] + 1) / 2 % (mod - 1) * (b[i] % (mod - 1));
                tmp %= mod - 1;

                //printf("%d %lld\n", i, b[i]);

                ans *= power(i, tmp * l[i - 1] % (mod - 1) * r[i + 1] % (mod - 1));
            }
            ans %= mod;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
