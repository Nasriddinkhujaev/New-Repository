#include <stdio.h>

// -------------------- task 1

int getLength(char input[])
{
    int size = 0;
    while (input[size] != '\0') // \0 is = null so when input[size] = null it stops
    {
        size++;
    }
    return size;
}

void reverseInPlace(char input[]) // create temp array and store the first half of input array and assign second half of input array to first half then replace the second half with temp
{
    int len = getLength(input);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = input[i];
        input[i] = input[len - 1 - i];
        input[len - 1 - i] = temp;
    }
}

int checkLCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}

int upperCase(char input[])
{
    int count = 0;
    int len = getLength(input);
    for (int i = 0; i < len; i++)
    {
        if (checkLCase(input[i]))
        {
            input[i] = input[i] - 32;
            count++;
        }
    }
    return count;
}

void keyboardInput(char input[], int maxLen)
{
    fgets(input, maxLen, stdin); // this reads the entire line including spaces

    int len = getLength(input);
    if (len > 0 && input[len - 1] == '\n')
    { // if there is a space then perform  space = null
        input[len - 1] = '\0';
    }
}

void printOutput(char input[], int length, int capCount)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c\n", input[i]);
    }
    printf("The string is %d chars and %d chars were capitalized", length, capCount);
}

// -------------------- task 2
int SortAndFind(char Arr[], int x) // if Arr is char then each element cant be greater than 127 or less than -128
{
    int len = getLength(Arr);
    int index = -1;
    char *smaller;
    char *bigger;

    // bubble sort
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                smaller = &Arr[j + 1]; // points to the smaller element
                bigger = &Arr[j];      // points to the bigger element
                char temp = *smaller;
                *smaller = *bigger; // move the bigger one to next
                *bigger = temp;     // move the smaller one to previous
            }
        }
    }
    for (int l = 0; l < len; l++)
    {
        if (Arr[l] == x) // find the x
        {
            index = l;
            return index; // stop at first occurrence
        }
    }
    return index; // return -1 if not found
}

// -------------------- task 3

int match_content(char *file1, char *file2)
{
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    if (f1 == NULL || f2 == NULL)
    {
        if (f1 != NULL)
        {
            fclose(f1);
        }
        if (f2 != NULL)
        {
            fclose(f2);
        }
        return 0; // one of the files coudnt open
    }
    while (1)
    {
        int ch1 = fgetc(f1); // reads one character at a time
        int ch2 = fgetc(f2);

        if (ch1 >= 'A' && ch1 <= 'Z')
        {                            // convert uppercase to lowercase
            ch1 = ch1 + ('a' - 'A'); // 'a' - 'A' = 32
        }
        else
        {
            ch1 = ch1; // do nothing for other chars
        }
        if (ch2 >= 'A' && ch2 <= 'Z')
        {
            ch2 = ch2 + ('a' - 'A');
        }
        else
        {
            ch2 = ch2;
        }

        if (ch1 == EOF && ch2 == EOF)
        { // EOF end of file
            fclose(f1);
            fclose(f2);
            return 1; // if both files ended and match
        }
        else if (ch1 == EOF || ch2 == EOF)
        {
            fclose(f1);
            fclose(f2);
            return 0; // one file ended first
        }
        else if (ch1 != ch2)
        {
            fclose(f1);
            fclose(f2);
            return 0; // different characters
        }
    }
}

int main(int argc, char const *argv[])
{
    char str[100];
    keyboardInput(str, 100);
    int length = getLength(str);
    reverseInPlace(str);
    int capCount = upperCase(str);

    printf("\n output: \n");
    printOutput(str, length, capCount);
    printf("\n \n---------------------------------------------------- task 1\n");

    char arr[] = {'d', 'a', 'c', 'b', 'e'};
    int x = 'c';
    int index = SortAndFind(arr, x);

    printf("Sorted array: ");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\nIndex of %c: %d\n", x, index);

    printf("\n \n---------------------------------------------------- task 2\n");

    char file1[] = "file1.txt";
    char file2[] = "file2.txt";

    if (match_content(file1, file2))
    {
        printf("\nFiles match!\n");
    }
    else
    {
        printf("\nFiles do not match.\n");
    }
    printf("\n \n---------------------------------------------------- task 3\n");

    return 0;
}
