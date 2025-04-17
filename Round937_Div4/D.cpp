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
void generate(vector<int> &arr,int n,string s,int c){
	if(c >= n){
		arr.push_back(stoi(s));
		return ;
	}
	generate(arr,n,s+"0",c+1);
	generate(arr,n,s+"1",c+1);
}
bool solve(vector<int>&arr,int index,int p,int tar){
	if(index >= arr.size()) return false;
	if(p * arr[index] > tar) return false;
	if(p * arr[index] == tar) return true;

	if(arr[index] == 1){
		return solve(arr,index+1,p,tar);
	}
	bool p1 = solve(arr,index,p*arr[index],tar);
	bool p2 = solve(arr,index+1,p,tar);
	return p1||p2;

}
signed main(){
	fast_io();
	vector<int> ans;
    for(int i=1;i<=5;i++){
    	generate(ans,i,"",0);
    }
    // do_unique(ans);
    set<int> s;
    for(auto it:ans){
    	s.insert(it);
   	}
   	ans.clear();
   	for(auto it:s){
   		ans.push_back(it);
   	}
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        if(solve(ans,1,1,n)){
        	cout << "YES" << endl;
        }
        else{
        	cout << "NO" << endl;
        }

    }
    return 0;
}