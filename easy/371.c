
int getSum(int a, int b){
    int sum = a;
    int carry = 0;
    while(b!=0)
    {
        sum = a^b;
        carry = a & b;
        a = sum;
        b = (unsigned int)carry << 1;
    }
    return sum;
}
