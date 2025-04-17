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
// VERDICT -> ACCEPTED
int solve(string s)
{
	
	int n = s.size();
	int cnt = 0;
	int mini = INT_MAX;
	int a = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'A') a++,cnt++;
		else
		{
			mini = min(mini,cnt);
			cnt=0;
		}
	}
	mini = min(mini,cnt);
	if(s[n-1] == 'B') return a;
	return max(0LL,a-mini);

}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
