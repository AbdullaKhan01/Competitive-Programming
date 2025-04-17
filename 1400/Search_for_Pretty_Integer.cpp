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
    ll a,b;
    cin >> a >> b;
    vector<int> arr1(10,0),arr2(10,0);
    int x1=11,y1=11;
   	while(a--){
   		int x;cin>>x;
   		x1 = min(x1,x);
   		arr1[x]=1;
   	}
   	while(b--){
   		int x;cin>>x;
   		y1=min(y1,x);
   		arr2[x]=1;
   	}
   	for(int i=0;i<=9;i++){
   		if(arr1[i]==1 && arr2[i]==1){
   			cout << i << endl;
   			return 0;
   		}
   	}
   	cout << min(x1,y1) << max(x1,y1) << endl;
    return 0;
}