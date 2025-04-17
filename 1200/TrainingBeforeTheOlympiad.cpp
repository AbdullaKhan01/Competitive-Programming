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
        vi arr(n);
        input(arr);
        vi ans(n);
        ans[0] = arr[0];
        int odd = (arr[0]%2!=0);
        for(int i=1;i<n;i++){
        	ans[i] = ans[i-1] + arr[i];
        }
        for(int i=1;i<n;i++){
        	odd+=(arr[i] % 2 !=0);
        	if(odd == 1){
        		ans[i]--;
        		continue;
        	}
        	else if(odd>=3){
        		int alice = odd%3;
        		int bob = odd/3;
        		ans[i]-=bob;
        		if(alice == 1) ans[i]--;
        	}
        }
        output(ans);
        cout << endl;
    }
    return 0;
}