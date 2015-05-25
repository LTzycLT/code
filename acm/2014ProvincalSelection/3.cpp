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

ll n,a,b;
ll t[100005];
ll dp[100005][2];

int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        cin>>n>>a>>b;
        for(int i=0;i<n;i++){
            cin>>t[i];
        }
        dp[0][1]=2*a+b;
        dp[0][0]=a+b;
        for(int i=1;i<n;i++){
            dp[i][0]=min(dp[i-1][0]+b*(t[i]-t[i-1]),dp[i-1][1]+a+b);
            dp[i][1]=min(dp[i-1][0]+b*(t[i]-t[i-1])+a,dp[i-1][1]+b+2*a);
        }
        printf("Case #%d: ",++cas);
        cout<<min(dp[n-1][0]+a,dp[n-1][1])<<endl;
    }
    return 0;
}
