#include <iostream>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int x,y;
        cin>>x>>y;
        long long int a,o1,b,o2;
        a=x/2;
        b=y/2;
        o1=(x+1)/2;
        o2=(y+1)/2;
        cout<<a*b+o1*o2<<endl;
    }
    return 0;
}
