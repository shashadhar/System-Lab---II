#include <iostream>
#include <math.h>
using namespace std;


// BCD subtract
int bcdSubtract(int num1, int num2)
{

    // 9's complement subtract of bcds
    int bigno;

    if(num1> num2)
    {
        bigno = num1;
    }
    else
    {
        bigno= num2;
    }
    int noOfDigit = (to_string(bigno)).length();

    int number = pow(10, noOfDigit) - 1;
    int complementNo = number- num2;

    // add the complement
    int result = num1+complementNo;

    // check carry
    int noOfDigitInResult = (to_string(result)).length();

    if(noOfDigitInResult> noOfDigit)
    {
        // carry add it to result
        result = result +1;
        string stringResult = to_string(result);
        string resultWithoutCarry;

        // discard the carry
        for(int i=1; i<=noOfDigit; i++)
        {
            resultWithoutCarry= resultWithoutCarry+ stringResult.at(i);
        }

        result = std::stoi(resultWithoutCarry);

    }
    else
    {
        result = -(number- result);
    }

    return result;

}

// complement of a char
char flip(char c) {return (c == '0')? '1': '0';}


// BCD subtract
string BcdSubtract( string first, string second,char *carryPassed)
{
    string result;  // To store the sum bits

    int carry = carryPassed[0] -'0';

    // complement second number
    string second_c;
    for (int i = 0; i<3; i++)
        second_c = flip(second.at(i))+second_c ;


    // Add all bits one by one
    for (int i = 3 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second_c.at(i) - '0';


        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';

        result = (char)sum + result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
    carryPassed[0] = carry +'0';

    return result;
}

// convert the digit in bcd
string convertToBcd(int digit)
{

    char *bcdBits = new char[4];
    int index = 3;
    int num= digit;
    while(index>=0)
    {

        /* Store LSB of num to bin */
        bcdBits[index] = (digit & 1) + '0';


        /* Decrement index */
        index--;

        /* Right Shift num by 1 */
        digit >>= 1;
    }
    string result(bcdBits);
    return result;
}

// display the in bcd format
void diplayNum(int num1)
{
    string result ;
    int r1;
    num1= abs(num1);
    while (num1 != 0)
    {

        // Extract the last digit of N
        r1 = num1 % 10;

        num1 = num1 / 10;
        result=" " +convertToBcd(r1)+result;
    }
    cout << "("<<result<<")";
}

// display the num and result in correct format
void display(int num1, int num2, int result)
{
    cout << "Output:"<<endl;
    cout << num1<<" ";
    diplayNum(num1);

    cout<<" - ";
    cout<< num2 <<" ";



    diplayNum(num2);

    // result
    cout<<" = " << result;
    diplayNum(result);

}


int main()
{
    int noOfTestCases;
    cout<<"Number of test cases: ";
    cin>>noOfTestCases;

    // run the implementation for the no of test cases
    for(int cases=0; cases<noOfTestCases; cases++)
    {

        int num1, num2,bigNo,smallNo;
        cout<<endl;
        cout<<"First number: ";
        cin>>num1;
        cout << "Second number: ";
        cin>>num2;

        // get the result
        int result  = bcdSubtract(num1, num2);

        // display the result
        display(num1, num2,result);
    }

    return 0;
}







