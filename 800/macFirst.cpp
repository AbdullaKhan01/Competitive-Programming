vector<int> nextSmaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> nextS(n);
    stack<int> st;
    st.push(n);
    for(int i=n-1;i>=0;i--)
    {
        if(st.top() == n)
        {
            nextS[i] = n;
            st.push(i);
            continue;
        }
        else
        {
            while(arr[st.top()] >= arr[i] && st.top()!=n)
            {
                st.pop();
            }
            nextS[i] = st.top();
            st.push(i);
        }
    }
    return nextS;
}