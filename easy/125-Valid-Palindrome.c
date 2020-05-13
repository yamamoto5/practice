
bool isPalindrome(char * s){
    int i = 0, j = 0, k = 0, len = strlen(s);
    j = len;
    while(k <= strlen(s))
    {
        if((s[i]<'A' || s[i]>'Z') && (s[i]<'a' || s[i]>'z') && (s[i]<'0' || s[i]>'9'))
        {
            k++;
            i++;
            continue;
        }
        if((s[j]<'A' || s[j]>'Z') && (s[j]<'a' || s[j]>'z') && (s[j]<'0' || s[j]>'9'))
        {
            k++;
            j--;
            continue;
        }
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i] += 32;
        }
        if(s[j]>='A' && s[j]<='Z')
        {
            s[j] += 32;
        }
        if(s[i] != s[j])
        {
            return false;
        }
        k=k+2;
        i++;
        j--;
    }
    return true;
}
