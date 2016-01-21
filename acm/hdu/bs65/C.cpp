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

#define Type int
#define maxn 100000
class sbtree { // SizeBalanceTree
    public:
        void clear() {
            tot = 0;
            lc[0] = rc[0] = 0;
            sz[0] = 0;
            root = 0;
        }
        int size() {return sz[root];}
        bool empty() {return root == 0;}
        void Build(int s,int e) {Build(root,s,e);}
        bool Find(Type val) {return Find(root, val);}
        void Insert(Type val) {Insert(root, val);}
        void Delete(Type val) {Delete(root, val);}
        Type DeleteSelect(int k) {return DeleteSelect(root, k);}
        void DeleteSmall(Type val) {DeleteSmall(root, val);}
        int Rank(Type val) {return Rank(root, val);}
        Type Select(int k) {return Select(root, k);}
        Type getMin() {
            int temp = root;
            while (lc[temp]) temp = lc[temp];
            return key[temp];
        }
        Type getMax() {
            int temp = root;
            while (rc[temp]) temp = rc[temp];
            return key[temp];
        }
        Type DeleteMax() {
            int temp = root;
            if(rc[root] == 0) {
                root = lc[root];
                return key[temp];
            }
            while (rc[rc[temp]]) {
                sz[temp] --;
                temp = rc[temp];
            }
            sz[temp] --;
            Type ret = key[rc[temp]];
            rc[temp] = lc[rc[temp]];
            return ret;
        }
        Type DeleteMin() {
            int temp = root;
            if(lc[root] == 0) {
                root = rc[root];
                return key[temp];
            }
            while (lc[lc[temp]]) {
                sz[temp] --;
                temp = lc[temp];
            }
            sz[temp] --;
            Type ret = key[lc[temp]];
            lc[temp] = rc[lc[temp]];
            return ret;
        }
    private:
        int sz[maxn];
        //sz[i]表示以i为根的子树的大小
        Type key[maxn]; //存放val值 (左儿子 <= 根 <= 右儿子)
        int lc[maxn];
        //左儿子
        int rc[maxn]; //右儿子
        int root , tot;
        // 建树之前先clear()
        void Build(int &root,int s,int e) { //以[s, e]的连续整数建SBT
            if(s > e) return ;
            int mid = (s + e)/2;
            root = ++tot;
            key[root] = mid;
            lc[root] = 0;
            rc[root] = 0;
            sz[root] = e - s + 1;
            if(s == e) return ;
            Build(lc[root] , s , mid - 1);
            Build(rc[root] , mid + 1 , e);
        }
        bool Find(int &root,Type k) {
            if (root == 0) {
                return false;
            } else if (k < key[root]) {
                return Find(lc[root] , k);
            } else {
                return (key[root] == k || Find(rc[root] , k));
            }
        }
        void Insert(int &root,Type val) {
            if (root == 0) {
                root = ++tot;
                lc[root] = rc[root] = 0;
                sz[root] = 1;
                key[root] = val;
                return ;
            }
            sz[root] ++;
            if (val < key[root]) {
                Insert(lc[root] , val);
            } else {
                Insert(rc[root] , val);
            }
            maintain(root , !(val < key[root]));
        }
        Type Delete(int &root,Type val) { //删除一个val值(val值必须存在)(无内存回收)
            sz[root]--;
            if ((key[root] == val) || (val < key[root] && lc[root] == 0) ||
                    (key[root] < val && rc[root] == 0)) {
                Type ret = key[root];
                if ( lc[root] == 0 || rc[root] == 0 )
                    root = lc[root] + rc[root];
                else //从左子树中取最大的节点取代当前节点
                    key[root] = Delete(lc[root] , key[root] + 1);
                return ret;
            } else {
                if ( val < key[root] )
                    return Delete(lc[root] , val);
                else
                    return Delete(rc[root] , val);
            }
        }
        void DeleteSmall(int &root , Type val){ //删除小于val的所有数(破坏树的平衡)
            if ( root == 0 ) return ;
            if ( key[root] < val ) {
                root = rc[root];
                DeleteSmall(root , val);
            } else {
                DeleteSmall(lc[root] , val);
                sz[root] = 1 + sz[lc[root]] + sz[rc[root]];
            }
        }
        int Rank(int &root , Type val) { //查询val值rank多少(val值必须存在)
            if ( key[root] == val ) {
                return 1;
            } else if ( val < key[root] ) {
                return Rank(lc[root], val);
            } else {
                return sz[lc[root]] + 1 + Rank(rc[root] , val);
            }
        }
        Type Select(int &root , int k) { // 查询第k小元素(从1开始)
            if ( sz[lc[root]] + 1 == k ) {
                return key[root];
            } else if ( k > sz[lc[root]] ) {
                return Select(rc[root] , k - 1 - sz[lc[root]]);
            } else {
                return Select(lc[root] , k);
            }
        }
        Type DeleteSelect(int &root,int k) { // 删除第k小元素
            sz[root]--;
            if ( sz[lc[root]] + 1 == k ) {
                Type ret = key[root];
                if (lc[root] == 0 || rc[root] == 0 )
                    root = lc[root] + rc[root];
                else
                    key[root] = Delete(lc[root] , key[root] + 1);
                return ret;
            } else if ( k > sz[lc[root]] ) {
                return DeleteSelect(rc[root] , k - 1 - sz[lc[root]]);
            } else {
                return DeleteSelect(lc[root] , k);
            }
        }
        Type pred(int &root , Type val) { // 查询小于val的最大值
            if (root == 0) {
                return val;
            } else if (val > key[root]) {
                Type ret = pred(rc[root] , val);
                if(ret == val) return key[root];
                return ret;
            } else {
                return pred(lc[root] , val);
            }
        }
        Type succ(int &root , Type val) { // 查询大于val的最小值
            if (root == 0) {
                return val;
            } else if (key[root] > val) {
                Type ret = succ(lc[root] , val);
                if (ret == val) return key[root];
                return ret;
            } else {
                return succ(rc[root] , val);
            }
        }
        void LeftRotate(int &root) {
            int temp = rc[root];
            rc[root] = lc[temp];
            lc[temp] = root;
            sz[temp] = sz[root];
            sz[root] = 1 + sz[lc[root]] + sz[rc[root]];
            root = temp;
        }
        void RightRotate(int &root) {
            int temp = lc[root];
            lc[root] = rc[temp];
            rc[temp] = root;
            sz[temp] = sz[root];
            sz[root] = 1 + sz[lc[root]] + sz[rc[root]];
            root = temp;
        }
        void maintain(int &root , bool flag) {
            if (root == 0) return ;
            if ( !flag ) { // 调整左子树
                if ( sz[lc[lc[root]]] > sz[rc[root]] ) {
                    RightRotate( root );
                } else if ( sz[rc[lc[root]]] > sz[rc[root]] ) {
                    LeftRotate( lc[root] );
                    RightRotate( root );
                } else {
                    return ;
                }
            } else { // 调整右子树
                if ( sz[rc[rc[root]]] > sz[lc[root]] ) {
                    LeftRotate( root );
                } else if ( sz[lc[rc[root]]] > sz[lc[root]] ) {
                    RightRotate( rc[root] );
                    LeftRotate( root );
                } else {
                    return ;
                }
            }
            maintain(lc[root] , false);
            maintain(rc[root] , true);
            maintain(root , false);
            maintain(root , true);
        }
};

sbtree zyc;
int a[50005], b[50005];
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        zyc.clear();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) zyc.Insert(i);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = n - 1; i >= 1; i--)
        {
            a[i] = a[i] - a[i - 1];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            b[i] = zyc.Select(i + 1 - a[i]);
            zyc.Delete(b[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(i != 0) printf(" "); 
            printf("%d", b[i]);
        }
        puts("");
    }
    return 0;
}
