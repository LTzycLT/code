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

const int N = 150; // 300左右是极限了,否则ans什么都就要开成全局变量
const ll mod = 1000000007;
typedef ll type;
struct matrix {
    int n;
    type a[N][N];
    void clear() {forn (i, n) forn (j, n) a[i][j] = 0; }
    matrix(){}
    matrix(int z) { n = z; clear(); }
    matrix operator + (const matrix& u) {
        matrix ans; ans.n = n;
        forn (i, n) forn (j, n) {
            ans.a[i][j] = a[i][j] + u.a[i][j];
            if (ans.a[i][j] >= mod) ans.a[i][j] %= mod;
        } return ans;
    }
    matrix operator * (const matrix& u) {
        matrix ans(n);
        forn (i, n) forn (k, n) if (a[i][k])
            forn (j, n) if (u.a[k][j]) {
                ans.a[i][j] += a[i][k] * u.a[k][j];
                if (ans.a[i][j] >= mod) ans.a[i][j] %= mod;
            }
        return ans;
    }
    matrix pow(int k) {
        matrix r(n), t = *this;
        forn (i, n) r.a[i][i] = 1;
        while (k) {
            if (k & 1) r = t * r;
            t = t * t;
            k >>= 1;
        } return r;
    }
    matrix calc(int); // A + A^2 + A^3 + ... + A^k
};
matrix matrix::calc(int k) {
    matrix r(2 * n), t, ret(n);
    forn(i, n) forn(j, n)
        r.a[i][j] = r.a[i][j + n] = a[i][j];
    forn(i, n) r.a[i + n][i + n] = 1;
    t = r.pow(k);
    forn(i, n) forn(j, n)
        ret.a[i][j] = t.a[i][j + n];
    return ret;
}

matrix a;
int l, r, K;
int ch(int i, int j)
{
    return i * 7 + j;
}
ll solve(int p)
{
    if(p == 0) return 0;
    if(p == 1) return 1;

    ll ans = 1;

    ll v[70], w[70];
    clr(w, 0);
    clr(v, 0);
    for(int i = 1; i < 10; i++)
    {
        v[ch(i, i % 7)] = 1;
    }

    a.clear();
    a.n = 70;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 7; j++)
        { 
            for(int k = 0; k < 10; k++)
            {
                if(i + k == K)  continue;   
                a.a[ch(k, (j * 10 + k) % 7)][ch(i, j)] = 1;
            }
        }
    }
    a = a.calc(p - 1);
    
    for(int i = 0; i < 70; i++)
    {
        for(int j = 0; j < 70; j++) 
        {
            w[i] += a.a[i][j] * v[j];
            w[i] %= mod;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        ans += w[ch(i, 0)];
        ans %= mod;
    }
    return ans;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    { 
        scanf("%d%d%d", &l, &r, &K); 
        ll ans = solve(r) - solve(l - 1);
        ans = (ans % mod + mod) % mod;
        printf("%lld\n", ans); 
    }

    return 0;
}
