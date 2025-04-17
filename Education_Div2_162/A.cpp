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
int apSum(int a,int n){
	int ans = (n * (2*a - (n-1)))/2;
	return ans;
}
int solve(int m,int p){
	// cout << "in func" << endl;
	// cout << "Start" << m << endl;
	// cout << "no of ele" << p << endl;
	return apSum(m,p);
}
void print(vi &pref,int a,int b){
	int minus = pref[a-1];
	for(int i=a;i<=b;i++){
		int l = pref[i] - minus;
		cout << solve(b,l) << " "  << i << endl;
	}
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
        vi pref(n+1,0);
        for(int i=1;i<=n;i++){
        	pref[i] = pref[i-1]+arr[i-1];
        }
        int q;
        cin >> q;
        while(q--){
        	int a,b;
        	cin >> a >> b;
        	int minus = pref[a-1];
        	int mid = (a+n)/2;
        	// cout << mid << endl;
        	print(pref,a,b);
        	cout << endl << endl;
        	int ans = solve(b,pref[mid]-minus);

        	int index = mid;
        	// cout << ans << " " << index << " " << pref[mid]-minus << endl;
        	
        	int s1 = a,e1 = mid;
        	int s2 = mid+1,e2 = n;
        	cout << "ans is " << ans << endl;
        	while(s1 <= e1){
        		// cout << "first while" << endl;
        		int mid1 = (s1+e1)/2;
        		int midd1 = mid1+1;
        		// cout << pref[mid2] << endl;
        		int mn = pref[mid1] - minus;
        		int mn2 = pref[midd1] - minus;
        		int gg = solve(b,mn);
        		int pp = solve(b,mn2);
        		cout << "here " << mid1 << endl;
        		// cout << mid1 << " " << mn << " " << gg << endl;
        		if(gg == ans){
        			// cout << "nono"<<endl;
        			if(mid1 < index){
        				index = mid1;
        			}
        			s1 = mid1+1;
        		}
        		if(gg > ans && gg > pp){
        			// cout << "here"<<endl; 
        			index = mid1;
        			ans = gg;
        			// s1 = mid1 + 1;
        			e1 = mid1-1;
        		}
        		else{
        			// cout << "where" << endl;
        			s1 = mid1 + 1;
        			// e1 = mid1-1;
        		}
        		cout << s1 << " " << e1 << endl;
        	}
        	// cout << "in" << endl;
        	// cout << s2 << " " << e2 << endl;
        	// cout << "here" << ans << endl;
        	while(s2 <= e2){
        		// cout << "second while" << endl;
        		int mid2 = (s2+e2)/2;
        		int midd2 = mid2 + 1;
        		int mn = pref[mid2] - minus;
        		int mn2 = pref[midd2] - minus;	
        		// cout << pref[mid2] << endl;
        		int gg = solve(b,mn);
        		int pp = solve(b,mn2);
        		cout << "here2 " << mid2 << endl;
        		// cout << mid2 << " "<< mn <<  " " << gg << endl;
        		if(gg == ans){
        			// cout << "no" << endl;
        			if(mid2 < index){
        				index = mid2;
        			}
        			s2 = mid2+1;
        		}
        		else if(gg > ans && gg > pp){
        			// cout << "here2" << endl;
        			index = mid2;
        			ans = gg;
        			s2 = mid2 + 1;
        		}
        		else{
        			e2 = mid2 - 1;
        		}
        		// cout << "here" << s2 << " "<< e2 << endl;
        	}
        	// cout << ans << endl;
        	cout << index << " ";        	
        }
        cout << endl;
    }
    return 0;
}