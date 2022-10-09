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

vector<int> primeDiv;
lli ar[150001], br[150001];

void addPrimes(long long int n)
{
    for (lli i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;

            primeDiv.push_back(i);
        }

    if (n > 1)
        primeDiv.push_back(n);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> ar[i] >> br[i];

    addPrimes(ar[1]);
    addPrimes(br[1]);

    for (lli d : primeDiv)
    {
        bool flag = true;
        for (int i = 2; i <= n; i++)
        {
            if ((ar[i] % d != 0) && (br[i] % d != 0))
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            cout << d;
            return 0;
        }
    }

    cout << -1;
}
