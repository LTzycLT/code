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

const int inf = 1e8;
struct tune
{
    int a, b;
}a[5005][4];
int dp[10000][24];
int n;

bool check(int s[], int x)
{
    return true;
}

int convert(int p[], int q[], int x)
{
    return 0;
}
int first_convert(int p[])
{
    return 0;
}

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas <= T; cas++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                scanf("%d%d", &a[i][j].a, &a[i][j].b);
            }
            int p[4] = {0, 1, 2, 3};
            int pn = 0;
            do
            {
                dp[i][pn] = inf;
                if(!check(p, i))
                {
                    pn++;
                    continue;
                }
                if(i == 0)
                {
                    dp[i][pn] = first_convert(p);
                }
                else
                {
                    int q[4] = {0, 1, 2, 3};
                    int qn = 0;
                    do{
                        if(!check(q, i - 1)) 
                        {
                            qn++;
                            continue;
                        }
                        dp[i][pn] = min(dp[i][pn], dp[i - 1][qn] + convert(p, q, i));
                        qn++;
                    }while(next_permutation(q, q + 4));
                }
                pn++;
            }
            while(next_permutation(p, p + 4));
        } 
        int ans = inf;
        for(int i = 0; i < 24; i++)
        {
            ans = min(ans, dp[n - 1][i]); 
        }
        printf("Case #%d:%d\n", cas + 1, ans);
    }
    return 0;
}
