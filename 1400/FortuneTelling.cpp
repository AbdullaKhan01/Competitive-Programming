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
VERDICT -> ACCEPTED
*/
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        int first = x;
        int second = x+3;
        int cnt = 0;
        /*
		APPROACH -> + and ^(xor) these operations have 
		one thing in common and that is if we add a odd number
		or xor with a odd number then the parity of the 
		number is flipped and adding an even number and 
		xorring with an even number will not flip the 
		parity of the number. Hence the no of odd numbers 
		in the array will tell us whether the parity of the 
		result will be flipped or not and since x and x + 3 
		are of different parities hence only one number will 
		match the parity of the resultant number which is given
		hence we can calculate the answer.
        */
        for(int i=0;i<n;i++){
        	int x;
        	cin >> x;
        	if(x & 1) cnt++;
        }
        cnt = cnt%2;
        if(cnt){
        	first++;
        	second++;
        }
        int alice_bit = 1 & first;
        int cbit = 1 & y;
        if(alice_bit == cbit){
        	cout << "Alice" << endl;
        }
        else{
        	cout << "Bob" << endl;
        }
    }
    return 0;
}