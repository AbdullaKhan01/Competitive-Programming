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
	
    int n;cin >> n;
    vi arr(n);
    input(arr);
    if(n == 1 || n==2){
    	cout << "no" << endl;
    	return 0;
    }
    // int l = min(arr[0],arr[1]);
    // int h = max(arr[0],arr[1]);
    int l1 = INT_MIN,l2=INT_MIN;
    int r1 = INT_MAX,r2=INT_MAX;
    bool flag = false;
    for(int i=0;i<n;i++){
    	int p = arr[i];
    	if((p>=l1 && p<=r1)||(p>=l2 && p<=r2)){

    	}
    	else{
    		flag = true;
    		break;
    	}
    	if(p>=l1 && p<=r1){
    		r2 = r1;
    		l2 = p;
    		r1 = p;
    	}
    	else if(p>=l2 && p<=r2){
    		l1 = l2;
    		r1 = p;
    		l2 = p;
    	}
    }
    cout << (flag?"yes":"no")<<endl;
    return 0;
}