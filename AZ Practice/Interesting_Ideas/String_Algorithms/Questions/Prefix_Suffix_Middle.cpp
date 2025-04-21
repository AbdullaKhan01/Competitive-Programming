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

Period 
Formula = N - kmp[last index]


*/

vector<int> kmp(string s){
	int n = s.size();
	vector<int> kmp(n+1);
	int i=0,j=-1;kmp[0] = -1;	
	while(i < n){
		while(j != -1 && s[i] != s[j]) j = kmp[j];
		j++;i++;
		kmp[i] = j;
	}
	return kmp;
}
void solve()
{
	int n;cin >> n;
	string s;cin >> s;
	vector<int> a = kmp(s);
	for(int i=1;i<=n;i++){
		// period is n - kmp[last]
		int p = i - a[i];
		if(i % p == 0 && i != p){
			cout << i << " " << i/p << endl;
		}
	}
	cout << endl;
	// cout << n - a.back() << endl;

}

/*

defdeabcldef
abcledfed

aaaa
T -> _ _ _ x x x x x x _ _ _

// def

// answer if either def ef f

// fed

*/
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    for(int i=1;i<=tt;i++)
    {
    	cout << "Test case #"<<i<<endl;
    	solve();
    }
    return 0;
}