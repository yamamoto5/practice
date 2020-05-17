int numPrimeArrangements(int n){
    int i=0, j=1, flag=0;
    int prime_num = 0, not_prime_num = 0;
    long result1 = 1;
    long result2 = 1;
    
    while(j<=n)
    {   
        flag = 0;
        if(j==1)
        {
            flag = 1;
            not_prime_num++;
        }
        else
        {   
            for(i=2; i<j; i++)
            {   
                if(j%i == 0)
                {   
                    flag = 1;
                    not_prime_num++;
                    break;
                }
            }
        }
        if(flag == 0)
        {   
            prime_num++;
        }
        j++;
    }
    
    for(i=1; i<=prime_num; i++)
    {
        result1 = (result1*i)%1000000007;
    }
    for(i=1; i<=not_prime_num; i++)
    {
        result2 = (result2*i)%1000000007;
    }
    return (result1*result2)%1000000007;
}
