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
int n,m;
int s[100005],t[100005];
int d[100005];

int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            d[i]=0;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&s[i],&t[i]);
            d[s[i]]++;
            d[t[i]]++;
        }
        ll ans=0;
        for(int i=1;i<=m;i++){
            ans += 2*(d[s[i]]-1)*(d[t[i]]-1);
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
