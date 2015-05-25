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
#define MAX(a,b) (a > b ? a : b)
#define ll long long
using namespace std;

const int N = 100;
char s[N];
int a[N], l;
char str[N];
int r[N], p[N];

void pk(int *r, int n, int *p) {
    int i, id, mx = 0;
    for (i = 1; i < n; ++i) {
        if (mx > i) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        for (; r[i + p[i]] == r[i - p[i]]; p[i]++);
        if (p[i] + i > mx) {
            mx = p[i] + i;
            id = i;
        }
    }
}
ll spe(int x, int y)
{
    int c[20];
    int n = 0;
    for(int i = 0; i < x; i++)
    {
        if((i == 0 && a[i] != 0) || (i != 0 && a[i] != a[i - 1]))
            c[n++] = a[i];
    }
    if((x == 0 && y != 0) || (x != 0 && y != a[x - 1]))
        c[n++] = y;
    if(n + x + 1 >= l) return -1;
    ll ans = 0;
    for(int i = 0; i < x; i++)
        ans = ans * 10 + a[i];
    ans = ans * 10 + y;
    int exp = l - x - n - 1;
    for(int i = 0; i < exp; i++)
        ans = ans * 10 + 9;
    for(int i = n - 1; i >= 0; i--)
        ans = ans * 10 + c[i];
    return ans;
}
ll cal(int x, int y, int need)
{
    int c[20];
    int n = 0;
    for(int i = 0; i < x; i++)
    {
        if((i == 0 && a[i] != 0) || (i !=0 && a[i] != a[i - 1]))
            c[n++] = a[i];
    }
    if((x == 0 && y != 0) || (x != 0 && y != a[x - 1]))
        c[n++] = y;

    vector<int> sup;
    int exp = l - x - 1 - need;
    for(int i = min(n - 1, need) ; i >= 0; i--)
    {
        if(exp !=0 && (i == 0 || c[i] > c[i - 1]))
        {
            for(; exp; exp--)
                sup.push_back(c[i]);
        }
        if(i < need)
            sup.push_back(c[i]);
    }
    ll ans = 0;
    for(int i = 0; i < x; i++)
        ans = ans * 10 + a[i];
    ans = ans * 10 + y;
    for(int i = 0; i < sup.size(); i++)
        ans = ans * 10 + sup[i];
    return ans;
}
ll solve()
{
    ll ans = -1; 
    for(int i = l - 1; i >= 0; i--)
    {
        for(int j = a[i] - 1; j >= 0; j--)
        {
            int n = 0;
            r[n++] = '$';
            r[n++] = '#';
            for(int k = 0; k < i; k++)
            {
                if(k == 0 || a[k] != a[k - 1])
                {
                    r[n++] = a[k];
                    r[n++] = '#';
                }
            }
            if(i == 0 || j != a[i - 1])
            {
                r[n++] = j;
                r[n++] = '#';
            }
            r[n] = -1;
            pk(r, n , p);
            ll ans = -1;
            for(int k = 0; k < n; k++)
            {
                if(p[k] + k == n)
                {
                    int need = (k - p[k]) / 2;
                    if(need <= l - i - 1)
                    {
                        ans = MAX(ans, cal(i, j, need));
                    }
                }
            }
            ans = MAX(ans, spe(i, j));
            if(ans != -1) 
                return ans;
        }
    }
    return 0;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s); 
        l = strlen(s);
        for(int i = 0; i < l; i++)
            a[i] = s[i] - '0';
        ll ans = solve();
        cout<<ans<<endl;
    }
    return 0;
}
