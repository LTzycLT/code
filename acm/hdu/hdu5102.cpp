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


int n, k;
vector<int> vc[100005];
queue<int> q;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        while(!q.empty()) q.pop();
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++) vc[i].clear();
        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            vc[u].push_back(v);
            vc[v].push_back(u); 
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < vc[i].size(); j++)
            {
                int u = i, v = vc[i][j];
                if(u > v) continue;
                q.push(u);
                q.push(v);
                q.push(v);
                q.push(u);
                q.push(1);
            }
        }
        ll ans = 0;
        while(k-- && !q.empty())
        {
            int u = q.front();q.pop();
            int v = q.front();q.pop();
            int pu = q.front();q.pop();
            int pv = q.front();q.pop();
            int w = q.front();q.pop();
            ans += w;
            if(k < q.size() / 5) continue;
            for(int i = 0; i < vc[v].size(); i++)
            {
                int v1 = vc[v][i];
                if(u <= v1 || v1 == pv)
                    continue;
                q.push(v1);
                q.push(u);
                q.push(v);
                q.push(pu);
                q.push(w + 1);
            }
            for(int i = 0; i < vc[u].size(); i++)
            {
                int u1 = vc[u][i];
                if(v <= u1 || u1 == pu)
                    continue;
                q.push(u1);
                q.push(v);
                q.push(u);
                q.push(pv);
                q.push(w + 1);
            }

       }
        printf("%I64d\n", ans);
    }
    return 0;
}
