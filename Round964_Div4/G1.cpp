// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// // #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// // #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// signed main(){
// 	fast_io();
// 	int tt;
// 	cin >> tt;
// 	while(tt--)
// 	{
// 	    auto ask = [&](int a,int b){
// 	    	cout << "? " << a << " " << b << endl;
// 	    	fflush(stdout);
// 	    	int x;
// 	    	cin >> x;
// 	    	return x;
//     	};
// 	    int s = 1 , e = 1000;
// 	    while(s <= e)
// 	    {
// 	    	int mid = (s+e)/3;
// 	    	int query = ask(1,mid);
// 	    	if(query > mid)	
// 	    	{
// 	    		e = mid - 1;
// 	    	} 
// 	    	else
// 	    	{
// 	    		s = mid + 1;
// 	    	}
// 	    }
// 	    cout << "! " << s << endl;
// 	}
    
//     return 0;
// }
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
vector<vector<char>> solution(vector<vector<char>> table){
		int n = table[0].size();
	    char intermediateTable[2*n][2*n];
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < n; j++) {
                intermediateTable[2 * n - i / 2 - j - 1][2 * n - 3 - i % 2 - i / 2 + j] = table[i][j];
            }
        }
        vector<vector<char>> rhombusCipher(2*n,vector<char>(n));
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < n; j++) {
                rhombusCipher[i][j] = intermediateTable[2 * n - i / 2 - j - 1][2 * n - 4 + i % 2 + i / 2 - j];
            }
        }
        return rhombusCipher;
}

void solve()
{
	vector<vector<char>> table = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r'}};
	vector<vector<char>> ans = solution(table);
	for(auto it : ans){
		for(auto i : it){
			cout << i << " ";
		}
		cout << endl;
	}
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}