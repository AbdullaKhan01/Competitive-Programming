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
int search1(vi &arr,vi &pref,int s,int e,int index){
	int ans = INT_MAX;
	int sub = pref[index];
	// cout << s << " " << e << endl;
	while(s <= e){
		int mid = (s+e)/2;
		// cout << mid << endl;
		// cout << "prefix is" << pref[mid] << " " << endl;
		if(pref[mid] - sub > arr[index]){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}
int search2(vi &arr,vi &suff,int s,int e,int index){
	int ans = INT_MAX;
	int sub = suff[index];
	while(s <= e){
		int mid = (s+e)/2;
		if(suff[mid] - sub > arr[index]){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        vi pref(n),suff(n);
        pref[0] = arr[0];
        suff[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
        	pref[i] = pref[i-1] + arr[i];
        }
        for(int i=n-1;i>=0;i--){
        	suff[i] = suff[i+1] + arr[i];
        }

        rep(i,0,n){
        	if(i == 0){
        		int a = search1(arr,pref,i+1,n-1,i);
        		a = abs(a-i);
        		cout << (a>=n?-1:a) << " ";
        	}
        	else if(i == n-1){
        		int l = search2(arr,suff,0,i-1,i);
        		int a1 = abs(l-i);
        		cout << (a1>=n?-1:a1) << " ";
        	}
        	else{
        		int a = search1(arr,pref,i+1,n-1,i);
        		int b = search2(arr,suff,0,i-1,i);
        		int k = abs(i-a);
        		int m = abs(i-b);
        		int g = min(k,m);
        		cout << (g >= n?-1:g) << " ";
        	}

        }
        cout << endl;
    }
    return 0;
}