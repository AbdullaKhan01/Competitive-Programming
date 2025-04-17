#include<bits/stdc++.h>
// #include"../template.cpp"
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
void solve()
{
    int n;cin >> n;
    map<int,int> mp;
    vector<int> a(n);
    bool flag = false;
    int is_preserved = -19;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    dbg(mp);
    dbg(flag,is_preserved);
}
signed main(){
	fast_io();
    solve();
    // ll tt;
    // cin >> tt;
    // while(tt--)
    // {
    //     int n;
    //     cin >> n;
    //     vi arr(n),brr(n);
    //     input(arr);
    //     input(brr);

    //     int s1 = 0 , e1 = n-1;
    //     int s2 = 0 , e2 = n-1;

    //     bool flag = true;
    //     while(s1 < e1)
    //     {
    //     	if((arr[s1] != brr[s2]) && (arr[s1] != brr[e2]))
	//         {
	//         	flag = false;
	//         	break;
	//         }
	//         if((arr[e1] != brr[s2]) && (arr[e1] != brr[e2]))
	//         {
	//         	flag = false;
	//         	break;
	//         }
	//         if(brr[s2] == arr[s1]) s2++;
	//         if(brr[e2] == arr[s1]) e2--;
	//         s1++;
    //     }
    //     cout << (flag?"Bob":"Alice") << endl;
    // }
    return 0;
}