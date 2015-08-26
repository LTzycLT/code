// BEGIN CUT HERE

// END CUT HERE
#line 5 "SumOverPermutations.cpp"
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

const ll mod = 1e9+7;

int c[20][20][20];
class SumOverPermutations
{
    public:
        int findSum(int nn)
        {
            int n;
            for(n = 2; n <= 12; n++)
            {
                clr(c, 0);
                vector<int> a;
                for(int i = 0; i < n; i++) a.push_back(i);
                do
                {
                    bool vis[10];
                    clr(vis, 0);
                    int b1 = 0,  b2 = 0, b3 = 0;
                    for(int i = 0; i < n; i++)
                    {
                        int x = n;
                        if(a[i] - 1 >= 0 && vis[a[i] - 1]) x--;
                        if(a[i] + 1 < n && vis[a[i] + 1]) x--;
                        vis[a[i]] = 1;
                        if(x == n) b1++;
                        if(x == n - 1) b2++;
                        if(x == n - 2) b3++;
                    }
                    c[b1][b2][b3]++;
                }while(next_permutation(a.begin(), a.end()));
                for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) if(c[i][j][k] != 0) printf("%d %d %d %d\n", i, j, k, c[i][j][k]);
                puts("");
            }
            return 0;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 66; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 58310114; verify_case(2, Arg1, findSum(Arg0)); }
	void test_case_3() { int Arg0 = 3900; int Arg1 = 940560814; verify_case(3, Arg1, findSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SumOverPermutations ___test;
    ___test.run_test(0);
    system("pause");
}
// END CUT HERE
