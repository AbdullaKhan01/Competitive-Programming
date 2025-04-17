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
int longestSubArray(vi &arr,int n,int diff){
    int s = 0;
    int e = 1;
    int ans = INT_MIN;
    int cnt = 1;
    while(s < n && e < n){
        if(arr[e] - arr[s] <= 5){
            e++;
            cnt++;
        }
        else{
            ans = max(ans,cnt);
            while(s<=e && arr[e] - arr[s] > 5){
                cnt--;
                s++;
            }
        }
    }
    ans = max(ans,cnt);
    return ans;
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b,int mody){
    ll p = (a%mody * b%mody)%mody;
    return p;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
        vi arr(n);
        input(arr);
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i=1;i<n;i++){
        	// cout << arr[i] << " " << arr[i]%m << endl;
        	// cout << pref[i-1] << " " << pref[i-1]%m << endl;
        	pref[i] = modMul(arr[i],pref[i-1],m);
        }
        string q;
        cin >> q;
      	int left = 0;
      	int l = 1%m;
      	// cout << "bahar" << l << endl;
      	int right = n-1;
      	output(pref);
      	cout << endl;
      	// int prod = pref[n-1];
        for(int i=0;i<q.size();i++){
        	char ch = q[i];
        	int prod = pref[right];	
        	int p;
        	if(l == 0){
        		cout << "andar" << endl;
        		 p = 0;
        	}
        	else{
        		cout << "andar2" << endl;
        		cout << prod << " " << l << "\n";
        		 p = prod/l;
        	}
        	if(ch == 'R'){
        		cout << p << "RRRR" << m << endl;
        		cout << p%m << " ";
        		// prod/=arr[right];
        		right--;
        	}
        	else{
        		cout << p << "LLLL" << m << endl;
        		cout << p%m << " ";
        		l = modMul(l,arr[left],m);
        		// prod/=arr[left];
        		left++;
        	}
        }
        cout << endl;
    }
    return 0;
}