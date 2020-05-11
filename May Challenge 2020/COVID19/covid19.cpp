#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int x[n + 1], count[n + 1];             //add 1 to answer
        for (int i = 1; i <= n; i++)
        cin >> x[i];
        for(int i = 1 ; i <= n ; i++)
        count[i] = 1;
        count[0] = 1;
        int initial = 1;
        while (initial <= n)
        {
            int k = initial; 
            while (k > 1)
            {
                if(x[k] - x[k-1] <= 2)
                {
                    count[initial]++;
                }
                else
                {
                    break;
                }
                k--;
            }
            k = initial;
            while (k < n)
            {
                if(x[k+1] - x[k] <= 2)
                {
                    count[initial]++;
                }
                else
                {
                    break;
                }
                k++;
            }
            initial++;
        }
        sort(count+1 , count+n+1);
        cout<<count[1]<<" "<<count[n]<<endl;
    }
    return 0;
}
