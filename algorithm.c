#define INITIAL_SEED 17
#define MULTIPLIER 25173
#define INCREMENT 13849
#define MODULUS 20000

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

static unsigned seed = INITIAL_SEED;

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
    printf("숫자를 입력해 주세요.\n");
    // scanf("%d", &line);
    line = 3;
    int t[6][line];

    srand((unsigned int)time(NULL));

    for(int i=0;i<line;i++) {
        for(int j=0;j<6;j++){
            t[i][j] = random_number(j);
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<line;i++) {
        x1 = t[i][0];
        x2 = t[i][1];
        y1 = t[i][2];
        y2 = t[i][3];
        r1 = t[i][4];
        r2 = t[i][5];

        int distance = ((x1 - (y1)) + (x2 - (x2)));
        int result = 0;
        if(distance < 0) {
            distance = -distance;
        }
        printf("%d Line : %d ", (i + 1), distance);
        printf("r1 + r2 : %d \n", r1+r2);

        if(distance != 0) {
            if(distance < (r1+r2)) {
                result = 2;
            }else if(distance == (r1+r2)) {
                result = 1;
            }else {
                /* code */
                result = 0;
            }
        }else{
            /* code */
            result = -1;
        }
        
        printf("%d\n", result);
    }
}

int random_number(int number)
{
    seed = 0;
    if((number + 1) % 3 == 0){
        seed = rand() % MODULUS;
    }else{
        seed = (rand() % MODULUS) - (MODULUS/2);
    }
    
   return seed;
}