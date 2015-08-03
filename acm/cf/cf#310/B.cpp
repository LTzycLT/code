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

const int N = 500000;
int n, m;
struct item
{
    ll l, r;
    int id;
    int mid;
}a[N];
struct point
{
    ll x;
    int id; 
}b[N];
multimap<ll, int> zyc;

int cmpl(item a, item b)
{
    return a.l < b.l;
}
int cmpid(item a, item b)
{
    return a.id < b.id;
}
int cmpx(point a, point b)
{
    return a.x < b.x;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    scanf("%d%d", &n, &m);
    ll pl = 0, pr = 0;
    for(int i = 0; i < n; i++)
    {
        ll tl, tr;
        scanf("%lld%lld", &tl, &tr);
        if(i != 0)
        {
            a[i - 1].l = tl - pr; 
            a[i - 1].r = tr - pl;
            a[i - 1].id = i - 1;
            a[i - 1].mid = -1;
        }
        pl = tl;
        pr = tr;
    }
    n = n - 1;
    for(int i = 0; i < m; i++)
    {
       scanf("%lld", &b[i].x); 
       b[i].id = i;
    }
    sort(a, a + n, cmpl);
    sort(b, b + m, cmpx);
    for(int i = 0, j = 0; i < m; i++)
    {
        while(j < n && a[j].l <= b[i].x)
        {
            zyc.insert(MP(a[j].r, j));
            j++;
        } 
        while(!zyc.empty())
        {
            multimap<ll, int>::iterator it = zyc.begin(); 
            if(it->first < b[i].x)
            {
                zyc.erase(it);
            }
            else
            {
                a[it->second].mid = b[i].id;
                zyc.erase(it);
                break;
            }
        }
    }
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
       if(a[i].mid == -1)
       {
            flag = false;
       } 
    }
    if(flag)
    {
        puts("Yes");
        sort(a, a + n, cmpid);
        for(int i = 0; i < n; i++)
        {
            printf("%d ", a[i].mid + 1);
        }
        puts(""); 
    }
    else
    {
        puts("No");
    }

     
    return 0;
}
