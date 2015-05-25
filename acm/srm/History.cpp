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

struct edge{
    int u,v,w;
}e[1000000];
int n ,m;
int t[100][100],c[100],d[100];

class History
{
public:
    int getNumber(int &i,string s){
        int w = 0;
        while(i<s.size() && s[i] <= '9' &&  s[i] >= '0'){
            w = w*10+s[i]-'0';
            i++;
        }
        return w;
    }
    char getChar(int &i,string s){
        i++;
        return s[i-1];
    }

    bool bellman(){
        int inf = 100000000;
        for(int i=0;i<=n;i++) d[i] = inf;
        d[n] = 0;

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m+1;j++){
                if(d[e[j].v] > d[e[j].u] + e[j].w)
                    d[e[j].v] = d[e[j].u] +e[j].w;
            }
        }
        for(int j=0;j<=m+1;j++)
            if(d[e[j].v] > d[e[j].u] + e[j].w)
                return 0;
        return 1;
    }
	string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries){
		n = dynasties.size();
        m = 0;
		for(int i=0;i<n;i++) c[i]=0;
		for(int i=0;i<n;i++){
            int j=0;
            string s = dynasties[i];
            while(j<s.size()){
                t[i][c[i]] = getNumber(j,s);
                j++;
                c[i]++;
            }
		}
		for(int i=0;i<n;i++){
            e[m].u = n;
            e[m].v = i;
            e[m++].w = 0;
		}
		string s = "";
		for(int i=0;i<battles.size();i++) s += battles[i];
		for(int j=0;j<s.size();){
            int u = getChar(j,s) - 'A';
            int x = getNumber(j,s);
            j++;
            int v = getChar(j,s) - 'A';
            int y = getNumber(j,s);
            j++;

            e[m].u = u;e[m].v =v;
            e[m++].w = t[u][x+1]-1-t[v][y];

            e[m].u = v;e[m].v =u;
            e[m++].w = t[v][y+1]-1-t[u][x];
		}
		string ans ="";
		for(int i=0;i<queries.size();i++){
            string s = queries[i];
            int j = 0;
            int u = getChar(j,s) - 'A';
            int x = getNumber(j,s);
            j++;
            int v = getChar(j,s) - 'A';
            int y = getNumber(j,s);

            e[m].u = u;e[m].v =v;
            e[m].w = t[u][x+1]-1-t[v][y];

            e[m+1].u = v;e[m+1].v =u;
            e[m+1].w = t[v][y+1]-1-t[u][x];

            if(bellman()) ans += "Y";
            else ans += "N";
		}
		return ans ;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 4",
 "1 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A1-B0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYY"; verify_case(0, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B1-C0 A0-B0 A2-C1 B1-C1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYYYNN"; verify_case(1, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 4 5",
 "10 13 17"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B0 A0-B0 B0-A0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYY"; verify_case(2, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 5 6",
 "1 2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0",
 "-B0 A",
 "1-B1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYY"; verify_case(3, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYNNYNNNY"; verify_case(4, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	History ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
