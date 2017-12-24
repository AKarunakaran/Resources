int fastPow(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res *= base;
        base *= base;
        power >>= 1;
    }
    return res;
}

int fastPowMod(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res = (res*base) % M;
        base = (base*base) % M;
        power >>= 1;
    }
    return res;
}