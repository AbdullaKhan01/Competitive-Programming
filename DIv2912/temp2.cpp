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
// vector<pair<int,int>>pp;
// int n,m;

// bool check(int x)
// {
// 	int cnt = 0;
// 	int maxi = INT_MIN;
// 	int available = m;
// 	int last = pp[n-1].first+1;
// 	bool flag = true;
// 	for(int i=n-1;i>=0;i--)
// 	{
// 		if(flag)
// 		{
// 			if(available >= pp[i].first)
// 			{
// 				int fact = available/pp[i].first;
// 				// fact = min(fact,pp[i].second);
// 				int cut = pp[i].first * fact;
// 				cnt += cut;
// 				available -= cut;
// 			}
// 			else {
// 				maxi = max(maxi,cnt);
// 				cnt = 0;
// 				i++;
// 				flag = false;
// 			}
// 		}
// 		else
// 		{
// 			if(m >= pp[i].first)
// 			{
// 				int fact = m/pp[i].first;
// 				// fact = min(fact,pp[i].second);
// 				int cut = pp[i].first * fact;
// 				cnt += cut;
// 				available -= cut;
// 				flag = true;
// 			}
// 			else
// 			{
// 				cnt = 0;
// 				flag = false;
// 			}
// 		}
// 	}
// 	// cout << cnt << endl;
// 	maxi = max(maxi,cnt);
// 	// cout << "for " << x << " " << maxi << " " << cnt << endl;
// 	return maxi >= x;
// }
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
        
//         cin >> n >> m;
//         pp.resize(n);
//         for(int i=0;i<n;i++)
//         {
//         	cin >> pp[i].first;
//         }
//         for(int i=0;i<n;i++)
//         {
//         	cin >> pp[i].second;
//         }
//         sort(all(pp));
//         int s = 0 , e = 1e9;
//         int ans = 0;
//         while(s <= e)
//         {
//         	int mid = (s+e)/2;
//         	if(check(mid))
//         	{
//         		ans = mid;
//         		s = mid+1;
//         	}
//         	else e = mid - 1;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }



// #include <iostream>
// #include <bits/stdc++.h>
// #define int long long int
// using namespace std;
// signed main(){
//     int t;cin>>t;
//     while(t--){
//        int n;cin>>n;
//        string s;cin>>s;
//        vector<int>v;
//        for(int i=0;i<s.size();i++){
//         if(s[i]=='0'){
//             v.push_back(i+1);
//         }
//        }
//        map<int,int>m;
//        for(int i=0;i<v.size();i++){
//         m[v[i]]=v[i];
//        }
//        if(v.size()==0){
//         cout<<0<<endl;
//        }
//        else{
//        int ans=0;
//        for(int i=0;i<v.size();i++){
//             auto it=m.find(v[i]);
//             if(it!=m.end()){
//                 ans+=(*it).second;
//                 // ans = 1 + 1 + 
//                 int c=(*it).first+(*it).second;
//                 auto it2=m.find(c);
//                 if(it2!=m.end()){
//                     int f=(*it2).first+(*it2).second;
//                     int j=(*it2).second;
//                     m.erase(it2);
//                     m[f]=j;
//                 }
//                 int f=(*it).second;
//                 m.erase(it);
//                 m[c]=f;
//                 // m[4] = 2 m.erase(2);
//                 // m[2] = 1;
//                 //
//             }
//        }
//        cout<<ans<<endl;
//     }
//     }
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
        string s;
        cin >> s;
        map<int,set<int>> mp;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0') mp[i+1].insert(i+1);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                int num = i+1;
                set<int> st = mp[num];

                ans += *st.begin();
                // cout << num << " -> ";
                for(auto it:st)
                {
                    // mp[num + it].insert(it);
                    // cout << it << " ";
                    int k = *mp[num + it].begin();
                    if(it > k)
                    {
                        mp[num + 2*it].insert(it);
                    }
                    else mp[num + it].insert(it);
                }
                // cout << endl;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}