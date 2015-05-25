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
#define MID(l, r) ((l + r)>>1) 
using namespace std;



int n, m;
struct node
{
    int l, r;
    ll sum, maxx;
    int flag;
}a[100000];

void push_up(int rt)
{
    a[rt].sum = a[rt * 2] + a[rt * 2 + 1];
    a[rt].maxx = max(a[rt * 2].maxx, a[rt * 2 + 1].maxx);
}
void push_down(int rt)
{
    for(int i = 0; i < a[rt].flag; i++)
    {
        a[rt * 2].sum *= 2;
        a[rt * 2 + 1].sum *= 2;
        a[rt * 2].maxx *= 2;
        a[rt * 2 + 1].maxx *= 2;
    }
    a[rt * 2].flag += a[rt].flag;
    a[rt * 2 + 1].flag += a[rt].flag;
    a[rt].flag = 0;
}
void init(int rt, int l, int r)
{
    a[rt].l = l;
    a[rt].r = r;
    a[rt].flag = 0;
    a[rt].sum=0;
    a[rt].maxx = 0;
    if(l == r)
    {
        a[rt].sum = 1;
        return ;
    }    
    init(rt * 2, l, MID(l, r));
    init(rt * + 1, MID(l, r) + 1, r);
    push_up(rt);
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        init(1, 1, n);
        while(m--)
        {
            char s[2];
            int l, r;
            scanf("%s%d%d", s, &l, &r);
            if(s[0] == 'D')
            {
                
            }
            else
            {
            }
        }
    }
    return 0;
}
