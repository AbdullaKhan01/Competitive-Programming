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
        int n,f,a,b;
        cin >> n >> f >> a >> b;
        vi arr(n);
        input(arr);
        bool flag = true;
        int m = 0;
        int charge = f;
        for(int i=0;i<n;i++){
        	if(charge<=0){
        		flag = false;
        		break;	
        	} 
        	int p = arr[i];
        	int sec = p - m;
        	m = p;
        	charge -= min(sec*a,b);
        }
        if(charge<=0) flag = false;
        cout << (flag?yes:no) << endl;
    }
    return 0;
}