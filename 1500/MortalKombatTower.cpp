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
        vector<int> arr(n);
        input(arr);

        // bro[i] -> min no of skip points to kill bosses from [i,n) if it's bro's move
        // my[i] -> min no of skip points to kill bosses from [i,n) if it's my move
        vector<int> my(n+1),bro(n+1);
        for(int i=n-1;i>=0;i--)
        {
        	{
        		// calculate bro[i]
        		bro[i] = my[i+1] + arr[i];
        		if(i + 2 <= n)
        			bro[i] = min(bro[i],my[i+2]+arr[i]+arr[i+1]);
        	}
        	{
        		// calculate my[i]
        		my[i] = bro[i+1];
        		if(i + 2 <= n)
        			my[i] = min(my[i],bro[i+2]);
        	}
        }
        cout << bro[0] << '\n';
    }
    return 0;
}