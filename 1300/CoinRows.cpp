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
// signed main(){
	
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int m;
//         cin >> m;
//         vector<vector<int>>arr(2,vector<int>(m,0));
//         rep(i,0,2){
//         	rep(j,0,m){
//         		cin >> arr[i][j];
//         	}
//         }
//         vector<int> prefix(m+1,0);
//         vector<int> suffix(m+1,0);
//         suffix[m-1] = arr[0][m-1];
//         prefix[0] = arr[1][0];
//         for(int i=1;i<m;i++){
//         	prefix[i] = prefix[i-1] + arr[1][i];
//         }
//         for(int i=m-2;i>=0;i--){
//         	suffix[i] = suffix[i+1] + arr[0][i];
//         }
//         int ans = INT_MAX;
//         rep(i,0,m){
//         	int l = suffix[i] - arr[0][i];
//         	int p = prefix[i] - arr[1][i];
//         	int d = max(l,p);
//         	ans = min(ans,d);

//         }
//         cout << ans << endl;    }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		int n; cin>>n;
    vector<vector<int>> arr(2,vector<int>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int acoins=0;
    int bcoins=0;
    int sum=0;
    arr[0][0] = 0;
    arr[1][n-1] = 0;
    for(int i=0;i<n-1;i++){
        sum+=arr[1][i];
        if(arr[0][i+1]>=sum){
            arr[0][i+1]=0;
        }
        else{
            for(;i<n;i++){
                arr[1][i]=0;
            }
            break;
        }
    }
    int sum1 = 0;
    int sum2 = 0;
   	for(int i=0;i<n;i++){
    	cout << arr[0][i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
    	cout << arr[1][i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        sum1+=arr[0][i];
        sum2+=arr[1][i];
    }
    cout<<max(sum1,sum2) << endl;

	}
    
}