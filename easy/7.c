
int reverse(int x){
    int a = 0, b = 0;
    long temp = x;
    long value = 0;
    int isNegative = (x < 0)?1:0;
    if(isNegative)
    {
        temp *= -1;
        if((int)temp != temp)
        {
            temp = 0;
        }
    }
    while(temp != 0)
    {
        if(temp < 10)
        {
            value += temp;
            break;
        }
        a = temp/10;
        b = temp%10;
        value = value*10 + b*10;
        if((int)value != value)
        {
            value = 0;
            break;
        }
        temp = a;
    }
    if(isNegative)
    {
        value *= -1;
    }
    return value;
}
