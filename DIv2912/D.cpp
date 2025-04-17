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
        int n,k,x;
        cin >> n >> k >> x;
        vi arr(n);
        input(arr);
        sort(all(arr));
        int sum = 0;
        for(int k=n-1-x;k<n;k++){
        	sum+=arr[k];
        }
        vi pref(n,0),suff(n,0);
        pref[0] = arr[0];
        suff[n-1] = arr[n-1];
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
        	pref[i] = pref[i-1] + arr[i];
        }
        for(int i=n-2;i>=0;i--){
        	suff[i] = suff[i+1] + arr[i];
        }
        int j = n;
        if(j-x >= 0)
        {int p = pref[j-x] + (suff[j-x]) * -1;
        ans = max(ans,p);}
        for(int i=1;i<=k;i++){
            int q=INT_MIN;
            if(j-i-x>=0)
                q = pref[j-i-x] +  ((suff[j-i-x+1] - suff[j-i]) * -1); 
            ans = max(ans,q);
        }
        if(x>=n && k<n){
            int sum = 0;
            for(int i=0;i<k;i++){
                sum+=arr[i];
            }
            cout << sum*-1 << endl;
        }
        else{
            if(k>=n) cout << max(ans,1LL*0) << endl;
            else cout << ans << endl;    
        }
    }
    return 0;
}