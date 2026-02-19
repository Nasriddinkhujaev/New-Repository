#include <stdio.h> // input/output libraray

int main(){
    int n; //user input
    int sum = 0; // sum of the even number between 0 - n
    printf("enter a number: "); // prints what user should do 
    scanf("%d", &n); // takes the user input

    for (int i = 2; i <= n; i++) // loop goes through all numbers from 2 to N . i declared i as 2 because 0 and 1 is not even number so it would save some memory and time
    {
        if( i % 2 == 0){ // checks if i % 2 is = 0. If it is true then i is even 
            sum = sum + i;
        }
        
    }
    printf("%d\n", sum); // "%d" is the object type which is integer
    return 0; // int main should return int so if it return 0 it means program runned without errors 
}
    