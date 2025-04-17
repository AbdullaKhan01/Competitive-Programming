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
int func(string s){
    int n = s.length();
    int a = 0,b=0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'o')
        {
            a += b;
        }
        else if(s[i] == 'w')
        {
            ans += a;
            b++;
        }
    }
    return ans;
}
signed main(){
	
    string s;
    cin >> s;
    int n = s.size();
    string a;
    int cnt = 0;
    for(int i=0;i<n;i++){
    	if(s[i] == 'o'){
    		if(cnt>1){
    		string g(cnt-1,'w');
    		a+=g;
    		}
    		a.pb('o');
    		cnt = 0;
    	}
    	if(s[i] == 'v') cnt++;
    }
    if(cnt>1)
    {string g(cnt-1,'w');
        a+=g;
    }
    int p = func(a);
    cout << p << endl;
    return 0;
}