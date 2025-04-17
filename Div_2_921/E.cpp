#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define F(i, l, r) for (ll i = l; i < (r); ++i)
#define FD(i, r, l) for (ll i = r; i > (l); --i)
#define A(a) (a).begin(), (a).end()
#define K first
#define V second

// const long long M = 1000000007; ////998244353

void solve()
{
   // G(n) G(x) G(y)
    int n,x,y;
    cin >> n >> x >> y;
   vl v(n);
   map<ll,map<ll,ll>>mp;
   F(i,0,n){
        cin>>v[i];
        mp[v[i]%x][v[i]%y]++;
   }
   ll tot=0;
   auto cmp = [&](int val) {
       return (x - (val%x))%x;
   };
   for(auto i:v) tot+=mp[cmp(i)][i%y] - (i %x ==cmp(i));
   cout<<(tot/2)<<endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}