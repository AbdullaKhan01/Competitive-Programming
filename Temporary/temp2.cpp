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
int correct(int arr[],int n){
	return 0;
}
int solve(int arr[],int n){
	return 0;
}
void test(){
	srand(time(NULL));
	int cnt = 1;
	int MAX = 1e3;
	while(cnt <= MAX){
		int n = rand() % 20 + 1;
		int arr[n];
		for(int i=0;i<n;i++){
			arr[i] = rand() % 1000 + 1;
		}
		int correctAns = correct(arr,n);
		int myAns = solve(arr,n);
		if(correctAns != myAns){
			output(arr);
			break;
		}
		cnt++;
	}
}
signed main(){
	fast_io();
    cout << "here" << endl;
    return 0;
}