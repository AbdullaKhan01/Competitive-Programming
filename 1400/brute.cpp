// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ll long long
// #define ll long long
// #define lli long long int
// #define vi vector<int>
// #define vll vector<ll>
// #define pii pair<int,int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define llmax(a,b) max(1LL*(a),1LL*(b))
// #define output(x) for(auto a:x) cout << a <<" ";
// #define FOR(i,n) for(i=0;i<n;i++)
// using namespace std; 

// int main(){
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         ll n;
//         cin >> n;
//         int a=0,b=0,c=0,d=0;
//         vector<pii>arr;
//         while(n--){
//         	ll x,y;
//         	cin >> x >> y;
//         	if(x==0 || y==0){
//         		arr.push_back({x,y});
//         		continue;
//         	}
//         	if(x > 0 && y>0){
//         		a = 1;
//         	}
//         	else if(x > 0 && y<0){
//         		d=1;
//         	}
//         	else if(x < 0 && y>0){
//         		b = 1;
//         	}
//         	else if(x < 0 && y<0){
//         		c = 1;
//         	}
//         }
//         for(auto it:arr){
//         	int x=it.first;
//         	int y=it.second;
//         	if(x == 0){
//         		if(y > 0){
//         			if(c == 1) b=1;
//         			if(d == 1) a=1;
//         		}
//         		if(y < 0){
//         			if(a == 1) d = 1;
//         			if(b == 1) c = 1;
//         		}
//         	}
//         	if(y==0){ 	
//         		if(x > 0){
//         			if(b == 1) a=1;
//         			if(c == 1) d=1;
//         		}
//         		if(x < 0){
//         			if(a == 1) b = 1;
//         			if(d == 1) c = 1;
//         		}
//         	}
//         }
//         // cout << a << b << c << d << endl;
//         cout << ((a+b+c+d)<=2?"YES":"NO") << endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
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
        int a=0,b=0,c=0,d=0,up=0,down=0,right=0,left=0;
        while(n--){
            ll x,y;
            cin >> x >> y;
            if(x == 0){
                if(y>0) up = 1;
                if(y<0) down = 1;
                continue;
            }
            if(y == 0){
                if(x > 0) right =1;
                if(x < 0) left = 1;
                continue;
            }
            if(x > 0 && y>0){
                a = 1;
            }
            else if(x > 0 && y<0){
                d=1;
            }
            else if(x < 0 && y>0){
                b = 1;
            }
            else if(x < 0 && y<0){
                c = 1;
            }
        }
        // cout << a << b << c << d << up << down << right << left << endl;
        if(a+b+c+d > 2 ||(up && down && (b+c)==2) ||
        (right && left && (a+d)==2) || (up && (c+d)==2) 
        || (down && (a+b)==2) || (right && (b+c)==2) 
        || (left && (a+d)==2)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}