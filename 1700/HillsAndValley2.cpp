#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        vector<ll> newArr(n,0);
        ll count = 0;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i] < arr[i-1] and arr[i] < arr[i+1])
            {
                count++;
                newArr[i]=2;
            }
            else if(arr[i] > arr[i+1] and arr[i] > arr[i-1])
            {
                count++;
                newArr[i] = 1;
            }
        }
        int maxi = 0;
        for(int i=1;i<n-1;i++){
            if(newArr[i] == 1)
            {
                
                if(newArr[i-1] == 2 && newArr[i+1] == 2)  
                {
                    maxi = max(maxi,3);
                }
                else if(newArr[i-1] == 2 || newArr[i+1] == 2)
                {
                    maxi = max(maxi,2);
                }
                else
                {
                    maxi = max(maxi,1);
                }
            }
            else if(newArr[i] == 2)
            {
                if(newArr[i+1]!=1 && newArr[i-1]!=1)
                {
                    maxi = max(maxi,1);
                }
                else if(newArr[i+1] == 1 && newArr[i-1]==1)
                {
                    maxi = 3;
                    break;
                }
                else {
                    maxi = max(maxi,2);
                }
            }
        }
        cout << count - maxi << endl;
    } 
    return 0;
}