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

char s1[2005], s2[505];
int dp[2005][2005], nxt[2005];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%s%s", s1 + 1, s2 + 1);
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    
    for(int i = 1; i <= l1; i++)
    {
        int j = i, k = 1;
        while(j <= l1 && k <= l2)
        {
            if(s1[j] == s2[k])
                k++;
            j++;
        }
        if(k > l2)
            nxt[i] = j - 1;
        else
            nxt[i] = -1;
    }
    
    int ans = 0;
    clr(dp, -1);
    dp[0][0] = 0;
    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j <= l1; j++)
        {
            if(dp[i][j] == -1)
                continue;
            if(nxt[i + 1] != -1)
            {
                int k = nxt[i + 1] - i - l2;
                if(j + k <= l1)
                    dp[nxt[i + 1]][j + k] = max(dp[nxt[i + 1]][j + k], dp[i][j] + 1);
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    for(int i = 0; i <= l1; i++)
    {
        printf("%d ", dp[l1][i]); 
    }
    puts("");
    return 0;
}
