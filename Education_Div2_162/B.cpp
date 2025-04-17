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
int n,k;
vector<int> a;
int maxi = 1;
int sum = 0;
bool check(int mid)
{
    int freq = sum / mid;
    if(sum % mid != 0) freq++;
    if((mid * freq - sum) > k) return 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] > mid)
        {
            return 1;
        }
    }
    maxi = max(maxi,freq);
    return 1;
}
void solve()
{
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int s = 0 , e = 20;
    while(s <= e)
    {
        int mid = (s+e)/2;
        // cout << "for " << mid;
        if(check(mid))
        {
            // cout << " YES" << endl;
            s = mid+1;
        }
        else
        {
            // cout << " NO" << endl;
            e = mid - 1;
        }
    }
    cout << maxi << endl;
}

enum Color { RED = 0, GREEN = 1, BLUE = 2 };

signed main() {
    Color c = GREEN;
    int colorValue = static_cast<int>(c);  // Cast enum to int
    cout << "Enum GREEN as int: " << colorValue << endl;

    int num = 2;
    Color colorFromInt = static_cast<Color>(num);  // Cast int to enum
    cout << "Integer 2 as enum: " << colorFromInt << endl;
    
    return 0;
}