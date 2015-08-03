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

int n;
ll m, k, a[10005];
int dp[10005];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%lld%lld", &n, &m, &k); 
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        sort(a, a + n);
        bool flag = true;
        for(int i = 0, j = 0; i < n; i++)
        {
            if(a[i] <= m)
            {
                dp[i] = 0;
            }  
            else
            {
                while(j < i && a[j] + (k - dp[j]) < a[i])
                {
                    j++; 
                } 
                if(j < i && dp[j] + 1 <= k)
                {
                    dp[i] = dp[j] + 1;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        printf("Case #%d:\n", cas + 1);
        if(flag)
        {
            puts("why am I so diao?");
        }
        else
        {
            puts("madan!");
        }
    }
    return 0;
}
