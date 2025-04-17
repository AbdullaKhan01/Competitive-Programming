#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        string s(n,'a');
        if(k == 1){
        	s[n-1] = s[n-2] = 'b';
        	cout << s << endl;
        	continue;
        }
        int ans;
        int st = 2 , e = n;
        while(st <= e){
        	int mid = (st+e)/2;
        	int p = (mid*(mid+1))/2;
        	if( (p-k) >=0 && (p-k) <= p){
        		ans = mid;
        		e = mid - 1;
        	}
        	else{
        		st = mid + 1;
        	}
        }
        int g = (ans*(ans+1))/2;

        s[n-1-ans] = 'b';
        s[n-ans+(g-k)] = 'b';
        cout << s << endl;
    }
    return 0;
}