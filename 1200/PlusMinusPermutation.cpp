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
long long lcm (long long a, long long b) {
    return a / __gcd(a, b) * b;
}
int apSum(int start,int no_of_elements,int difference){
	int ans = (no_of_elements * (2*start + ((no_of_elements-1)*difference)))/2;
	return ans;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        // vi arr(n+1,0);
        // int e1 = n/x;
        int lcm1 = lcm(x,y);
        int terms = n/lcm1;
        int terms2 = (n/y) - terms;
        int terms3 = n/x;
        cout << "here" << terms << " " << terms2 << " " << terms3 << endl;
        int p = lcm1/x;
        int s1 = apSum(n,terms3,-1);
        int s2 = apSum(n-p+1,terms,-p);
        int s3 = apSum(-1,terms2,-1);
        // cout << s1 << endl;
        // cout << s2 << endl;
        // cout << s3 << endl;
        cout << s1 - s2 + s3 << endl;
        // cout << "*********"<<endl;
    }
    return 0;
}