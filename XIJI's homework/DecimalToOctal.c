#include <stdio.h>
/*
【问题描述】对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
【输入形式】非负十进制整数
【输出形式】相应十进制整数转换后的八进制正整数，若输入不符合要求，提示错误，重新输入
【样例输入】5548
【样例输出】12654
*/

//基于数组倒序存储
void ToOctal(int dec, int *oct_pos) {
    int oct_neg[100];
    int n = 0;
    for (n = 0; dec > 0; n++) {
        oct_neg[n] = dec % 8;
        dec /= 8;
    }
    n--;
    for (int i = 0; i < 100; i++) {
        oct_pos[i] = -1;
    }
    for (int i = 0; i <= n; i++) {
        oct_pos[i] = oct_neg[n - i];
    }
}
//基于递归逐次打印
void ToOctal_recurse(int dec) {
    if (dec <= 0) return;
    ToOctal_recurse(dec / 8);
    printf("%d", dec % 8);
}

//解决问题时注意考虑程序的健壮性,比如处理特殊数据当dec=0时的情况
int main() {
    int dec;
    scanf("%d", &dec);
    if (dec < 0) {
        return -1;
    }
    else if (dec == 0) {
        printf("0");
        return 0;
    }
    // int oct[100];
    // ToOctal(dec, oct);
    // for (int i = 0; oct[i] != -1; i++) {
    //     printf("%d", oct[i]);
    // }
    ToOctal_recurse(dec);
    return 0;
}