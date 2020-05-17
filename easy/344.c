void reverseString(char* s, int sSize){
    int i=0;
    char temp;
    
    while(i<sSize/2)
    {
        temp = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = temp;
        i++;
    }
}
