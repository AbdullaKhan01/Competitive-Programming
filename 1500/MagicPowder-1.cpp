#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 
bool isPossible(vll need,vll ing,ll n,ll k,ll tar)
{
    ll a;
    FOR(a,n)
    {
        ll req = tar*need[a];
        ll ava = ing[a];
        if(ava < req)
        {
            k-=(req-ava);
            if(k<0)
            return false;
        }
    }
    return true;
}
int main(){ 
    ll n,k;
    cin >> n >> k;
    vll arr1(n),arr2(n);
    ll i;
    FOR(i,n)
    {
        cin >> arr1[i];
    }
    FOR(i,n)
    {
        cin >> arr2[i];
    }
    ll s = 0,e=*max_element(all(arr2)) + k;
    ll ans=0;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(isPossible(arr1,arr2,n,k,mid))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}