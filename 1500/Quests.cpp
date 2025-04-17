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
int n,c,d;
vector<int> arr;

bool check(int x)
{

    int cnt = 0;
    if(x == 0) return (arr[0]*d) >= c;
    x++;
    for(int i=1;i<=n;i++)
    {
        
        int num = arr[i-1];
        int freq = ceil(max(0LL,d-i+1),x);
        cnt += num * freq;
        if(i == d || i==x) break;
    }
    return cnt >= c;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        cin >> n >> c >> d;
        arr.resize(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        sort(rall(arr));
        int s = 0 , e = 1e18;
        int ans = -1;
        while(s <= e)
        {
            int mid = (s+e)/2;
            if(check(mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        if(ans == 1e18)
        {
            cout << "Infinity" << endl;
        }
        else if(ans == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}