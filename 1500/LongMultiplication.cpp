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
// let's say there are two numbers
        // abcdefg 
        // xyzjklm
        // such that a > x

        // for eg
        // 894 
        // 356

        // 894*356 - 896*354 if > 0 then don't swap
        // else swap the digits 
        
        // 894*356 = (896-2) * 356 = 896*356 - 2*356
        // 896*354 = 896 * (356-2) = 896*356 - 2*896


        // 89 * 35 = (85+4) * 35 = 85*35 + 4*35
        // either this or
        // 85 * 39 = 85*35 + 4*85
        
        // which number is greater == 

        // when will be swap the ith digit is this the real
        // question or something else ? ? ? ? ? ? ? 
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string a,b;
        cin >> a >> b;
        int n = (int)a.size();
        int idx = 0;
        for(int i=0;i<n;i++)
        {
        	if(a[i] > b[i])
        	{
        		idx = i;
        		break;
        	} 
        	else if(b[i] > a[i])
        	{
        		idx = i;
        		swap(a,b);
        		break;
        	}
        }
        for(int i=n-1;i>idx;i--)
        {
        	if(a[i] > b[i])
        	{
        		swap(a[i],b[i]);
        	}
        }
        cout << a << '\n' << b << '\n';
    }
    return 0;
}