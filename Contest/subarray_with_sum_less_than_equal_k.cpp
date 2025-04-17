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
int solve(vector<int>&arr,int n,int k)
{
	int tail = 0 , head = -1;
	int ans = INT_MAX;
	map<int,int> mp;
	int distCount = 0;
	while(tail < n)
	{
		// eat as many elements as possible till its valid
		while(head + 1 < n && (distCount < k))
		{
			// add to ds
			if(mp[arr[head+1]] == 0) distCount++;
			mp[arr[head+1]]++;
			head++;
		}
		// update the answer for current start
		if(distCount == k)
			ans = min(ans,(head - tail + 1));
		// move start one step forward
		if(tail > head)
		{
			tail++;
			head = tail - 1;
		}
		else
		{
			//remove from ds
			mp[arr[tail]]--;
			if(mp[arr[tail]] == 0) distCount--;
			tail++;
		}
	}
	return ans;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        set<int> s;
        for(int i=0;i<n;i++)
        {
        	cin >> arr[i];
        	s.insert(arr[i]);
        }
        // cout << "set size iss.size() << endl;
        cout << solve(arr,n,s.size()) << endl;
    }
    return 0;
}

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
// int mp[1000100] = {0};
// int solve(vector<int>&arr,int n,int D)
// {
// 	int tail = 0 , head = -1;
// 	int ans = INT_MAX;
// 	int distCount = 0;
// 	while(tail < n)
// 	{
// 		// eat as many elements as possible till its valid
// 		if(head + 1 >= n) break;
// 		while(head+1 - tail < D)
// 		{
// 			// add to ds
// 			if(mp[arr[head+1]] == 0) distCount++;
// 			mp[arr[head+1]]++;
// 			head++;
// 			continue;
// 		}
// 		// update the answer for current start
// 		ans = min(ans,distCount);
// 		// move start one step forward
// 		{
// 			//remove from ds
// 			mp[arr[tail]]--;
// 			if(mp[arr[tail]] == 0) distCount--;
// 			tail++;
// 		}
// 	}
// 	for(int i=tail;i<n;i++) mp[arr[i]]--;
// 	return ans;
// }
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n,k;
//         cin >> n >> k;
//         vi arr(n);
//         input(arr);
//         cout << solve(arr,n,k) << endl;
//     }
//     return 0;
// }



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
// int solve(vector<int>&arr,int n)
// {
// 	int tail = 0 , head = -1;
// 	int ans = 0;
// 	map<int,int> mp;
// 	while(tail < n)
// 	{
// 		// eat as many elements as possible till its valid
// 		while(head+1 < n && mp[arr[head+1]] == 0)
// 		{
// 			// add to ds
// 			// if(mp[arr[head+1]] == 0) distCount++;
// 			mp[arr[head+1]]++;
// 			head++;
// 			continue;
// 		}
// 		// update the answer for current start
// 		ans = max(ans,(int)mp.size());
// 		// move start one step forward
// 		{
// 			//remove from ds
// 			mp[arr[tail]]--;
// 			if(mp[arr[tail]] == 0) mp.erase(arr[tail]);
// 			tail++;
// 		}
// 	}
// 	return ans;
// }
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vi arr(n);
//         input(arr);
//         cout << solve(arr,n) << endl;
//     }
//     return 0;
// }







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
// int mp[200100] = {0};
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n,d;
//         cin >> n >> d;
//         vi arr(n);
//         input(arr);
//         int ans = INT_MAX;
        
//         int distinctCnt = 0;
//         int s = 0 , e = 0;
//         while(s < n && e < n)
//         {
//         	while(e < d-1)
//         	{
//         		if(mp[arr[e]] == 0) distinctCnt++;
//         		mp[arr[e++]]++;
//         		continue;
//         	}
//         	{
//         		// add the current element
//         		if(mp[arr[e]] == 0) distinctCnt++;
//         		mp[arr[e]]++;
//         		// calculate the answer
//         		ans = min(ans,distinctCnt);
//         		//remove the element from start
//         		mp[arr[s]]--;
//         		if(mp[arr[s]] == 0) distinctCnt--;
//         		//increase pointers
//         		s++;
//         		e++;
//         	}
//         }
//         for(int i=max(0LL,n-d+1);i<n;i++) mp[arr[i]]--;
//         cout << ans << "\n";
//     }
//     return 0;
// }