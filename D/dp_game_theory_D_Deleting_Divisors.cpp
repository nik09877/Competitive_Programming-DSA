#include "bits/stdc++.h"
using namespace std;
/*
Let's consider 3

cases for this problem:

1) n is odd

2) n is even, and n
is not a power of 2

3) n is a power of 2

If n
is odd, the only move is to subtract an odd divisor (since all the divisors are odd). Doing this, we will obtain an even number that is not a power of 2(case 2). If D is the divisor of n, then n−D must also be divisible by D, and since D is odd, n−D cannot be a power of 2

.

If n
is even and is not a power of 2, it means that n has an odd divisor. By subtracting this odd divisor, we will obtain n−D is odd(case 1). Now let's show that subtracting an odd divisor every move results in a win. Primes are losing since the only move you can make on them is subtracting the entire number, which results in n=0

and a loss. Since every prime is odd or a power of 2, it works to give the other player an odd number because it will either be a prime(the other player loses), or they will make a move and give you another even number that is not a power of 2. You can continue this process because you will never land on a losing number and because the game must end after a finite number of moves, your opponent must always lose.

So we proved that odd numbers are losing and even numbers that are not powers of 2

are winning.

What if n
is a power of 2? You can do two things in one move, halve n or make n an even number that is not a power of 2(we proved that this is a winning position for the other player). The only optimal move is to halve n, making it another power of 2. The players continue like this until one gets 2, which is a prime number, so it's losing. If log2(n) is even, Alice wins, otherwise Bob wins.
*/
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        if (n % 2 == 1)
        {
            cout << "Bob\n";
            continue;
        }
        int cnt = 0;
        while (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }

        if (n > 1)
        {
            cout << "Alice\n";
        }
        else if (cnt % 2 == 0)
        {
            cout << "Alice\n";
        }
        else
            cout << "Bob\n";
    }
}