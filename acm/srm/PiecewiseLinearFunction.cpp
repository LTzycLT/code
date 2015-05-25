#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;
const double eps = 1e-6 ;
class PiecewiseLinearFunction
{
public:
	int maximumSolutions(vector <int> Y){
        int ans = 0;
        for(int i=0;i<Y.size()-1;i++)
            if(Y[i] == Y[i+1]) return -1;

        for(int i=0;i<Y.size();i++){
            int x = Y[i];
            int tmp = 0;
            for(int j=0;j<Y.size()-1;j++){
                int s = Y[j] , t = Y[j+1];
                if(s>t) swap(s,t);
                if(x<=t && x>=s) tmp++;
            }
            for(int j=1;j<Y.size()-1;j++)
                if(Y[j] == x)
                    tmp--;
            ans = max(ans,tmp);

            tmp = 0;
            for(int j=0;j<Y.size()-1;j++){
                int s = Y[j] , t = Y[j+1];
                if(s>t) swap(s,t);
                if(x<t && x>=s) tmp++;
            }
            ans = max(ans,tmp);

            tmp = 0;
            for(int j=0;j<Y.size()-1;j++){
                int s = Y[j] , t = Y[j+1];
                if(s>t) swap(s,t);
                if(x<=t && x>s) tmp++;
            }
            ans = max(ans,tmp);
        }

		return ans ;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximumSolutions(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, maximumSolutions(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 4, -1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumSolutions(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 1, 2, 1, 3, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSolutions(Arg0)); }
	void test_case_4() { int Arr0[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, maximumSolutions(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	PiecewiseLinearFunction ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
