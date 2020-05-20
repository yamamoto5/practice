
#define MAX_SIZE 22
char * defangIPaddr(char * address){
    char *result = (char *)malloc(MAX_SIZE);
    int i = 0, j = 0;
    while(address[i] != '\0')
    {
        if(address[i] != '.')
        {
            result[j++] = address[i++];
        }
        else
        {
            result[j++] = '[';
            result[j++] = address[i++];
            result[j++] = ']';
        }
        
    }
    result[j] = '\0';
    return result;
}
