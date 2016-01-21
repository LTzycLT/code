// BEGIN CUT HERE

// END CUT HERE
#line 5 "TaroFillingAStringDiv1.cpp"
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

ll mod = 1e9 + 7;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
class TaroFillingAStringDiv1
{
    public:
        int getNumber(int L, vector <int> position, string value)
        {
            int n = position.size();
            ll ans = 1;
            vector<pair<int, int> > a;
            for(int i = 0; i < n; i++) a.push_back(MP(position[i], value[i] - 'A'));
            sort(a.begin(), a.end(), cmp);
            for(int i = 1; i < (int)a.size(); i++)
            {
                int l = a[i - 1].second, r = a[i].second, len = a[i].first - a[i - 1].first - 1;
                if((l == r && len % 2 == 0) || (l != r && len % 2 == 1))
                    ans = ans * (len + 1) % mod; 
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AB"; int Arg3 = 2; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBA"; int Arg3 = 1; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arr1[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBBBABABBAAABA"; int Arg3 = 1; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 305; int Arr1[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABAABBABBAABABBBBAAAABBABBBA"; int Arg3 = 43068480; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TaroFillingAStringDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
