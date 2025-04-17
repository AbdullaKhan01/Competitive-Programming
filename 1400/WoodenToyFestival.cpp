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
bool solve(vector<int>& arr,int time){
	int n = arr.size();
	int i=0,j=n-1;
	while(i < n && arr[i] - arr[0] <= 2*time){
		i++;
	}
	while(j >= 0 && arr[n-1] - arr[j] <= 2*time){
		j--;
	}
	if(i > j || arr[j] - arr[i] <= 2*time){
		return true;
	}
	else{
		return false;
	}

}
/*
VERDICT -> ACCEPTED
*/
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        sort(all(arr));
        int s = 0 , e = 1e9;
        int ans = -1;
        while(s <= e){
        	int mid = (s+e)/2;
        	if(solve(arr,mid)){
        		ans = mid;
        		e = mid - 1;
        	}
        	else{
        		s = mid + 1;
        	}
        }
        cout << ans << endl;
    }
    return 0;
}