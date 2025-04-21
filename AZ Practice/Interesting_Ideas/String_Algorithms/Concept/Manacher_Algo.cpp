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
Manacher Algo -> Find length of Longest Palindromic
String considering that index as the Center of the 
Palindrome

so if M[i] = 4 -> this means that there is a 4 length
string which is a palindrome and at whose center is the 
index i

Mostly Used as Black Box

Eg -> abaab
What do we do
make a new String 
#a#b#a#a#b#
Now find its manacher array

M = [0 1 0 3 0 1 4 1 0 1 0]

No of Palindromic Substrings in a String = 
Summation 0 to 2*n (Manacher[i]+1)/2
*/
void solve()
{
	
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}