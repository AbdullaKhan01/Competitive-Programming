#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 
/*
VERDICT -> ACCEPTED
*/
int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n,x;
        cin >> n >> x;
        vll ans(x);
        input(ans);
        vi tracker;
        sort(all(ans));
        tracker.push_back((n-ans[x-1]) + (ans[0]-1));
        for(int i=1;i<ans.size();i++){
            tracker.push_back(ans[i]-ans[i-1] -1 );
        }
        sort(rall(tracker));
        ll l = 0;
        ll cnt = 0;
        for(auto i:tracker){
            ll x = (i-1)-l;
            if(x==0) cnt++ ,l+=4;
            else if(x>0) cnt+=x,l+=4;
            else break;
        }
        cout << n-cnt << endl;
    }
    return 0;
}