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
        string s;
        cin >> s;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
        	
        	if(i+1<n){
        		//2 length substr
        		int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
        		for(int k = i ; k<=i+1;k++){
        			cnt1+= s[k]=='a';
        			cnt2+= s[k]=='b';
        			cnt3+= s[k]=='c';
        		}
        		if(cnt1 > cnt2 && cnt1 >cnt3){
        			// cout << "here" << i << endl;
        			ans = min(ans,1LL*2);
        		}
        	}
        	if(i+2<n){
        		//3 length substr
        		int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
        		for(int k = i ; k<=i+2;k++){
        			cnt1+= s[k]=='a';
        			cnt2+= s[k]=='b';
        			cnt3+= s[k]=='c';
        		}
        		if(cnt1 > cnt2 && cnt1 >cnt3){
        			ans = min(ans,1LL*3);
        		}
        	}
        	if(i+3<n){
        		//4 length substr
        		int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
        		for(int k = i ; k<=i+3;k++){
        			cnt1+= s[k]=='a';
        			cnt2+= s[k]=='b';
        			cnt3+= s[k]=='c';
        		}
        		if(cnt1 > cnt2 && cnt1 >cnt3){
        			ans = min(ans,1LL*4);
        		}
        	}
        }

        cout << (ans==INT_MAX?-1:ans) << endl;
    }
    return 0;
}