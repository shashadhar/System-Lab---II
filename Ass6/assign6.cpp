/**
 * @file assign6.cpp
 * @author Shashadhar Das (2111cs14)
 * @brief
 * @version 0.1
 * @date 2022-03-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// delimeter to token the file input line
const char *delim = " ";
int noOfHashFunctions, noOfTotalElements, noOfElementsInserted, noOfQueryElements;
string elementsString = "";

// Class represents element and hashpair
class ElementHashPair
{
public:
    int element;
    int hashIndex;
    ElementHashPair *right;
};


// Class stores all the element hash pair
class ElementHashPairs
{
public:
    ElementHashPair *startNode = NULL;
    ElementHashPair *lastNode = NULL;

    // insert a node to the list
    void insertNode(ElementHashPair *node)
    {
        // first node
        if (startNode == NULL)
        {

            startNode = node;
            lastNode = node;
        }
        else
        {
            lastNode->right = node;
            lastNode = node;
        }
    }
};

// Class represents a hash function
class HashFunction
{
public:
    int index = 0;
    int a;
    int b;
    int c;
    HashFunction *right = NULL;
};


// Stores all the hash functions
class HashFunctions
{
public:
    HashFunction *startNode = NULL;
    HashFunction *lastNode = NULL;

    // inserts a hash function to the list
    void insertNode(HashFunction *node)
    {
        // first node
        if (startNode == NULL)
        {
            node->index = 1;
            startNode = node;
            lastNode = node;
        }
        else
        {
            node->index = lastNode->index + 1;
            lastNode->right = node;
            lastNode = node;
        }
    }

    // Calculate hash index
    int calculateHashIndex(HashFunction *hash, int element)
    {
        // h(x) = ((ax + b) mod c) mod n

        int ax = ((hash->a % hash->c) * (element % hash->c)) % hash->c;
        int b = hash->b % hash->c;
        int ax_b = ((ax % hash->c) + (b % hash->c)) % hash->c;
        int index = ax_b % noOfTotalElements;
        return index;
    }


    // Display a hash function
    void displayHashFunctions()
    {
        HashFunction *first;
        for (first = startNode; first->right != NULL; first = first->right)
        {
            cout << "a:" << first->a << " "
                 << "b:" << first->b << " "
                 << "c:" << first->c << endl;
        }
        cout << "a:" << first->a << " "
             << "b:" << first->b << " "
             << "c:" << first->c << endl;
    }
};

// Used to store all the hash functions
HashFunctions hashFunctions;

// checks if the string is valid number
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

// reads a single line with hash data and token the string with delimeter " "
// and converts data to Hash class
bool readHashData(string line)
{
    bool validInput = true;
    int cols = 0;

    // gets the next token separated by the delimeter and we should have only 3 values
    // separated by delimeter " "
    char *token = strtok(const_cast<char *>(line.c_str()), delim);
    cols++;
    bool validNumerical = true;
    HashFunction *hash = new HashFunction();
    while (token != nullptr)
    {
        switch (cols)
        {

        // it should be "a" value
        case 1:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    // converts string value to integer
                    num = stoi(token);
                    hash->a = num;
                }
                catch (const exception &e)
                {
                    validInput = false;
                }
            }
            else
            {
                validInput = false;
            }
            break;
        }

        // it should be "b" value
        case 2:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    // converts string value to integer
                    num = stoi(token);
                    hash->b = num;
                }
                catch (const exception &e)
                {
                    validInput = false;
                }
            }
            else
            {
                validInput = false;
            }
            break;
        }

        // it should be "c" value
        case 3:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    // converts string value to integer
                    num = stoi(token);
                    hash->c = num;
                }
                catch (const exception &e)
                {
                    validInput = false;
                }
            }
            else
            {
                validInput = false;
            }
            break;
        }

        default:
            // something wrong
            validInput = false;
            break;
        }

        if (validInput == false)
        {
            break;
        }
        token = strtok(nullptr, delim);
        cols++;
    }

    // we successfully tokenized, store the node
    if (validInput)
    {
        hashFunctions.insertNode(hash);
    }
    return validInput;
}

// Read data from the input file ip.txt
bool readDataFromFile(ofstream *outFile)
{
    bool validInput = true;
    int lines = 1;
    ifstream inputFile("ip.txt");

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {

            string inputLine = line;
            if (lines == 1)
            {
                if (isNumber(line))
                {
                    noOfHashFunctions = stoi(line);
                    lines++;
                }
                else
                {
                    cout << " Not a valid input number";
                    *outFile << "Not A Valid Input\n";
                    return false;
                }
            }
            else if (lines <= noOfHashFunctions + 1)
            {
                if (readHashData(inputLine))
                {

                    // cout << "No of Nodes" << noOfNodes++;
                }
                else
                {
                    cout << "Not A Valid Input\n";
                    *outFile << "Not A Valid Input\n";
                    validInput = false;
                    break;
                }
                lines++;
            }
            else if (lines == noOfHashFunctions + 2)
            {
                if (isNumber(line))
                {
                    noOfTotalElements = stoi(line);
                    lines++;
                }
                else
                {
                    cout << " Not a valid input number";
                    *outFile << "Not A Valid Input\n";
                    return false;
                }
            }
            else if (lines == noOfHashFunctions + 3)
            {
                if (isNumber(line))
                {
                    noOfElementsInserted = stoi(line);
                    lines++;
                }
                else
                {
                    cout << " Not a valid input number";
                    *outFile << "Not A Valid Input\n";
                    return false;
                }
            }
            else if (lines == noOfHashFunctions + 4)
            {

                elementsString.append(line);
            }
        }
    }
    inputFile.close();
    return validInput;
}

// Main Function
int main()
{
    int noOfProcess;

    ofstream outFile;
    outFile.open("op.txt");
    if (readDataFromFile(&outFile))
    {
        int insertedElements[noOfElementsInserted];
        int bloomFilter[noOfTotalElements];
        int maxElementInserted = -1;

        noOfQueryElements = noOfTotalElements - noOfElementsInserted;
        int falsePositives[noOfQueryElements];
        int queryElements[noOfQueryElements];
        ElementHashPairs elementHashPairsList[noOfTotalElements];

        // assing zero to all bloom
        for (int i = 0; i < noOfTotalElements; i++)
        {
            bloomFilter[i] = 0;
        }

        // get the elements to the array

        // gets the next token separated by the delimeter, we have all the elements here
        // separated by delimeter " "
        char *token = strtok(const_cast<char *>(elementsString.c_str()), delim);
        bool validNumerical = true;
        HashFunction *hash = new HashFunction();
        int i = 0;
        while (token != nullptr)
        {

            if (isNumber(token))
            {
                int num = stoi(token);
                insertedElements[i++] = num;
                if (num > maxElementInserted)
                {
                    maxElementInserted = num;
                }
            }
            else
            {
                cout << "Not a valid input\n";
            }

            token = strtok(nullptr, delim);
        }

        // create the bloom filter
        for (int i = 0; i < noOfElementsInserted; i++)
        {
            int number = insertedElements[i];
            // cout<<"Trying bloom filter for element:"<< number;

            // try all the hashes

            HashFunction *first;
            for (first = hashFunctions.startNode; first != NULL; first = first->right)
            {
                if (first != NULL)
                {
                    // get the hash index value to set
                    int index = hashFunctions.calculateHashIndex(first, number);
                    bloomFilter[index] = 1;

                    // store the element hash pair in the list
                    ElementHashPair *elementHashPair = new ElementHashPair();
                    elementHashPair->element = number;
                    elementHashPair->hashIndex = first->index;
                    elementHashPairsList[index].insertNode(elementHashPair);
                }
            }
        }

        outFile.close();
        string str = "op_m";

        // output file name
        string outputFileName = str.append(to_string(noOfHashFunctions)).append("n").append(to_string(noOfTotalElements)).append("k").append(to_string(noOfElementsInserted)).append(".txt");
        outFile.open(outputFileName);
        outFile << "m = " << noOfHashFunctions << endl;
        cout << "m = " << noOfHashFunctions << endl;
        outFile << "n = " << noOfTotalElements << endl;
        cout << "n = " << noOfHashFunctions << endl;
        outFile << "k = " << noOfElementsInserted << endl;
        cout << "k = " << noOfHashFunctions << endl;

        // display the boom filter
        cout << "The Boom Filter is" << endl;
        outFile << "The Boom Filter is" << endl;
        cout << "|";
        outFile << "|";
        for (int i = 0; i < noOfTotalElements; i++)
        {
            cout << " " << bloomFilter[i] << " |";
            outFile << " " << bloomFilter[i] << " |";
        }
        cout << endl;
        outFile << endl;

        cout << "Press Enter to Continue\n";
        cin.ignore();

        // generate the query elements
        int num = maxElementInserted;
        for (int i = 0; i < noOfQueryElements; i++)
        {
            num = num + 1;
            queryElements[i] = num;
        }

        /*queryElements[0] = 0;
        queryElements[1] = 1;
        queryElements[2] = 2;
        queryElements[3] = 13;
        queryElements[4] = 14;
        queryElements[5] = 15;*/

        //cout << "Query elements\n";
        //for (int i = 0; i < noOfQueryElements; i++)
        //{
        //    cout << queryElements[i] << " ";
        //}

        cout << "Membership queries" << endl;
        outFile << endl
             << "Membership queries" << endl;

        int totalFPCases = 0;
        // create the false positives array for each element
        for (int i = 0; i < noOfQueryElements; i++)
        {
            int atmost = 0;
            int queryElement = queryElements[i];
            
            // check the indexes for each hash functions
            HashFunction *first;
            bool fp = true;
            string hashPairsString = "";
            for (first = hashFunctions.startNode; first != NULL; first = first->right)
            {
                if (first != NULL)
                {
                    int index = hashFunctions.calculateHashIndex(first, queryElement);
                    if (bloomFilter[index] == 0)
                    {
                        // number not present
                        falsePositives[i] = 0;
                        fp = false;
                        break;
                    }
                    else
                    {
                        // we got index is set as 1
                        // get the elements and hash pair which sets the index
                        ElementHashPairs pairs = elementHashPairsList[index];

                        ElementHashPair *first;
                        for (first = pairs.startNode; first != NULL; first = first->right)
                        {

                            if (first != NULL)
                            {
                                first->element;
                                first->hashIndex;
                                string hashPairStr = "";
                                hashPairStr.append("<");
                                hashPairStr.append(std::to_string(first->element));
                                hashPairStr.append(",");
                                hashPairStr.append(std::to_string(first->hashIndex));
                                hashPairStr.append(">");
                                if (hashPairsString.find(hashPairStr) == std::string::npos)
                                {
                                    // we need to add only atmost m entries
                                    if(atmost<noOfHashFunctions){
                                    atmost = atmost +1;    
                                    hashPairsString.append(hashPairStr);
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
            cout << endl;
            outFile << endl;
            // check if the element is false positive or not
            if (fp)
            {
                cout << queryElement << ", "
                     << " False Positive (Y) : "
                     << "Collision cases : " << hashPairsString;
                outFile << queryElement << ", "
                        << " False Positive (Y) : "
                        << "Collision cases : " << hashPairsString;
                totalFPCases = totalFPCases + 1;
            }
            else
            {
                cout << queryElement << ", "
                     << " False Positive (N)";
                outFile << queryElement << ", "
                        << " False Positive (N)";
            }
        }

        double fpProbability = (double)totalFPCases / noOfQueryElements;
        std::setprecision(2);
        cout << endl
             << fixed << setprecision(2) << "Fraction Of False Positives , p = " << fpProbability << endl;
        outFile << endl
                << fixed << setprecision(2) << "Fraction Of False Positives , p = " << fpProbability << endl;

        cout << "\nInserted elements\n";
        for (int i = 0; i < noOfElementsInserted; i++)
        {
            cout << insertedElements[i] << " ";
        }

        //hashFunctions.displayHashFunctions();
    }
    
    outFile.close();
    return 0;
}
