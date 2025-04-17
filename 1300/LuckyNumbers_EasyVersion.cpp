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
void generate(int size,string s,vector<int>&ans,int cnt){
	if(cnt>=size){
		ans.pb(stoi(s));
		return ;
	}
	generate(size,s+"4",ans,cnt+1);
	generate(size,s+"7",ans,cnt+1);
}
signed main(){
	
	vector<int> p;
    for(int i=1;i<=9;i++){
    	generate(i,"",p,0);
    }
    int n;
    cin >> n;
    p.pb(4444477777);
    for(auto it:p){
    	// cout << it << endl;
    	if(it < n){
    		continue;
    	}
    	else{
    		int cnt = 0;
    		int cnt2 = 0;
    		int x = it;
    		while(x != 0){
    			int digit = x%10;
    			if(digit == 7) cnt2++;
    			else cnt++;
    			x /=10;
    		}
    		if(cnt2 == cnt){
    			cout << it << endl;
    			return 0;
    		} 
    	}
    }
    return 0;
}