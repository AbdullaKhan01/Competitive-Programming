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

void print(priority_queue<int,vector<int>,greater<int>>pq)
{
	cout << pq.size() << endl;
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        vi arr(k);
        input(arr);
        // output(arr);
        // cout << endl;
        int o = 0;
        // for(auto it:arr)
        // {
        // 	cout << it << " ";
        // 	if(it != 1) pq.push(it);
        // 	else o++;
        // }
        // print(pq);
        // for(int i=0;i<k;i++)
        // {
        // 	if(arr[i] != 1) pq.push(arr[i]);
        // 	else o++;
        // }
        sort(all(arr));
        int piece = k;
        int count = 0;
        for(int i=k-2;i>=0;i--)
        {
        	if(arr[i] == 1) break;
        	piece += (arr[i]-1);
        	count += (arr[i]-1);
        }
        // cout << pi
        // while(!pq.empty() && o < n-1)
        // {
        // 	int top = pq.top();
        // 	pq.pop();
        // 	o++;
        // 	piece++;
        // 	count++;
        // 	if(top-1 != 1)
        // 		pq.push(top-1);
        // }
        cout << count+(piece-1) << endl;
    }
    return 0;
}