#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll >
#define vvll vecotr<vll >
#define vl vector<ll> 
#define vvl vector<vl >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for(long long x = 0; x < n; x++)
#define _input(arr, NN) loop(ii, NN)cin>>arr[ii];
#define input2(arr, NN, MM) loop(ii, NN)loop(jj, MM)cin>>arr[ii][jj]
#define ini(arr, N) loop(ii, N)scanf("%d", &arr[ii]);
#define inl(arr, N) loop(ii, N)scanf("%ld", &arr[ii]);
#define ini2(arr, N, M) loop(ii, N)loop(jj, M)scanf("%d", &arr[ii][jj]);
#define inl2(arr, N, M) loop(ii, N)loop(jj, M)scanf("%ld", &arr[ii][jj]);
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define ff first
#define ss second
#define pb push_back

using namespace std;


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin>>N>>M;
        int arr[N];
        bool graph[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                graph[i][j] = false;
        for(int n = 0; n < N; n++)
        {
            cin>>arr[n];
            arr[n]--;
        }
        int x, y;
        for(int m = 0; m < M; m++)
        {   
            cin>>x>>y;
            graph[x-1][y-1] = graph[y-1][x-1] = true;
        }
        int id = 0;
        int group[N] = {0};
        bool visited[N];
        memset(visited, false, sizeof(visited));

        for(int n = 0; n < N; n++)
        {
            if(!visited[n])
            {
                id++;
                queue<int> q;
                q.push(n);
                visited[n] = true;
                group[n] = id-1;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for(int v = 0; v < N; v++)
                    {
                        if(!visited[v] && graph[u][v])
                        {
                            visited[v] = true;
                            group[v] = id-1;
                            q.push(v);
                        }
                    }
                }
            }
        }



        int cross[id][id];
        for(int i = 0; i < id; i++)
            for(int j = 0; j < id; j++)
                cross[i][j] = 0;

        for(int n = 0; n < N; n++)
            cross[group[n]][group[arr[n]]]++;
        
        for(int n = 0; n < id; n++)
            cross[n][n]=0;
        
        int num = 0;
        
        // bool inside = false;

        for(int k = 0; k < N; k++)
        {
            // inside = true;
            for(int i = 0; i < id; i++)
            {
                for(int j = 0; j < id; j++)
                {
                    if(cross[i][j] > 0 && i!=j)
                    {
                        // inside = false;
                        bool visit[id];
                        memset(visit, false, sizeof(visit));
                        vector<int> st;
                        st.pb(i);
                        visit[i] = true;
                        bool flag = false;
                        int ele;
                        while(!st.empty())
                        {
                            flag = true;
                            int u = st.back();
                            for(int vv = st.size()-1; vv >= 0; vv--)
                            {
                                if(cross[u][st[vv]] > 0)
                                {
                                    flag = false;
                                    ele = st[vv];
                                    break;
                                }
                            }
                            if(flag)
                            {
                                for(int v = 0; v < id; v++)
                                {
                                    if(cross[u][v] > 0)
                                    {
                                        if(!visit[v])
                                        {
                                            st.pb(v);
                                            visit[v] = true;
                                            break;
                                        }
                                        if(visit[v])
                                        {
                                            ele = v;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(st.back()==u)
                            {
                                break;
                            }
                            assert(!st.empty());
                        }
                        int v = ele;
                        while(!st.empty() && st.back() != ele)
                        {
                            int u = st.back();
                            cross[u][v]--;
                            num++;
                            st.pop_back();
                            v = u;
                        }
                        assert(st.back() == ele);
                        cross[ele][v]--;
                    }
                }
            }
        }
        // assert(inside == true);
    cout<<num<<endl;
    // assert(t < 1);
    }
    // assert(maxid > 11);
    return 0;
}
