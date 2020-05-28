uint32_t reverseBits(uint32_t n) {
    uint32_t bin = 0;
    int i = 31;
    while(i >= 0)
    {
        bin |= (n&1) << i--;
        n >>= 1;
    }
    return bin;
}
