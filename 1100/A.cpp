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

    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        // string l;
        int s1=0,e1=0;
	    int stemp = 0,etemp=0;
	    int cnt = 1;
	    int maxi = INT_MIN;
	    for(int i=1;i<n;i++){
	    	if(s[i] == s[i-1]){
	    		cnt++;
	    		etemp++;
	    	}
	    	else{
	    		if(cnt >= maxi){
	    			s1 = stemp;
	    			e1 = i-1;
	    			maxi = cnt;
	    		}
	    		cnt = 1;
	    		stemp = i;
	    		etemp = i;
	    	}
	    }
	    if(cnt >= maxi){
			s1 = stemp;
			e1 = n-1;
			maxi = cnt;
	    }
	    char p = s[n-1];
	    int cnt2 = 1;
	    if(e1 != n-1){
	    	for(int i=s.size()-1;i>0;i--){
	    		if(s[i] == s[i-1]){
	    			cnt2++;
	    		}
	    		else{
	    			// cout << i << "Here"<<endl;
	    			break;
	    		}
	    	}
	    }
	    else cnt2 = maxi;
	    // cout << cnt2 << endl;
	    bool first = true;
	    string l;
        for(int i=0;i<q;i++){
        	cout << maxi << " ";
        	char ch;
        	cin >> ch;
        	l.pb(ch);
        	if(first){
        		if(p == ch){
        			cnt2++;
        			maxi = max(maxi,cnt2);
        		}
        		else{
        			first = false;
        			cnt2 = 1;
        			maxi = max(maxi,cnt2);	
        		}
        	}
        	else{
        		if(l[i-1] == l[i]){
        			cnt2++;
        			maxi = max(maxi,cnt2);
        		}
        		else{
        			cnt2 = 1;
        		}
        	}
        }
        cout << maxi << endl;
    }
    return 0;
}