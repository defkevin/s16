#ifndef _S16_GCD_H__
#define _S16_GCD_H__

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

#endif // _S16_GCD_H__