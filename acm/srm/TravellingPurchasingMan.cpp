#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;
const double eps = 1e-6 ;

int inf = 1000000000;
struct item{
    int u,rt,d;
    item(int u,int rt,int d):u(u),rt(rt),d(d){}
    bool operator<(item A)const{
        return d>A.d;
    }
};
int n,m;
int d[100][1<<16];
bool vis[100][1<<16];
int s[100],t[100],dur[100];
vector<int> ev[100],ew[100];
priority_queue<item> q;

class TravellingPurchasingMan
{
public:
    int dij(){
        for(int i=0;i<n;i++)
            for(int j=0;j<(1<<m);j++){
                d[i][j] = inf;
                vis[i][j] = 0;
            }
        while(!q.empty()) q.pop();
        d[n-1][0] = 0;
        q.push(item(n-1,0,0));
        while(!q.empty()){
            item temp = q.top();
            q.pop();
            int u = temp.u;
            int rt = temp.rt;
            if(vis[u][rt]) continue;
            vis[u][rt] = 1;

            if(u<m && ((rt>>u)&1) == 0&& d[u][rt]<=t[u]){
                int w = max(d[u][rt],s[u]) + dur[u];
                int nrt = (rt|((1<<u)));
                if(d[u][nrt] > w){
                    d[u][nrt] = w;
                    q.push(item(u,nrt,w));
                }
            }

            for(int i=0;i<(int)ev[u].size();i++){
                int v = ev[u][i];
                int w = ew[u][i];
                if(d[v][rt] > d[u][rt] + w){
                    d[v][rt] = d[u][rt] + w;
                    q.push(item(v,rt,d[v][rt]));
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(1<<m);j++)
                if(d[i][j] < inf){
                    int tmp = 0;
                    for(int k=0;k<m;k++)
                        if((j>>k)&1)
                            tmp++;
                    ans = max(ans,tmp);
                }
        }
        return ans;

    }

    int getInt(int &i,string s){
        int res = 0 ;
        while(s[i]>='0' && s[i] <='9'){
            res = res*10+s[i]-'0';
            i++;
        }
        return res;
    }
	int maxStores(int N, vector <string> interestingStores, vector <string> roads){
//        interestingStores.clear();
//        roads.clear();

//        N = 4;
//        interestingStores.push_back("2 2 0");
//        interestingStores.push_back("4 4 0");
//        interestingStores.push_back("6 6 0");
//        interestingStores.push_back("0 0 0");
//
//        roads.push_back("3 0 1");
//        roads.push_back("3 1 1");
//        roads.push_back("3 2 1");


        n = N;
        m = interestingStores.size();
        for(int i=0;i<m;i++){
            int j=0;
            string str = interestingStores[i];
            s[i] = getInt(j,str);
            j++;
            t[i] = getInt(j,str);
            j++;
            dur[i] =getInt(j,str);
        }
        for(int i=0;i<n;i++){
            ev[i].clear();
            ew[i].clear();
        }
        for(int i=0;i<(int)roads.size();i++){
            string str = roads[i];
            int j=0;
            int u,v,w;
            u = getInt(j,str);
            j++;
            v = getInt(j,str);
            j++;
            w = getInt(j,str);
            ev[u].push_back(v);ew[u].push_back(w);
            ev[v].push_back(u);ew[v].push_back(w);
        }
		return dij();
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"0 1000 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	TravellingPurchasingMan ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
