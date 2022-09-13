#include <iostream>
using namespace std;

//adds the two-bit strings and return the result
string addBcdStrings( string first, string second, char* carry );


// The main function that adds two-bit sequences and returns the addition
string addBcdStrings( string first, string second,char *carryPassed)
{
    string result;  // To store the sum bits

    int carry = carryPassed[0] -'0';

    // Add all bits one by one
    for (int i = 3 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';


        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';

        result = (char)sum + result;

        // boolean expression for 3-bit carry
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    int s3 = result.at(0)-'0';
    int s2= result.at(1)-'0';
    int s1= result.at(2)-'0';
    int carryResult = carry;



    // check for invalid sum case i.e c+s3s2+s3s1
    if (carryResult | (s3 & s2) | (s3 & s1) )
    {

        string six = "0110";

        int invalidSumCarry= 0;
        string invalidResult = result;
        string validResult;

        // Add all bits one by one
        for (int i = 3 ; i >= 0 ; i--)
        {
            int firstBit = six.at(i) - '0';
            int secondBit = invalidResult.at(i) - '0';


            // boolean expression for sum of 3 bits
            int sum = (firstBit ^ secondBit ^ invalidSumCarry)+'0';

            validResult = (char)sum + validResult;

            // boolean expression for 3-bit addition
            invalidSumCarry = (firstBit & secondBit) | (secondBit & invalidSumCarry) | (firstBit & invalidSumCarry);
        }

        carry = (carryResult | invalidSumCarry);
        result = validResult;
    }


    carryPassed[0] = carry+'0';
    return result;
}

// convert the digit to BCD
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

// display no in BCD format
void diplayNum(int num1)
{
    string result ;
    int r1;
    while (num1 != 0)
    {

        // Extract the last digit of N
        r1 = num1 % 10;

        num1 = num1 / 10;
        result=" " +convertToBcd(r1)+result;
    }
    cout << "("<<result<<")";
}

// display the results in correct format
void display(int num1, int num2, string * finalResults, char* carry,int noOfDigits)
{
    cout << "Output:"<<endl;
    int result = num1 + num2;
    cout << num1<<" ";
    diplayNum(num1);

    cout<<" + ";
    cout<< num2 <<" ";
    diplayNum(num2);

    // result
     cout<<" = ";
     cout<<result<<" ";
     cout << "( ";

    if(carry[0]=='1')
    {
        cout<<"0001"<<" ";
    }
    for(int i=noOfDigits-1; i>=0 ; i--)
        cout<<finalResults[i]<<" ";
    cout<<" )";

}


int main()
{
    int noOfTestCases;
    cout<<"Number of test cases: ";
    cin>>noOfTestCases;

    // run the implementation as no of test cases
    for(int cases=0; cases<noOfTestCases;cases++){

    int num1, num2,bigNo,smallNo;
    cout<<endl;
    cout<<"First number: ";
    cin>>num1;
    cout << "Second number: ";
    cin>>num2;

    // get the big no
    if(num1>num2)
    {
        bigNo = num1;
        smallNo = num2;
    }
    else
    {
        bigNo = num2;
        smallNo = num1;

    }

    int i = 0;
    int j, r1,r2;

    string result;

    // store the carry from each digit i.e final carry
    char *carry = new char[1];
    carry[0] ='0';

    // store all the digits sum result
    string *finalResults;
    int noOfDigits = (to_string(bigNo)).length();
    finalResults = new string[noOfDigits];
    i=0;

    // for each digit add the digits after converting to bcd
    while (bigNo != 0)
    {

        // Extract the last digit of N
        r1 = bigNo % 10;
        r2= smallNo %10;
        bigNo = bigNo / 10;
        smallNo = smallNo /10;
        result=  addBcdStrings(convertToBcd(r1),convertToBcd(r2), carry);
        finalResults[i++]= result;
    }

    // display the numbers in correct format
    display(num1, num2, finalResults, carry, noOfDigits);

    // delete the memory
    delete[] finalResults;
    delete[] carry;
    }

    return 0;
}







