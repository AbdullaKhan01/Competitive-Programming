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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        string l = s;
        string target;
        cin >> target;
        for(int i=0;i<n;i++){
        	if(s[i] != target[i]){
        		if(i+3 < n && s[i+3] == target[i]){
        			swap(s[i],s[i+3]);
        		}
        		else if(i+4 < n && s[i+4] == target[i]){
        			swap(s[i],s[i+4]);
        		}
        	}
        }for(int i=n-1;i>=0;i--){
        	if(l[i] != target[i]){
        		if(i-3 >=0 && l[i-3] == target[i]){
        			swap(l[i],l[i-3]);
        		}
        		else if(i-4 >=0 && l[i+4] == target[i]){
        			swap(l[i],l[i-4]);
        		}
        	}
        }
        cout << s << " " << l << endl;
        cout << (s == target||l==target?yes:no) << endl;
    }
    return 0;
}