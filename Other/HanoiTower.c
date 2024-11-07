#include <stdio.h>

/*递归经典 汉诺塔问题*/

void HanoiTower(int n, char a, char b, char c) {
    if(n == 1){
        printf("%c to %c\n", a, c);
        return;
    }
    else{
        HanoiTower(n - 1, a, c, b);
        printf("%c to %c\n", a, c);
        HanoiTower(n - 1, b, a, c);
    }

}



int main() {
    HanoiTower(2, 'A', 'B', 'C');
}