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

const int N = 10005;
int n, m;
int a[N];
int mx[N][20], mi[N][20], ln[N], val[N]; //val[]置为待查询数组
int c[N];
map<int, int> zyc;

void init(int n){
    int i,j,k,sk;
    ln[0] = ln[1] = 0;
    for (i = 2; i < n; ++i)
        ln[i] = ln[i >> 1] + 1;
    for(i=0;i<n;i++) mx[i][0]=mi[i][0]=val[i];
    for(i=1,k=2;k<n;i++,k<<=1)
        for(j=0,sk=k>>1;j<n;j++,sk++){
            mx[j][i]=mx[j][i-1];
            mi[j][i]=mi[j][i-1];
            if(sk<n && mx[j][i]<mx[sk][i-1])
                mx[j][i]=mx[sk][i-1];
            if(sk<n && mi[j][i]>mi[sk][i-1])
                mi[j][i]=mi[sk][i-1];
        }
}
int query(int a,int b){
    int bl = ln[b - a + 1];
    return max(mx[a][bl],mx[b-(1<<bl)+1][bl]) - min(mi[a][bl],mi[b-(1<<bl)+1][bl]);
}

int check(int l, int r, int k, int dup)
{
    if(dup)
    {
        return 0; 
    }
    if(query(l, r) + 1 == k)
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}
void insert(int x, int &dup)
{
    c[x] ++;
    if(c[x] == 2)
    {
        dup++; 
    }
}
void remove(int x, int &dup)
{
    c[x]--;
    if(c[x] == 1)
    {
        dup--; 
    }
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int cas = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        zyc.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &val[i]);
            zyc.insert(MP(val[i], 0));
        }
        init(n);
        int cnt = 0;
        for(map<int, int>::iterator it = zyc.begin(); it != zyc.end(); it++)
        {
            it->second = cnt++;
        }
        for(int i = 0; i < n; i++)
        {
            a[i] = zyc[val[i]];
        }
                

        cas++;
        printf("Case #%d:\n", cas);
        while(m--)
        {
            int k;
            int ans = 0;
            int dup = 0;
            scanf("%d", &k);
            for(int i = 0; i < cnt; i++)
            {
                c[i] = 0;
            }
            for(int i = 0; i < k; i++)
            {
                insert(a[i], dup);
            }
            ans += check(0, k - 1, k, dup);
            for(int i = k; i < n; i++)
            {
                insert(a[i], dup);
                remove(a[i - k], dup);
                ans += check(i - k + 1, i, k, dup);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
