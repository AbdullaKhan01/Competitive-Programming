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
static bool cmp(vi &a,vi&b){
	return a[0]<=b[0];
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n, m;
        cin >> n >> m;
        vector<vi>arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		cin >> arr[i][j];
        	}
        }
        sort(all(arr),cmp);
        int s = 0;
        int e = m-1;
        for(int i=0;i<m;i++){
        	int cnt = m;
        	int st = s;
        	int en = e;
        	int row = 0;
        	while(st>=0 && cnt>0){
        		cout << arr[row][st] << " ";
        		st--;row++;cnt--;
        	}
        	while(cnt>0){
        		cout << arr[row][en] << " ";
                cnt--;
        	}
            s++;
            e--;
        	cout << endl;
        }
    }
    return 0;
}