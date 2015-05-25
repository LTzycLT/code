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

ll num[500000],tmp[500000];
class RandomApple
{
public:
    int n,K;
    int a[50][50],sum[50];
	double b[50];
	vector<double> ans;
	vector <double> theProbability(vector <string> hundred, vector <string> ten, vector <string> one){
        clr(b,0);clr(num,0);clr(sum,0);clr(a,0);
        n = hundred.size();
        K = hundred[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<K;j++){
                a[i][j] = (hundred[i][j]-'0')*100 + (ten[i][j]-'0')*10 + one[i][j]-'0';
                sum[i] += a[i][j];
            }
        int maxx = 0;
        for(int i=0;i<n;i++){
            for(int j=maxx;j>=0;j--){
                if(num[j]){
                    num[j+sum[i]] += num[j];
                }
            }
            num[sum[i]]++;
            maxx += sum[i];
        }
        for(int i=0;i<n;i++){
            memcpy(tmp,num,sizeof(num));
            for(int j=maxx;j>=0;j--){
                if(tmp[j] && j-sum[i]>0){
                    tmp[j-sum[i]] -= tmp[j];
                }
            }
            for(int j=1;j<=maxx;j++)
                b[i] += tmp[j]*1.0/j;
        }

        ll total = (1LL<<n)-1;
        ans.clear();
		for(int i=0;i<K;i++){
            double tmp = 0;
            for(int j=0;j<n;j++)
                tmp += a[j][i] * b[j] /total;
            ans.push_back(tmp);
		}
		return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"58"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.38461538461538464, 0.6153846153846154 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"00", "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"21", "11"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.5888888888888889, 0.4111111111111111 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0000", "0000", "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2284", "0966", "9334"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1090", "3942", "4336"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.19685958571981937, 0.24397246802233483, 0.31496640865458775, 0.24420153760325805 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"01010110", "00011000", "00001000", "10001010", "10111110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"22218214", "32244284", "68402430", "18140323", "29043145"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"87688689", "36101317", "69474068", "29337374", "87255881"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.11930766223754977, 0.14033271060661345, 0.0652282589028571, 0.14448118133046356, 0.1981894622733832, 0.10743462836879789, 0.16411823601857622, 0.06090786026175882 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {1.0, 0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, theProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	RandomApple ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
