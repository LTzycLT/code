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


struct rec
{
    int x, y;
    int id;
};
char a[1000][1000];


void p(int x1, int y1, int x2, int y2, int c)
{
    for(int i = x1; i <= x2; i++)
    {
        for(int j = y1; j <= y2; j++)
        {
           a[i][j] = 'A' + c; 
        }
    }
}
void out(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%c", a[i][j]);
        puts("");
    }
}

bool dfs1(rec a, rec b, rec c, int dep)
{
    if(dep == 0)
    {
        if(dfs1(a, b, c, dep + 1)) return true;;
        swap(a.x, a.y);
        if(dfs1(a, b, c, dep + 1)) return true;;
    }
    else if(dep == 1)
    {
        if(dfs1(a, b, c, dep + 1)) return true;;
        swap(b.x, b.y);
        if(dfs1(a, b, c, dep + 1)) return true;;
    }
    else if(dep == 2)
    {
        if(dfs1(a, b, c, dep + 1)) return true;;
        swap(c.x, c.y);
        if(dfs1(a, b, c, dep + 1)) return true;;
    }
    else
    {
        if((a.x == b.x + c.x) && (b.y == c.y) && (a.y + b.y == a.x))
        {
            //printf("%d%d%d%d%d%d\n", a.x, a.y, b.x, b.y, c.x, c.y);
            p(0, 0, a.x, a.y, a.id);
            p(0, a.y, b.x, a.y + b.y, b.id);
            p(b.x, a.y, a.x, a.x, c.id);
            printf("%d\n", a.x);
            out(a.x);
            return true;
        }
        if((a.x == b.x) && (b.x == c.x) && (a.x == a.y + b.y + c.y))
        {
            //printf("%d%d%d%d%d%d\n", a.x, a.y, b.x, b.y, c.x, c.y);
            p(0, 0, a.x, a.y, a.id);
            p(0, a.y, b.x, a.y + b.y, b.id);
            p(0, a.y + b.y, c.x, a.y + b.y + c.y, c.id);
            printf("%d\n", a.x);
            out(a.x);
            return true;
        }
    }
    return false;
}

void solve(rec a, rec b, rec c)
{
    if(dfs1(a, b, c, 0)) return;
    if(dfs1(a, c, c, 0)) return;
    if(dfs1(b, a, c, 0)) return;
    if(dfs1(b, c, a, 0)) return;
    if(dfs1(c, a, b, 0)) return;
    if(dfs1(c, b, a, 0)) return;
    printf("-1\n");
}

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    rec a[3];
    scanf("%d%d%d%d%d%d", &a[0].x, &a[0].y, &a[1].x, &a[1].y, &a[2].x, &a[2].y);
    a[0].id = 0;
    a[1].id = 1;
    a[2].id = 2;

    solve(a[0], a[1], a[2]);

    return 0;
}
