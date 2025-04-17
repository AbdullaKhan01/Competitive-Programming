// // #include<bits/stdc++.h>
// // #define mod 1000000007
// // #define mod2 998244353
// // #define ceil(a,b) ((a+b-1)/b)
// // #define ll long long
// // #define int long long
// // #define vi vector<int>
// // #define all(x) (x).begin(),(x).end()
// // #define rall(x) (x).rbegin(),(x).rend()
// // #define input(x) for(auto &a:x) cin >> a;
// // #define output(x) for(auto a:x) cout << a <<" ";
// // #define rep(i,a,n) for(int i=(a);i<n;i++)
// // #define pb push_back
// // #define ppb pop_back
// // #define pf push_front
// // #define ppf pop_front
// // #define ff first
// // #define ss second
// // #define si set<int>
// // #define pii pair<int,int>
// // #define mii map<int,int>
// // #define msi map<string,int>
// // #define yes "YES"
// // #define no "NO"
// // #define endl '\n'
// // using namespace std; 
// // signed main(){
	
// //     ll tt;
// //     cin >> tt;
// //     while(tt--)
// //     {
// //     	int n;
// //     	cin >> n;    
// //     	// vi arr(n),brr(n),crr(n);
// //     	vector<pii> va,vb,vc;
// //     	for(int i=0;i<n;i++){
// //     		int x;cin >> x;
// //     		va.pb({x,i});
// //     	}
// //     	for(int i=0;i<n;i++){
// //     		int x;cin >> x;
// //     		vb.pb({x,i});
// //     	}
// //     	for(int i=0;i<n;i++){
// //     		int x;cin >> x;
// //     		vc.pb({x,i});
// //     	}
// //     	sort(all(va),greater <> ());
// //     	sort(all(vb),greater <> ());
// //     	sort(all(vc),greater <> ());
// //     	int res = -1;
// //     	for(int i=0;i<3;i++){
// //     		for(int j=0;j<3;j++){
// //     			for(int k=0;k<3;k++){
// //     				if(va[i].second != vb[j].second &&  vb[j].second != vc[k].second  && va[i].second != vc[k].second)
// //     					res = max(res,va[i].first+vb[j].first+vc[k].first); 
// //     			}
// //     		}
// //     	}
// //     	cout << res << '\n';
// //     }
    

// //     return 0;
// // }




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
// /* 
// for fast input output use printf and scanf;
// */
// signed main(){
//     fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vector<pair<int,int>>a(n),b(n),c(n);
//         for(int i=0;i<n;i++)
//         {
//             cin >> a[i].first;
//             a[i].second = i;
//         }
//         for(int i=0;i<n;i++)
//         {
//             cin >> b[i].first;
//             b[i].second = i;
//         }
//         for(int i=0;i<n;i++)
//         {
//             cin >> c[i].first;
//             c[i].second = i;
//         }
//         sort(a.rbegin(),a.rend());
//         sort(b.rbegin(),b.rend());
//         sort(c.rbegin(),c.rend());
        
//         int ans = INT_MIN;
//         for(int i=0;i<3;i++)
//         {
//             for(int j=0;j<3;j++)
//             {
//                 for(int k=0;k<3;k++)
//                 {
//                     pair<int,int> x = a[i];
//                     pair<int,int> y = b[j];
//                     pair<int,int> z = c[k];
//                     if((x.second != y.second) && (y.second != z.second) && (x.second != z.second))
//                     {
//                         ans = max(ans,x.first+y.first+z.first);
//                     }
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi a(n),b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<n;i++)
        {
            cout << a[i] << " \n"[(i+1==n)];
        }
        for(int i=0;i<n;i++)
        {
            cout << b[i] << " \n"[i+1==n];
        }
    }
    /*
    WHAT DO I WANT FROM LIFE ? 

    MONEY -> NO 
    GF -> NO 
    LUXURY -> NO

    then what ? 

    fit body -> 2 years (GYM is tiring)  
    
    competitive programming -> 2 years (I am getting less time)

    good gate preparation -> 2 years ( sorted everyday time )

    cleanliness -> everyday ( takes only 30 mins if done fast )

    prayer -> everyday ( the one who will give me all of the above needs to be thanked )

    what else -> good food ? NO > why am i overthinking so much then 



    TIME TABLE should be made 

    5:00 am to 5:30 am -> Freshen Up and Prayer
    5:30 am to 7:15 am -> Gym and come
    7:15 to 8:00 am -> bath wash clothes etc.
    8:00 am to 9:00 am -> have breakfast and go for class
    9:00 am to 1:00 pm -> college classes 
    1:30 -> come back to room after having lunch
    rest till 2:00 pm 
    2:00 pm to 5:00 pm -> C111111111111111111111111111111111111111ompetitive programming
    5:00 pm to 5:30 pm -> prayer
    5:30 pm to 6:30 pm -> revise
    6:30 pm to 8:30 pm -> GATE CLASSES if(contest then watch till 7:50) and rewatch after contest or before next day revision
    8:30 pm to 9 pm -> Dinner
    9:00 pm to 11:00 pm -> Competitive Programming( Practice or class or contest)
    11:00 pm to 11:30 pm -> Prayer 
    11:30 pm to 5:00 am -> sleep

    for Saturday and Sunday make a custom schedule 

    on Sunday no gym -> so can practice CP no college class so go for CP and AZ class


    

    // then what is going wrong such that i am feeling
    lonely 

    */
    return 0;
}













