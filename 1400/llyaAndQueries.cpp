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
    int n = s.size();
    vll arr(n,0);
    for(int i=1;i<n;i++){
    	arr[i] = arr[i-1] + (s[i-1]==s[i]);
    }
    int nn;
    cin >> nn;
    while(nn--){
    	int a,b;
    	cin >> a >> b;
    	a--,b--;
    	cout << arr[b] - arr[a] << endl;
    }
    return 0;
}