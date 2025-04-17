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
int solve(int n,int mid){
	int x = mid-1;
	int sum1 = (x * (x+1)) / 2;
	// int sum2 = (mid * (mid+1))/2;
	if(sum1 < n){
		return true;
	}
	return false;
}
int solve2(int n,int p,int mid){
	
	int a = n-1;
	int b = mid;
	int sum1 = (a*(a+1))/2;
	int sum2 = (b*(b+1))/2;
	int give = sum1-sum2;
	// cout << n << endl;
	// cout << "Here" << sum1 << " " << sum2 << endl;
	// cout<<"here "<< give << " " << p << endl;
	if(give<p){
		return true;
	}
	return false;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        int sum = (n * (n+1))/2;

        if(sum >= k){
        	int s = 1 , e = n;
        	int ans=1;
        	while(s<=e){
        		int mid = (s+e)/2;
        		if(solve(k,mid)){
        			// cout << mid << " " << yes << endl;
        			ans = mid;
        			s = mid+1;
        		}
        		else{
        			e = mid - 1;
        		}
        	}
        	cout << ans << endl;
        }
        else{
        	int p1 = n;
        	int p2 = 0;
        	int z = k - sum;
        	// cout << sum << endl;
        	// cout << "z is " << z << endl;
        	int s = 1 , e = n-1;
        	while(s<=e){
        		int mid = (s+e)/2;
        		// cout << s << " " << e << " "<<endl;
        		if(solve2(n,z,mid)){
        			// cout << "here" << mid;
        			p2 = n-mid;
        			e = mid - 1;
        		}
        		else{
        			s = mid + 1;
        		}
        	}
        	// cout << p2 << endl;
        	cout << p1 + p2 << endl;
        }
    }
    return 0;
}