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

const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x) {
    if (x < -eps) return -1; else return x > eps;
}
struct cpoint {
    double x, y;
    cpoint(){}
    cpoint(double x, double y) : x(x), y(y) {}
    cpoint operator + (const cpoint &u) const {
        return cpoint(x + u.x, y + u.y);
    }
    cpoint operator - (const cpoint &u) const {
        return cpoint(x - u.x, y - u.y);
    }
    cpoint operator * (const double &s) const {
        return cpoint(x * s, y * s);
    }
    cpoint operator / (const double &s) const {
        return cpoint(x / s, y / s);
    }
    double operator * (const cpoint &u) const { // 叉积
        return x * u.y - y * u.x;
    }
    double operator ^ (const cpoint &u) const { // 点积
        return x * u.x + y * u.y;
    }
    double len() { return sqrt(x * x + y * y); }
    bool operator == (const cpoint& u) const {
        return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;
    }
};
double cross(cpoint o, cpoint p, cpoint q) { // 叉积
    return (p - o) * (q - o);
}
double dissqr(cpoint p, cpoint q) {
    // 距离平方
    return sqr(p.x - q.x) + sqr(p.y - q.y);
}

cpoint bp;
int PolarCmp(const cpoint &p1, const cpoint &p2) {
    int u = dcmp(cross(bp, p1, p2));
    return u > 0 || (u == 0 && dcmp(dissqr(bp, p1)-dissqr(bp, p2)) < 0);
}
// ch中的点为逆时针顺序,边界无三点共线
void graham(cpoint pin[], int n, cpoint ch[], int &m) {
    int i, j, k, u, v;
    memcpy(ch, pin, n * sizeof(cpoint));
    for (i = k = 0; i < n; ++i) {
        u = dcmp(ch[i].x - ch[k].x);
        v = dcmp(ch[i].y - ch[k].y);
        if (v < 0 || (v == 0 && u < 0)) k = i;
    }
    bp = ch[k];
    sort(ch, ch + n, PolarCmp);
    n = unique(ch, ch + n) - ch; // 注意重载‖==‖
    if (n <= 1) { m = n; return ;}
    if (dcmp(cross(ch[0], ch[1], ch[n - 1])) == 0) {
        m = 2; ch[1] = ch[n - 1]; return;
    }
    ch[n++] = ch[0];
    for (i = 1, j = 2; j < n; ++j) {
        while (i > 0 && dcmp(cross(ch[i - 1], ch[i], ch[j])) <= 0) i--;
        ch[++i] = ch[j];
    }
    m = i;
}

double inf = 1e18;
int n, k;
cpoint point[10000];
cpoint a[10000];
int main() {
    //    freopen("/home/zyc/Downloads/in","r",stdin);
    //    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                scanf("%lf%lf", &point[cnt].x, &point[cnt].y);
                cnt++;
            } 
        }   
        n = n * 4;
        graham(point, n, a, k);
        double ans = inf;
        for(int i = 0; i < k; i++)
        {
            int j = i + 1;
            if(j >= k)
            {
                j = 0; 
            }
            double p = a[j].y - a[i].y;
            double q = -(a[j].x - a[i].x);
            double vmax = -inf, vmin = inf, wmax = -inf, wmin = inf;
            for(j = 0; j < n; j++)
            {
                double v = p * point[j].x + q * point[j].y;
                if(v > vmax)
                {
                    vmax = v; 
                } 
                if(v < vmin)
                {
                    vmin = v;
                }
                double w = -q * point[j].x + p * point[j].y;
                if(w > wmax)
                {
                    wmax = w;
                }
                if(w < wmin)
                {
                    wmin = w; 
                }
            }
            ans = min(ans, (vmax - vmin) * (wmax - wmin) / (p * p + q * q));
        }
        printf("Case #%d:\n%.0lf\n", cas + 1, ans);
    }
    return 0;
}
