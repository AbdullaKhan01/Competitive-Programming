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
APPROACH -> let the array be 
n
a1 a2 a3 ..... am am+1 ...... an

Observation -> so prefix sum of elements after the mth
index can not be zero 
i.e 
am+1 should be >= 0 
am+1 + am+2 should be >= 0
am+1 + am+2 + ...... an should be >= 0

so we can directly check that 

lets say some index i before m is changed from a[i] to -a[i]
how will the prefix sum change

pref[i] will decrease by 2 * a[i]
pref[i+1] will decrease by 2 * a[i]
...
pref[m] will decrease by 2 * a[i]

lets say some index i before m is changed from -a[i] to a[i]
how will the prefix sum change

pref[i] will increase by 2 * a[i]
pref[i+1] will increase by 2 * a[i]
...
pref[m] will increase by 2 * a[i]

we never want to increase pref[m] right ??? 

because that's just a stupid operation


VERDICT -> ACCEPTED

error in my approach going from 1 to m 
instead should have gone from m to 1

why ? -> because if we change some index i then
only the indexes before it can be affected
hence we might miss some index
*/
vector<int> a;
void solve()
{
	int n,m;
	cin >> n >> m;
	m--;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int cnt = 0;
	int sum = 0;
	multiset<int> ms;
	for(int i=m+1;i<n;i++)
	{
		sum += a[i];
		ms.insert(a[i]);
		while(sum < 0)
		{
			auto it = *ms.begin();
			ms.erase(ms.find(it));
			sum += -2 * (it);
			cnt++;
		}
	}
	if(m != 0)
	{
		// do something
		if(a[m] > 0) a[m] *= -1,cnt++;
		sum = 0;
		multiset<pair<int,int>> st;
		vector<int> pref(m+1,0);
		for(int i=0;i<=m;i++)
		{
			sum += a[i];
			pref[i] = a[i];
			if(i > 0) pref[i] += pref[i-1];
			if(i < m) st.insert({-a[i],i});
		}
		// got the prefix sum
		priority_queue<int> pq;
		for(int i=m-1;i>=0;i--)
		{
			int psum = pref[i];
			while(psum < sum && !pq.empty())
			{
				auto it = pq.top(); pq.pop();
				sum -= 2 * (it);
				cnt++;
			}
			pq.push(a[i]);
		}
	}
	cout << cnt << endl;
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