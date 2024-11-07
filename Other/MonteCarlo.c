/*蒙特卡洛法计算圆周率 pi*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 设置随机数种子
    srand(time(NULL));
    unsigned long circle_times = 0;
    unsigned long times;
    printf("输入实验次数(单位*10000):\n");
    scanf("%ul",&times);
    times *= 10000;

    for(unsigned long i = 0; i <= times; i++) {
        // 生成一个0到1之间的随机小数
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if(x * x + y * y <= 1) {
            circle_times++;
        } 
    }
    float p = (float)circle_times / (float)times;
    printf("pi = %f", p * 4.0);

    return 0;
}