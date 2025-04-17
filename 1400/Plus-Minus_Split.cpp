#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define llmin(a,b) min(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        ll minusCount = 0;
        ll plusCount = 0;
        // for(ll i=0;i<s.length();i++){
        // 	if(s[i] == '-'){
        // 		if(plusCount>0){

        // 			ans--;
        // 		}
        // 		else{
        // 			// ll count = 0;
        // 			while(i<n && s[i] == '-'){
        // 				minusCount++;
        // 				i++;
        // 			}
        // 			while(i < n && s[i] == '+' && minusCount>0){
        // 				minusCount--;
        // 				i++;
        // 			}
        // 			if(i < n) i--;
        // 			plusCount = 0;
        // 		}
        // 	}
        // 	else{
        // 		minusCount = 0;
        // 		plusCount++;
        // 		ans++;
        // 	}
        // }
        for(ll i=0;i<n;i++){
        	if(s[i] == '+'){
        		if(minusCount == 0){
        		plusCount++;
        		ans++;
        		}
        		else
        		{
        			minusCount--;
        		}
        	}
        	else{
        		if(plusCount > 0){
        			ans--;
        			plusCount--;
        		}
        		else{
        			minusCount++;
        		}
        	}
        }
        if(minusCount > 0) ans+=minusCount;
        cout << ans << endl;
        // ++-- --+-+--
    }
    return 0;
}