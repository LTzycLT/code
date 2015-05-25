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


char s[100005], t[100005];
int fail[100005];
ll dp[100005], mod = 1e9 + 7;
bool match[100005];

void kmp(char a[], int n, char b[], int m)
{
    for(int i = 0, j = -1; i < n; i++)
    {
        while(j != -1 && b[j + 1] != a[i]) j = fail[j]; 
        if(b[j + 1] == a[i])
        {
            j++;
        }
        if(j == m - 1)
        {
            match[i] = 1; 
            j = fail[j];
        }
    }
}
void make_fail(char a[], int n)
{ 
    fail[0] = -1;
    for(int i = 1, j = -1; i < n; i++)
    {
        while(j != -1 && a[j + 1] != a[i]) j = fail[j];
        if(a[j + 1] == a[i])
        {
            j++;
        }
        fail[i] = j;
    }
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);

    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    make_fail(t, m);
    kmp(s, n, t, m);
 
    ll sum = 0, diff = 0;
    for(int i = 0, j = -1; i < n; i++)
    {
        if(match[i])
        {
            sum += (i - m + 1 - j) * diff;
            sum %= mod;
            for(; j <= i - m; j++)
            {
                if(j != -1)
                {
                    sum += dp[j] * (i - m - j + 1);
                    diff += dp[j];
                    sum %= mod;
                    diff %= mod;
                }
            }
        }
        dp[i] = sum + j + 1;
        dp[i] %= mod;
    }
//    for(int i = 0; i < n; i++)
//    {
//        printf("%d ", match[i]);
//    }
//    puts("");
//    for(int i = 0; i < n; i++)
//    {
//        printf("%lld ", dp[i]);
//    }
//    puts("");
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += dp[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
