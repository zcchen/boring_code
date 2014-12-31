#include <stdio.h>

/*#define len(##X) sizeof(##X)/sizeof(##X[0])*/

double data[] = {
    0, 1, 3, 5, 7, 9, 7, 6, 5, 4, 6, 8, 10, 12, 15,
    14, 12, 10, 8, 6, 4, 3, 4, 6, 7, 5, 4, 3, 1,
};
double array[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
};

#define LENGTH(x)  (sizeof(x) / sizeof(x[0]))

int find_the_biggest(double *data_array, int data_len, int * biggest_num)
{
    *biggest_num = 0;
    for (int i = 0; i < data_len; i++) {
        if (*(data_array + i) > *(data_array + *biggest_num))
            *biggest_num = i;
    }
    /*printf("The biggest num is %d, %lf\n", *biggest_num, *(data_array + *biggest_num));*/
    return 0;
}

int find_the_lowest_one_before_biggest(double *data_array, int data_len, int * lowest_one_before_biggest)
{
    int biggest_num;
    find_the_biggest(&data[0], LENGTH(data), &biggest_num);
    *lowest_one_before_biggest = biggest_num;
    for (int i = biggest_num; i > 1; i--) {
        if (*(data_array + i - 1) > *(data_array + i)){
            *lowest_one_before_biggest = i;
            break;
        }
    }
    /*printf("The lowest one before the biggest is %d, %lf\n",*/
           /**lowest_one_before_biggest, *(data_array + *lowest_one_before_biggest));*/
    return 0;
}

int find_the_2nd_biggest(double *data_array, int data_len, int * sec_biggest_num)
{
    *sec_biggest_num = 0;
    int lower;
    find_the_lowest_one_before_biggest(&data[0], LENGTH(data), &lower);
    for (int i = 0; i < lower; i++) {
        if (*(data_array + i ) > *(data_array + *sec_biggest_num))
            *sec_biggest_num = i;
    }
    /*printf("The second biggest num is %d, %lf\n", *sec_biggest_num, *(data_array + *sec_biggest_num));*/
    return 0;
}

int find_the_equal_one(double *data_array, int data_len,
                       double * ratio_between, int * equal_start)
{
    int biggest_num = 0;
    int lowest_one_before_biggest = 0;
    int sec_biggest_num = 0;
    find_the_biggest(&data[0], LENGTH(data), &biggest_num);
    find_the_lowest_one_before_biggest(&data[0], LENGTH(data), &lowest_one_before_biggest);
    find_the_2nd_biggest(&data[0], LENGTH(data), &sec_biggest_num);
    for (int i = lowest_one_before_biggest; i < (biggest_num - 1); i++) {
        if ( *(data_array + i) <= *(data_array + sec_biggest_num) &
             *(data_array + i + 1) >= *(data_array + sec_biggest_num) ){
            *ratio_between = (*(data_array + sec_biggest_num) - *(data_array + i) ) \
                           / (*(data_array + i + 1) - *(data_array + i) );
            *equal_start = i;
        }
    }
    /*printf("The equal_start num is %d, %lf\n", *equal_start, *(data_array + *equal_start));*/
    /*printf("The ratio between is %lf\n", *ratio_between);*/
}

int findout_all(double *data_array_1, double *data_array_2)
{
    int biggest_num = 0;
    int lowest_one_before_biggest = 0;
    int sec_biggest_num = 0;
    double ratio = 0.0;
    int equal_start = 0;
    find_the_biggest(&data_array_1[0], LENGTH(data_array_1), &biggest_num);
    find_the_lowest_one_before_biggest(&data_array_1[0], LENGTH(data_array_1), &lowest_one_before_biggest);
    find_the_2nd_biggest(&data_array_1[0], LENGTH(data_array_1), &sec_biggest_num);
    find_the_equal_one(&data_array_1[0], LENGTH(data_array_1), &ratio, &equal_start);
    double point[3][2];
    point[0][0] = *(data_array_1 + sec_biggest_num);
    point[0][1] = *(data_array_2 + sec_biggest_num);
    point[1][0] = *(data_array_1 + lowest_one_before_biggest);
    point[1][1] = *(data_array_2 + lowest_one_before_biggest);
    point[2][0] = *(data_array_1 + equal_start) + ratio * (*(data_array_1 + equal_start + 1) - *(data_array_1 + equal_start));
    point[2][1] = *(data_array_2 + equal_start) + ratio * (*(data_array_2 + equal_start + 1) - *(data_array_2 + equal_start));
    printf("Peak value: (%lf, %lf)\n", point[0][0], point[0][1]);
    printf("Trough value: (%lf, %lf)\n", point[1][0], point[1][1]);
    printf("Equal value: (%lf, %lf)\n", point[2][0], point[2][1]);
}

int main(void)
{
    printf("The main func is for the test!\n");
    printf("The length of data[] is %d \n", LENGTH(data));
    printf("The length of array[] is %d \n", LENGTH(array));
    double ratio = 0.0;
    findout_all(&data[0], &array[0]);
    return 0;
}
