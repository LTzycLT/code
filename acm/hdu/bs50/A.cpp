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

double PI = acos(-1.0);
double eps = 1e-6;
int n;
int x[100], y[100];
int d[100][100];
int a[10];
set<int> zyc;


bool check(int m)
{
    double ang = (m - 2) * PI / m;
    for(int i = 0; i < m; i++)
    {
        int u = a[i], v = a[(i + 1) % m], w = a[(i + 2) % m];
        double a1 = atan2(y[v] - y[u], x[v] - x[u]); 
        double a2 = atan2(y[w] - y[v], x[w] - x[v]); 
        double ang1 = (a1 - a2);
        if(ang1 < 0) ang1 += 2 * PI;
        if(ang1 > 2 * PI) ang1 -= 2 * PI;
        if(ang1 > PI) ang1 = 2 * PI - ang1;
        if(fabs(ang - ang1) > eps) return false;
    }

    /*
    for(int i = 0; i < n; i++)
    {
        bool in = false;
        for(int j = 0; j < m; j++)
        {
            if(a[j] == i) in = true;
        }
        if(in) continue;
        for(int j = 0; j < m; j++)
        {
            int u = a[j], v = a[(j + 1) % m]; 
            int sx = min(x[u], x[v]), tx = max(x[u], x[v]), sy = min(y[u], y[v]), ty = max(y[u], y[v]);
            if(x[i] >= sx && x[i] <= tx && y[i] >= sy && y[i] <= ty)
            {
                if((x[i] - sx) * (ty - y[i]) == (tx - x[i]) * (y[i] - sy))
                {
                    return false;
                }
            }
        }
    }
    */
    return true;
}
void dfs(int s, int dep, int dis)
{
    if(dep >= 3 && dep <= 6)
    {
        if(d[a[dep - 1]][s] == dis) 
        {
            if(check(dep))
            {
                int w = 0; 
                for(int i = 0; i < dep; i++)
                    w += (1 << a[i]);
                zyc.insert(w);
            }
        }
    }
    if(dep == 6) return;
    for(int i = 0; i < n; i++)
    {
        bool flag = false;
        for(int j = 0; j < dep; j++)
        {
            if(d[i][a[j]] == 0) flag = true; 
        }
        if(flag) continue;
        if(d[a[dep - 1]][i] == dis)
        {
            a[dep] = i;
            dfs(s, dep + 1, dis); 
        }
    }
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    while(scanf("%d", &n) != EOF)
    {
        zyc.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                d[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                a[0] = i;
                a[1] = j;
                if(d[i][j] == 0) continue;
                dfs(i, 2, d[i][j]);
            }
        }
        printf("%d\n", (int)zyc.size());
    }
    return 0;
}
