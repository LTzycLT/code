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

int lowbit(int x){
    return x&(-x);
}

struct item{
    int x,h;
    int l,r,num;
}a[10005];
int idx[100005];
int n;

void add(int l,int number){
    for(int i=l;i<=100000;i+=lowbit(i))
        idx[i]+=number;
}
int query(int l){
    int ans=0;
    for(int i=l;i>0;i-=lowbit(i))
        ans+=idx[i];
    return ans;
}
void update(int i,int k,int h){
    if(a[i].h<=a[k].h){
        if(h>a[k].h){
            add(a[k].h,-1);
            add(h,1);
        }
    }else{
        if(h>=a[k].h){
            add(a[i].h,-1);
            add(h,1);
        }else{
            add(a[i].h,-1);
            add(a[k].h,1);
        }
    }
}
int main() {
    //    freopen("/home/zyc/Downloads/in","r",stdin);
    //    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=100000;i++) idx[i]=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].x,&a[i].h);
            a[i].l=a[i].r=-1;
            a[i].num=0;
        }
        int l=-1;
        for(int i=0;i<n;i++){
            if(a[i].h==0) a[i].l=l;
            else l=i;
        }
        int r=-1;
        for(int i=n-1;i>=0;i--){
            if(a[i].h==0) a[i].r=r;
            else r=i;
        }
        for(int i=0;i<n;i++){
            if(a[i].h==0){
                int l=a[i].l,r=a[i].r;;
                if(l!=-1&&r!=-1){
                    if(abs(a[l].x-a[i].x)<abs(a[r].x-a[i].x)) a[l].num++;
                    else if(abs(a[l].x-a[i].x)>abs(a[r].x-a[i].x)) a[r].num++;
                    else{
                        a[l].r=i;
                        a[r].l=i;
                    }
                }else if(l==-1){
                    a[r].num++;
                }else{
                    a[l].num++;
                }
            }else{
                a[i].num++;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i].h!=0){
                add(a[i].h,a[i].num);
                if(a[i].r!=-1){
                    int j=a[i].r;
                    int k=a[j].r;
                    add(max(a[i].h,a[k].h),1);
                }
            }
        }
        int m;scanf("%d",&m);
        printf("Case #%d:\n",++cas);
        while(m--){
            char s[2];
            scanf("%s",s);
            if(s[0]=='Q'){
                int rk;scanf("%d",&rk);
                printf("%d\n",query(rk));
            }else{
                int i,h;
                scanf("%d%d",&i,&h);
                add(a[i].h,-a[i].num);
                add(h,a[i].num);
                if(a[i].l!=-1){
                    int j=a[i].l;
                    int k=a[j].l;
                    update(i,k,h);
                }
                if(a[i].r!=-1){
                    int j=a[i].r;
                    int k=a[j].r;
                    update(i,k,h);
                }
                a[i].h=h;
            }
        }
    }    
    return 0;
}
