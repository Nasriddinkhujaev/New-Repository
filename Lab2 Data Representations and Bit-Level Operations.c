/*

    Number converter

    Menu
    Convert between integer, binary and hexadecimal

    This program should accept numeric values in hexadecimal,
    decimal and binary formats as:

        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Bin b0 to b11111111111111111111111111111111

    After a value is input the code in main will interpret the
    data types above an process the conversion to an unsigned
    int.  The unsigned int will be used to convert the input to
    strings containing hexadecimal and binary strings.

*/

#include <stdio.h>
#include <string.h>


//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);


int error = 0;


int main(){

    char input[50];
    unsigned int n = 0;
    char output[50];

    unsigned int a, b;
    printf(" --------------------- task 1 ----------------\n");
    printf("Enter first number a: ");
    scanf("%u", &a);//  user input

    printf("Enter second number b: ");
    scanf("%u", &b); // (scanf --- scans user input)  ("%u" -- unsigned integer ) ( & --- needs to address where to store the user input) ( b --- is variable where gets the input)
    getchar(); // consume leftover '\n' before fgets

    printf("a xor b = %u\n", a ^ b);
    printf("a or b = %u\n", a | b);
    
    
    // Write code here to test your functions

    // ------------------ task 2
    printf(" --------------------- task 2 ----------------\n");
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf(" --------------------- task 3 ----------------\n");

    // Uncomment code below when done

    printf("Enter a binary, decimal or hexadecimal number\n");
    printf("convert > ");
    fgets(input, sizeof(input), stdin); // gets() giving error 
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }
    // Unknown
    else{
        printf("ERROR: Unknown data type: %s\n", input);
    }

    // Print results
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);


    
}


/*
    This function converts the value part of the hex
    string to an unsigned integer value.  The first
    two chars are 0x, which tells that the string is
    in hex.  Start processing the value at index 2 until
    the null, calculating the int value as you would on
    paper.  Try on paper first.
*/
// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multiplier = 1;
    // Declare iterator
    int i = 0;
    // Loop through value part of input string
    int len = strlen(input); // same as input.length
    // 0x33
    //16^1 or 16^0
    for (i =len-1; i >= 2; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier
        if (input[i]>='0' && input[i] <= '9')
        {
            res += (input[i] - '0') * multiplier;
        }
        // If between A and F add 10 to 15 to res with multiplier
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            res += (input[i] - 'A' + 10) * multiplier;
        }
        else if (input[i] >= 'a' && input[i] <= 'f')
        {
            res += (input[i] - 'a' + 10) * multiplier;
        }
        // Error - exit
        else{
            printf("ERROR: Invalid hex character %c\n", input[i]);
            error = 1;
            return 0;
        }
        // Advance multiplier to next position value
        multiplier *= 16;
    }
        return res;
}


/*
    Copy hex_to_uint() and modify for decimal input.
*/
// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
   // Declare and set multiplier to 1
    int multiplier = 1;
    // Declare iterator
    int i = 0;
    // Loop through value part of input string
    int len = strlen(input); // same as input.length
    // example: 5
    for (i =len-1; i >= 0; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier
        if (input[i] >= '0' && input[i] <= '9'){
            res += (input[i] - '0') * multiplier;
        }
        // Error - exit
        else{
            printf("ERROR: Invalid dec character %c\n", input[i]);
            error = 1;
            return 0;
        }
        // Advance multiplier to next position value
        multiplier *= 10;
    } 

    return res;
}



/*
    Copy dec_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
   // Declare and set multiplier to 1
    int multiplier = 1;
    // Declare iterator
    int i = 0;
    // Loop through value part of input string
    int len = strlen(input); // same as input.length

    for (i =len-1; i >= 1; i--){
        // If between 0 and 1 add 1 to res with multiplier
        if (input[i] =='0' || input[i] == '1'){
            res += (input[i] - '0') * multiplier;
        }
        // Error - exit
        else{
            printf("ERROR: Invalid dec character %c\n", input[i]);
            error = 1;
            return 0;
        }
        // Advance multiplier to next position value
        multiplier *= 2;
    } 
    return res;
}


/*
    This function converts from unsigned int to a hex
    char array.  Try this on paper before coding.
*/
// Convert an unsigned integer to hexadecimal string
void uint_to_hex(unsigned int n, char *output){
    // Declare a uint for remainder
    unsigned int reminder;
    // Declare an int for division 
    int division = n;
    // Declare a char array buffer
    char arrayBuffer[50];
    int index = 0;
    
    // Use a loop to generate a hex string - string will be reverse
    if (n == 0) {
        // handle zero 
        output[0] = '0';
        output[1] = 'x';
        output[2] = '0';
        output[3] = '\0';
        return;
    }

    while (n > 0)
    {
        reminder = n % 16; // get last hex digit

        // convert reminder to hex character
        if (reminder < 10)
        {            //         '0' = 48 so 48 + reminder[1,10] gives us hex [0-9]              
            arrayBuffer[index] = '0' + reminder; // 0-9
            index++;
        }
        else
        {                       // 'A' = 65 so 65 + (reminder - 10) gives us 
            arrayBuffer[index] = 'A' + (reminder - 10); // A-F
            index++;
        }

        division = n / 16; // advance to next digit - dont really need division here
        n = division;
    }

    // terminate buffer  so array doesnt give garbage or index error
    arrayBuffer[index] = '\0';

    // Copy 0x to output string
    output[0] = '0';
    output[1] = 'x';

    // Copy chars from buffer in reverse order to output string
    for (int i = 0; i < index; i++) {
        output[2 + i] = arrayBuffer[index - 1 - i]; // output[0x index - 1 - i] its taking from third index and replace it with reversed arrayBuffer
    }

    // Put null at end of output
    output[2 + index] = '\0'; // this line terminates the buffer so array doesnt give index error

}


/*
    Copy uint_to_hex() and modify for bin
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){
unsigned int reminder;
    // Declare an int for division (we'll use n directly, so this can be optional)

    // Declare a char array buffer
    char arrayBuffer[50];
    int index = 0;
    
    // Use a loop to generate a binary string - string will be reverse
    if (n == 0) {
        // handle zero 
        output[0] = 'b';
        output[1] = '0';
        output[2] = '\0';
        return;
    }

    while (n > 0)
    {
        reminder = n % 2; // get binary character

        arrayBuffer[index++] = '0' + reminder;


        n = n / 2; // advance to next digit
    }

    // terminate buffer  so array doesnt give garbage or index error
    arrayBuffer[index] = '\0';

    // Copy b to output string
    output[0] = 'b';

    // Copy chars from buffer in reverse order to output string
    for (int i = 0; i < index; i++) {
        output[1 + i] = arrayBuffer[index - 1 - i]; // output[b index - 1 - i] its taking from third index and replace it with reversed arrayBuffer
    }

    // Put null at end of output
    output[1 + index] = '\0'; // this line terminates the buffer so array doesnt give index error
}
