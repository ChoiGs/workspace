#define MODULUS 20000

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int random_number(int number);
void back_joon_1002();

void fibo(int n);
void fibonacci(int n, int * count_0, int * count_1);
void back_joon_1003();

int main(int argc, char const *argv[])
{
    /* code */
    // back_joon_1002();
    clock_t start, end;
    float res;

    start = clock();
    back_joon_1003();
    end = clock();

    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("%lf", res);
    return 0;
}

void back_joon_1002()
{
    int x1 = 0;
    int x2 = 0;
    
    int y1 = 0;
    int y2 = 0;

    int r1 = 0;
    int r2 = 0;

    int line = 0;
    printf("숫자를 입력해 주세요. : ");
    scanf("%d", &line);
    int t[line][6];

    srand((unsigned int)time(NULL));

    for(int i=0;i<line;i++) {
        for(int j=0;j<6;j++){
            // t[i][j] = random_number(j);
            while(1) {
                scanf("%d", &t[i][j]);
                if((j+1)%3==0) {
                    if(t[i][j] >= 0 && t[i][j] <= 10000) {
                        break;
                    }
                }else {
                    if(t[i][j] >= -10000 && t[i][j] <= 10000) {
                        break;
                    }
                }
            }
        }
    }

    for(int i=0;i<line;i++) {
        x1 = t[i][0];
        y1 = t[i][1];
        r1 = t[i][2];
        x2 = t[i][3];
        y2 = t[i][4];
        r2 = t[i][5];

        int distance = pow((x1 - x2), 2) + pow((y1 - y2), 2);
        int result = 0;
        if(distance < 0) {
            distance = -distance;
        }
        // printf("%d Line : %d ", (i + 1), distance);
        // printf("r1 + r2 : %d \n", r1+r2);

        if(distance != 0) {
            if(distance < pow(r1+r2, 2) && distance > pow(r1-r2, 2)) {
                result = 2;
            }else if(distance == pow(r1+r2, 2) || distance == pow(r1-r2, 2)) {
                result = 1;
            }else {
                /* code */
                result = 0;
            }
        }else{
            /* code */
            if(r1 == r2){
                result = -1;
            }else {
                result = 0;
            }
        }
        
        printf("%d\n", result);
    }
}

int random_number(int number)
{
    int seed = 0;
    if((number + 1) % 3 == 0){
        seed = rand() % (MODULUS/2);
    }else{
        seed = (rand() % MODULUS) - (MODULUS/2);
    }
    
   return seed;
}


int cnt_0[41];
int cnt_1[41];
void back_joon_1003() {
    int line = 0;
    /* code */
    scanf("%d", &line);
    for(int i=0; i<line; i++){
        int n = 0;
        while (1)
        {
            /* code */
            scanf("%d", &n);
            if(0 <= n && n <= 40) break;
        }
        fibo(n);

        printf("%d %d\n", cnt_0[n], cnt_1[n]);
    }
}

void fibo(int n) {

    if (n == 0) {
        cnt_0[n] = 1;
        cnt_1[n] = 0;
        return;
    } else if(n == 1){
        cnt_0[n] = 0;
        cnt_1[n] = 1;
        return;
    }else if(cnt_0[n] == 0 && cnt_1[n] == 0) {
        fibo(n-1);
        fibo(n-2);

        cnt_0[n] = cnt_0[n-1] + cnt_0[n-2];
        cnt_1[n] = cnt_1[n-1] + cnt_1[n-2];
    }
}

void fibonacci(int n, int * count_0, int * count_1) {
    if (n == 0) {
        *count_0 = *count_0 + 1;
        return;
    } else if (n == 1) {
        *count_1 = *count_1 + 1;
        return;
    } else {
        fibonacci(n-1, count_0, count_1);
        fibonacci(n-2, count_0, count_1);
        return;
    }
}