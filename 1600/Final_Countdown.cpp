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
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        // 12345
        // 12345 
        //  1234
        //   123
        //    12
        //     1
        // 5 + 1234(1) + 123 

        // 42
        // 42
        //  4

        // 99 
        // 99
        //  9

        int n;
        cin >> n;
        string s;
        cin >> s;
        vi pref(n+1,0);
        for(int i=0;i<n;i++)
        {
        	int digit = s[i] - '0';
        	pref[i+1] = pref[i] + digit;
        }
        string ans(n,' ');
        int carry = 0;
        for(int i=n;i>=1;i--)
        {
        	// ans[i-1] digit 
        	int sum = pref[i] + carry;
        	int digit = sum % 10;
        	carry = sum / 10;
        	ans[i-1] = (digit+'0');
        }
        if(carry != 0)
        {
        	string s = to_string(carry);
        	ans = s + ans;
        }
        while(ans.front() == '0')
        {
        	ans.erase(0,1);
        }
        cout << ans << endl;
    }
    return 0;
}



// 1 - 1000 L = 1 R = 1000 MID = 500
// 1 - 500

// 1 - 1000 L1 = 300 L2 = 