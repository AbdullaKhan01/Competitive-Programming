// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
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
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// int sum(int k)
// {
// 	return(k*(k+1))/2;
// }
// int check(int mid,int l,int r)
// {
// 	// int mid = s;
// 	int a = sum(mid) - sum(l-1);
// 	int b = sum(r) - sum(mid);
// 	return abs(a-b);
// }
// void solve4()
// {
// 	int a,b;
// 	cin >> a >> b;
// 	int ans = LLONG_MAX;
// 	for(int i=a;i<=b;i++)
// 	{
// 		ans = min(ans,(i-a) + (b-i));
// 	}
// 	cout << ans << endl;
// }
// void solve3()
// {
// 	int n;
// 	cin >> n;
// 	vector<string> a(n);
// 	input(a);
// 	for(int i=n-1;i>=0;i--)
// 	{
// 		int idx = 1;
// 		for(auto it:a[i])
// 		{
// 			if(it == '#')
// 			{
// 				cout << idx << " ";
// 				break;
// 			}
// 			idx++;
// 		}
// 	}
// 	cout << endl;

// }
// void solve2()
// {
// 	int a,b,k;
// 	cin >> a >> b >> k;

// 	int x = ceil(a,k);
// 	int y = ceil(b,k);

// 	int ans = 2 * max(x,y);
// 	if(x > y) ans--;
// 	cout << ans << endl;
// }
// void solve()
// {
// 	int l , x;
// 	cin >> x >> l;
// 	int r = l + x - 1;

// 	// cout << l << " " << r << endl;
// 	int s = l , e = r;
// 	// int ans = -1;
// 	while(s <= e)
// 	{
// 		int mid = (s+e)/2;
// 		int k1 = sum(mid) - sum(l-1);
// 		int k2 = sum(r) - sum(mid);
// 		if(k1 - k2 < 0)
// 		{
// 			s = mid+1;
// 		}
// 		else
// 		{
// 			e = mid-1;
// 		}
// 	}
// 	int ans = min(check(s,l,r),check(s-1,l,r));
// 	cout << ans << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve4();
//     }
//     return 0;
// }

#include <iostream> 
#include <bits/stdc++.h> 
#define int long long int 
using namespace std; 
signed main(){ 
    int t;cin>>t; 
    while(t--){ 
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
        	cin >> a[i];
        }
        int ans = a[n-1];
        for(int k=n-2;k>=0;k--){
        	if(a[k] > a[k-1])
        }
    }
}

// 4 4 4 4
// 4 4 4 3
// 4 4 3 2 
// 4 3 2 1
// 4 operations

// 4 4
// 4 3
// 4 

// a>b<c>d<e
// // c will take c->c-d seconds to become equal to
// 7 4 4 3 2
// 6 4 3 2 1
// 5 3 2 1 0
// 4 2 1 0 0
// 

// else cout << i << " " << j << " " << r << " " << k << endl;