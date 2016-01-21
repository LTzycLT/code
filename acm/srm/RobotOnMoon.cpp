// BEGIN CUT HERE
// END CUT HERE
#line 96 "RobotOnMoon.cpp"
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

class RobotOnMoon
{
    public:
        int longestSafeCommand(vector <string> board)
        {
            int n = board.size(), m = board[0].size();
            int si, sj;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(board[i][j] == 'S')
                        si = i, sj = j;
            for(int i = 0; i < n; i++) if(board[i][sj] == '#') return -1;
            for(int j = 0; j < m; j++) if(board[si][j] == '#') return -1;
            return n + m - 2; 
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, longestSafeCommand(Arg0)); }
	void test_case_1() { string Arr0[] = {"S......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, longestSafeCommand(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, longestSafeCommand(Arg0)); }
	void test_case_3() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, longestSafeCommand(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RobotOnMoon ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
