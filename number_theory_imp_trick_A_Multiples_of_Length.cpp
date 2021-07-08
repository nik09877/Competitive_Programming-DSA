#include <bits/stdc++.h>

using namespace std;

using ll = long long;

//make a[i] 0
//1-: a[i]-n*a[i] = a[i](1-n)
//2-: a[i](1-n) + (n-1)a[i] = a[i](1-n) - a[i](1-n) =  0
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    if (N == 1)
    {
        for (int z = 0; z < 3; ++z)
        {
            cout << "1 1\n";
            cout << -A[0] << "\n";
            A[0] = 0;
        }
        return 0;
    }
    cout << "1 " << N << "\n";
    for (int i = 0; i + 1 < N; ++i)
        cout << -A[i] * N << " ";
    cout << "0\n";
    cout << "1 " << N - 1 << "\n";
    for (int i = 0; i + 1 < N; ++i)
        cout << A[i] * (N - 1) << " ";
    cout << "\n";
    cout << N << " " << N << "\n";
    cout << -A[N - 1] << "\n";
    return 0;
}