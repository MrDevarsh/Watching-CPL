#include<bits/stdc++.h>
#include<time.h>
#define forloop(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long int
#define ld long double
#define pb emplace_back
#define ravi ios_base::sync_with_stdio(false); 
#define parmar2002 cin.tie(NULL); cout.tie(NULL);
#define nl "\n"
#define whole(x) x.begin(), x.end()
#define wholer(x) x.rbegin(), x.rend()
#define len(s) s.size()
#define endline cout<<"\n";
#define T(T) ll t; cin>>t; while(t--)
using namespace std;
ll func(vector <ll> arr, ll x)
{
    ll i = 0;
    for(i = 0; i<len(arr); i++)
    {
        if(arr[i] >= x)
        {
            return i;
        }
    }
    return i-1;
}
int main() 
{
    ravi parmar2002
    // clock_t tStart = clock();
    T(T)
    {
        ll n, h;
        cin>>n>>h;
        vector <ll> arr;
        ll sum = 0;
        forloop(i, 0, n) 
        {
            ll x;
            cin>>x;
            arr.pb(x);
            sum += x;
        }
        if(sum<2*h || n==1) cout<<-1<<nl;
        else
        {
            sort(whole(arr));
            ll sum1 = arr[n-1]; 
            ll sum2 = arr[n-2];
            arr.pop_back();
            arr.pop_back();
            ll ans = 2;
            while(1)
            {
                if((sum1 >= h && sum2 >= h) || len(arr)==0) break;
                if(sum1 < h)
                {
                    ll i = 0, flag = 0;
                    for(i=0; i<len(arr); i++)
                    {
                        if(arr[i]+sum1 >= h) 
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag==1) 
                    {
                        ans++;
                        sum1 += arr[i];
                        arr.erase(arr.begin() + i);
                    }
                    else
                    {
                        ans++;
                        sum1 += arr.back();
                        arr.pop_back();
                    }
                }
                if(sum2 < h)
                {
                    ll i = 0, flag = 0;
                    for(i=0; i<len(arr); i++)
                    {
                        if(arr[i]+sum2 >= h) 
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag==1) 
                    {
                        ans++;
                        sum2 += arr[i];
                        arr.erase(arr.begin() + i);
                    }
                    else
                    {
                        ans++;
                        sum2 += arr.back();
                        arr.pop_back();
                    }
                }
            }

            if(sum1 >= h && sum2 >= h) cout<<ans<<nl;
            else cout<<-1<<nl;
        }
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}