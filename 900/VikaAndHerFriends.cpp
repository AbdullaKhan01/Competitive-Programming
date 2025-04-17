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

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        int x,y;
        cin >> x >> y;
        bool flag=false;
        while(c--){
            int x1,y1;
            cin >> x1 >> y1;
            if((x1+y1)%2 == (x+y)%2)
                flag = true;
        }
        cout << (flag?"NO":"YES") << endl;
    }
    return 0;
}