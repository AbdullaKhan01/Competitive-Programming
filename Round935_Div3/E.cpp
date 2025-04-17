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
class bag
{
public:
    int K;
    priority_queue<int> pq;
    int sumK;
    void init(int _K)
    {
        K = _K;
        sumK = 0;
    }
    void insert(int x)  // O(logn)
    {
        sumK += x;
        pq.push(-x);
        if (pq.size() > K)
        {
            int sm = -pq.top();
            pq.pop();
            sumK -= sm;
        }
    }

    int topk()   // O(1)
    {
        return sumK;
    }
};
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m,d;
        cin >> n >> m >> d;
        bag b;
        b.init(d);
        int ans = 0;
        vi arr(n+1);
        for(int i=1;i<=n;i++)
        {
        	cin >> arr[i];
        }
        for(int i=1;i<=n;i++)
        {
        	b.insert(arr[i]);
        	ans = max(ans,b.topk()-(d*i));
        }
        cout << ans << endl;
    }
    return 0;
}