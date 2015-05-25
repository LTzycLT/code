#include<stdio.h>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

struct item{
    int a,b;
};

ll mod = 1e9+7;
ll rev[1000005],dp[1000005];
ll power_mod(ll x,ll idx){
    ll ans=1;
    while(idx){
        if(idx&1) ans*=x;
        ans%=mod;

        x*=x;
        x%=mod;
        idx>>=1;
    }
    return ans;
}


int main(){
    
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);


    for(int i=1;i<=1000000+1;i++){
        rev[i] = power_mod(i,mod-2);
    }
    dp[1]=1;

    for(int i=2;i<=1000000;i++){
        dp[i] = dp[i-1]*(4*i-2)%mod*rev[i+1]%mod;
    }
    int T,cas=0; 
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("Case #%d:\n",++cas);
        printf("%I64d\n",dp[n]);
    }
    return 0;
}

