// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// void solve()
// {
// 	int n,m;
// 	cin >> n >> m;
// 	string s;
// 	cin >> s;
// 	vector<int> a(n),pref(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		// cin >> a[i];
// 		if(i == 0)
// 		{
// 			pref[i] = (s[i] == '1');
// 		}
// 		else
// 		{
// 			pref[i] = pref[i-1] + (s[i] == '1');
// 		}
// 	}
// 	vector<int> one,zero;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(s[i] == '1') one.pb(i);
// 		else zero.pb(i);
// 	}
// 	set<pair<int,int>> st;
// 	while(m--)
// 	{
// 		int l,r;
// 		cin >> l >> r;
// 		l--,r--;
// 		// let's say we have some part between 
// 		// l and r which is not sorted that is the difference
// 		// maker let that part be [lx,rx]

// 		// so we want to find the index of last zero in [lx,rx]
// 		// and we want to find the index of first one in [lx,rx]

// 		// this part when sorted makes a unique string to just
// 		// insert this in the set and in the end the size of the
// 		// set is our final answer
// 		int cntone = pref[r];
// 		if(l > 0) cntone -= pref[l-1];

// 		if(cntone==(r-l+1) || cntone == 0)
// 		{
// 		 	st.insert({-1,-1});
// 		 	continue;
// 		}

// 		int first_one = lower_bound(all(one),l) - one.begin();
// 		int last_zero = upper_bound(all(zero),r) - zero.begin();

// 		first_one = one[first_one];
// 		last_zero--;
// 		last_zero = zero[last_zero];

// 		if(last_zero > first_one)
// 		{
// 			// this is the unique range
// 			st.insert({first_one,last_zero});
// 		}
// 		else st.insert({-1,-1});
// 	}
// 	cout << st.size() << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> pref(n+1,0);
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		pref[i+1] = pref[i] + a[i];
	}
	set<int> st;
	st.insert(0);
	int prev = 0;
	for(int i=1;i<=n;i++)
	{
		if(st.count(pref[i]-prev))
		{
			prev = pref[i];
			cnt++;
			set<int> nst;
			nst.insert(0);
			st = nst;

		}
		else st.insert(pref[i] - prev);
	}
	cout << cnt << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}