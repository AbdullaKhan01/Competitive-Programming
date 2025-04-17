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
// void generate(vector<int>&ans,int index,string s){
//     if(s.size() >= index){
//         ans.push_back(stoi(s));
//         return ;
//     }
//     generate(ans,index,s+"0");
//     generate(ans,index,s+"1");
// }
// signed main(){
//     fast_io();
//     vector<int> binaries;
//     for(int i=1;i<=6;i++){
//         generate(binaries,i,"");
//     }
//     set<int> s;
//     for(auto it:binaries){
//         s.insert(it);
//     }
//     binaries.clear();
//     for(auto it:s){
//         binaries.pb(it);
//     }
//     sort(all(binaries));

//     return 0;
// }







// // 4 2 [2,2,3]
// // 2 3 4 9 11 


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
vector<int> f(int n)
{
    vector<int> ans;
    for(int i=1;i*i<=n;i++)
    {
        if(n % i == 0)
        {
            ans.pb(i);
            if(n/i != i) ans.pb(n/i);
        }
    }
    sort(all(ans));
    return ans;
}
signed main(){
    fast_io();
       ll tt;
       cin >> tt;
       while(tt--)
       {
            int n,h;
            cin >> n >> h;
            int k = 12;
            vi arr(n);
            input(arr);
            sort(all(arr));
            // output(arr);
            // cout << endl;
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(arr[i] < h)
                {
                    h+=(arr[i]/2);
                    cnt++;
                }
                else
                {
                    vector<int> l=f(k);
                    // cout << "Entering k " << k << endl;
                    bool flag = false;
                    // 2 * 2 * 3 
                    cout << arr[i] << " " << h << " " << k << " " << cnt << endl;
                    for(auto it:l)
                    {
                        if(h * it > arr[i])
                        {
                            // cout << "YES" << it << endl;
                            h *= it;
                            h += (arr[i]/2);
                            k = k/it;
                            // cout << "k is " << k << endl;
                            flag = true;
                            cnt++;
                            break;
                        }
                    }
                    if(flag == false) break;
                }
            }
            // cout << h << endl;
            cout << cnt << "\n";    
       }   
    return 0;
}