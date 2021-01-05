#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int d1,v1,d2,v2,p,final=0;
	cin>>d1>>v1>>d2>>v2>>p;
	if(d1!=1 and d2!=1)
	{
		final=final+min(d1,d2)-1;
	}
if(d1<d2)
	{
		while(d1!=d2 and p>0)
		{
			p-=v1;
			d1++;
            final++;
		}
	}
else if(d2<d1)
	{
while(d2!=d1 and p>0)
	{
		p-=v2;
		d2++;
		final++;
	}
}
while(p>0)
{
	p=p-(v1+v2);
	final++;
}
	cout<<final<<endl;
	return 0;
}


