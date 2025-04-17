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
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        bool flag = false;
        int i,j,k;
        for(i=1;i<=26;i++){
        	for(j=1;j<=26;j++){
        		for( k=1;k<=26;k++){
        			if(i+j+k == n){
        				// cout << i << j << k << endl;
        				flag = true;
        				break;
        			}
        		}
        		if(flag == true) break;
        	}
        	if(flag){
        		cout << char(i+'a'-1) << char(j+'a'-1) << char(k+'a'-1) << endl;
        		break;
        	}
        }
    }
    return 0;
}