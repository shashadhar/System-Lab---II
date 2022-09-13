#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

// list of vertex , used for printing
string vertex[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

// stores all the lines , read from the file
std::string lines[26];

// stores the adjacency matrix
int adjMat[26][26];

// flag indicates if valid matrix or not
bool validMatrix = true;

// stores the no of rows in the input matrix
int rows = 0;

// delimeter to token the file input line
const char *delim = " ";

// Struct for representing a node
struct node
{
    int vertex;
    struct node *next;
};

// struct for representing the graph
struct Graph
{
    int numVertices;
    struct node **adjLists;
};

// Creates a node i.e vertex in the graph
struct node *createNode(int v)
{
    struct node *newNode = (node *)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creates the graph
struct Graph *createAGraph(int vertices)
{
    struct Graph *graph = (Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (node **)malloc(vertices * sizeof(struct node *));
    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Add an edge to the graph from sourct to destination
void addEdge(struct Graph *graph, int source, int dest)
{
    // Add edge from source to destination
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;
}

// Print the adjacncy list
void printAdjacecyList(struct Graph *graph)
{
    cout << "The Adjacency List" << endl;
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        cout << vertex[v] << ":";
        while (temp)
        {
            cout << vertex[temp->vertex] << "->";
            temp = temp->next;
        }
        cout << "Empty";
        cout << endl;
    }
}

// tokenize the file input line by delimeter
// it creates the matrix
// following constraints are check
//   1. Square matrix
//   2. Valid numerical value i,e string value added
//   3. Non binary values
//   3. Paraller edge
//   4. Self loop
bool tokenize()
{
    for (int i = 0; i < rows; i++)
    {
    std:
        string str = lines[i];
        int cols = 0;

        // gets the next token separated by the delimeter
        char *token = strtok(const_cast<char *>(str.c_str()), delim);
        bool validNumerical = true;
        while (token != nullptr)
        {
            int num;
            try
            {
                //converts string value to interger
                num = std::stoi(token);
            }
            catch (const std::exception &e)
            {
                // we got exception converting to int , mean it is not a valid integer value
                cout << "Not A Proper Numerical Value\n";
                validNumerical = false;
                break;
            }

            // checks for proper binary value
            if (!(num == 0 || num == 1))
            {
                cout << "Not A Proper Binary Value\n";
                validNumerical = false;
                break;
            }

            // checks if self loop exists
            if (i == cols && num == 1)
            {
                cout << "Self Loop Exists In The Graph\n";
                validNumerical = false;
                break;
            }

            adjMat[i][cols++] = num;
            token = strtok(nullptr, delim);
        }

        // return if it is not a valid input matrix
        if (!validNumerical)
        {
            return false;
            break;
        }
        else
        {

            // check if the value of col and is equal to rows i.e square matrix
            if (rows != cols)
            {
                cout << "Number of rows and columns are not same:\n";
                return false;
                break;
            }
        }
    }

    return true;
}

// prints the adjacency matrix
void printAdjacencyMatrix()
{
    cout << "The Adjacency Matrix" << endl;
    cout << " "
         << " ";
    for (int i = 0; i < rows; i++)
    {
        cout << vertex[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << vertex[i] << " ";
        for (int j = 0; j < rows; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}



// The main function
int main()
{

    std::ifstream file("ip.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            lines[rows++] = line;
        }
        file.close();
    }

    if (!tokenize())
    {
        cout << "Not A Valid Input Matrix" << endl;
    }
    else
    {
        // prints adjacency matrix
        printAdjacencyMatrix();

        // create adjacency list
        struct Graph *graph = createAGraph(rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (adjMat[i][j] == 1)
                {
                    addEdge(graph, i, j);
                }
            }
        }
        
        // prints adjancey list
        printAdjacecyList(graph);
    }
    return 1;
}