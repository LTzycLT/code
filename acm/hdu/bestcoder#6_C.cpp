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

ll n, k;
ll mod = 1e9 + 7;

int eular(int n)
{
    int ret = 1, i;
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            n /= i;
            ret *= i - 1;
        }
        while(n%i == 0)
        {
            n /= i;
            ret *= i;
        }
    }

    if(n > 1)
        ret *= n - 1;
    return ret;
}
ll gao(ll x)
{
    ll y = n / x;
    return eular(y);
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(scanf("%I64d%I64d", &n, &k) != EOF)
    {
        if(n == 1)
        {
            puts("1");
            continue;
        }
        if(k > 2)
        {
            puts("0");
        }
        else if(k == 2)
        {
            puts("1");
        }
        else{
            ll limit = (ll)sqrt((double)n);
            ll ans = 0;
            for(int i = 1; i <= limit; i++)
            {
                if(n % i == 0){
                    ans += gao(i) * gao(n / i) * 2;
                    ans %= mod;
                }
                if(i * i == n){
                    ans -= gao(i) * gao(i);
                    ans = (ans % mod + mod) % mod;
                }
            }
            printf("%I64d\n", ans % mod);
        }
    }
    return 0;
}
