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
    int n;
    cin >> n;
    vi arr(n);
    int brr[5] = {0};
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
    	cin >> arr[i];
    	mp[arr[i]]++;
    	int freq = mp[arr[i]];
    	if(freq != 0 && freq % 4 == 0)
    	{	
    		brr[4]++;
    	}
    	if(freq != 0 && freq % 2 == 0)
    	{
    		brr[2]++;
    	}
    }
    int q;
    cin >> q;

    while(q--)
    {
    	char a;
    	int b;
    	cin >> a >> b;
    	if(a == '+')
    	{
    		mp[b]++;
    		if(mp[b]%4 == 0) brr[4]++;
    		if(mp[b]%2 == 0) brr[2]++;
    		if(brr[4] >= 2 || (brr[4] == 1 && brr[2] >= 4))
    		{
    			cout << yes << endl;
    		}
    		else{
    			cout << no << endl;
    		}
    	}
    	else
    	{
    		if(mp[b]%4 == 0) brr[4]--;
    		if(mp[b]%2 == 0) brr[2]--;
    		mp[b]--;
    		if(brr[4] >= 2 || (brr[4] == 1 && brr[2] >= 4))
    		{
    			cout << yes << endl;
    		}
    		else{
    			cout << no << endl;
    		}
    	}
    }
    return 0;
}

