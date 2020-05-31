int firstUniqChar(char * s){
    int i = 0;
    int *array = (int *)malloc(sizeof(int)*26);
    memset(array, 0, sizeof(int)*26);
    
    for(i = 0; s[i] != '\0'; i++)
    {
        array[s[i]-'a']++;
    }
    for(i = 0; s[i] != '\0'; i++)
    {
        if(array[s[i]-'a'] == 1)
        {
            free(array);
            return i;
        }
    }
    return -1;
}
