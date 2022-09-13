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

const int IN_STACK = 1;
const int NOT_VISITED = -1;
const int DONE = 5;

class Stack
{
public:
    int stack[100];
    int top = -1;

    void push(int value)
    {
        top++;
        stack[top] = value;
    }

    int pop()
    {
        return stack[top--];
    }
    void initilize()
    {
        top = -1;
        for (int i = 0; i < 100; i++)
        {
            stack[i] = -8;
        }
    }

    int peek()
    {
        return stack[top];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// class represents a graph node
class Node
{
public:
    int value;
    string color;
    Node *next = NULL;
};

// class represents adjacency list
class AdjacencyList
{
public:
    Node *start = NULL;
    Node *end = NULL;

    // insert a node to the list
    void insertNode(Node *node)
    {
        // first node
        if (start == NULL)
        {

            start = node;
            end = node;
        }
        else
        {
            end->next = node;
            end = node;
        }
    }

    // clear the node, free the memory
    void clear(Node *start)
    {
        if (start->next != NULL)
        {
            clear(start->next);
        }
        delete start;
    }

    // display the adjacency list
    void display(ofstream *outFile)
    {
        Node *first = start;
        if (first != NULL)
        {
            cout << endl
                 << first->value << "->";
            *outFile << endl
                     << first->value << "->";

            for (first = start->next; first != NULL; first = first->next)
            {

                if (first->next == NULL)
                {
                    cout << " " << first->value;
                    *outFile << " " << first->value;
                }
                else
                {
                    cout << " " << first->value << ",";
                    *outFile << " " << first->value << ",";
                }
            }
        }
    }
};

// class represents graph
class Graph
{
public:
    int vertices;
    AdjacencyList *list;

    AdjacencyList getAdjacencyList(int value)
    {
        AdjacencyList ad;
        for (int i = 0; i < vertices; i++)
        {
            ad = list[i];
            if (ad.start != NULL && ad.start->value == value)
            {
                return ad;
            }
        }
        return ad;
    }
};

class Edge
{
public:
    int src;
    int dest;
    Edge *next;
};

class Edges
{
public:
    Edge *startNode = NULL;
    Edge *lastNode = NULL;

    // insert a node to the list
    void insertNode(Edge *edge)
    {
        // first node
        if (startNode == NULL)
        {

            startNode = edge;
            lastNode = edge;
        }
        else
        {
            lastNode->next = edge;
            lastNode = edge;
        }
    }

    // clear the edge, free the memory
    void clear(Edge *start)
    {
        if (start->next != NULL)
        {
            clear(start->next);
        }
        delete start;
    }

    // display the edges list
    void display()
    {
        Edge *first;
        for (first = startNode; first != NULL; first = first->next)
        {
            cout << "Src:" << first->src << " "
                 << "Dest:" << first->dest << " "
                 << endl;
        }
    }
};

// delimeter to token the file input line
const char *delim = " ";
int noOfVertices;
Edges edges;
string *colors;
Graph originalGraph;
Graph redGraph;
Graph blueGraph;
Node *nodes;

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

// read color from the string
bool readColor(string line)
{
    bool validInput = true;
    int cols = 0;

    colors = new string[noOfVertices];

    // gets the next token separated by the delimeter and we should have only 3 values
    // separated by delimeter " "
    char *token = strtok(const_cast<char *>(line.c_str()), delim);

    while (token != nullptr)
    {
        string tokenStr = token;
        if (cols < noOfVertices && (tokenStr.compare("r") == 0 || tokenStr.compare("b") == 0))
        {
            // valid string
            colors[cols] = tokenStr;
        }
        else
        {
            validInput = false;
        }

        token = strtok(nullptr, delim);
        cols++;
    }

    return validInput;
}

// create edge from the token string ex "0 1"
bool createEdge(string tokenStr)
{
    bool validInput = true;
    int length = 0;
    std::stringstream ss;
    ss.str(tokenStr);

    Edge *edge = new Edge();

    // first src
    string src;
    ss >> src;
    if (isNumber(src))
    {
        int num = stoi(src);
        if (num < noOfVertices)
        {
            edge->src = num;
        }
        else
        {
            validInput = false;
        }
    }
    else
    {
        validInput = false;
    }

    // second dest
    string dest;
    ss >> dest;
    if (isNumber(dest))
    {
        int num = stoi(dest);
        if (num < noOfVertices)
        {
            edge->dest = num;
        }
        else
        {
            validInput = false;
        }
    }
    else
    {
        validInput = false;
    }

    while (!ss.eof())
    {
        // we have more strings , not valid
        validInput = false;
    }
    if (validInput)
    {
        edges.insertNode(edge);
    }
    return validInput;
}

// read edges
bool readEdges(string line)
{
    bool validInput = true;

    // gets the next token separated by the "," and we should have only 2 values
    // separated by delimeter ","
    char *token = strtok(const_cast<char *>(line.c_str()), ",");

    while (token != nullptr)
    {
        string tokenStr = token;
        if (tokenStr.compare(" -1") == 0)
        {
            // done with the input
            break;
        }
        else
        {
            if (createEdge(tokenStr))
            {
                // cout << "created edge for: " << tokenStr << endl;
            }
            else
            {
                validInput = false;
                break;
            }
        }

        token = strtok(nullptr, ",");
    }

    return validInput;
}

// Read data from the input file ip.txt
bool readDataFromFile(string inputFileName, ofstream *outFile)
{
    bool validInput = true;
    int lines = 1;
    ifstream inputFile(inputFileName);

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
                    noOfVertices = stoi(line);
                    lines++;
                }
                else
                {
                    cout << " Not a valid input number";
                    *outFile << "Not A Valid Input\n";
                    return false;
                }
            }
            else if (lines == 2)
            {
                if (readColor(inputLine))
                {
                    cout << "Successfully color read from file" << endl;
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
            else if (lines == 3)
            {
                if (readEdges(line))
                {
                    cout << "Successfully edges read from file" << endl;
                }
                else
                {
                    cout << " Not a valid input number";
                    *outFile << "Not A Valid Input\n";
                }
            }
            else
            {
                cout << " Not a valid input number";
                *outFile << "Not A Valid Input\n";
                return false;
            }
        }
    }
    inputFile.close();
    return validInput;
}

void printCycle(Stack *stack, int vertex, string color, int *count, ofstream *outfile)
{
    Stack *stack2 = new Stack();
    stack2->initilize();
    stack2->push(stack->peek());
    stack->pop();
    while (stack2->peek() != vertex)
    {
        stack2->push(stack->peek());
        stack->pop();
    }

    int startNode = stack2->peek();
    bool allRed = true;
    bool allBlue = true;
    string cycle = "";
    string cycleColor = " color (";
    while (!stack2->isEmpty())
    {
        // cout<<stack2->peek()<<"->";
        cycle.append(to_string(stack2->peek())).append("->");
        cycleColor.append(nodes[stack2->peek()].color).append("-");
        if (nodes[stack2->peek()].color.compare("b") == 0)
        {
            allRed = false;
        }
        else
        {
            allBlue = false;
        }
        stack->push(stack2->peek());

        stack2->pop();
    }
    // cout<<startNode;
    cycle.append(to_string(startNode));
    cycleColor.append(nodes[startNode].color).append(")");
    if (color.compare("r") == 0)
    {
        // print only red cycles
        if (allRed)
        {
            cout << cycle;
            *outfile << cycle;
            cout << cycleColor;
            *outfile << cycleColor;
            *count = *count + 1;
        }
    }
    else if (color.compare("b") == 0)
    {
        // print only blue cycles
        if (allBlue)
        {
            cout << cycle;
            cout << cycleColor;
            *outfile << cycle;
            *outfile << cycleColor;
            *count = *count + 1;
        }
    }
    else if (color.compare("rb") == 0)
    {
        if (!allRed && !allBlue)
        {
            cout << cycle;
            cout << cycleColor;
            *outfile << cycle;
            *outfile << cycleColor;
            *count = *count + 1;
        }
    }

    delete stack2;
}

void processDFSTree(Graph graph, Stack *stack, int visited[], int parent, string color, int *count, ofstream *outfile)
{
    int parent1 = stack->peek();
    // AdjacencyList adlist = graph.list[parent1];
    AdjacencyList adlist = graph.getAdjacencyList(parent1);
    Node *start = adlist.start;
    for (start = start->next; start != NULL; start = start->next)
    {
        if (start->value == parent)
        {
            continue;
        }
        if (visited[start->value] == IN_STACK)
        {
            cout << endl;
            *outfile << endl;
            if (*count == 2)
            {
                return;
            }
            else
            {
                printCycle(stack, start->value, color, count, outfile);
            }
        }
        else if (visited[start->value] == NOT_VISITED)
        {
            stack->push(start->value);
            visited[start->value] = IN_STACK;
            processDFSTree(graph, stack, visited, parent1, color, count, outfile);
        }
    }
    visited[stack->peek()] = DONE;
    stack->pop();
}

// Main Function
int main()
{
    ofstream outFile;
    string inputFileName;
    string outputFileName;

    cout << "Enter input file name:" << endl;
    cin >> inputFileName;
    cout << "Enter output file name:" << endl;
    cin >> outputFileName;

    outFile.open(outputFileName);
    if (readDataFromFile(inputFileName, &outFile))
    {

        // create the graph
        originalGraph.vertices = noOfVertices;
        originalGraph.list = new AdjacencyList[noOfVertices];
        int noOfRedVertices = 0, noOfBlueVertices = 0;

        nodes = new Node[noOfVertices];
        for (int i = 0; i < noOfVertices; i++)
        {
            Node node;
            node.value = i;
            node.color = colors[i];
            nodes[i] = node;
            if (node.color.compare("r") == 0)
            {
                noOfRedVertices = noOfRedVertices + 1;
            }
            else
            {
                noOfBlueVertices = noOfBlueVertices + 1;
            }
        }

        // add the first node to each adjacencyList
        for (int i = 0; i < noOfVertices; i++)
        {
            AdjacencyList adjacencyList = originalGraph.list[i];
            Node *node = new Node();
            node->color = nodes[i].color;
            node->value = nodes[i].value;
            node->next = nodes[i].next;
            adjacencyList.insertNode(node);
            originalGraph.list[i] = adjacencyList;
        }

        // add the edges to the adjacency list
        Edge *startEdge;
        for (startEdge = edges.startNode; startEdge != NULL; startEdge = startEdge->next)
        {
            // get the adjanceylist for the source and add the distination node
            AdjacencyList adjacencyListSrc = originalGraph.list[startEdge->src];
            Node *node = new Node();
            node->color = nodes[startEdge->dest].color;
            node->value = nodes[startEdge->dest].value;
            node->next = nodes[startEdge->dest].next;
            adjacencyListSrc.insertNode(node);
            originalGraph.list[startEdge->src] = adjacencyListSrc;

            // get the adjacencylist for the destination and add the source node
            AdjacencyList adjacencyListDest = originalGraph.list[startEdge->dest];
            Node *newNode = new Node();
            newNode->color = nodes[startEdge->src].color;
            newNode->value = nodes[startEdge->src].value;
            newNode->next = nodes[startEdge->src].next;
            adjacencyListDest.insertNode(newNode);
            originalGraph.list[startEdge->dest] = adjacencyListDest;
        }

        redGraph.vertices = noOfRedVertices;
        redGraph.list = new AdjacencyList[noOfRedVertices];

        blueGraph.vertices = noOfBlueVertices;
        blueGraph.list = new AdjacencyList[noOfBlueVertices];

        int redNodeIndex = 0, blueNodeIndex = 0;
        for (int i = 0; i < noOfVertices; i++)
        {

            if (nodes[i].color.compare("r") == 0)
            {
                // red node
                AdjacencyList adList = redGraph.list[redNodeIndex];
                // get the adjacency list for the red node and add only the red nodes from the list
                AdjacencyList originalAdList = originalGraph.list[nodes[i].value];
                Node *start = originalAdList.start;
                for (; start != NULL; start = start->next)
                {
                    if (start->color.compare("r") == 0)
                    {
                        Node *node = new Node();
                        node->color = start->color;
                        node->value = start->value;
                        node->next = NULL;
                        adList.insertNode(node);
                    }
                }
                redGraph.list[redNodeIndex] = adList;
                redNodeIndex = redNodeIndex + 1;
            }
            else
            {
                // blue node
                AdjacencyList adList = blueGraph.list[blueNodeIndex];
                // get the adjacency list for the blue node and add only the blue nodes from the list
                AdjacencyList originalAdList = originalGraph.list[nodes[i].value];
                Node *start = originalAdList.start;
                for (; start != NULL; start = start->next)
                {
                    if (start->color.compare("b") == 0)
                    {
                        Node *node = new Node();
                        node->color = start->color;
                        node->value = start->value;
                        node->next = NULL;
                        adList.insertNode(node);
                    }
                }
                blueGraph.list[blueNodeIndex] = adList;
                blueNodeIndex = blueNodeIndex + 1;
            }
        }

        // dispay the original graph
        cout << endl
             << endl
             << "Original graph";
        outFile << endl
                << endl
                << "Original graph";
        for (int i = 0; i < noOfVertices; i++)
        {
            // cout<<endl;
            originalGraph.list[i].display(&outFile);
        }

        // display red subgraph
        cout << endl
             << endl
             << "Red sub graph";
        outFile << endl
                << endl
                << "Red sub graph";
        for (int i = 0; i < noOfRedVertices; i++)
        {
            // cout<<endl;
            redGraph.list[i].display(&outFile);
        }

        // display blue subgraph
        cout << endl
             << endl
             << "Blue sub graph";
        outFile << endl
                << endl
                << "Blue sub graph";
        for (int i = 0; i < noOfBlueVertices; i++)
        {
            blueGraph.list[i].display(&outFile);
        }

        // cycle detection
        Stack *stack = new Stack();
        int visited[noOfVertices];
        // initialize all as not visited
        for (int i = 0; i < noOfVertices; i++)
        {
            visited[i] = NOT_VISITED;
        }

        cout << endl
             << "Red cycles";
        outFile << endl
                << "Red cycles";
        int count = 0;
        for (int i = 0; i < noOfRedVertices; i++)
        {
            if (count == 2)
            {
                break;
            }
            else
            {
                if (visited[i] == NOT_VISITED)
                {
                    stack->initilize();
                    AdjacencyList ad = redGraph.list[i];
                    stack->push(ad.start->value);
                    visited[ad.start->value] = IN_STACK;
                    processDFSTree(redGraph, stack, visited, -1, "r", &count, &outFile);
                }
            }
        }

        delete stack;
        stack = new Stack();
        // initialize all as not visited
        for (int i = 0; i < noOfVertices; i++)
        {
            visited[i] = NOT_VISITED;
        }

        cout << endl
             << "Blue cycles";
        outFile << endl
                << "Blue cycles";
        count = 0;
        for (int i = 0; i < noOfBlueVertices; i++)
        {
            if (count == 2)
            {
                break;
            }
            else
            {
                if (visited[i] == NOT_VISITED)
                {
                    stack->initilize();
                    AdjacencyList ad = blueGraph.list[i];
                    stack->push(ad.start->value);
                    visited[ad.start->value] = IN_STACK;
                    processDFSTree(blueGraph, stack, visited, -1, "b", &count, &outFile);
                }
            }
        }

        delete stack;
        stack = new Stack();
        // initialize all as not visited
        for (int i = 0; i < noOfVertices; i++)
        {
            visited[i] = NOT_VISITED;
        }
        cout << endl
             << "Multi color cycles";
        outFile << endl
                << "Multi color cycles";
        count = 0;
        for (int i = 0; i < noOfVertices; i++)
        {
            if (count == 2)
            {
                break;
            }
            else
            {
                if (visited[i] == NOT_VISITED)
                {
                    stack->initilize();
                    AdjacencyList ad = originalGraph.list[i];
                    stack->push(ad.start->value);
                    visited[ad.start->value] = IN_STACK;
                    processDFSTree(originalGraph, stack, visited, -1, "rb", &count, &outFile);
                }
            }
        }
    }
    else
    {
    }
    outFile.close();
    return 0;
}
