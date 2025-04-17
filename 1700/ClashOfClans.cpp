#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
static bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
	return a.first<=b.first;
}
signed main(){
	
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    int n;
    cin >> n;
    vector<int> arr,brr,crr;
    for(auto it: a) arr.push_back(it-48);
    for(auto it: b) brr.push_back(it-48);
    for(auto it: c) crr.push_back(it-48);	

    int ans = 0;
    vector<pair<int,pair<int,int>>>drr;
	int x = arr.size();
	for(int i=0;i<x;i++){
		pair<int,pair<int,int>>p = {crr[i],{brr[i],arr[i]}};
		drr.push_back(p);
	}
	sort(all(drr),cmp);
	int prev = drr[0].first;
	int maxi = 0;
	cout << "Printing" << endl;
	for(auto it:drr){
		if(it.ff != prev){
			cout << prev << " " << maxi << endl;
			ans+=maxi;
			maxi = 0;
			if(it.ss.ff<=n) maxi = max(maxi,it.ss.ss);
			prev = it.first;
		}
		else{
			if(it.ss.ff<=n){
				maxi = max(maxi,it.ss.ss);
			}
		}
	}
	cout << prev << " " << maxi << endl;
	ans+=maxi;
	cout << ans << endl;
    return 0;
}