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

int n,m;
int g[1005][1005],a[1005];
bool flag[1005];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        g[u][v]=g[v][u]=1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int maxx=-1,x=0;
        for(int j=0;j<n;j++)
            if(!flag[j]&&a[j]>maxx){
                maxx=a[j];
                x=j;
            }
        flag[x]=1;
        for(int j=0;j<n;j++)
            if(!flag[j]&&g[x][j])
                ans+=a[j];
    }
    printf("%d\n",ans);
    return 0;
}
