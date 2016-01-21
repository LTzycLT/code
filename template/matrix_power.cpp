/* http://wenku.baidu.com/link?url=7Zhu8SqdhibKS3ow3De3DFkI-Y9ECnHQjIOWCWhIhiV0Hj54Yo_0U-fB139NRCdus6LyZtOnFW7Eem-6R7Ik3Rm4LD-wU-SBxnP98-gjXAi 
 *
 * 矩阵乘法快速幂, n^2 * log(n)
 * 求res = A ^ n * x
 *
 * res: 所求结果向量
 * A: r 阶矩阵
 * x: 初始向量
 *
 * 假设 |k * I - A| 的特征多项式为: k ^ n + s[n - 1] * k ^ (n -1) + ... s[0]
 * t = [-s[0], -s[1], ... , -s[n - 1]]
 *
 * a[i] 为第i項结果的向量, 需要前r项作为输入
 *
 * void solve(ll n, int r, type t[R], type a[][R], type res[R])
 *
 *  
 *
 * r 阶数
 */

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
#define MP(x,y) mare_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


const int R = 2;

typedef ll type;
type mod = 1e9 + 7;

type c[2 * R - 1][R];
type p2[64][R];

void multiply(type a[R], type b[R], type result[R], int r)
{
    type temp[2 * r - 1];
    clr(temp, 0);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            temp[i + j] += a[i] * b[j];     
            temp[i + j] %= mod;
        }
    }
    for(int i = 0; i < r; i++) result[i] = 0;

    for(int i = 0; i <= 2 * r - 2; i++)
    {
        for(int j = 0; j < r; j++)    
        {
            result[j] += c[i][j] * temp[i];
            result[j] %= mod;
        }
    }
}
void power(ll idx, type result[R], int r)
{
    for(int i = 0; i < 64; i++)
    {
        if((idx >> i) & 1) 
        {
            multiply(result, p2[i], result, r);        
        }
    }
}

void init_p2(int r)
{
    int i = 0;
    for(; (1 << i) <= r; i++)
    {
        for(int j = 0; j < r; j++) 
        {
            p2[i][j] = c[(1 << i)][j];
        }
    }
    for(; i < 64; i++)
    {
        multiply(p2[i - 1], p2[i - 1], p2[i], r);
    }
}

void solve(ll n, int r, type t[R], type a[][R], type res[R])
{
    for(int i = 0; i <= 2 * r - 2; i++) for(int j = 0; j < r; j++) c[i][j] = 0;

    for(int i = 0; i < r; i++) c[i][i] = 1; 
    for(int i = 0; i < r; i++) c[r][i] = t[i] % mod;
    for(int i = r + 1; i <= 2 * r - 2; i++)
    {
        for(int j = 0; j < r; j++) 
        {
            c[i][j] = t[r - 1] * c[i - 1][j];
            c[i][j] %= mod;
        }
        for(int j = 0; j < r - 1; j++)
        {
            c[i][j] += t[j]; 
            c[i][j] %= mod;
        }
    }

#ifdef DEBUG
    for(int i = 0; i <= 2 * r - 2; i++)
    {
        for(int j = 0; j < r; j++)
        {
            printf("%lld ", c[i][j]);
        }
        puts("");
    }
    puts("");
#endif

    init_p2(r);

#ifdef DEBUG
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < r; j++)
        {
            printf("%lld ", p2[i][j]);
        }
        puts("");
    }
#endif


    type result[r];
    clr(result, 0);
    result[0] = 1;
    power(n - r + 1, result, r);

    for(int i = 0; i < r; i++) res[i] = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            res[j] += result[i] * a[i][j];
        }
    }
}


//Fibnacii Sample
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    type t[R] = {1, 1};
    type a[R][R] = {
        {1, 1}, 
        {1, 2}
    };
    type res[2];
    solve(8, 2, t, a, res);
    printf("%lld %lld\n", res[0], res[1]);

    
    return 0;
}
