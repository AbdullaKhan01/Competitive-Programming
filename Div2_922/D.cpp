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
int msb(int n) {      // Efficient approach
  
    for(int i = 1; i <= 64; i*=2){
        n |= n >> i;
    }
  
    n = n + 1;
    return n>>1;
}
int give(int n){
	int l = msb(n);
	int ind=0;
	for(int i=0;i<=64;i++){
		if((1 << i) == l){
			ind = i;
			break;
		}
	}
	ind++;
	return ind;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int a,b,x;
        cin >> a >> b >> x;
        if(a<b) swap(a,b);
        int take = 0;
        int first = true;
        for(int k=63;k>=0;k--){
            int mask = (1LL << k);
        	int bit1 = a & mask;
        	int bit2 = b & mask;
            int ab = a ^ mask;
            int bc = b ^ mask;
            if(bit1 != 0 && bit2 == 0){
                if(first){
                    first = false;
                    continue;
                }
                if((take | mask)<=x ){
                    a = ab;
                    b = bc;
                    take += mask;
                }    
            }
            
            // if(abs(ab-bc)<=abs(a-b)){
            //     a = ab;
            //     b = bc;
            //     take |= (1<<k);
            // }
            // if(a < b){
            //     swap(a,b);
            // }	
        }
        // cout << "take" << take<<endl;
        cout << abs(a - b) << endl;
    }
    return 0;
}