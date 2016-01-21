// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlmostEulerianGraph.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

class AlmostEulerianGraph
{
    public:
        int calculateGraphs(int n)
        {
            $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; verify_case(0, Arg1, calculateGraphs(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 0; verify_case(1, Arg1, calculateGraphs(Arg0)); }
	void test_case_2() { int Arg0 = 42; int Arg1 = 29010676; verify_case(2, Arg1, calculateGraphs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlmostEulerianGraph ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
