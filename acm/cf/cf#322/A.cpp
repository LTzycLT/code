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

int a, b;
int main() {
    //freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    scanf("%d%d", &a, &b);
    printf("%d %d\n", min(a, b), (a + b) / 2 - min(a, b));
    return 0;
}
