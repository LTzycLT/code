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

const int N = 200005;
int n;
ll a[N], b[N], c[N];

void deal(ll d[], int x)
{
    ll mask = (1LL << (x + 1));
    int p;
    for(p = 0; p < n; p++)
    {
        if(d[p] >= mask) 
        {
            break;
        }
    }
    for(int i = p; i < n; i++)
    {
        d[i] &= (mask - 1);
    }
    for(int i = 0, j = p, k = 0; i < p || j < n;)
    {
        if(i == p)
        {
            c[k++] = d[j++];
        }
        else if(j == n)
        {
            c[k++] = d[i++];
        }
        else
        {
            if(d[i] < d[j])
            {
                c[k++] = d[i++];
            }
            else
            {
                c[k++] = d[j++];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        d[i] = c[i];
    }
}
ll count(ll limit)
{
    ll sum = 0;
    for(int i = 0, j = n - 1; i < n; i++)
    {
        while(j >= 0 && a[i] + b[j] >= limit) j--;
        sum += (n - j - 1);
    }
    return sum;
}
int main() {
    //freopen("/home/zyc/Downloads/in","r",stdin);
    //freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        ll ans = 0;
        for(int i = 61; i >= 0; i--)
        {
            deal(a, i);
            deal(b, i);
        
            ll number = count(1LL << i) - count((1LL << i) * 2) + count((1LL << i) * 3);
            if(number & 1)
            {
                ans += (1LL << i); 
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
