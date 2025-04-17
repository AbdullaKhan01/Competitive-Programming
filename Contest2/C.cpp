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
long long binpow(long long a, long long b, long long m=1e9+7) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
struct dash
{
    //mean
    int sum = 0;
    int cnt = 0;
    int inv2 = binpow(2,mod-2);
    //mode
    map<int,int> mp;
    multiset<pair<int,int>> f;

    //median
    multiset<int> low,high;
    void balance()
    {
        if(low.size() < high.size())
        {
            int val = *high.begin();
            high.erase(high.find(val));
            low.insert(val);
        }
        if(low.size() > high.size() + 1)
        {
            int val = *low.rbegin();
            low.erase(low.find(val));
            high.insert(val);
        }
    }
    void insert(int x)
    {
        //mean
        sum += x;
        cnt++;

        //mode
        int freq = mp[x];
        if(f.find(make_pair(freq,-x))!=f.end())
        {
            f.erase(f.find(make_pair(freq,-x)));
        }
        mp[x]++;
        f.insert({mp[x],-x});

        //median
        if(low.empty()) low.insert(x);
        else if(x <= *low.rbegin())
        {
            low.insert(x);
        }else{
            high.insert(x);
        }
        balance();
    }
    void remove(int x)
    {
        //mean
        sum -= x;
        cnt--;

        //mode
        int freq = mp[x];
        if(f.find(make_pair(freq,-x))!=f.end())
        {
            f.erase(f.find(make_pair(freq,-x)));
        }
        mp[x]--;
        if(mp[x])f.insert({mp[x],-x});

        //median
        if(high.find(x) != high.end())
        {
            high.erase(high.find(x));
        }
        else if(low.find(x) != low.end())
        {
            low.erase(low.find(x));
        }
        balance();
    }
    int getMean()
    {
        if(cnt == 0) return -1;
        int l = binpow(cnt,mod-2);
        return ((sum%mod) * l)%mod;
    }
    int getMedian()
    {
        if(cnt == 0) return -1;
        if(cnt%2 != 0)
        {
            int val = *low.rbegin();
            return val%mod;
        }
        else 
        {
            int val = *low.rbegin() + *high.begin();
            return ((val%mod) * inv2)%mod;
        }
    }
    int getMode()
    {
        if(cnt==0) return -1;
        return abs(f.rbegin()->second);
    }
};
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int q;
        cin >> q;
        dash d;
        while(q--)
        {
            string s;
            cin >> s;
            if(s == "insert")
            {
                int x;
                cin >> x;
                d.insert(x);
            }
            else if(s == "remove")
            {
                int x;
                cin >> x;
                d.remove(x);
            }
            else if(s == "getMean")
            {
                cout << d.getMean() << endl;
            }
            else if(s == "getMedian")
            {
                cout << d.getMedian() << endl;
            }
            else 
            {
                cout << d.getMode() << endl;
            }
            // cout << "done" << endl;
        }
    }
    return 0;
}