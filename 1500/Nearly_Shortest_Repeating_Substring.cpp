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
vector<int> fact(int n)
{
	vector<int> ans;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i == 0)
		{
			ans.pb(i);
			if(n/i != i)
				ans.pb(n/i);
		}
	}
	sort(all(ans));
	return ans;
}
signed main(){
	fast_io();
	// intuition -> since we want to concatenate 
	// k occurences of the string to make the original
	// string so string length * k == length of original string
	// this means that string length should be 
	// a factor of the original string length
	// since factors of numbers till 1e5 will be around 150
	// we can easily iterate on all the factors
	// and find the answer 
	// how -> if the answer is 3 length string then
	// either the first 3character string or the 
	// last 3character string must the original 
	// string so we can check for both
	// if any one string satisfy condition of at most
	// 1 different element then that is one possible
	// ans we take min of all such answers
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    vector<int> ans = fact(n);
	    int ff = n;
	    bool flag = true;
	    for(auto a:ans)
	    {

	    	string first = s.substr(0,a);
	    	string second = s.substr(n-a);
	    	int cnt1 = 0;
	    	for(int i=0;i<n;i++)
	    	{
	    		if(s[i] != first[i%a]) cnt1++;
	    	}
	    	int cnt2 = 0;
	    	for(int i=0;i<n;i++)
	    	{
	    		if(s[i] != second[i%a]) cnt2++;
	    	}
	    	
	    	if(cnt1 <= 1 || cnt2 <= 1) 
	    	{
	    		cout << a << endl;
	    		flag = false;
	    		break;
	    	}

	    }
	    if(flag) cout << ff << '\n';
	}
    return 0;
}