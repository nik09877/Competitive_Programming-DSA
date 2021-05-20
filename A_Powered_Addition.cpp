#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846

    void solve(){
        int n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll maxi=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                maxi=max(maxi,a[i-1]-a[i]);
                a[i]=a[i-1];
            }
        }
        cout<<(int)ceil(log2(maxi+1))<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
