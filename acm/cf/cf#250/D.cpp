#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


struct item{
    int u,w;
}a[100005];
vector<int> vc[100005];
int f[100005],n,m;
double sum[100005];
bool vis[100005];

int find(int u){
    if(f[u]==u) return f[u];
    else return f[u]=find(f[u]);
}
int cmp(item a,item b){
    return a.w>b.w;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].w);
        a[i].u=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        f[i]=i;
        sum[i]=1;
    }
    double ans=0;
    for(int i=1;i<=n;i++){
        int u=a[i].u;
        vis[u]=1;
        for(int j=0;j<vc[u].size();j++){
            int v=vc[u][j];
            if(!vis[v]) continue;
            int fu=find(u),fv=find(v);
            if(fu!=fv){
                ans+= sum[fu]*sum[fv]*a[i].w*2;
                f[fu]=fv;
                sum[fv]+=sum[fu];
            }
        }
    }
    printf("%.8lf\n",ans/n/(n-1));
    return 0;
}


