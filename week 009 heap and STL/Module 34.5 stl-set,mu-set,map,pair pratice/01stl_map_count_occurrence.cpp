#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];

    map<int, int> m;

    for(int i=0; i<n; i++)
        m[a[i]]++;

    for(auto it : m)
        cout<<it.first<<": "<<it.second<<"\n";


    return 0;
}
