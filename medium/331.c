#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidSerialization(char * preorder){
    int count = 1;
    int i = 0;
    char *token = strtok(preorder, ",");

    while(token != NULL)
    {
		printf("%c\n", *token);
        if(count == 0)
        {
			printf("count = %d\n", count);
            return false;
        }
        if(*token != '#')
        {
			printf("count = %d\n", count);
            count++;
        }
        else
        {
			printf("count = %d\n", count);
            count--;
        }
		printf("count = %d\n", count);
        i++;
		token = strtok(NULL, ",");
    }
    return count == 0;
}

int main()
{
	char str[] = "9,#";
	printf("\n %d\n", isValidSerialization(str) == true ? 1:0);
	return 0;
}
