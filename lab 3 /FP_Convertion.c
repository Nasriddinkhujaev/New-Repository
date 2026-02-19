#include <stdio.h>
#include <string.h>

void print_type_conversions(signed char sc); // function should be declred before main
unsigned int bin_to_uint(char *input);
void uint_to_bin(unsigned int value, char *output);

void bitwise_OR(int a, int b);
void bitwise_AND(int a, int b);
void bitwise_XOR(int a, int b);

int main(int argc, char const *argv[])
{
    printf("------------------------------------------ task 2 \n");
    print_type_conversions(-7); // convert function call

    printf("------------------------------------------ task 3 \n");
    unsigned int a, b;

    printf("Enter the first Unsigned integer: ");
    scanf("%u", &a);

    printf("Enter the second Unsigned Integer: ");
    scanf("%u", &b);

    bitwise_OR(a, b);
    bitwise_AND(a, b);
    bitwise_XOR(a, b);

    return 0;
}
void print_type_conversions(signed char sc)
{
    unsigned char usc = sc;
    short sx = sc;
    unsigned short usx = sc;
    unsigned short usy = sx;
    int ty = sc;
    unsigned int uty = ty;

    printf("sc (signed char): %d | hex = %x\n", sc, sc);
    printf("usc (unsigned char): %u | hex = %x\n", usc, usc);
    printf("sx (short): %d | hex = %x\n", sx, sx);
    printf("usx (unsigned short from sc): %u | hex = %x\n", usx, usx);
    printf("usy (unsigned short from sx): %u | hex = %x\n", usy, usy);
    printf("ty (int): %d | hex = %x\n", ty, ty);
    printf("uty (unsigned int): %u | hex = %x\n", uty, uty);
}

// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input)
{
    unsigned int res = 0;
    int multiplier = 1;
    int len = strlen(input);
    for (int i = len - 1; i >= 0; i--) // start from 0
    {
        if (input[i] == '0' || input[i] == '1')
            res += (input[i] - '0') * multiplier;
        else
        {
            printf("ERROR: Invalid binary character %c\n", input[i]);
            return 0;
        }
        multiplier *= 2;
    }
    return res;
}

// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int value, char *output)
{
    char arrayBuffer[50];
    int index = 0;

    if (value == 0)
    {
        output[0] = '0';
        output[1] = '\0';
        return;
    }

    while (value > 0)
    {
        arrayBuffer[index++] = '0' + (value % 2);
        value /= 2;
    }

    // reverse into output
    for (int i = 0; i < index; i++)
    {
        output[i] = arrayBuffer[index - 1 - i];
    }
    output[index] = '\0';
}
// ---------------------------------------- taks 3
void bitwise_OR(int a, int b)
{
    char a_bin[50], b_bin[50], res_bin[50], bit_a, bit_b;
    int len_a, len_b, max_len;

    // convert to binary
    uint_to_bin(a, a_bin);
    uint_to_bin(b, b_bin);

    // find the legnth of the biary
    len_a = strlen(a_bin);
    len_b = strlen(b_bin);

    // get the max len
    if (len_a >= len_b)
    {
        max_len = len_a;
    }
    else
        max_len = len_b;

    for (int i = 0; i < max_len; i++)
    {
        // aligning shorter string with leading 0s for a . i have separate if else otherwise shorter one could have wrong alignment
        if (i < max_len - len_a)
            bit_a = '0';
        else
            bit_a = a_bin[i - (max_len - len_a)];

        if (i < max_len - len_b)
            bit_b = '0';
        else
            bit_b = b_bin[i - (max_len - len_b)];

        // manual OR
        if (bit_a == '1' || bit_b == '1')
            res_bin[i] = '1';
        else
            res_bin[i] = '0';
    }

    // this ends the array
    res_bin[max_len] = '\0';

    // convert result back to decimal
    unsigned int result = bin_to_uint(res_bin);

    printf(" a OR b = %u\n ", result);
}

void bitwise_AND(int a, int b)
{
    char a_bin[50], b_bin[50], res_bin[50], bit_a, bit_b;
    int len_a, len_b, max_len;

    // convert to binary
    uint_to_bin(a, a_bin);
    uint_to_bin(b, b_bin);

    // find the length of the binary strings
    len_a = strlen(a_bin);
    len_b = strlen(b_bin);

    // get the max len
    if (len_a >= len_b)
    {
        max_len = len_a;
    }
    else
        max_len = len_b;

    for (int i = 0; i < max_len; i++)
    {
        // aligning shorter string with leading 0s for a . i have separate if else otherwise shorter one could have wrong alignment
        if (i < max_len - len_a)
            bit_a = '0';
        else
            bit_a = a_bin[i - (max_len - len_a)];

        if (i < max_len - len_b)
            bit_b = '0';
        else
            bit_b = b_bin[i - (max_len - len_b)];
        // manual AND
        if (bit_a == '1' && bit_b == '1')
            res_bin[i] = '1';
        else
            res_bin[i] = '0';
    }

    // terminate the result string
    res_bin[max_len] = '\0';

    // convert result back to decimal
    unsigned int result = bin_to_uint(res_bin);

    printf("a AND b = %u\n", result);
}

void bitwise_XOR(int a, int b)
{
    char a_bin[50], b_bin[50], res_bin[50], bit_a, bit_b;
    int len_a, len_b, max_len;

    // convert numbers to binary strings
    uint_to_bin(a, a_bin);
    uint_to_bin(b, b_bin);

    // find the length of the binary strings
    len_a = strlen(a_bin);
    len_b = strlen(b_bin);

    // get the maximum length
    max_len = (len_a >= len_b) ? len_a : len_b;

    for (int i = 0; i < max_len; i++)
    {
        // align shorter string with leading zeros for a
        if (i < max_len - len_a)
            bit_a = '0';
        else
            bit_a = a_bin[i - (max_len - len_a)];

        // align shorter string with leading zeros for b
        if (i < max_len - len_b)
            bit_b = '0';
        else
            bit_b = b_bin[i - (max_len - len_b)];

        // manual XOR
        if (bit_a != bit_b)
            res_bin[i] = '1';
        else
            res_bin[i] = '0';
    }

    // terminate the result string
    res_bin[max_len] = '\0';

    // convert result binary back to decimal
    unsigned int result = bin_to_uint(res_bin);

    printf("a XOR b = %u\n", result);
}