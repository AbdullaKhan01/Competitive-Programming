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
	
    int n,m;
    cin >> n >> m;
 	vi arr1(n),arr2(m);
 	input(arr1);
 	input(arr2);
 	sort(all(arr1));
 	sort(all(arr2));
 	int a = *max_element(all(arr1));
 	int time = max(arr1[0]*2,a);
 	if(a == arr1[0]){
 		if(arr2[0]>time){
 			cout << time << endl;
 		}
 		else{
 			cout << -1 << endl;
 		}
 	}
 	else{
 		if(a<=time && arr2[0]>time){
 			cout << time << endl;
 		}
 		else{
 			cout << -1 << endl;
 		}
 	}
    return 0;
}