#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
    	if(i==s.size()-1){
    		if(s[i]=='.') cout << 0;
    	}
    	else{
    		if(s[i]=='.'){
    			cout << 0;
    		}
    		else{
    			if(s[i+1]=='.'){
    				cout << 1;
    				i++;
    			}
    			else{
    				cout << 2;
    				i++;
    			}
    		}
    	}
    }
    return 0;
}