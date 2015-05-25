#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define INC(x,y) {x = (x+y);if(x>=mod) x-=mod;}
#define Min(x,y) {if(y<x) x=y;}
#define Max(x,y) {if(y>x) x=y;}
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;
const double eps = 1e-6 ;
const int inf = 1e8;

ll dp[1<<18][40];
class TheBoardingDivOne
{
public:
    int n;
    bool check(int mask,int l){
        int has = 0;
        for(int i=l-1;i>=0;i--)
            if((mask>>i)&1)
                has = 1;
        if(has){
            for(int i=l+1;i<n;i++)
                if(!((mask>>i)&1))
                    return false;
        }
        return true;
    }
    void calc(int mask,int x,int y){
        if(!((mask>>y)&1)) return;
        int sub = mask - (1<<y);
        if(!check(mask,y))
            return;
        int nval = y + n - x;
        for(int i=0;i<40;i++){
            dp[mask][max(nval,i)] += dp[sub][i];
        }
    }
	long long find(vector <int> p, int T){
        n = p.size();
        int tot = (1<<n);
        clr(dp,0);
        dp[0][0] = 1;
        for(int mask=1;mask<tot;mask++){
            int x = 0;
            for(int i=0;i<n;i++) if((mask>>i)&1) x++;
            x = n-x;
            int y = p[x];
            if(y == -1){
                for(int i=0;i<n;i++)
                    calc(mask,x,i);
            }
            else{
                calc(mask,x,y-1);
            }
        }
        tot--;
        ll ans = 0;
        bool flag=1;
        for(int i=0;i<n;i++)
            if(p[i]!=-1 && p[i]!=i+1)
                flag = 0;
        if(flag)
            dp[tot][n]--;
        for(int i=0;i<40;i++){
            if(148+i<=T)
                ans+=dp[tot][i];
        }
        if(flag && 74+n<=T)
            ans++;
		return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 =100; long long Arg2 = 1LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 2, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 222; long long Arg2 = 1LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 1, 3, 5, 4, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 155; long long Arg2 = 1LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 198; long long Arg2 = 233LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	TheBoardingDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
