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
VERDICT->ACCEPTED
*/
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        /*
		APPROACH -> only those subarrays will be valid
		in the answer which are [al,al+1,.....,ar]
		where l is the leftmost occurennce 
		position of the element al and r is the rightmost 
		occurence position of the element ar

		//edge don't forget to think about subarrays of size 1.
        */
        vector<int> arr(n);
        input(arr);
        map<int,int> mp;
        vector<int> next(n,1);
        for(int i=n-1;i>=0;i--){
        	if(mp.count(arr[i])){
        		next[i] = 0;
        	}
        	mp[arr[i]]++;
        }
        vector<int> prev(n,1);
        mp.clear();
        for(int i=0;i < n ; i++){
        	if(mp.count(arr[i])){
        		prev[i] = 0;
        	}
        	mp[arr[i]]++;
        }
        
        int ans = 0;
        int cnt = 0;

   	 	//cnt stores those elements in the left which are at
   	 	//their leftmost occurence position
   	 	for(int i=0;i<n;i++){
   	 		if(next[i]){
   	 			ans += cnt;
   	 		}
   	 		if(prev[i]){
   	 			cnt++;
   	 		}
   	 		if(next[i] && prev[i]) ans++;//for 1 size subarr
   	 	}

   	 	cout << ans << endl;
    }
    return 0;
}