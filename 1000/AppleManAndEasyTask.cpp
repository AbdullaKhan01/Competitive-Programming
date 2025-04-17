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
	
    int n;
    cin >> n;
    vector<vector<char>> arr(n,vector<char>(n,' '));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin >> arr[i][j];
    	}
    }
    bool flag = true;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		int sum = 0;
    		if(i+1<n) sum+=(arr[i+1][j]) == 'o';
    		if(j+1<n) sum+=(arr[i][j+1]) == 'o';
    		if(i-1>=0) sum+=(arr[i-1][j]) == 'o';
    		if(j-1>=0) sum+=(arr[i][j-1]) == 'o';
    		if(sum%2!=0){ 
    		flag = false;
    		break;
    		}
    	}

    }
    cout << (flag?yes:no) << endl;
    return 0;
}