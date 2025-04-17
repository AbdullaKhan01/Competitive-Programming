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
void dfs(vector<string>&arr,int i,int j,int val,vector<vi>&visited,int n,int m){
	if(visited[i][j]) return ;
	visited[i][j] = true;
	arr[i][j] = val+48;
	if(i+1 < n && arr[i+1][j] == '.'){
		dfs(arr,i+1,j,!val,visited,n,m);
	}
	if(i-1>=0 && arr[i-1][j] == '.'){
		dfs(arr,i-1,j,!val,visited,n,m);
	}
	if(j+1<m && arr[i][j+1] == '.'){
		dfs(arr,i,j+1,!val,visited,n,m);
	}
	if(j-1>=0 && arr[i][j-1] == '.'){
		dfs(arr,i,j-1,!val,visited,n,m);
	}
}
signed main(){
	
    int a,b;
    cin >> a >> b;
    vector<string> arr(a);
    vector<vi>visited(a,vi(b,0));
    input(arr);
    for(int i=0;i<a;i++){
    	for(int j=0;j<b;j++){
    		if(!visited[i][j] && arr[i][j] == '.'){
    			dfs(arr,i,j,0,visited,a,b);
    		}
    	}
    }
    for(int i=0;i<a;i++){
    	for(int j=0;j<b;j++){
    		if(arr[i][j] == '0') cout << "B";
    		else if(arr[i][j] == '1') cout << "W";
    		else cout << arr[i][j];;
    	}
    	cout << endl;
    }
    return 0;
}