// EDITORIAL
// assume L=xx..x0abc..d(B) R=xx..x1efg..h(B) obviously L<=xx..x011..1<xx..x100..0<=R,and xx..x011..1 xor xx..x100..0 is maximum

// The main problem was to find the position of the highest set bit of the number L^R and then you already know what follows. So, to do this there's one of the __builtin functions ( __builtin_clz ) which returns the number of leadings 0-bits in a given number, using this nice function it's possible to solve the problem in the following way:

#include <cstdio>
#include <iostream>
int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a == b)
    {
        std::cout << 0;
        return 0;
    }
    printf("%lld", (1LL << (64 - __builtin_clzll(a ^ b))) - 1LL);
}