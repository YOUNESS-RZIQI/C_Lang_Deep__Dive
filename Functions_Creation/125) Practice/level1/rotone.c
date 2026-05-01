/*

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

*/

#include <unistd.h>

void rotone(char c)
{
    if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
    {
        c++;
        write(1, &c, 1);
    }
    else if (c == 'z' || c == 'Z')
    {
        if (c == 'z')
            c = 'a';
        else
            c = 'A';

        write(1, &c, 1);
    }
    else
        write(1, &c, 1);

}



int main(int c, char **v)
{

    if (c == 2 && v[1][0])
    {
        int i = 0;
        while (v[1][i])
        {
            rotone(v[1][i]);
            i++;
        }

    }

    write(1, "\n", 1);

    return 0;
}