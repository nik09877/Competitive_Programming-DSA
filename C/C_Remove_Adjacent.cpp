#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

int main()
{
    string st;
    int n;
    cin >> n >> st;

    for (char ch = 'z'; ch > 'a';)
    {
        bool flag = 0;
        for (int i = 0; i < st.size(); i++)
            if (st[i] == ch)
            {
                if ((i > 0 && st[i - 1] == (char)(ch - 1)))
                    st.erase(st.begin() + i), flag = 1;
                else if (i + 1 < st.size() && st[i + 1] == (char)(ch - 1))
                    st.erase(st.begin() + i), flag = 1;

                if (flag)
                    break;
            }

        if (!flag)
            ch--;
    }

    cout << n - st.size();
}
