// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// bool solve(vector<vector<char>>arr,int row,int col,int counter){
// 	int cnt = 0;
// 	int n = arr[0].size();
// 	while(col < n){
// 		// cout << row << " "<< col << endl;
// 		if(arr[row][col] == 'B'){
// 			 cnt++;
// 			 arr[row][col] = ' ';	
// 		}
// 		if(row == 0){
// 			if(arr[1][col] == 'B'){
// 				row = 1;
// 			}
// 			else if(col+1<n && arr[0][col+1] == 'B'){
// 				col++;
// 			}
// 			else break;
// 		}
// 		else if(row == 1){
// 			if(arr[0][col] == 'B'){
// 				row = 0;
// 			}
// 			else if(col+1<n && arr[1][col+1] == 'B'){
// 				col++;
// 			}
// 			else break;
// 		}
// 	}
// 	return cnt == counter;
// }
// signed main(){
	
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vector<vector<char>>arr(2,vector<char>(n,' '));
//         int counter = 0;
//         rep(i,0,2){
//         	rep(j,0,n){
//         		cin >> arr[i][j];
//         		counter += (arr[i][j] == 'B');
//         	}
//         }
//         int ind = 0;
//         rep(i,0,n){
//         	if(arr[0][i] == 'B' || arr[1][i] == 'B'){
//         		ind = i;
//         		break;
//         	}
//         }
//         bool flag1 = solve(arr,0,ind,counter);
//         bool flag2 = solve(arr,1,ind,counter);
//         // cout << ind << endl;
//         if(flag1 || flag2){
//         	cout << yes << endl;
//         }
//         else{
//         	cout << no << endl;
//         }
//     }
//     return 0;
// }
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
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
    	int n;
    	cin >> n;
    	int counter = 0;
        vector<vector<char>>arr(2,vector<char>(n,' '));
        rep(i,0,2){
        	rep(j,0,n){
        		cin >> arr[i][j];
        		counter += (arr[i][j] == 'B');
        	}
        }
        vector<vector<int>>dp(2,vector<int>(n,0));
        dp[0][0] = (arr[1][0] == 'B') + (arr[0][0] == 'B');
        dp[1][0] = (arr[1][0] == 'B') + (arr[0][0] == 'B');
        for(int col=1;col<n;col++){
        	int a=0;
        	int b=0;
        	int c=0;
        	int d=0;
    		if(arr[0][col] != 'W'){
    			if(arr[0][col-1]!='W'){
        			a = max(dp[0][col],1+dp[0][col-1]);
        		}
        		if(arr[!0][col] != 'W'){
        			b = max(dp[0][col],1+dp[!0][col]);
        		}
    		}
    		if(arr[1][col] != 'W'){
    			if(arr[1][col-1]!='W'){
        			c = max(dp[1][col],1+dp[1][col-1]);
        		}
        		if(arr[!1][col] != 'W'){
        			d = max(dp[1][col],1+dp[!1][col]);
        		}
    		}
    		
        	dp[0][col]=max(a,b);
        	dp[1][col]=max(c,d);
        }
        for(int i=0;i<n;i++){
        	cout << dp[0][i] << " ";
        }
        cout << endl;
        for(int i=0;i<n;i++){
        	cout << dp[1][i] << " ";
        }
        if(dp[0][n-1] == counter || dp[1][n-1] == counter){
        	cout << yes << endl;
        }
        else{
        	cout << no << endl;
        }
    }
    return 0;
}