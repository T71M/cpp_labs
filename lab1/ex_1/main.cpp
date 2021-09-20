#include <iostream>
using namespace std;
#include <random>


 int processArray(int array[]) {
     int a;
     int b;
     int negative[15];
     int counter = 0;


     printf("введите число a: ");
     scanf("%d", &a);

     printf("введите число b: ");
     scanf("%d", &b);

     cout << "source array" << endl;
     for (int i = 1; i < 15; i += 2) {
         array[i] *= rand() % a - b;
         if (array[i] < 0) {
             negative[counter++] = array[i];
         }
     }

     for (int i = 0; i < 15; i++) {
         cout << array[i] << " ";
     }

     printf("\n");
     printf("answer: \n");
     

     for (int i = 0; i < counter; i++) {
         printf("%d", negative[i]);
     }


     return counter;
}




int main() {
    int array[15];
    int count = 0;
    while (count < 15) {
        array[count++] = 1;
    }
    int answer = processArray(array);
    printf( "count: ");
    printf("\n");
    printf("%d", answer);
    printf("\n");
    
    return 0;
}

