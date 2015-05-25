#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<climits>
#define N 1010
#define oo 1e20
using namespace std;

struct Seg
{
    int s,e;
    double w;

    Seg(int a,int b,double c):s(a),e(b),w(c){}
    bool operator < (const Seg& p) const
    {
        if (e == p.e) return (s > p.s);
        else return (e < p.e);
    }
};

double area(double a, double b)
{
    double iterval = (b - a) /2;
    return iterval * iterval;
}

double dp[N];
vector<Seg>segs;
int n;

int main()
{
    int t, ys=0;

    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        segs.clear();
        for (int i=0;i<n;++i) {
            int x, y, w;
            scanf("%d%d%d",&x,&y,&w);
            segs.push_back(Seg(x-y,x+y,(double)w));
        }
        segs.push_back(Seg(-2100,-2100,0));
        sort(segs.begin(),segs.end());

        dp[0] = 0;
        double ans = 0;
        for (int i=1;i<=n;++i) {
            dp[i] = -oo;
            double coverVal = 0;
            double orgCost = area(segs[i].s,segs[i].e);

            for (int j=i-1;j>=0;--j){
                if (segs[j].s >= segs[i].s){
                    coverVal += segs[j].w;

                }else{
                    double cost = orgCost;
                    if (segs[j].e > segs[i].s) cost -= area(segs[j].e, segs[i].s);
                    dp[i] = max(dp[i], dp[j] - cost + segs[i].w + coverVal);
                    continue;
                }
            }
            ans = max(ans, dp[i]);
        }

        printf("Case #%d: %.2f\n",++ys,ans);
    }
    return 0;
}
