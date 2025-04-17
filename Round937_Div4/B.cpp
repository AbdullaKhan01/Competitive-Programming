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
char flip(char a){
	if(a == '#') return '.';
	else return '#';
}

signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        char g = '#';
        // solve(n);
        string a;
        for(int i=0;i<n;i++){
        	a.push_back(g);
        	a.push_back(g);
        	g = flip(g);
        }
        string b;
        for(int i=0;i<a.size();i++){
        	if(a[i] == '#') b.push_back('.');
        	else if(a[i] == '.') b.push_back('#');
        }
        vector<string> m(2*n);
        for(int i=0;i<2*n;i+=2){
        	m[i] = m[i+1] = a;
        	swap(a,b);
        }
        for(auto it:m){
        	cout << it << endl;
        }
        // vector<vector<char>> arr(2*n,vector<char>(2*n,' '));
        // char g = '.';
        // for(int i=0;i<2*n;i+=2){
        // 	g = flip(g);
        // 	for(int j=0;j<2*n;j+=2){
        // 		g = flip(g);
        // 		arr[i][j] = arr[i+1][j] = arr[i][j+1] = arr[i+1][j+1]=char(g);
        		
        // 	}
        // 	// g = flip(g);
        // 	// cout << endl;
        // }
        // for(int i=0;i<2*n;i++){
        // 	for(int j=0;j<2*n;j++){
        // 		cout << arr[i][j];
        // 	}
        // 	cout << endl;
        // }
        // cout << endl;
    }
    return 0;
}