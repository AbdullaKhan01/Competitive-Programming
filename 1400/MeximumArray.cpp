#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
int mex(vector<int> &a) {
    vector<bool> f(a.size() + 1, 0);
    for (int i : a) if (i <= (int) a.size()) f[i] = 1;
    int mex = 0;
    while (f[mex]) ++mex;
    return mex;
}
vector<int> Suffix_Mex(vector<int>& A, int n) {
    // Create a boolean vector to track the presence of numbers
    vector<bool> b(n+1);
     
    // Initialize mex (minimum excluded value) to 0
    int mex = 0;
     
    // Result vector to store the Prefix Mex values
    vector<int> result(n);
 
    // Loop through the input vector A
    for (int i = n-1; i >= 0; i--) {
        // Mark the current element as present
        b[A[i]] = true;
 
        // Update mex until a non-present value is found
        while (b[mex] == true) {
            mex++;
        }
 
        // Store the current mex value in the result vector
        result[i] = mex;
    }
 
    // Return the result vector
    return result;
}
vector<int> Prefix_Mex(vector<int>& A, int n) {
    // Create a boolean vector to track the presence of numbers
    vector<bool> b(n+1);
     
    // Initialize mex (minimum excluded value) to 0
    int mex = 0;
     
    // Result vector to store the Prefix Mex values
    vector<int> result(n);
 
    // Loop through the input vector A
    for (int i = 0; i < n; i++) {
        // Mark the current element as present
        b[A[i]] = true;
 
        // Update mex until a non-present value is found
        while (b[mex] == true) {
            mex++;
        }
 
        // Store the current mex value in the result vector
        result[i] = mex;
    }
 
    // Return the result vector
    return result;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        vector<int> ans;
        vector<int> suff_mex = Suffix_Mex(arr,arr.size());
        vector<bool> b(n+1,0);
        break;
        int mex = 0;
        int i=0;
       	for(;i<n;i++){
       		int find = suff_mex[i];
       		b[arr[i]] = true;
       		while(mex != find){
		       	while (b[mex] == true) {
		            mex++;
		        }
		        i++;
       		}
       		ans.push_back(find);
       		b.clear();
       		mex = 0;
       	}
       	cout << ans.size() << endl;
       	for(auto it:ans){
       		cout << it << " ";
       	}
       	cout << endl;
    }
    return 0;
}