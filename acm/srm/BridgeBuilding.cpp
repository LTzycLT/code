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

 
class BridgeBuilding
{
public:
	int minDiameter(vector <int> a, vector <int> b, int K){


		return int() ;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,9,1,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 43; int Arg3 = 42; verify_case(1, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50,10,15,31,20,23,7,48,5,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,8,3,2,16,11,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 124; verify_case(2, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {50,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 17; verify_case(3, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {2,4,10,2,2,22,30,7,28,14,17,6,32,41,1,3,16,20,40,39,6,4,18,3,3,7,
 3,2,2,14,10,6,38,6,13,3,6,1,23,26,9,17,1,38,1,21,2,12,3,13,28,6,4,
10,3,1,1,43,15,11,18,6,41,1,2,5,6,26,43,9,5,13,1,27,1,33,12,16,1,12,
1,37,34,6,20,3,21,3,1,17,3,10,2,1,8,25,2,6,7,1,7,22,11,8,49,9,1,7,1,
13,17,20,27,31,43,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,26,1,2,6,2,16,3,15,1,1,38,2,4,6,1,2,3,11,2,2,2,25,16,2,15,45,3,10,
4,17,5,6,1,16,13,29,3,1,2,4,47,4,10,1,2,23,3,29,20,4,21,1,28,7,25,6,6,
10,1,2,1,17,6,1,28,2,2,12,2,3,42,39,11,18,3,15,4,1,15,3,9,4,26,4,13,41,
1,27,1,14,1,2,14,5,33,1,34,5,17,23,3,33,14,23,2,29,18,3,41,1,45,5,4,6,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 1184; verify_case(4, Arg3, minDiameter(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	BridgeBuilding ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
