#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define pb push_back
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    vll arr;
    while(tt--){
    	ll x;
    	cin >> x;
    	arr.pb(x);
    }
    ll s = -1,e = -1;
   	for(int i=1;i<arr.size();i++){
   		if(arr[i-1]>arr[i]){
   			if(s==-1){
   				s = i-1;
   			}
   			e = i;
   		}
   		else{
   			if(s!=-1){
   				break;
   			}
   		}
   	}
   	if(s!=-1){
   		reverse(arr.begin()+s,arr.begin()+e+1);
   	}
    bool flag = true;
    for(int i = 1 ;i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            flag = false;
            break;
        }
    }
    if(flag){
   	cout << "yes" << endl;
    if(s == -1) cout << "1 1" << endl;
    else cout << s+1 << " " << e+1 << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}