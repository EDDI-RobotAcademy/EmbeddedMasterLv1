#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 폐기 처분...
// void *get_sum_by_type(void *arr, int arr_len, int type)
// {
//     static void *sum = NULL;

//     if (type == INT)
//     {
//         sum = get_sum_of_int_arr((int *)arr, arr_len);
//     }
//     else if (type == DOUBLE)
//     {
//         sum = get_sum_of_double_arr((double *)arr, arr_len);
//     }

//     return (void *)sum;
// }

double get_sum(double *arr, int arr_len)
{
    int i;
    double sum = 0.0;

    for (i = 0; i < arr_len; i++)
    {
        sum += arr[i];
    }

    return sum;
}

double get_mean(double *arr, int arr_len)
{
    double sum = get_sum(arr, arr_len);

    return sum / arr_len;
}

double get_variance(double *arr, int arr_len)
{
    // variance (분산)
    double var;
    double mean_of_arr;
    int i;

    // 편차의 제곱을 저장할 배열
    double *tmp = (double *)malloc(sizeof(double) * arr_len);

    if (tmp == NULL)
    {
        printf("get_variance 함수에서 tmp 배열 동적 할당 실패!\n");
        exit(-1);
    }

    // 인자로 넘어온 배열의 평균을 구함
    mean_of_arr = get_mean(arr, arr_len);

    for (i = 0; i < arr_len; i++)
    {
        // difference (차이)
        double diff = arr[i] - mean_of_arr;
        tmp[i] = diff * diff;   // 편차의 제곱을 배열에 저장
    }

    // 편차 제곱의 평균
    var = get_mean(tmp, arr_len);

    free(tmp);
    return var;
}

double get_standard_deviation(double *arr, int arr_len)
{
    return sqrt(get_variance(arr, arr_len));
}

double get_max(double *arr, int arr_len)
{
    int i;
    double max = arr[0];

    for (i = 1; i < arr_len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

double get_min(double *arr, int arr_len)
{
    int i;
    double min = arr[0];

    for (i = 1; i < arr_len; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}

// double 배열을 가지고 통계를 구한다고 했을 때 필요한 구조체 작성
typedef struct _statistics statistics;
struct _statistics
{
    double sum;
    double mean;
    double variance;            // 분산
    double standard_deviation;    // 표준 편차
    double min;
    double max;
};

// double형 배열을 넘겨주면 통계를 계산해서 반환하는 함수
statistics get_statistics(double *arr, int arr_len)
{
    // calculation result (계산 결과)
    statistics calc_result = { 0.0 };

    // 성능은 포기하고 가독성과 유지보수성을 극대화한 코드
    calc_result.sum = get_sum(arr, arr_len);
    calc_result.mean = get_mean(arr, arr_len);
    calc_result.variance = get_variance(arr, arr_len);
    calc_result.standard_deviation = get_standard_deviation(arr, arr_len);
    calc_result.min = get_min(arr, arr_len);
    calc_result.max = get_max(arr, arr_len);

    return calc_result;
}

void print_statistics(statistics *tmp)
{
    printf("*통계*\n");
    printf("총합: %.2f\n", tmp->sum);
    printf("평균: %.2f\n", tmp->mean);
    printf("분산: %.2f\n", tmp->variance);
    printf("표준 편차: %.2f\n", tmp->standard_deviation);
    printf("최대값: %.2f\n", tmp->max);
    printf("최소값: %.2f\n", tmp->min);
}

int main(void)
{
    double arr[] = {175.0, 177.0, 179.0, 181.0, 183.0};

    statistics tmp = get_statistics(arr, sizeof(arr) / sizeof(double));

    print_statistics(&tmp);

    return 0;
}