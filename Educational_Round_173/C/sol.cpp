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
vector<int> a;
int n;
pair<int,int> f(int st,int en){
	int cnt1 = 0,cnt2 = 0;
	int i = st;
	pair<int,int> ans = {0,0};
	while(i < en){
		if(a[i] == -1){
			if(cnt1 > 0) cnt1--;
			cnt2++;
		}
		else if(a[i] == 1){
			if(cnt2 > 0) cnt2--;
			cnt1++;
		}
		ans.first = max(ans.first,cnt1);
		ans.second = max(ans.second,cnt2);
		i++;
	}
	return ans;
}
void solve()
{
	cin >> n;
	a.resize(n);
	int idx = -1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] != 1 && a[i] != -1) idx = i;
	}
	int one = max(f(0,idx).first,f(idx+1,n).first);
	int minus_one = max(f(0,idx).second,f(idx+1,n).second);
	int ans =  one + minus_one;
	// cout << ans << endl;
	vector<int> suff;
	suff.push_back(0);
	int sum = 0;
	for(int i=0;i<idx;i++){
		sum += a[i];
		suff.push_back(sum);
	}
	vector<int> pref;
	for(int i=idx;i<n;i++){
		sum += a[i];
		pref.push_back(sum);
	}
	set<int> ap;
	ap.insert(0);
	for(int i=1;i<=one;i++){
		ap.insert(i);
	}
	for(int i=1;i<=minus_one;i++){
		ap.insert(-i);
	}
	sort(all(suff));
	sort(all(pref));
	reverse(pref.begin(),pref.end());
	// output(suff);
	// cout << endl;
	// output(pref);
	// cout << endl;
	int k = 2e9;
	for(auto it : pref){
		// it - m < k
		// m > it - k
		int idx = upper_bound(suff.begin(),suff.end(),it - k) - suff.begin();
		for(int index = idx;index<(int)suff.size();index++){
			int cnt = it - suff[index];
			ap.insert(cnt);
			k = min(k,cnt);
		}
	}	
	// int maxi = one;
	// int mini = -minus_one;
	
	// if(idx != -1){
	// 	for(int i=idx;i<n;i++){
	// 		sum += a[i];
	// 		cout << i << " " << sum << endl;
	// 		output(g);
	// 		cout << endl;
	// 		// pref[r] - pref[l-1] > maxi
	// 		// pref[r] - pref[l-1] < mini
	// 		// pref[l-1] > pref[r] - mini
	// 		// pref[l-1] < pref[r] - maxi
	// 		int idx = lower_bound(g.begin(),g.end(),sum - maxi) - g.begin();
	// 		for(int k=0;k<idx;k++){
	// 			int nsum = sum - g[k];
	// 			maxi = max(maxi,nsum);
	// 			ap.insert(sum - g[k]);
	// 		}
	// 		int idx2 = upper_bound(g.begin(),g.end(),sum - mini) - g.begin();
	// 		for(int k=idx2;k<(int)g.size();k++){
	// 			int nsum = sum - g[k];
	// 			mini = min(mini,nsum);
	// 			ap.insert(nsum);
	// 		}
	// 		g.push_back(sum);
		// }
	// }
	cout << ap.size() << endl;
	for(auto it : ap){
		cout << it << " ";
	}
	cout << endl;
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