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

int n, mod;
const int N = 3;
typedef  ll type ;
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
}mtx;
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
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    while(scanf("%d%d", &n, &mod) != EOF)
    {
        matrix ans(1);
        ans.a[0][0] = 4;
        if(n != 1)
        {
        ans = ans.calc(n / 2 - 1); 
        ll tmp = ans.a[0][0];
        tmp = (tmp * 2 + 2) % mod;
        if(n & 1)
            tmp = (tmp * 2 + 1) % mod;
        cout<<tmp<<endl;
        }
        else
        {
            if(mod == 1)
                puts("0");
            else
                puts("1");
        }
    }
    return 0;
}
