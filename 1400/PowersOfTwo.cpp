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
#define c_one(n) __builtin_popcount(n)
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
	
 	int n,k;
 	cin >> n >> k;
 	int z = c_one(n);
 	int m = 0;
 	if(k>=z && k<=n){
 		cout << yes << endl;
 		for(int i=31;i>=0;i--){
 			if(n&(1<<i)){
 				n &= ~(1<<i);
 				// int m = i+1;
 				int make = (1<<i);
 				int p = (1<<i);
 				// cout << i << " " << p << endl;
 				// cout << z << endl;
 				m++;
 				// cout << endl <<"OK " << k << " " << z << " " << m << endl;
 				int y = (k - (z - m));
 				bool flag = false;
 				// k -= y;
 				// cout << endl << p << " " << i << endl;	

 				while(y>0 && p>0){
 					flag = true;
 					if((make-p)>=y-1){
 						// cout << endl << make << " " << p << " " << y-1 << endl;
 						cout << p << " ";
 						y--;
 						make-=p;
 					}
 					else{
 						p = p / 2;
 					}
 				}
 				if(flag) k-=y;
 			}
 			if(k<=0) break;
 		}
 		// cout << endl << n << endl;
 		// for(int i=31;i>=0;i--){
 		// 	if(n&(1<<i)){
 		// 		cout << (1<<i) << endl;
 		// 	}
 		// }
 	}   
 	else{
 		cout << no << endl;
 	}
    return 0;
}