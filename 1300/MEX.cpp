#include <bits/stdc++.h>
using namespace std;

int mex(vector<int> arr, int n)
{
    int mex = 0;
    sort(arr.begin(), arr.end());
    if (n == 1)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == mex)
        {
            mex = arr[i] + 1;
        }
    }
    return mex;
}

bool check(vector<int> arr, int m, int n)
{
    int k = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m + 1)
        {
            k = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == m + 1)
        {
            l = i;
            break;
        }
    }
    for (int i = k; i <= l; i++)
    {
        arr[i] = m;
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i];
    // }cout<<endl;
    int nm = mex(arr, n);
    if ((nm - m) == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int m = mex(arr, n);
        if (m == -1)
        {
            if (arr[0] == 0)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
            continue;
        }
        if (check(arr, m, n))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}