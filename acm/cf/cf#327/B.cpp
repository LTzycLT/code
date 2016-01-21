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

/*
const double PI = acos(-1.0);
const double INF = 1e18;
const double EPS=1e-10;
double MIN, MAX;

double xx1, yy1;
double vmax, t;

double cal(double x, double y, double xx, double yy){
    x =  xx1 - x;
    y =  yy1 - y;  
    double a = vmax * vmax - yy * yy - xx * xx;
    double b = 2 * y * yy + 2 * x * xx;
    double c = -(y * y + x * x);

    if(b * b - 4 * a * c < 0) return INF;
    else
    {
        double ans1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        double ans2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        if(ans1 > ans2) swap(ans1, ans2);
        if(ans1 >= 0) return fabs(ans1);
        else return fabs(ans2);
    }
}


double dis2(double sx1, double sy1, double sx2, double sy2)
{
    return (sx2 - sx1) * (sx2 - sx1) + (sy2 - sy1) * (sy2 - sy1);
}
double dis(double sx1, double sy1, double sx2, double sy2)
{
    return sqrt(dis2(sx1, sy1, sx2, sy2));
}

double vx, vy, wx, wy;
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    double tx1, ty1, tx2, ty2;
    scanf("%lf%lf%lf%lf", &tx1, &ty1, &tx2, &ty2);
    xx1 = tx2 - tx1;
    yy1 = ty2 - ty1;
    scanf("%lf%lf", &vmax, &t);
    scanf("%lf%lf%lf%lf", &vx, &vy, &wx, &wy);

    if(dis(xx1, yy1, vx * t, vy * t) < vmax * t + EPS)
    {
        printf("%.10lf", cal(0, 0, vx, vy)); 
    }
    else
    {
        double R = vmax * t;
        double sx = vx * t, sy = vy * t;

        double ang = atan2(yy1 - vy * t, xx1 - vx *t); 
        double dang = acos(R / dis(xx1, yy1, vx * t, vy * t));
        double left= ang - dang,right = ang + dang;
        double mid1,mid2;

        while(left+EPS<right){
            mid1=left+(right-left)*0.381966;
            mid2=left+(right-left)*0.618034;
            if(cal(sx + R * cos(mid1), sy + R * sin(mid1), wx, wy) < cal(sx + R * cos(mid2), sy + R * sin(mid2), wx, wy)) right=mid2; //求极小值
            else left=mid1;
        }
        printf("%.10lf", cal(sx + R * cos(left), sy + R * sin(left), wx, wy) + t); 
    }
    return 0;
}
*/
const double PI = acos(-1.0);
const double INF = 1e18;
const double EPS=1e-8;
double MIN, MAX;

double xx1, yy1;
double vmax, t;

double vx, vy, wx, wy;

double dis2(double sx1, double sy1, double sx2, double sy2)
{
    return (sx2 - sx1) * (sx2 - sx1) + (sy2 - sy1) * (sy2 - sy1);
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    double tx1, ty1, tx2, ty2;
    scanf("%lf%lf%lf%lf", &tx1, &ty1, &tx2, &ty2);
    xx1 = tx2 - tx1;
    yy1 = ty2 - ty1;
    scanf("%lf%lf", &vmax, &t);
    scanf("%lf%lf%lf%lf", &vx, &vy, &wx, &wy);


    double left = 0, right = INF;
    while(right - left > EPS)
    {
        double mid = (right + left) / 2;
        double x, y;
        if(mid < t)
        {
            x = vx * mid; 
            y = vy * mid;
        }
        else
        {
            x = vx * t + (mid - t) * wx;
            y = vy * t + (mid - t) * wy;
        }
        if(dis2(x, y, xx1, yy1) < vmax * mid * vmax * mid)
        {
            right = mid;        
        }
        else
        {
            left = mid;
        }
    }
    printf("%.10lf\n", left);

    
    return 0;
}
