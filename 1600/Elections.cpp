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
// int n,c;
// int arr[100100];
// int ans[100100];

// void printmp(map<int,set<int>>mp)
// {
// 	for(auto it:mp)
// 	{
// 		cout << it.first << " -> ";
// 		for(auto jt:it.second) cout << jt << " ";
// 		cout << endl;
// 	}
// 	cout << endl;
// }
// void printst(map<int,int>mp)
// {
// 	for(auto it:mp)
// 	{
// 		cout << it.first << " " << it.second << endl;
// 	}
// 	cout << endl;
// }
// struct solve
// {
// 	int cnt = 0;
// 	int extraVotes = 0;
// 	set<int> smallest;
// 	map<int,set<int>>mp;
// 	map<int,int> gp;
// 	// some thing to find number of candidates

// 	void init()
// 	{
// 		for(int i=0;i<n;i++)
// 		{
// 			cin >> arr[i];
// 			smallest.insert(i+1);
// 			if(i == 0) mp[arr[i]+c].insert(i+1),gp[i+1]=arr[i]+c;
// 			else mp[arr[i]].insert(i+1),gp[i+1] = arr[i];
// 		}
// 		// printmp(mp);
// 		// printst(gp);
// 	}

// 	void query()
// 	{
// 		for(int i=1;i<=n;i++)
// 		{

// 			set<int> st = mp.rbegin()->second;
			
// 			// x - pref[r] >= 0
// 			// 2 2 2 3 3 4 4 
//  			// the first element is the current element
// 			int a = *(st.begin());
// 			// cout << "curr " << mp.rbegin() -> first << " " << a << " " << cnt << endl;
// 			// what all to do
// 			// -> first calculate the current answer
// 			ans[a] = cnt;
// 			smallest.erase(a);
// 			// erase gp[a]
// 			int z = gp[a];
// 			gp.erase(a);
// 			mp[z].erase(a);
// 			// -> increase the cnt by 1
// 			cnt += 1;
// 			// -> take the votes of the current number
// 			int currentVotes = mp.rbegin()->first;
// 			// -> increase the votes of the smallest
// 			int sm = *(smallest.begin());
// 			int prev_votes = gp[sm];
// 			int new_votes = gp[sm] + currentVotes; 
// 			gp[sm] = new_votes;

// 			// cout << sm << " " << prev_votes << " " << new_votes << endl;
// 			// -> erase the previous entry in the map
// 			mp[prev_votes].erase(sm);
// 			// if(mp[prev_votes].empty())
// 			// {
// 			// 	mp.erase(prev_votes);
// 			// }
// 			// gp.erase(smallest);
// 			// -> insert a new entry in the map 
// 			mp[new_votes].insert(sm);
// 		}
// 		// printmp(mp);
// 		// printst(gp);
// 	}
// 	void print()
// 	{
// 		for(int i=1;i<=n;i++)
// 		{
// 			cout << ans[i] << " ";
// 		}
// 		cout << endl;
// 	}

// };
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//     	cin >> n >> c;
//         solve s;
//         s.init();
//         s.query();
//         s.print();
//     }
//     return 0;
// }


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
#define output(x) for(auto a:x) {cout << a <<" ";}cout<<endl;
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
using namespace __gnu_pbds;
/* 
for fast input output use printf and scanf;
*/

//VERDICT -> ACCEPTED
void solve()
{
	int n,c;
	cin >> n >> c;
	vector<int> p(n);
	vector<int> pref(n+1,0);
	vector<int> ans(n+1,-1);
	int abc = -1;
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
		if(i == 0) p[i]+=c;
		abc = max(abc,p[i]);
		pref[i+1] = pref[i] + p[i];
	}
	// cout << abc << endl;
	for(int i=1;i<=n;i++)
	{
		if(p[i-1] == abc)
		{
			ans[i] = 0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i] == -1)
		{
			int votes = p[i-1];
			int prepix = pref[i-1];
			if(votes + prepix >= abc)
			{
				ans[i] = i-1;
			}
			else
			{
				// we want some elements from the right side
				ans[i] = i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	// reverse(mp.begin(),mp.end());
	
	// output(pref);
	// output(suff);

	// auto it = lower_bound(suff.rbegin(),suff.rend(),6) - suff.rbegin();
	// cout << it << endl;
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
