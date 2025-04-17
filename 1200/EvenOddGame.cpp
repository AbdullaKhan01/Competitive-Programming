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
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi odd,even;
        vi arr(n);
        input(arr);
        for(int i=0;i<n;i++){
        	if(arr[i] % 2 == 0) even.pb(arr[i]);
        	else odd.pb(arr[i]);
        }
        sort(all(odd));
        sort(all(even));

        // output(even);
        // cout << endl;
        // output(odd);
        // cout << endl;
        int alice = 0,bob = 0;
        int alice_turn = 1;
        while(odd.size() || even.size()){
        	if(alice_turn){
        		if(even.size() == 0){
        			if(odd.size() != 0) odd.pop_back();
        		}
        		else{
        			if(odd.size() == 0){
        				alice+= even.back();
        				even.ppb();
        			}
        			else{
        				// cout << 'h' << endl;;;
        				if(even.back() < odd.back()){
        					// cout << 'p' << endl;
        					odd.ppb();	
        				} 
        				else alice+=even.back(),even.ppb();
        			}
        		}
        	}
        	else{
        		if(odd.size() == 0){
        			if(even.size()!= 0) even.ppb();
        		}
        		else{
        			if(even.size() == 0){
        				bob+=odd.back();odd.ppb();
        			}
        			else{
        				if(odd.back() < even.back()) even.ppb();
        				else bob+=odd.back(),odd.ppb();
        			}
        		}
        	}
        	alice_turn = !alice_turn;
        }
        if(alice > bob){
        	cout << "Alice" << endl;
        }
        else if(alice < bob){
        	cout << "Bob" << endl;
        }
        else{
        	cout << "Tie" << endl;
        }
    }
    return 0;
}