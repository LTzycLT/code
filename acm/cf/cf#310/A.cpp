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

int n, m;
vector<int> a[100005];
map<int, int> zyc;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++)
        {
            int w;
            scanf("%d", &w); 
            a[i].push_back(w);
            zyc.insert(MP(w, 0));
        }
    }
    int cnt = 0;
    for(map<int, int>::iterator it = zyc.begin(); it != zyc.end(); it++)
    {
       it->second = cnt++; 
    }
    int ans = n - 1 + (n - m);
    for(int i = 0; i < m; i++)
    {
        if(a[i].size() > 0 && zyc[a[i][0]] == 0)
        {
            int j = 0;
            for(; j < (int)a[i].size(); j++)
            {
                if(zyc[a[i][j]] != j)
                {
                    break;
                }
            } 
            ans -= 2 * (j - 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
