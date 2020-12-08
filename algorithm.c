#define MODULUS 20000

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int random_number(int number);
void back_joon_1002();

int main(int argc, char const *argv[])
{
    /* code */
    back_joon_1002();
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

        int distance = pow((x1 - y1), 2) + pow((x2 - y2), 2);
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