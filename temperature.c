#include <stdio.h>
#include <stdlib.h>

char * usage_msg =
"\
Usage: input the temperature using the format like 12.3f.\n\
    f/c means fahr / celsius temperature type;\n\
    The number before f/c means the temperature.\n\
    Use <C-c> to exit the function.\n\
";

float fahr2cel(float fahr);
float cel2fahr(float cel);

int main(void)
{
    printf("%s\n", usage_msg);

    char * str_temp, * appdix;
    /*int ret_code;*/
    /*ret_code =*/ scanf("%m[0-9.]%m[fcFC]", &str_temp, &appdix);
    /*printf("input_chars are\t%s\t%s\n", str_temp, appdix);*/

    if (str_temp == NULL || appdix == NULL) {
        printf("Error!\n");
        printf("%s\n", usage_msg);
        return 1;
    }
    else {
        float temp = atof(str_temp);
        /*printf("temp is %.1f\n", temp);*/
        if (*appdix == 'f' || *appdix == 'F') {
            /*printf("F\n");*/
            float conv_temp = fahr2cel(temp);
            printf("%.1fF  =  %.1fC\n", temp, conv_temp);
        }
        else if (*appdix == 'c' || *appdix == 'C') {
            /*printf("c\n");*/
            float conv_temp = cel2fahr(temp);
            printf("%.1fC  =  %.1fF\n", temp, conv_temp);
        }
        return 0;
    }
    return 2;
}

float fahr2cel(float fahr)
{
    float conv;
    conv = 5 * (fahr - 32) / 9;
    return conv;
}

float cel2fahr(float cel)
{
    float conv;
    conv = 9 * cel / 5 + 32;
    return conv;
}
