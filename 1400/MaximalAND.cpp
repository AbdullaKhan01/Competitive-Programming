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
        int n,k;
        cin >> n >> k;
        vi arr(n);
        input(arr);
        vector<pair<int,int>> p(32,{1,0});
        vector<int> visited(32,0);
        int sum = 0;
        for(int j=0;j<=30;j++){
            for(int i=0;i<n;i++){
        		int bit = arr[i] & (1<<j); 
        		if(!bit){
        			p[j].first = 0;
        			p[j].second++;
        		}
                else{
                    visited[j] = 1;
                }
        	}
            if(visited[j] && p[j].first == 1){
                sum |= (1<<j);
            }
        }
        for(int i=30;i>=0;i--){
            if(p[i].first == 1) continue;
            if(k >= p[i].second){
                sum |= (1<<i);
                k-=p[i].second;
            }
        }
        cout << sum << endl;
    }
    return 0;
}