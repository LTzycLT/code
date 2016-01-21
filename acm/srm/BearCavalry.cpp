// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearCavalry.cpp"
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

const ll mod = 1e9 + 7;

class BearCavalry
{
    public:
        int countAssignments(vector <int> a, vector <int> b)
        {
            int n = a.size();
            sort(a.begin() + 1, a.end());
            sort(b.begin(), b.end());
            ll ans = 0;
            for(int i = 0; i < n; i++)
            {
                ll c = a[0] * b[i];
                ll tmp = 1;
                for(int j = n - 1; j >= 1; j--)
                {
                    ll sum = 0;
                    for(int k  = 0; k < n; k++)
                    {
                        if(k == i) continue; 
                        if(a[j] * b[k] < c) sum += 1;
                    }
                    sum -= (n - 1 - j);
                    if(sum < 0) sum = 0;
                    tmp =(tmp * sum) % mod;
                }
                ans += tmp; 
                ans %= mod;
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,8,4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19,40,25,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, countAssignments(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, countAssignments(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,2,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,150,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, countAssignments(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, countAssignments(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {20,20,25,23,24,24,21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,25,25,20,25,23,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countAssignments(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,
800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 318608048; verify_case(5, Arg2, countAssignments(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BearCavalry ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
