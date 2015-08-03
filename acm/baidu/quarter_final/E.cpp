/**
 * 维护长度最短, 并且刚好第一次在i位置出现的子序列个数
 */
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

const int N = 100005;
const int inf = N, mod = 1000000007;
int dp[N], nxt[N][26];
char s[N];
int len[N];
int n;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1); 
        for(int i = 0; i <= n + 1; i++)
        {
            dp[i] = 0;
            len[i] = inf;
        }
        for(int i = 0; i < 26; i++)
        {
            int w = n + 1;
            for(int j = n; j >= 0; j--)
            {
                nxt[j][i] = w;
                if(s[j] - 'a' == i)
                {
                    w = j;
                }
            }
        }
        len[0] = 0;
        dp[0] = 1;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(len[nxt[i][j]] > len[i] + 1)
                {
                    len[nxt[i][j]] = len[i] + 1;
                    dp[nxt[i][j]] = dp[i];
                }
                else if(len[nxt[i][j]] == len[i] + 1)
                {
                    dp[nxt[i][j]] += dp[i];
                    dp[nxt[i][j]] %= mod;
                }
            }
        }
        printf("Case #%d:\n%d %d\n", cas + 1, len[n + 1], dp[n + 1]);
    }
    return 0;
}

 
