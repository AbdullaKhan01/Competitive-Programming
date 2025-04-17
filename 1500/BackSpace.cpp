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

//VERDICT -> ACCEPTED

// intuition -> to remove any middle part
// of the string that part must be even size
// because in one backspace operation two
// characters are removed at a time 



bool solve(string &s,string &t,int st)
{
	if(st == -1) return false;
	int n = s.size() , m = t.size();
	int i = st+1 , j = 1;
	int prev = st;
	for(;i<n;i++)
	{
		if(j>=m) break;
		if(s[i] == t[j])
		{
			if((i-prev+1) % 2 == 0)
			{
				j++;
				prev = i;
			}
		}
	}
	return j>=m && (n-i)%2==0;
}
bool my(string s,string t)
{

        int a = -1 , b = -1;
        vector<int> check;
        for(int i=s.size()-1;i>=0;i--)
        {
        	if(s[i] == t[0])
        	{
        		if(i%2 == 0) a = i;
        		else b = i;
        	}
        }
        check.pb(a);
        check.pb(b);
        bool ans = false;
        for(auto it:check)
        {
        	ans |= solve(s,t,it);
        }
        return ans;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
    	string s,t;
    	cin >> s >> t;
        cout << (my(s,t)?yes:no) << endl;
    }
    return 0;
}