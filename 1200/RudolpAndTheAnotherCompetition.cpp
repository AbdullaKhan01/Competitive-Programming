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
static bool cmp(pii &a,pii &b){
	if(a.first == b.first){
		return a.second <= b.second;
	}
    return a.first > b.first;
}
long long binpow(long long a, long long b, long long m=1e9+7) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main(){
	
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n,m,h;
        cin >> n >> m >> h;
        vector<vector<int>>arr(n,vector<int>(m,0));
        // cout << 10 << endl;
        // int arr[n][m];
        // for(int i=0;i<n;i++){
        // 	for(int j=0;j<m;j++){
        // 		arr[i][j] = 0;
        // 	}
        // }



        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		cin >> arr[i][j];
        	}
        	sort(all(arr[i]));
        }
        bool first1 = true;
        int rscore,rpenalty;
        vector<pair<int,int>> ls;
        for(int i=0;i<n;i++){
        	int score,penalty;
        	score = penalty = 0;
        	int cnt = 0;
        	for(int j=0;j < m;j++){
        		if(score + arr[i][j] <= h){
        			score += arr[i][j];
        			penalty += score;
        			cnt++;
        		}
        	}
        	ls.push_back({cnt,penalty});
        	if(first1){
        		rscore = cnt;
        		rpenalty = penalty;
        		first1 = false;
        	}
        }

        sort(ls.begin(),ls.end(),cmp);
        int pos = 1;
        int ans = 0;
        for(auto it:ls){
        	if(it.first == rscore && it.second == rpenalty){
        		ans = pos;
        		break;
        	}
        	pos++;
        }
        cout << ans << endl;
    }
    return 0;
}