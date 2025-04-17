// #include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
// using namespace __gnu_pbds;

// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
//     tree_order_statistics_node_update>
//     ordered_set;
//     /*
//     order_of_key (k) return iterator to kth largest element
//     find_by_order(k) number of items in a set that are < x

// */

// ordered_set st;
// int lessequal(int x)
// {
// 	// cout << x << endl;
// 	int ans = st.order_of_key({x+1,0});
// 	return ans;
// }
// int greaterequal(int x)
// {
// 	// cout << x << endl;
// 	int ans = st.order_of_key({x,0});
// 	// cout << ans << endl;
// 	return st.size() - ans;
// }

// /* 
// for fast input output use printf and scanf;
// */
// void solve()
// {
// 	st.clear();
// 	st.insert({0,0});
// 	int n;
// 	cin >> n;
// 	int l,u;
// 	cin >> l >> u;
// 	vector<int> a(n);
// 	vector<int> pref(n+1);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> a[i];
// 		pref[i+1] = pref[i] + a[i];
// 	}
// 	int ans = 0;
// 	// 0 3 8 7 14 32 17


// 	cout << 0 << " ";
// 	for(int i=1;i<=n;i++)
// 	{
// 		cout << pref[i] << " ";
// 	}
// 	cout << endl << endl;

// 	// [a , b , c , d , e , f]
// 	for(int i=1;i<=n;i++)
// 	{
// 		//
		

// 		int pref_r = pref[i];
// 		int a = lessequal(pref_r - l);
// 		int b = greaterequal(pref_r - u);
// 		int c = lessequal(pref_r - u - 1);
// 		int d = greaterequal(pref_r - l + 1);


// 		// 6 -7 13
// 		// 3 5 -1 7 18 -15
// 		// 3 3 3 2 1



// 		// 17 - 24 >= 

// 		// cout << pref_r << " " << pref_r - l << " " << pref_r - u << " " << a << " " << b << " " << c << " " << d << endl;	
		
// 		// cout << a << " " << b << " " << c << " " << d << endl;
// 		int cnt = max(0LL,a)  + max(0LL,b)  - c - d;
// 		// cout << pref_r << " " << cnt << " " << cnt/2 << endl;
// 		if(cnt > 0)
// 			ans += cnt/2;

// 		st.insert({pref[i],i});
// 	}
// 	cout << ans << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
// int dpWin[61][151][151][11][3];
// // int dpPos[61][160][11];
// int r[]={1,2,3,4,6,0};
// long long prob;
// const int M=1e9+7;
// ll modAdd(ll a,ll b){
//     ll p = (a%mod + b%mod)%mod;
//     return p;
// }
// ll modSub(ll a,ll b){
//     ll p = (a%mod - b%mod)%mod;
//     if(p<0) p+=mod;
//     return p;
// }
// ll modMul(ll a,ll b){
//     ll p = (a%mod * b%mod)%mod;
//     return p;
// }
// int inverse(int a,int p=mod-2){
// 	int result = 1;
// 	while(p>0){
// 		if(p&1)
// 			result = a*result %mod;
// 		a = a * a %mod;
// 		p >>= 1;
// 	}
// 	return result;
// }

// int rec1(int ballRem,int runRem,int vkRuns,int wickRem,int strike){

//     //base case   
//     if(strike == 2 && vkRuns < 100) return 0;
//     if(runRem<=0){
//         return (vkRuns>=100);
//     }
//     if(wickRem==0)return 0;
//     if(ballRem==0){
//         return 0;
//     }

//     if(ballRem % 6 == 0)
//     {
//         // strike will change
//         if(strike == 2) strike = 2;
//         else strike = !strike;
//     }

//     //cache check
//     if(dpWin[ballRem][runRem][vkRuns][wickRem][strike]!=-1){
//         return dpWin[ballRem][runRem][vkRuns][wickRem][strike];
//     }

//     int ans=0;
//     for(int i=0;i<5;i++){
//         if(i == 0 || i == 2)
//         {
//             // strike change    
//             if(strike == 1)
//             {
//                 // vk on strike
//                 ans=modAdd(ans,modMul(prob,rec1(ballRem-1,runRem-r[i],vkRuns+r[i],wickRem,0)));
//             }
//             else
//             {
//                 int nstrike = (strike == 2 ? 2 : 1);
//                 ans=modAdd(ans,modMul(prob,rec1(ballRem-1,runRem-r[i],vkRuns,wickRem,nstrike)));
//             }
            
//         }
//         else // strike not change
//         {
//             if(strike == 1)
//             {
//                 ans=modAdd(ans,modMul(prob,rec1(ballRem-1,runRem-r[i],vkRuns+r[i],wickRem,1)));       
//             }
//             else
//             {
//                 int nstrike = strike;
//                 ans=modAdd(ans,modMul(prob,rec1(ballRem-1,runRem-r[i],vkRuns,wickRem,nstrike)));   
//             }
            
//         }
//     }
//     if(strike == 1){
//         // get virat kohli out
//         ans=modAdd(ans,modMul(prob,rec1(ballRem-1,runRem,vkRuns,wickRem-1,2)));
//         // ans+=rec1(ballRem-1,runRem,vkRuns,wickRem-1,!strike);
//     }
//     else{
//         // get some other player out;
//         ans=modAdd(ans,modMul(prob,rec1(ballRem-1,runRem,vkRuns,wickRem-1,strike)));
//     }
//     //save and return
//     return dpWin[ballRem][runRem][vkRuns][wickRem][strike]=ans;
// }

// int N,b,w,x;
// void solve(){
	
//     cin>>N>>b>>w>>x;
//     int p=rec1(b,N,x,10-w,(b%6 != 0));
//     // p = 2;
//     // int q=rec2(b,N,10-w);
//     cout << p << endl;
// }

// signed main(){

//     memset(dpWin,-1,sizeof(dpWin));
//     prob = modMul(1,inverse(6));
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--)
//     solve();
//     return 0;
// }
#include <iostream>
using namespace std;
long long sumOfGoodNumbers(long long n) {
    long long sum = 0;

    for (long long x = n; x >= 1; ) {
        long long k_max = n / x;          
        sum += k_max;
        x = n / (k_max + 1);
    }

    return sum;
}

int main() {
    long long n;
    std::cin >> n;

    long long result = sumOfGoodNumbers(n);
    cout << result << endl;

    return 0;
}
