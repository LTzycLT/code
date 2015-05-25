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

const ll MOD = 1000000009;
int n, k, m;
char s1[1000], s2[1000];
ll dp[105][105], c[105][105];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    c[0][0] = 1;
    for (int i = 1; i <= 100; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= MOD;
        }
    }
    while (scanf("%d%d%d", &n, &k, &m) != EOF)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s1[i] != s2[i])
                ++cnt;
        }
        clr(dp, 0);
        dp[0][cnt] = 1;
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                int l = max(0, j - n + m);
                int r = min(j, m);
                for (int k = l; k <= r; ++k)
                {
                    int h = m - k;
                    dp[i + 1][j - k + h] += c[j][k] * c[n - j][h] % MOD *  dp[i][j] % MOD;
                    dp[i + 1][j - k + h] %= MOD;
                }
            }
        }
        cout << dp[k][0] << endl;
    }
    return 0;
}
