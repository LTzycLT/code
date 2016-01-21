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
#include<assert.h>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

const int N = 805; // 300左右是极限了,否则ans什么都就要开成全局变量
const int M = 5;
int mod = 1000000000;
typedef ll type;
type c[M][N * 2][N * 2];
int used[M];

void reset(int id)
{
    if(used[id] == 0)
    {
        assert(0);
    }
    used[id] = 0;
}

struct matrix {
    int n;
    int id;
    void clear() {forn (i, n) forn (j, n) c[id][i][j] = 0; }
    matrix(int z)
    {
        for(int i = 0; i < M ;i++)if(used[i] == 0){used[i] = 1; id = i; break;}
        n = z; 
        clear();
    }
    void operator += (const matrix& u) {
        matrix ans(n);
        forn (i, n) forn (j, n) {
            c[ans.id][i][j] = c[u.id][i][j] + c[u.id][i][j];
            if (c[ans.id][i][j] >= mod) c[ans.id][i][j] %= mod;
        }
        reset(id);
        id = ans.id;
    }
    int operator *= (const matrix& u) {
        matrix ans(n);
        forn (i, n) forn (k, n) if (c[id][i][k])
            forn (j, n) if (c[u.id][k][j]) {
                c[ans.id][i][j] += c[id][i][k] * c[u.id][k][j];
                if (c[ans.id][i][j] >= mod) c[ans.id][i][j] %= mod;
            }
        reset(id);
        id = ans.id;
        return id;
    }
    void pow(int k) {
        matrix r(n), t = *this;
        forn (i, n) c[r.id][i][i] = 1;
        while (k) {
            if (k & 1) r *= t;
            t *= t;
            k >>= 1;
        }
        reset(t.id);
        id = r.id;
    }
    void log()
    {
        forn(i, n) 
        {
            forn(j , n)
            {
                printf("%lld ", c[id][i][j]);
            }
            puts("");
        }
    }
    void calc(int);
};
void matrix::calc(int k) {
    matrix r(2 * n), ret(n);
    forn(i, n) forn(j, n)
        c[r.id][i][j] = c[r.id][i][j + n] = c[id][i][j];
    forn(i, n) c[r.id][i + n][i + n] = 1;
    r.pow(k);
    forn(i, n) forn(j, n)
        c[ret.id][i][j] = c[r.id][i][j + n];

    reset(r.id);
    reset(id);
    id = ret.id;
}
void log_id()
{
    for(int i = 0; i < M; i++) printf("%d ", used[i]);
    puts("");
}

int n, m;

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    while(scanf("%d%d%d", &n, &m , &mod) != EOF)
    { 
        if(n >= N)
        {
            puts("haha");
            continue;
        }
        matrix p1(n + 1), p2(n + 1);
        for(int i = 0; i <= n; i++) for(int j = i; j <= n; j++) c[p1.id][i][j] = 1;
        for(int i = 0; i <= n; i++)
        {
            c[p2.id][i][i] = 1;     
            if(i + 1 <= n) c[p2.id][i][i + 1] = 1;
        }
        p2 *= p1;
        reset(p1.id);
        p2.calc(m);
        matrix p3(n + 1);
        for(int i = 0; i <= n; i++) for(int j = i; j <= n; j++) c[p3.id][i][j] = (j >= i) ? 1 : 0;
        p3 *= p2;
        int ans = (c[p3.id][0][n] + 1) % mod;
        printf("%d\n", ans);

        reset(p2.id);
        reset(p3.id);
        //log_id();
    }

    return 0;
}

int main1()
{
    int n = 3, m = 10;
    int dp[100][100];
    clr(dp, 0);
    dp[0][0] = 1;
    for(int j = 0; j <= m; j++)
    {
        forn(i, n) dp[i + 1][j] += dp[i][j];
        for(int i = 0; i <= n; i++)
        {
            dp[i][j + 1] += dp[i][j];
            dp[i + 1][j + 1] += dp[i][j];
        }
        printf("%d ", dp[n][j]);
    }
    return 0;
}

