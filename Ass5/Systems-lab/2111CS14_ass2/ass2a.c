//
//  main.c
//  Lab
//
//  Created by Shashadhar Das on 08/08/21.
//

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

// convert to BCD digit
char *toBcdDigit(int digit) {

    char *bcdBits = malloc(4* sizeof(char));
    int index = 3;
    while(index>=0)
    {

        //Store LSB of num and convert it to string
        bcdBits[index] = (digit & 1) + '0';

        /* Decrement index */
        index--;

        /* Right Shift num by 1 */
        digit >>= 1;
    }
    return bcdBits;
}

// gets the digits from the decimal no
int* getDigits(int noOfDigits ,int number)
{
    // store the digits
    int *digits = malloc(noOfDigits * sizeof(int));
    int i = 0;
    int j, r;

    // till n becomes 0
    while (number != 0) {

        // extract the last digit of N
        r = number % 10;

        // put the digit in array
        digits[i++] = r;

        // update N to N/10
        number = number / 10;

    }
    return digits;
}

/* Implements the test case **/
char**  implementTestCase(){

    int decimalNUmber,bitsAvailable,noOfDigits=0;

    //Get the no of bits available
    printf("Bits available?: ");
    scanf("%d", &bitsAvailable);

    // get the decimal number
    printf("Decimal Number: ");
    scanf("%d", &decimalNUmber);

    // stores the bcd nos
    char **allDigits;


    // calculate no of digits
    int n = decimalNUmber;
    while (n != 0) {
        n = n/10;     // n = n/10
        ++noOfDigits;
    }

    // check if available bits are enough to store
    if(bitsAvailable<(noOfDigits * 4))
    {
        // don't have available bits
        char **p;
        p=(char **)malloc(2 * sizeof(char *));
        p[0]= (char *)malloc(21 * sizeof(char *));
        strcpy(p[0], "cannot be represented");
        p[1]=NULL;
        allDigits = p;
    } else {
        // get the digits array
        int* digits = getDigits(noOfDigits,decimalNUmber);

        // store the BCDs
        char** bcds;
        bcds=(char **)malloc( (noOfDigits +1)* sizeof(char *));
        int i=0;

        // start from the msb digit
        for (int j = noOfDigits - 1; j >=0; j--) {
            bcds[i++]=toBcdDigit(digits[j]);
        }
        bcds[i]=NULL;
        allDigits = bcds;
    }

    return allDigits;

}

/* Main function */
int main(int argc, const char * argv[]) {
    int noOfTestCases;
    printf("Number of test cases: ");
    scanf("%d",&noOfTestCases);


    // store the result of all test cases
    char** allNumbers[noOfTestCases];

    // calculate the BCD for each test case
    for(int i = 0 ;i<noOfTestCases ; i++){
        printf("\n");
       allNumbers[i]= implementTestCase();
    }

    // print all the test case results
    for (int i = 0; i <  noOfTestCases; i++){
        printf("\nBCD equivalent: ");
        for(int j=0; allNumbers[i][j]!=NULL;j++){
             printf("%s ", allNumbers[i][j]);
             free(allNumbers[i][j]);
        }
        free(allNumbers[i]);
    }

 return 0;
}
