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
   INTUITION -> Basically we don't have the number 4
   available in this special kind of number system
   so we have to find the kth number in this number system

   what we can do is convert the given decimal number 
   to 9 number system and just increase all the elements greater
   than 4 by 1
*/
void decimalto9(int n)
{
      string temp = "";
      while(n != 0)
      {
         int rem = n % 9;
         rem += (rem>=4);
         temp.push_back(rem+48);
         n/=9;  
      }
      reverse(all(temp));
      cout << temp << endl;
}

signed main(){
   fast_io();
   ll tt;
   cin >> tt;
   while(tt--)
   {
      int n;
      cin >> n;
      decimalto9(n);
   } 
   return 0;
}