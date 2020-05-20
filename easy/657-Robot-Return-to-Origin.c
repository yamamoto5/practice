
bool judgeCircle(char * moves){
    int x = 0, y = 0;
    int i = 0;
    while(moves[i] != '\0')
    {
        if(moves[i] == 'U')
        {
            y++;
        }
        else if(moves[i] == 'D')
        {
            y--;
        }
        else if(moves[i] == 'R')
        {
            x++;
        }
        else if(moves[i] == 'L')
        {
            x--;
        }
        else
        {
            return false;
        }
        i++;
    }
    return (x == 0 && y == 0);
}
