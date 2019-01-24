#include <stdio.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
int getBit(int i, int x) {
  return (1 & (x >> i));
}

int main(int argc, char *argv[]){
    int bitPattern1 = 0x10011001;
    int bitPattern2 = 0x01100110;
    int bitPattern3 = 0xFFFFFFFF;
    int bitPattern4 = 0x00000000;

    // printf("%d\n", bitPattern1);
    // printf("%d\n", bitPattern2);
    // printf("%d\n", bitPattern3);
    // printf("%d\n", bitPattern4);
    // printf("%d\n", 2 | 1);
    // printf("%d\n", 2 & 2);
    printf("%d\n", 6 & 2);
    /* pair 1 */
    printf("bitPattern1 &  bitPattern2 = %x\n", bitPattern1 &  bitPattern2);
    printf("bitPattern1 && bitPattern2 = %x\n", bitPattern1 && bitPattern2);

    /* pair 2 */
    printf("bitPattern1 |  bitPattern2 = %x\n", bitPattern1 |  bitPattern2);
    printf("bitPattern1 || bitPattern2 = %x\n", bitPattern1 || bitPattern2);

    /* pair 3 */
    printf("bitPattern1 &  bitPattern3 = %x\n", bitPattern1 &  bitPattern3);
    printf("bitPattern1 && bitPattern3 = %x\n", bitPattern1 && bitPattern3);

    /* pair 4 */
    printf("bitPattern1 |  bitPattern3 = %x\n", bitPattern1 |  bitPattern3);
    printf("bitPattern1 || bitPattern3 = %x\n", bitPattern1 || bitPattern3);

    /* pair 5 */
    printf("bitPattern2 &  bitPattern4 = %x\n", bitPattern2 &  bitPattern4);
    printf("bitPattern2 && bitPattern4 = %x\n", bitPattern2 && bitPattern4);

    /* pair 6 */
    printf("bitPattern2 |  bitPattern4 = %x\n", bitPattern2 |  bitPattern4);
    printf("bitPattern2 || bitPattern4 = %x\n", bitPattern2 || bitPattern4);

    return 0;
}
