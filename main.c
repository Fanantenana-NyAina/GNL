#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);

    char    *res1 = get_next_line(fd);
    printf("print first line: %s", res1);
    char    *res2 = get_next_line(fd);
    printf("print second line: %s", res2);
    char    *res3 = get_next_line(fd);
    printf("print third line: %s\n", res3);
/*    char    *res4 = get_next_line(fd);
    printf("is there last line ?: %s", res4);*/
    close(fd);
    return 0;
}
