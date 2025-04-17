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
        string s;
        cin >> s;
        string g = s.substr(0,2);
        string m = s.substr(2,5);
        int a = stoi(g);
        if(g == "00"){
        	s[0] = '1';
        	s[1] = '2';
        	cout << s << " AM" << endl;
        	continue;
        }
        if(a == 12){
        	cout << s << " " << "PM" << endl;
        }
        else if(a > 12){
        	int k = a - 12;
        	string aa = to_string(k);
        	if(aa.size () == 1) aa = "0"+aa;
        	aa = aa+m+" PM";
        	cout << aa << endl;
        }
        else{
        	cout << s << " AM" << endl;
        }
    }
    return 0;
}