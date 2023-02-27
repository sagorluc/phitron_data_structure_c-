#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >>n;
    vector<int>a;
    a.resize(n);

    for(int i=0; i<n-1; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
    {
        a[i] = 0;
    }
    int temp[n+1];

    for(int i=0; i<n; i++)
    {
        temp[a[i]-1] = 1;
        cout<<a[i];

    }



    return 0;
}
