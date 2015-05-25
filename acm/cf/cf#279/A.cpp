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

int n;
vector<int> a[4];

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int w;
        scanf("%d", &w); 
        a[w].push_back(i + 1);
    }
    int ans = min(min(a[1].size(), a[2].size()), a[3].size());
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
        printf("%d %d %d\n", a[1][i], a[2][i], a[3][i]);
    return 0;
}
