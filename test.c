//variadic function

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

float   average(int num_args, ...)
{
    int total;
    va_list ap;
    int i;

    total = 0;
    va_start(ap, num_args);
    for (int i = 0; i < num_args; ++i)
        total += va_arg(ap, int);
    va_end(ap);
    printf("the total num is %d\n", num_args);
    return (total/num_args);
}

void    print(char *placeholder, ...)
{
    int length;
    int i;
    va_list args;

    va_start(args, placeholder);
    length = strlen(placeholder);
    i = 0;
    while(i < length)
    {
        if (placeholder[i] == 'd')
        {
            int x = va_arg(args, int);
            printf("%d\n", x);
        }
        else if(placeholder[i] == 'f')
        {
            double y = va_arg(args, double);
            printf("%f\n", y);
        }
        i++;
    }
    va_end(args);
}
int main()
{
    printf("The average value is %.2f\n", average(3,34,345,9));
    print("ddff", 3,2,1.4,1.5);
}