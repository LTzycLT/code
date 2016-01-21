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

ll l[100005], r[100005];
ll a[100005];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}
ll get(int l, ll c[])
{
    ll ans = 0;
    for(int i = l; i > 0; i -= lowbit(i))
    {
        ans += c[i];
    }
    return ans;
}
void insert(int l, int w, ll c[])
{
    for(int i = l; i <= n; i += lowbit(i))
    {
       c[i] += w; 
    }
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++) l[i] = r[i] = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        ll sum = 0, ans = 1e18;
        for(int i = m; i < n; i++)
        {
            ll x = get(a[i], r); 
            sum += (i - m - x);
            insert(a[i], 1, r);
        }
        if(ans > sum) ans = sum;
        for(int i = 0; i < n - m; i++)
        {
            sum -= (i - get(a[i + m], l));
            sum -= get(a[i + m] - 1, r);
            insert(a[i + m], -1, r);

            sum += get(a[i] - 1, r);
            sum += (i - get(a[i], l));
            insert(a[i], 1, l);
            if(ans > sum) ans = sum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
