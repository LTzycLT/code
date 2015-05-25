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

ll mod=1e9+7;
int n;
ll dp[10005][2];

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d",&T);
    dp[1][0]=21;
    dp[1][1]=5;
    for(int i=2;i<=10000;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])*21%mod;
        dp[i][1]=dp[i-1][0]*5%mod;
    }
    while(T--){
        scanf("%d",&n);
        cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    }
    return 0;
}
