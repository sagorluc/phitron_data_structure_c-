#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

for(int k=1;k<=n;k++)
{
	if(k%2==0){
		for(int i=1;i<=n;i++)
		{
			cout<<"k = "<<k<<" "<<"i = "<<i<<"\n";
		}
	}
}


    return 0;
}

/*

time complexity- O(logn)

*/
