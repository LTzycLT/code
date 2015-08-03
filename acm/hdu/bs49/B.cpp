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

const int N = 20010 * 2;

/*
 * Make sure all bitset has same length in same case.
 */
const int BN = 20000;
const long long mask = -1;
class bitset {
    int n, m;
    long long b[BN / 64 + 1];

    public:
    bitset(int __n) {
        n = __n;
        m = n / 64;
        if(n % 64 != 0) m++;
    }

    inline void set(int l, int x){
        if(x) b[l >> 6] |= (1LL << (l & 63));
        else b[l >> 6] &= ~(1LL << (l & 63));
    }
    inline bool get(int l) const{
        return (b[l >> 6] >> (l & 63)) & 1;
    }
    void set(int l, int r, bool x){
        int i;
        long long w = x ? mask : 0;
        for(i = l; (i & 63) && i < r; i++) set(i, x);
        for(; i < r; i += 64) b[i >> 6] = w;
        for(; i < r; i++) set(i, x);
    }

    int count(long long x) {
        long long y = x;  
        y >>= 1;
        while(y){x-= y; y >>= 1;}
        return x;
    }
    bool zero_interval(int l, int r) const {
        int i;
        for(i = l; (i & 63) && i < r; i++) if(get(i)) return false;
        for(; i < r; i += 64) if(b[i >> 6]) return false;
        for(; i < r; i++) if(get(i)) return false;
        return true;
    }

    void get_mask(int n, long long &l_mask, long long &r_mask) const {
        if(n == 64) l_mask = mask; 
        else if(n == 0) l_mask = 0;
        else l_mask = (1LL << n) - 1; 
        r_mask = mask - l_mask;
    }
    // x >= 0
    bitset operator << (int x) const {
        bitset ret(n);
        int s = x >> 6, t = x & 63, tt = 64 - t;
        long long suf, pre;
        get_mask(tt, pre, suf);
        for(int i = m - s - 1, j = m - 1, k = m; i >= 0; i--, j--, k--){
            ret.b[j] = (b[i] & pre) << t;
            if(k < m) ret.b[k] |= (b[i] & suf) >> tt;
        }
        ret.set(0, x, 0);
        return ret;
    }
    // x >= 0
    bitset operator >> (int x) const {
        bitset ret(n); 
        int s = x >> 6, t = x & 63, tt = 64 - t;
        long long pre, suf;
        get_mask(t, pre, suf);
        for(int i = s, j = 0, k = -1; i < m; i++, j++, k++){
            ret.b[j] = (b[i] & suf) >> t;
            if(k >= 0) ret.b[k] |= (b[i] & pre) << tt;
        }
        ret.set(n - x, n, 0);
        return ret;
    }

    bitset operator & (const bitset &u) const {
        bitset ret(n); 
        for(int i = 0; i < m; i++) ret.b[i] = b[i] & u.b[i];  
        return ret;
    }

    bitset operator | (const bitset &u) const {
        bitset ret(n); 
        for(int i = 0; i < m; i++) ret.b[i] = b[i] | u.b[i];  
        return ret;
    }
    void print() const{
        for(int i = 0; i < n; i++){
            if((i & 63) == 0) printf(" ");
            if(get(i))  printf("1");
            else printf("0");
        }
        puts("");
    }
};
//int main(){
//    bitset a(200);
//    a.set(0, 200, 1);
//    a.set(64, 100, 0);
//    a = a << 0;
//    a.print();
//}


/*
 * 原串: w a a b w s w f d
 * 新串r[]: $ # w # a # a # b # w # s # w # f # d #
 * 辅助数组P: 1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1
 * p[id]- 1 就是该回文子串在原串中的长度
 * */
char str[N];
int r[N], p[N], len, m;
struct item{
    int l, r;
}a[N];
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
void solve() {
    clr(p, 0);
    scanf("%s", str);
    len = strlen(str);
    int n = 0;
    r[n++] = '$'; r[n++] = '#';
    forn (i, len) {
        r[n++] = str[i];
        r[n++] = '#';
    }
    r[n] = 0;
    pk(r, n, p);
    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 0) 
        {
            a[m].l = i / 2 - p[i] / 2; 
            a[m].r = i / 2 + p[i] / 2 - 2;
        }
        else
        {
            if(p[i] == 1) continue;
            a[m].l = i / 2 - p[i] / 2; 
            a[m].r = i / 2 + p[i] / 2 - 1;
        }
        m++;
    }
}

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        m = 0;
        solve();
        bitset s(len);
        bitset t(len);
        bitset temp(len);
        s.set(0, len, 0);
        t.set(0, len, 0);
        for(int i = 0; i < m; i++)
        {
            if(a[i].r == len - 1) t.set(len - a[i].l - 1, 1);
            if(a[i].l == 0) s.set(a[i].r, 1);
        }
        int flag = 0;
        for(int i = 0; i < m; i++)
        {
            int l = max(a[i].l - 1, 0);
            int r = (a[i].l + a[i].r) / 2 - 1;
            if(r < l) continue;

            if(a[i].l > (len - a[i].r - 1))
            {
                temp = t << (a[i].l - (len - a[i].r - 1));
            }
            else
            {
                temp = t >> ((len - a[i].r - 1) - a[i].l); 
            }

            bitset  as = s & temp;
            if(as.zero_interval(l, r + 1) == false)
            {
                flag = true;
                break;
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
