// // #include<bits/stdc++.h>
// // using namespace std; 

// // // COMPUTER -> a b c d 
// // // COMPUTER -> 1 2 3 4

// // // COMPUTER only understands BINARY LANGUAGE
// // // What is a BINARY LANGUAGE ? 
// // // Ans -> binary language is only 
// // // computer understanding language of (0 and 1)

// // // 01011101101011110101010101010


// // // 
// // // a b c d e f
// // // ASCII -> American Standard Code for Information 
// // // Interchange

// // // A -> 65 
// // // B -> 66
// // // C -> 67
// // // D -> 68 
// // // E -> 69 
// // // F -> 70

// // // Z -> 90

// // // a -> 97
// // // b -> 98
// // // c -> 99

// // // z -> 122

// // int main(){ 
// //     // 5 > 6 - false - 0
// //     // 5 < 6 - true - 1
// //     // cout <<
// //     cout << (5 > 6);
// //     return 0;
// // }

// /******************************************************************************

// CSES - Array Devision

// *******************************************************************************/
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int n,k;
// int arr[200200];

// bool check(int x){
//     int currSum = 0;
//     int j = 0;
//     int cnt = 1;
    
//     while(j<n){
//         if(currSum + arr[j]  <= x){
//             currSum+= arr[j];
//             j++;    
//         }
//         else{
//             // cnt += (j-i+1);
//             cnt++;
//             if(arr[j] <= x)
//                 currSum = arr[j++];
//             else return false;
//             // i++;
//             // j=i;
//         }
//         if(cnt > k) return false;
//     }
//     return true;
// }

// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
    
//     cin>>n>>k;
    
//     for(int i=0;i<n;i++) cin>>arr[i];
    
//     int s = INT_MIN; //when k == 1 
//     int e = 0; //when k == n
//     for(int i=0;i<n;i++){
//         s = min(s,arr[i]);
//         e += arr[i];
//     }
//     int ans = e;
    
//     while(s<=e){
//         int mid = (s + e)/2;
//         if(check(mid)){
//             ans = mid;
//             e = mid - 1;
//         }
//         else{
//             s = mid + 1;
//         }
//     }
//     cout<<ans<<endl;

//     return 0;
// }

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
signed main(){
    fast_io();
    // 2
    // x x+1 -> answer is -1 
    // 3 5
    // b-x b b+x
    // x x
    // 0 0

    // 40 * nlogn 

    // BLANK 
    // MOST COMMON OBSERVATIONS QUESTION
    // -> x x+1 -> -1
    // TC -> 40 * N*logN
    // Observation -> [a,b,..x.,,d]
    // x = (a+b+c+d)/4
    // 150/4 - 37

    // SUM / 2 for each two elements
    // 80 40 20 10
    // 20 20 40 50
    // 10 10 10 20
    // 5 5 5 5
    // 0 0 0 0


    // 100 different elements 
    // > 40 different elements 
    // > 10 20 30 40 50 ...... 400 410 420 1 op -> 1
    // 40 operations 


    // AVERAGE -> 8  
    // 43 3 17 27 a < b < c <  d
    // 43 27 17 3
    // 20 4 6 20
    // 8 8 6 8
    // 1 1 1 1
    // 0 0 0 0 


    //   
    // 23 17 3 7
    // 13 5 9 5
    // 5 3 1 3
    // 1 1 3 1
    // 0 0 2 0
    // 1 1 1 1
    // 0 0 0 0

    // 1 2 3 4 5 
    // 2 1 0 1 2
    // 1 0 1 0 1
    // 0 1 0 1 0


    // | 7 - something b/w (0 2*7) | -> will always

    // 1 2 3 4 5 10
    // | number - 10 | 
    // 9 8 7 6 5 0 <= 10
    // | number - 9 |
    // 0 1 2 3 4 9 <= 9 
    // be <= 7 so we can reduce the numbers
    // to some bracket [0,x] by replacing them
    // ai - x where each ai is <= x;

    // since we want to do it as fast as possible

    // it is optimal to reduce it by powers of 2
    // starting from the highest power because
    // it is actually >= initial elements of the array


    // 3 9 15 | 2 9 15
    // 
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        // int sum = 0;
        int gcd = 1;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];

            gcd = __gcd(arr[i],gcd);
            // sum += arr[i];
        }
        vi ans;
        // int nsum = sum;
        int ngcd = gcd;
        int avg = 0;
        for(int i=1;i<=40;i++)
        {
            // sum = nsum;
            gcd = ngcd;
            if(sum == 0) break;
            avg = max(1LL,sum / n);
            ans.push_back(avg);
            nsum = 0;
            for(int j=0;j<n;j++)
            {
                arr[j] = abs(arr[j]-avg);
                nsum += arr[j];
            }
        }
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != 0) flag = false;
        }
        if(flag == true)
        {
            cout << ans.size() << endl;
            output(ans);
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}