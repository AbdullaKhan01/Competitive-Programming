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
	// fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        sort(all(arr));

        vector<int> s;
        int cnt = 1;
        int maxi = INT_MIN;
        for(int i=1;i<n;i++){
        	if(arr[i] == arr[i-1]){
        		cnt++;
        	}
        	else{
        		s.pb(cnt);
        		maxi = max(maxi,cnt);
        		cnt = 1;
        	}
        }
        maxi = max(maxi,cnt);
        s.pb(cnt);
        sort(all(s));
        // output(s);
        int n1 = s.size();
        int sum = 0;
        for(int i=n1-1;i>=0;i--){
            if(maxi <= 0) break;
            if(s[i] >= maxi){
                sum += maxi;
                maxi--;
            }
            else{
                sum += s[i];
                maxi = s[i] - 1;
            }

        }
        cout << sum << endl;
    }
    return 0;
}