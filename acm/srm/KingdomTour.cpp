#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define clr(x,y) memset(x,y,sizeof(x))
#define Min(x,y) if(y<x) x=y
#define Max(x,y) if(y>x) x=y
using namespace std ;
typedef long long ll ;
const double eps = 1e-6 ;

const int inf = 1e8;
vector<int> ev[205],ew[205];
int dp[205][105][2],p[105][2];
string s = "";
int K,L;

class KingdomTour
{
public:

    void dfs(int u,int f){
        for(int i=0;i<=K;i++) dp[u][i][0] = dp[u][i][1] = 0;

        for(int i=0;i<(int)ev[u].size();i++){
            int v = ev[u][i];
            int w = ew[u][i];
            if(v==f) continue;
            dfs(v,u);

            for(int i=0;i<=K;i++) p[i][0] = p[i][1] = inf;
            for(int i=0;i<=K;i++)
                for(int j=0;j<=K;j++)
                    if(i+j<=K){
                        Min(p[i+j+1][0],dp[u][i][0]+dp[v][j][0]+L+w);
                        Min(p[i+j][0],dp[u][i][0]+dp[v][j][1]+2*w);

                        Min(p[i+j][0],dp[u][i][1]+dp[v][j][0]+w);

                        Min(p[i+j][1],dp[u][i][1]+dp[v][j][1]+2*w);
                        Min(p[i+j+1][1],dp[u][i][1]+dp[v][j][0]+w+L);

                        Min(p[i+j+1][1],dp[u][i][0] + dp[v][j][0]+L+w);
                    }

            for(int i=0;i<=K;i++){
                dp[u][i][0] = p[i][0];
                dp[u][i][1] = p[i][1];
            }
        }
    }
	void get(int &w,int &i){
	    w = 0;
	    while(i<(int)s.size() && s[i]<='9' && s[i]>='0'){
            w = w*10 +s[i]-'0';
            i++;
	    }
        i++;
	}
	int minTime(int N, vector <string> roads, int K, int L){
	    ::K = K;
	    ::L = L;
	    s = "";
        for(int i=0;i<(int)roads.size();i++) s += roads[i];
        for(int i=0;i<N;i++) ev[i].clear(),ew[i].clear();
        int l = 0;
        while(1){
            int u,v,w;
            get(u,l);
            get(v,l);
            get(w,l);
            ev[u].push_back(v);ew[u].push_back(w);
            ev[v].push_back(u);ew[v].push_back(w);
            if(l>=(int)s.size()) break;
        }
        dfs(0,0);
        int ans = inf;
        for(int i=0;i<=K;i++) ans = min(ans,dp[0][i][1]);
		return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"2 1 9,0 1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; int Arg4 = 16; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"0 1 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; int Arg4 = 7; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"4 0 4,2 0 4,2 5 4,4 3 1",
 "0,1 2 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; int Arg4 = 41; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"1 2 2,4 1 9,2 5 5,6 5 4,", "1 7 7,7 3 1,2 0 2", ",5 8 5,9 5 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 59; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	KingdomTour ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
