// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 

// signed main(){
	
// 	ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     vi heroes(n);
//     int sum = 0;
//     rep(i,0,n){
//     	cin >> heroes[i];
//     	sum+=heroes[i];
//     }
//     sort(all(heroes));
//     int m;
//     cin >> m;
//     while(m--){

    	
//     	int a,b;
//     	cin >> a >> b;


// 	    int ans = n-1;
// 		int s = 0 , e = n - 1;
// 		while(s <= e){
// 			int mid = (s+e)/2;
// 			if(heroes[mid]>=a){
// 				ans = mid;
// 				e = mid-1;
// 			}
// 			else{
// 				s = mid + 1;
// 			}
// 		}

//     	int c2 = ans;
//     	int c1 = max(1LL*0,c2-1);
//     	int hero1 = heroes[c1];
//     	int hero2 = heroes[c2];

//     	int strength1 = sum - hero1;
// 		int attack1 = max(1LL*0,a-hero1);
// 		int defense1 = max(1LL*0,b-strength1);
// 		int cost1 = attack1 + defense1;

// 		int strength2 = sum - hero2;
// 		int attack2 = max(1LL*0,a-hero2);
// 		int defense2 = max(1LL*0,b-strength2);
// 		int cost2 = attack2 + defense2;


// 		cout << min(cost1,cost2) << endl;

//     }
//     return 0;
// }

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
	
	int n;
	cin >> n;

	vi arr(n);
	input(arr);
	

	rep(i,0,n){
		cout << arr[i] << endl;
	}


    return 0;
}