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

int cnt,s;
vector<int> a[50];
bool vis[100];

void dfs(int u,vector<int> path){
    if(u==s&&path.size()==21){
        printf("%d: ",++cnt);
        for(int i=0;i<21;i++) printf(" %d",path[i]);
        puts("");
        return ;
    }
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(!vis[v]){
            path.push_back(v);
            vis[v]=1;
            dfs(v,path);
            vis[v]=0;
            path.erase(path.end()-1);
        }
    }
}
int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(1){
        cnt=0;
        int x;
        scanf("%d",&x);
        if(x==0) break;
        for(int i=1;i<=20;i++) a[i].clear();
        a[1].push_back(x);
        scanf("%d",&x);a[1].push_back(x);
        scanf("%d",&x);a[1].push_back(x);
        for(int i=2;i<=20;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&x);
                a[i].push_back(x);
            }
        }
        for(int i=1;i<=20;i++) sort(a[i].begin(),a[i].end());
        clr(vis,0);
        vector<int> path;
        scanf("%d",&s);
        path.push_back(s);
        dfs(s,path);
    }
    return 0;
}
