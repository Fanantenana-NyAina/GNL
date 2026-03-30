#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);

    char    *res = get_next_line(fd);

    while (res)
    {
        printf("%s", res);
    }

    return 0;
}