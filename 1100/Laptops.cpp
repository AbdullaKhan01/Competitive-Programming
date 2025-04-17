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
bool cmp(pii &a,pii &b){
	return a.ff <= b.ff;	
}
signed main(){
	
    int n;
    cin >> n;
    vector<pii> arr;
    for(int i=0;i<n;i++){
    	int a,b;
    	cin >> a >> b;
    	arr.pb({a,b});
    }
    sort(all(arr),cmp);
    int p = arr[0].ff;
    int maxi = arr[0].ss;
    bool flag = false;
    for(int i=1;i<n;i++){
    	if(arr[i].ff > p && arr[i].ss < maxi){
    		flag = true;
    		break;
    	}
    	if(arr[i].ss > maxi){
    		p = arr[i].ff;
    		maxi = arr[i].ss;
    	}
    }
    if(flag){
    	cout << "Happy Alex" << endl;
    }
    else{
    	cout << "Poor Alex" << endl;
    }
    return 0;
}