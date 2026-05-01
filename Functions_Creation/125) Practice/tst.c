#include <unistd.h>

void print_bits(unsigned char oct)
{
    unsigned char result;
    int i = 8;
    while (i-- > 0)
    {
        result = (oct >> i &1) + '0';
        write(1, &result, 1);
    }
}

unsigned char reverse_bits(unsigned char oct)
{
    unsigned char result;
    int i = 8;
    while (i-- > 0)
    {
        result = result * 2 + (oct % 2);
        oct /= 2;
    }
    return result;
}

unsigned char swap_bits(unsigned char oct)
{
    return( oct >> 4 | oct << 4);
}

int main(void)
{
    
    print_bits(2);
    write(1, "\n", 1);
    print_bits(reverse_bits(2));
    write(1, "\n", 1);
    print_bits(swap_bits(2));
    return 0;
}