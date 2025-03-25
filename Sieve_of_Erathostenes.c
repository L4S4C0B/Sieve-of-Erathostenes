#include <stdio.h> //puts, scanf, printf
#include <stdlib.h> // malloc(), free()
#include <time.h> //clock(), CLOCKS_PER_SEC

void IsPrimeErato(unsigned long long range)
{

    unsigned int counter1 = 0, counter2 = 0;
    clock_t time_req;

    unsigned long long* array = (unsigned long long*)malloc((range) *sizeof(unsigned long long));

    for(unsigned int i = 2; i<=range; i++)
    {
        array[i] = i;
    }

    for (unsigned long long i = 2; i * i <= range; i++) {
        if (array[i] != 0) {
            for (unsigned long long j = i * i; j <= range; j += i) {
                array[j] = 0;
            }
        }
    }

    for(unsigned long long i = 2; i<= range; i++){
        if (array[i] != 0){
            counter2++;
        }
    }

    printf("Odd numbers in this range: %d", counter2);

    time_req = time_req - clock();

    printf("\nRun-time: %f\n", (float)time_req / CLOCKS_PER_SEC);

    free(array);
    }

    int main()
        {

            unsigned long long range;

            puts("Type a number for the range: ");
            scanf("%llu", &range);

            IsPrimeErato(range);

            return 0;
        }
