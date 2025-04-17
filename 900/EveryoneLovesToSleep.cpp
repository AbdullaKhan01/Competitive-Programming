#include<bits/stdc++.h>
using namespace std; 

int main(){ 
   int tt;cin >> tt;
   while (tt--)
   {
    /* code */
    int a,h,m;
    cin >> a >> h >> m;
    int ans = -1;
    int x=INT_MAX,y=INT_MAX;
    int mini = INT_MAX;
    for(int i=0;i<a;i++){
        int hh,mm;
        cin >> hh >> mm;
        if(mm <= m){
            if(hh > h) hh = hh - h;
            else hh = (24-hh) + h;
            mm = (60-m) + mm;
            
        }
        else{
            if(hh > h)  hh = hh - h;
            else hh = (24-hh) + h -1;
            mm = mm - m;
        }
        if(hh==mini){
            x = hh;
            y = min(y,mm);
        }
        else if(hh<mini){
            x = hh;
            y = mm;
            mini = hh;
        }
    }
    cout << x << " " << y << endl;
   }
     
 return 0;
}