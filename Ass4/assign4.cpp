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
using namespace std;

// delimeter to token the file input line
const char *delim = " ";

// Represent a tree node
class TreeNode
{

public:
    TreeNode()
    {
        leftTreeNode = NULL;
        RightTreeNode = NULL;
    };
    TreeNode(int data, int right, int left)
    {
        this->data = data;
        this->right = right;
        this->left = left;
        label = 0;
        height = 0;
        leftTreeNode = NULL;
        RightTreeNode = NULL;
    }

    int data;
    bool right;
    bool left;
    int height;
    int label;
    TreeNode *leftTreeNode;
    TreeNode *RightTreeNode;
};


// Represents queue class
class Queue
{
public:
    TreeNode *front = NULL;
    TreeNode *rear = NULL;

    //Function to check if queue is empty or not
    bool isempty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
            return false;
    }

    //function to enter elements in queue
    void enqueue(TreeNode *node)
    {
        // create a new node
        TreeNode *newNode = new TreeNode(node->data, node->right, node->left);
        newNode->leftTreeNode = NULL;
        newNode->RightTreeNode = NULL;

        //If inserting the first element/node
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->leftTreeNode = newNode;
            rear = newNode;
        }
    }

    //function to delete/remove element from queue
    TreeNode *dequeue()
    {
        TreeNode *returnNode = NULL;
        if (isempty())
            cout << "Queue is empty\n";
        else
            //only one element/node in queue.
            if (front == rear)
        {
            returnNode = front;
            front = rear = NULL;
        }
        else
        {
            returnNode = front;
            front = front->leftTreeNode;
        }
        return returnNode;
    }

    //function to show the element at front
    int showfront()
    {
        return front->data;
    }
};

// Represents binary tree
class BinaryTree
{

public:
    TreeNode *root;
    BinaryTree()
    {
        root = NULL;
    }

    // checks if binary tree is empty or not
    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Function to traverse the tree in preorder
    // and check if the given node exists in it
    TreeNode *getNode(TreeNode *node, int key)
    {
        if (node == NULL)
            return NULL;

        if (node->data == key)
            return node;

        /* check left sub tree */
        TreeNode *resultLeftTree = getNode(node->leftTreeNode, key);

        // node found, no need to look further
        if (resultLeftTree != NULL)
            return resultLeftTree;

        /* check right sub tree */
        TreeNode *resultRightTree = getNode(node->RightTreeNode, key);
        return resultRightTree;
    }

    /* Given a binary tree, print its nodes in inorder*/
    void printInorder(TreeNode *node, ofstream *file)
    {
        if (node == NULL)
            return;

        /* first recur on left child */
        printInorder(node->leftTreeNode, file);

        /* then print the data of node */
        cout << node->data << " ";
        *file << node->data << " ";

        /* now recur on right child */
        printInorder(node->RightTreeNode, file);
    }

    /* Given a binary tree, print its nodes in preorder*/
    void printPreorder(TreeNode *node, ofstream *file)
    {
        if (node == NULL)
            return;

        /* first print data of node */
        cout << node->data << " ";
        *file << node->data << " ";

        /* then recur on left subtree */
        printPreorder(node->leftTreeNode, file);

        /* now recur on right subtree */
        printPreorder(node->RightTreeNode, file);
    }

    // Gets the height of the node
    int heightOfTree(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int left_side;
            int right_side;
            left_side = heightOfTree(node->leftTreeNode);
            right_side = heightOfTree(node->RightTreeNode);
            if (left_side > right_side)
            {
                return left_side + 1;
            }
            else
                return right_side + 1;
        }
    }

    // left tilt a tree
    void rightRotateTree(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        rightRotateTree(node->leftTreeNode);
        rightRotateTree(node->RightTreeNode);
        rightRotateNode(node);
    }

    // left tilt a node
    void rightRotateNode(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        else
        {
            int leftHeight = heightOfTree(node->leftTreeNode);
            int rightHeight = heightOfTree(node->RightTreeNode);
            if (leftHeight < rightHeight)
            {
                // swap the links
                TreeNode *temp = node->leftTreeNode;
                node->leftTreeNode = node->RightTreeNode;
                node->RightTreeNode = temp;
            }
        }
    }
};

TreeNode *startNode = NULL;
TreeNode *lastNode = NULL;

// insert a node to the list
void insertNode(TreeNode *node)
{
    // first node
    if (startNode == NULL)
    {
        startNode = node;
        lastNode = node;
    }
    else
    {
        lastNode->leftTreeNode = node;
        lastNode = node;
    }
}

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

// reads a single line customer data and token the string with delimeter " "
// and converts data to Customer class
bool readNodeData(string line)
{
    bool validInput = true;
    int cols = 0;

    // gets the next token separated by the delimeter and we should have only 3 values
    // separated by delimeter " "
    char *token = strtok(const_cast<char *>(line.c_str()), delim);
    cols++;
    bool validNumerical = true;
    TreeNode *node = new TreeNode();
    while (token != nullptr)
    {
        switch (cols)
        {

        // it should be node value
        case 1:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    //converts string value to integer
                    num = stoi(token);
                    node->data = num;
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

        // it should be left subtree value
        case 2:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    //converts string value to integer
                    num = stoi(token);
                    if (num == 0 || num == 1)
                    {
                        node->left = num;
                    }
                    else
                    {
                        validInput = false;
                    }
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

        // it should be right sub tree
        case 3:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    //converts string value to integer
                    num = stoi(token);
                    if (num == 0 || num == 1)
                    {
                        node->right = num;
                    }
                    else
                    {
                        validInput = false;
                    }
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
        insertNode(node);
    }
    return validInput;
}

// Read data from the input file ip.txt
bool readDataFromFile(ofstream *outFile)
{
    bool validInput = true;
    int noOfNodes = 0;
    ifstream inputFile("ip.txt");

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            string inputLine = line;
            if (readNodeData(inputLine))
            {

                //cout << "No of Nodes" << noOfNodes++;
            }
            else
            {
                cout << "Not A Valid Input\n";
                *outFile << "Not A Valid Input\n";
                validInput = false;
                break;
            }
        }
    }
    inputFile.close();
    return validInput;
}

// Checks if all the node has unique values
bool isNodeIdUnique()
{
    TreeNode *first;
    for (first = startNode; first->leftTreeNode != NULL; first = first->leftTreeNode)
    {
        TreeNode *next;
        for (next = first->leftTreeNode; next != NULL; next = next->leftTreeNode)
        {
            if (first->data == next->data)
            {
                return false;
            }
        }
    }

    return true;
}

// Display the node data
void displayNodeData(ofstream *file)
{
    TreeNode *first;
    for (first = startNode; first->leftTreeNode != NULL; first = first->leftTreeNode)
    {
        cout << "data:" << first->data << " "
             << "left:" << first->left << " "
             << "Right:" << first->right << endl;
    }
    cout << "data:" << first->data << " "
         << "left:" << first->left << " "
         << "Right:" << first->right << endl;
}

// create a copy of the tree node
TreeNode *createCopy(TreeNode *node)
{
    TreeNode *newNode = NULL;
    if (node != NULL)
    {
        // create a new node
        newNode = new TreeNode(node->data, node->right, node->left);
        newNode->leftTreeNode = NULL;
        newNode->RightTreeNode = NULL;
    }
    return newNode;
}

// Constructs the binary tree
bool constructBinarySearchTree(BinaryTree *binTree)
{
    bool invalidInput = false;
    Queue *queue = new Queue();
    TreeNode *firstNode;
    if (startNode != NULL)
    {
        firstNode = startNode;
        queue->enqueue(startNode);
        while (!queue->isempty())
        {
            TreeNode *nodeToProcess = queue->dequeue();
            TreeNode *binaryTreeCurrentNode;
            // check if binary tree is empty
            if (binTree->isEmpty())
            {
                binTree->root = nodeToProcess;
            }
            // get the node
            binaryTreeCurrentNode = binTree->getNode(binTree->root, nodeToProcess->data);
            if (nodeToProcess->left == 1)
            {
                TreeNode *node = createCopy(firstNode->leftTreeNode);
                if (node != NULL)
                {
                    binaryTreeCurrentNode->leftTreeNode = node;
                    queue->enqueue(node);
                    firstNode = firstNode->leftTreeNode;
                }
                else
                {
                    invalidInput = true;
                }
            }
            if (nodeToProcess->left == 0)
            {
                binaryTreeCurrentNode->leftTreeNode = NULL;
            }
            if (nodeToProcess->right == 1)
            {
                TreeNode *node = createCopy(firstNode->leftTreeNode);
                if (node != NULL)
                {
                    binaryTreeCurrentNode->RightTreeNode = node;
                    queue->enqueue(node);
                    firstNode = firstNode->leftTreeNode;
                }
                else
                {
                    invalidInput = true;
                }
            }
            if (nodeToProcess->right == 0)
            {
                binaryTreeCurrentNode->RightTreeNode = NULL;
            }
        }

        if (queue->isempty())
        {
            if (firstNode->leftTreeNode == NULL)
            {
                // all inserted to tree
            }
            else
            {
                // we are left with some node
                invalidInput = true;
            }
        }
    }
    return invalidInput;
}

// stores the tree
BinaryTree *binaryTree = new BinaryTree();

//Main Function
int main()
{
    int noOfProcess;
    ofstream outFile;
    outFile.open("op.txt");
    if (readDataFromFile(&outFile))
    {
        if (isNodeIdUnique())
        {
            //displayNodeData(&outFile);
            if (!constructBinarySearchTree(binaryTree))
            {
                cout << "Input Binary Tree:" << endl;
                outFile << "Input Binary Tree:" << endl;
                cout << "Preorder:";
                outFile << "Preorder:";
                binaryTree->printPreorder(binaryTree->root, &outFile);
                cout << endl
                     << "Inorder:";
                outFile << endl
                        << "Inorder:";
                binaryTree->printInorder(binaryTree->root, &outFile);
                binaryTree->rightRotateTree(binaryTree->root);

                cout << endl
                     << "Tilted Binary Tree:" << endl;
                outFile << endl
                        << endl
                        << "Tilted Binary Tree:" << endl;
                cout << "Preorder:";
                outFile << "Preorder:";
                binaryTree->printPreorder(binaryTree->root, &outFile);
                cout << endl
                     << "Inorder:";
                outFile << endl
                        << "Inorder:";
                binaryTree->printInorder(binaryTree->root, &outFile);
            }
            else
            {
                cout << "Invalid Input Of Nodes";
                outFile << "Invalid Input Of Nodes";
            }
        }else
        {
            cout << "Node values are Not Unique\n";
            outFile << "Node Values Are Not Unique\n";
        }
        outFile.close();
        return 0;
    }
}
