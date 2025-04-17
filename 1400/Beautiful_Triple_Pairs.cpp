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
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        vector<map<pair<int,int>,int>> db(4);
        map<vector<int>,int> triple;
        int ans = 0;
        for(int i=2;i<n;i++)
        {
        	int a = arr[i-2];
        	int b = arr[i-1];
        	int c = arr[i];
        	int freq = 0;
        	if(triple.find({a,b,c}) != triple.end()) freq = triple[{a,b,c}];
        	if(db[1].find({a,b}) != db[1].end())
        	{
        		ans += db[1][{a,b}] - freq;
        	}
        	if(db[2].find({b,c}) != db[2].end())
        	{
        		ans += db[2][{b,c}] - freq;
        	}
        	if(db[3].find({a,c}) != db[3].end())
        	{
        		ans += db[3][{a,c}] - freq;
        	}
        	db[1][{a,b}]++;
        	db[2][{b,c}]++;
        	db[3][{a,c}]++;
        	triple[{a,b,c}]++;
        }
        cout << ans << endl;
    }
    return 0;   
}

// 1 4 3 2 2 3 4 5