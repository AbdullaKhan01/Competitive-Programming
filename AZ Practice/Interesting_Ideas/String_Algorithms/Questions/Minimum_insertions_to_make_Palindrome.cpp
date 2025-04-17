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
Question -> Given a String find the minimum number of new
characters that need to be appended at the back of this
string so that it becomes a palindrome
*/


/*

If N length string then definitely we can append characters
such that we can a palindrome string of length 2*N - 1

acbc#cbca

0000

THINK -> aasdkfljasdfknasd++++++

let's say we add x value to make string s a palindrome

then the String S[x]....S[n-1] should be a palindrome 
right ?? think about it

so we basically need to find the length of largest 
palindrome string ending at the index n-1 of the string
so N - len will be the answer

how to find the largest palindrome ending at n-1

do KMP of Reverse(s) + '#' + S

think about it 

Len will be kmp of last index why 
because kmp of last index denotes longest suffix which 
is also a prefix of this string

suffix means ending at the last index of s
and since the prefix will be taken from reverse of S
so that means its also a palindrome 



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