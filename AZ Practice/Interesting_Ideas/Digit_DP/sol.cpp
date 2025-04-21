#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/

/*

In digit DP one thing to take care of is that 
L and R should be of the same length and if they are not
then u should pad some zeroes in front of L to make it 
equal in length to R because we want the digit of L and 
R both at some position in the number to make the DP
transitions

Think of Numbers forming at Trie

we can bound some edges of the Trie as Blue Edges and
Red Edges 

Blue means cannot go to the left of this edge

Red means cannot go to the right of this edge

how is DP applicable in such questions the answer is

if we do not have any restriction some suffix after taking
some digits then the answer would be same for both of 
the sub problems for eg

find No of Odd numbers between 123292832 and 982327232
and lets say the 
we have taken two numbers as 25 _ _ _ _ _ _ _
and 						 26 _ _ _ _ _ _ _

now there is no restriction on the next numbers 
since they will always be greater than l and less than
r 

the answer of both the subproblems will be same because
the both are equally free from digit restrictions

*/

/*

Question Atcode DP Contest S - Digit Sum


*/


string L,R;
int D;
int len;
int dp[10010][2][2][100];
// tlo = tight low
// thi = tight high

int rec(int level,int tlo,int thi,int sumD){
	// pruning nothing
	// base case
	if(level == len){
		if(sumD == 0) return 1;
		else return 0;
	}
	// cache check
	if(dp[level][tlo][thi][sumD] != -1){
		return dp[level][tlo][thi][sumD];
	}
	// compute 
	int ans = 0;
	int lo = 0;
	if(tlo == 1) lo = L[level] - '0';

	int hi = 9;
	if(thi == 1) hi = R[level] - '0';

	for(int i=lo;i<=hi;i++){
		int ntlo = tlo;
		if(i != L[level]-'0') ntlo = 0;

		int nthi = thi;
		if(i != R[level]-'0') nthi = 0;

		ans += rec(level+1,ntlo,nthi,(sumD + i)%D);
		ans %= mod;
	}
	// save and return
	return dp[level][tlo][thi][sumD] = ans;
}

int rec2(int level,int thi,int tlo,int last3){
	// pruning nothing
	// base case
	if(level == len){
		if(last3 == 0) return 1;
		else return 0;
	}
	// cache check
	if(dp[level][tlo][thi][sumD] != -1){
		return dp[level][tlo][thi][sumD];
	}
	// compute 
	int ans = 0;
	int lo = 0;
	if(tlo == 1) lo = L[level] - '0';

	int hi = 9;
	if(thi == 1) hi = R[level] - '0';

	for(int i=lo;i<=hi;i++){
		int ntlo = tlo;
		if(i != L[level]-'0') ntlo = 0;

		int nthi = thi;
		if(i != R[level]-'0') nthi = 0;

		ans += rec2(level+1,ntlo,nthi,(sumD + i)%D);
		ans %= mod;
	}
	// save and return
	return dp[level][tlo][thi][sumD] = ans;
}
void solve(){
	cin >> R;
	cin >> D;
	len = R.size();
	// make L and R length equal
	L = "1";
	string temp;
	while(temp.size() + L.size() < R.size()) temp += '0';
	L = temp + L;

	memset(dp,-1,sizeof(dp));
	cout << rec(0,1,1,0) << endl;

}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}