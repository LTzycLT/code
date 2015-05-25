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

 
class TriangleXor
{
public:
	int theArea(int W){


		return int() ;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, theArea(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; verify_case(1, Arg1, theArea(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; verify_case(2, Arg1, theArea(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; verify_case(3, Arg1, theArea(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 2; verify_case(4, Arg1, theArea(Arg0)); }
	void test_case_5() { int Arg0 = 12345; int Arg1 = 4629; verify_case(5, Arg1, theArea(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	TriangleXor ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
