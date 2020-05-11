#include<bits/stdc++.h>
    #define ll long long 
    #define vll vector<ll >
    #define vvll vecotr<vll >
    #define vl vector<ll> 
    #define vvl vector<vl >
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    #define loop(x, n) for(long long x = 0; x < n; x++)
    #define _input(arr, NN) loop(ii, NN)cin>>arr[ii];
    #define input2(arr, NN, MM) loop(ii, NN)loop(jj, MM)cin>>arr[ii][jj]
    #define ini(arr, N) loop(ii, N)scanf("%d", &arr[ii]);
    #define pll pair<ll, ll> 
    #define ff first
    #define pb push_back
    #define ss second
    #define int ll
    #define umap unordered_map
    #define str to_string

using namespace std;

void _swap(ll arr[], ll x, ll y, ll z){
    ll temp = arr[z];
    arr[z] = arr[y];
    arr[y] = arr[x];
    arr[x] = temp;
    return;
}

bool dif(ll a, ll b, ll c){
    if(a == b || a == c || b==c)return false;
    else return true;
}

int32_t main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        string ans="";
        ll n, k;
        cin>>n>>k;
        ll count = 0;
        ll A[n], arr[n], idx[n];
        _input(A, n);
        stack<pll > buf;
        vector<pll > vp;
        pll p;
        loop(i, n){
            p.ff = A[i];
            p.ss = i;
            vp.push_back(p);
        }
        sort(vp.begin(), vp.end());
        loop(i, n){
            arr[vp[i].ss] = i;
            idx[i] = vp[i].ss;
        }
        

        for(ll i = 0 ; i < n; i++){
            if(arr[i] == i || (!buf.empty()&& i == buf.top().ss) ){
                continue;
            }
            ll j = arr[i];
            ll id = idx[i];
            if(arr[j] != i){
                ll k = arr[j];
                idx[i] = i;
                idx[j] = j;
                _swap(arr, i, j, id);
                // assert(dif(i, j, id));
                assert(id!=j);
                idx[k] = id;
                ans += str(id+1) + " " + str(i+1) + " " + str(j+1) + "\n";
                count++;
                continue;
            }

            if(!buf.empty() && buf.top().ss == i)continue;

            if(buf.empty()){
                p.ff = i;
                p.ss = arr[i];
                // assert(i != arr[i]);
                buf.push(p);
                continue;
            }
            p = buf.top();
            buf.pop();
            count+= 2;
            _swap(arr, p.ff, p.ss, i);
            _swap(arr, p.ff, j, i);
            ans += str(p.ff+1) + " "+str(p.ss+1)+" "+str(i+1)+"\n";
            ans += str(p.ff+1) + " "+str(j+1)+" "+str(i+1)+"\n";
            idx[p.ff] = p.ff;
            idx[j] = j;
            idx[i] = i;
            idx[p.ss] = p.ss;
            assert(dif(p.ff, p.ss, i) && (p.ff, j, i));
            continue;
            }
            bool flag = false;
            loop(i, n)if(arr[i] != i){flag = true;break;}
            if(flag || !buf.empty() || k < count){
                cout<<-1<<endl;
                continue;
            }
            cout<<count<<endl<<ans;
    }
    return 0;
}
