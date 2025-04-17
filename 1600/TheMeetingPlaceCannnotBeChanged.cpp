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
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
//VERDICT -> ACCEPTED
/*Approach -> every person can go some distance at the right 
and at the left so that max left distances for the people will
be the max of individual lefts, similarly the maximum right
will be the min of individual rights
Just Binary search on the time for minimum time
and mid will be valid only when left <= right.

*/
bool solve(vi &distances,vi &speeds,double time){

	double left = INT_MIN,right = INT_MAX;
	for(int i=0;i<distances.size();i++){

		double new_left = distances[i] - (speeds[i] * time);
		double new_right = distances[i] + (speeds[i] * time);

		left = max(left,new_left);
		right = min(right,new_right);
	}
	return left<=right;
}
signed main(){
	fast_io();
    int n;
    cin >> n;
    vi distances(n);
    vi speeds(n);
    input(distances);
    input(speeds);
    double s = 0 , e = 1e18;
    double ans = n;
    
    while(s <= e){
    	double mid = (s+e)/2;
    	if(solve(distances,speeds,mid)){
    		ans = mid;
    		e = mid - 0.0000001;
    	}
    	else{
    		s = mid + 0.0000001;
    	}
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
    return 0;
}