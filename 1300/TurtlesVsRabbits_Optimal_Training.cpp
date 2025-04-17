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
// int apSum(int a,int n){
// 	int ans = (n * (2*a - (n-1)))/2;
// 	return ans;
// }
// int solve(int m,int p){
// 	// cout << "in func" << endl;
// 	// cout << "Start" << m << endl;
// 	// cout << "no of ele" << p << endl;
// 	return apSum(m,p);
// }
// void print(vi &pref,int a,int b){
// 	int minus = pref[a-1];
// 	for(int i=a;i<=min((int)pref.size()-1,b);i++){
// 		int l = pref[i] - minus;
// 		cout << solve(b,l) << " "  << i << endl;
// 	}
// }
// signed main(){
	
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vi arr(n);
//         input(arr);
//         vi pref(n+2,0);
//         for(int i=1;i<=n;i++){
//         	pref[i] = pref[i-1]+arr[i-1];
//         }
//         int q;
//         cin >> q;
//         while(q--){
//         	int a,b;
//         	cin >> a >> b;
//         	int minus = pref[a-1];
//         	int ans = INT_MIN;
//         	int index = INT_MAX;
//         	int s = a , e = n;

//         	// print(pref,a,b);
//         	// cout << endl << endl;

//         	while(s<=e){
//         		int mid = (s + e) / 2;
//         		int counter = pref[mid] - minus;
//         		int counter2 = pref[mid+1] - minus;
//         		int value = solve(b , counter);
//         		int value2 = solve(b , counter2);
//         		if(value > ans){
//         			index = mid;
//         			ans = value;
//         			if(value <= value2){
//         				s = mid+1;
//         			}
//         			else{
//         				e = mid;
//         			}
//         		}
//         		else if(value == ans){
//         			index = min(index,mid);
//         			e = mid - 1;
//         		}
//         		else{
//         			e = mid - 1;
//         		}
//         	}
//         	cout << index << " ";
//         }
//         cout << endl;
//     }
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
	vector<vector<int>>A = 
    {
        // { 1, 2, 3 },
        // { 4, 5, 6 },
        // { 7, 8, 9 }
        {1}
    };
    vector<int>ans;
    int row = A.size()-1;
    int col = A[0].size()-1;
    int cnt = (row+1) * (col+1);
    // cout << row << " " << col << endl;
    int total = 0;
    // cout << cnt << " " << total << endl;
    int s = 0 , e = 0;
    while(total < cnt){
        
        for(int i=s;i<=col;i++){
            ans.push_back(A[s][i]);            
            total++;
        }
        if(total >= cnt) break;
        for(int j = s+1;j<=row;j++){
            ans.push_back(A[j][col]);
            total++;
        }
        col--;
        if(total >= cnt) break;
        for(int i=col;i>=s;i--){
            ans.push_back(A[row][i]);
            total++;   
        }
        row--;
        if(total >= cnt) break;
        for(int j = row ; j > s ; j--){
            ans.push_back(A[j][s]);
            total++;
        }
        s++;
        e--;        
    }
    for(auto it:ans){
    	cout << it << " ";
    }
}