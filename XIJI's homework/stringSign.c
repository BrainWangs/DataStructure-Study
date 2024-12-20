#include <stdio.h>
/*
【问题描述】假设一算术表达式中包括三种括号：圆括号（），方括号[]，花括号{}，
 且三种括号可按意 次序嵌套使用，试编写程序判定输入的表达式所含的括号是否正确配对出现
 （已知表达式已存入数据元素为字符的顺序表中）。若匹配，则返回1，否则返回0。
【输入形式】含括号的算数表达式
【输出形式】1/0
【样例输入】3+(44*[5-{6*[7*（45-10）]}])
【样例输出】1
*/

int main() {
    char str[100];
    gets(str);
    int sign1 = 0, sign2 = 0, sign3 = 0;
    char *p1 = &str[0];
    while (*p1 != '\0') {
        if (*p1 == '(' || *p1 == ')') {
            sign1++;
            p1++;
        }
        else if (*p1 == '[' || *p1 == ']') {
            sign2++;
            p1++;
        }
        else if (*p1 == '{' || *p1 == '}') {
            sign3++;
            p1++;
        }
        else {
            p1++;
        }
    }
    if (sign1 % 2 != 0 || sign2 % 2 != 0 || sign3 % 2 != 0) {
        printf("0");
        return 0;
    }
    else {
        printf("1");
        return 1;
    }
    return 0;
}