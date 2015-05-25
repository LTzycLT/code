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

ll mod = 123456789;
int n, m;
int a[10005];
ll idx[105][10005];
ll dp[10005][105];
map<int, int> mp;

int lowbit(int x)
{
    return x&(-x);
}
void insert(int pos, int x, ll val)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        idx[pos][i] += val;
        idx[pos][i] %= mod;
    }
}
ll query(int pos, int x)
{
    ll ans = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        ans += idx[pos][i];
    return ans % mod;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            mp.insert(MP(a[i], 0));
        }
        int cnt = 0;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
            it->second = ++cnt;
        for(int i = 0; i < n; i++)
            a[i] = mp[a[i]];

        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
                idx[i][j] = 0;

        for(int i = 0; i < n; i++)
        {
            dp[i][1] = 1;
            insert(1, a[i], 1);
            for(int j = 2; j <= m; j++)
            {
                dp[i][j] = query(j - 1, a[i] - 1);
                insert(j, a[i], dp[i][j]);
            }
        } 
        ll ans = 0;
        for(int i = 0; i < n; i++)
            ans += dp[i][m];
        ans %= mod;
        cout<<ans<<endl;
    }
    return 0;
}
