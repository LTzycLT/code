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

ll dp[2][1<<18][18];
ll count[1<<18], ans[20][20];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    for(int i = 0; i < (1 << 18); i++)
    {
        count[i] = 0;
        for(int j = 0; j < 18; j++)
            if(i & (1 << j))
                count[i]++;
    }
    clr(ans, 0); 
    clr(dp, 0);

    for(int i = 0; i < 18; i++)
    {
        dp[0][1][i] = 1;
    }
    ans[1][1] = 1;

    for(int i = 1; i < 18; i++)
    {
        int s = i & 1;
        int t = s ^ 1;
        for(int j = 0; j < (1 << i); j++)
        {
            for(int k = 0; k < 18; k++)
            {
                dp[i][j][] = dp[i - 1][j][] 
            }
        }
    }
    return 0;
}
