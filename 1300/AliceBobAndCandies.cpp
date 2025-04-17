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
        vi arr(n);
        input(arr);
        int alice_turn = false;
        int alice = arr[0],bob = 0;
        int sum = arr[0];
        int s = 1;
        int e = n-1;
        int cnt = 1;
        while(s <= e){
        	cnt++;
        	if(alice_turn){
        		int n1 = 0;
        		// cout << "Alice" << endl;
        		while(s<=e && s<n){
        			int ele = arr[s];
        			// cout << s << " " << ele << endl;
        			s++;
        			n1+=ele;
        			alice+=ele;
        			if(n1 > sum){
        				sum = n1;
        				break;
        			}
        		}
        		
        	}
        	else{
        		int n1 = 0;
        		// cout << "Bob" << endl;
        		while(e >= s && e>=0){
        			int ele = arr[e];
        			// cout << e << " " << ele << endl;
        			bob+=ele;
        			e--;
        			n1 += ele;
        			if(n1 > sum){
        				sum = n1;
        				break;
        			}
        		}
        	}
        	alice_turn = !alice_turn;
        }
        cout << cnt << " " << alice << " " << bob << endl;
    }
    return 0;
}