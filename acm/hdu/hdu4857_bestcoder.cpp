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
set<int> st;
int pre[200000];
vector<int> vc[200000];
bool vis[200000];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        st.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            vc[i].clear();
            pre[i] = 0;
            vis[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            pre[u]++;
            vc[v].push_back(u); 
        }
        for(int i = 0; i < n; i++)
        {
            if(pre[i] == 0)
                st.insert(i);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            set<int>::iterator it = st.end();
            it--;
            int u = *it;
            vis[u] = 1;
            st.erase(it);
            for(int j = 0; j < vc[u].size(); j++)
            {
                pre[vc[u][j]]--;
                if(pre[vc[u][j]] == 0 && !vis[vc[u][j]])
                    st.insert(vc[u][j]);
            }
            ans.push_back(u);
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(i != n-1)
                printf(" ");
            printf("%d", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}
