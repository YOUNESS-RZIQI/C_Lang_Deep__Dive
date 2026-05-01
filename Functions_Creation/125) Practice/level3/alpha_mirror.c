/*

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

*/



#include <unistd.h>

void alpha_mirror(char *s)
{


    int i = 0;
    char merror;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            merror = 'z' - (s[i] - 'a');
        else if (s[i] >= 'A' && s[i] <= 'Z')
            merror = 'Z' - (s[i] - 'A');
        else
            merror = s[i];

        write(1, &merror,1 );
        i++;

    }


}

int main(int c, char **v)
{

    if (c == 2 && v[1][0])
    {
        alpha_mirror(v[1]);
    }

    write(1, "\n", 1);

    return 0;
}