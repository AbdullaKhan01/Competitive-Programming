#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        vi arr(n);
        input(arr);
        ll maxi = 0;
        ll count =0;
        bool flag = true;
        bool added = false;
        int last = -1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= 1){
                count+=maxi;
                added = true;
                maxi = arr[i];
            }
            else{
                maxi = llmax(maxi,arr[i]);
                added = false;
            }
        }
        count+=maxi;
        cout << count << endl;
    }
    return 0;
}