#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int main(void)
{
    ft_printf("%x\n", UINT_MAX);
    printf("%x\n", UINT_MAX);
    return (0);
}