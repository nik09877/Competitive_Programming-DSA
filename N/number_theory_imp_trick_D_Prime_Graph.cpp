#include <iostream>

using namespace std;

bool prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

// A solution always exists. We show a simple construction.

// For n=3

// , a triangle is (the only) solution.

// For n≥4
// we make a cycle on n vertices: 1↔2↔3…n↔1. The degree of each vertex is 2 (a prime number), but the total number of edges – n – might not be. For some k, we add edges of form i↔i+n2 for all i from 1 to k. If k≤n2, each vertex gets at most one more neighbor, having degree 3

// .

// Fortunately for us, for each n≥3
// there is a prime number in interval [n,3n/2], simply the smallest of them will do.

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int m = n;
    while (!prime(m))
        ++m;
    cout << m << "\n1 " << n << '\n';
    for (int i = 0; i < n - 1; ++i)
    {
        cout << i + 1 << ' ' << i + 2 << '\n';
    }

    for (int i = 0; i < m - n; ++i)
    {
        cout << i + 1 << ' ' << i + 1 + n / 2 << '\n';
    }
}