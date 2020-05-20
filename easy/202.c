bool isHappy(int n){
    int a = 0;
    int b = 0;
    int sum = n;
    int temp = 0;
    while(sum != 1)
    {
        a = sum/10;
        b = sum%10;
        temp = 0;
        do
        {
            temp += b*b;
            if(a < 10)
            {
                temp += a*a;
                break;
            }
            else
            {
                b = a%10;
                a = a/10;
            }
        }while(1);
        
        sum = temp;
        if(temp == 4)
        {
            return false;
        }
    }
    return true;
}
