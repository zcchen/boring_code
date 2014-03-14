#include <stdio.h>
#include <string.h>
#include <math.h>

long double everyset(long long abc)
{
    long double signal = 0;
    if (abc % 2 == 0)
        signal = -1.0;
    else
        signal = 1.0;
    long double ret = 0.0;
    long double realA = abc * 2.0;
    ret = signal * 4.0 / (realA * (realA + 1) * (realA + 2));
    /*printf("everyset is %llf \n", ret);*/
    return ret;
}

long double pi(long long abc)
{
    long long i = 1;
    long double ret = 3;
    char x[4];
    long percent;
    while (i <= abc){
        if (i % 100 == 0) {
            percent = ceil(i * 100 / abc);
            sprintf(&x[0], "%2d", percent);
            x[2] = '%';
            x[3] = '\0';
            printf("\r%s", x);
            fflush(stdout);
        }

        ret = ret + everyset(i);
        i++;
    }
    printf("\r100%\n");
    return ret;
}

int char2int(char c)
{
    if (c < 0x30 || c > 0x39)
        goto Error;
    else
        return (c - 0x30);
Error:
    return -1;
}

long long char2llong(const char* chars)
{
    long long ret = 0;
    /*printf("The expected number is %s.\n", chars);*/
    long chars_size = strlen(chars);
    for (long i = 0; i < chars_size; i++) {
        ret = ret + char2int(*(chars + i)) * pow(10, (chars_size - 1 - i));
    }
    /*printf("ret is %lld \n", ret);*/
    return ret;
}

int main(int argc, const char *argv[])
{
    if (argc != 2)
        printf("Usage: pi.o <long_int_number>\n");
    else{
        long long para = char2llong(argv[1]);
        long double pi_number = pi(para);
        /*char x[4];*/
        /*int percent;*/
        /*for (long long i = 0; i <= para; i++) {*/
            /*percent = ceil(i / para * 100);*/
            /*sprintf(&x[0], "%2d", percent);*/
            /*x[2] = '%';*/
            /*x[3] = '\0';*/
            /*printf("\r%s", x);*/
        /*}*/
        printf("The value of pi is %.100llf \n", pi_number);
    }
    return 0;
}
