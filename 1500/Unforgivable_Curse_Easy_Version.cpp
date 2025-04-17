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

// INTUITION -> 
// lets say the string is abcdefgh and k = 3
// then can we swap c and b or c and d

// to swap c and cb lets swap c and f first 
// the string will then become abfdecgh
// then swap b and c -> acfdebgh
// then swap b and f -> acbdefgh

// to now swap a and c we can use the same process
// swap c and e -> aebdcfgh
// swap a and c -> cebdafgh
// swap a and e -> cabdefgh

// now can we swap c and d in abcdefgh
// to do that we can maybe swap c and g -> abgdefch
// then maybe swap d and c -> abgcefdh
// then swap g and d -> abdcefgh 

// lets try one more method -> abcdefgh
// swap c and f -> abfdecgh

// lumos -> 
// molus ->  

void solve()
{
    int n,k;
        cin >> n >> k;
        
        string a,b;
        cin >> a >> b;

        string t1 = a,t2=b;
        sort(all(t1));sort(all(t2));
        if(t1 != t2)
        {
            cout << "NO" << endl;
            return ;
        }

        for(int i=0;i<a.size();i++)
        {
            if(a[i] != b[i] && ((i-k)<0) && (i+k)>=n)
            {
                cout << "NO" << endl;
                return ;
            }
        }
        cout << "YES" << endl;
}

signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}