#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

// delimeter to token the file input line
const char *delim = " ";


 // Represnts the Serivice Type class, store the type and time to service
 // We are allowing only three types MW,MD,DD
class ServiceType
{
    string type;
    int time;

public:
    ServiceType();
    ServiceType(string typ, int num)
    {
        type = typ;
        time = num;
    }
    void setType(string mType)
    {
        type = mType;
    }
    void setTime(int value)
    {
        time = value;
    }

    string getType()
    {
        return type;
    }
    int getTime()
    {
        return time;
    }
};

// Represents Customer claass
// It stores the customer id, arrival time, completion time , waiting time etc
class Customer
{
private:
    string cId;
    int serviceTime;
    int nextCpuTime;
    int arrivalTime;
    int priority;
    long waitTime;
    int timeOfCompletion;
    bool isFinished;

public:
    Customer()
    {
        cId = "C0";
        serviceTime = 0;
        nextCpuTime = 0;
        arrivalTime = 0;
        priority = 0;
        waitTime = 0;
        timeOfCompletion = 0;
        isFinished = false;
    };
    void setCID(string _pid)
    {
        cId = _pid;
    };

    void setSeriviceTime(int _serviceTime)
    {
        serviceTime = _serviceTime;
    }
    void setNextServiceTime(int _time)
    {
        nextCpuTime = _time;
    };
    void setArrivalTime(int _arrivalTime)
    {
        arrivalTime = _arrivalTime;
    };
    void setPriority(int _priority)
    {
        priority = _priority;
    };
    void addWaitTime(double time)
    {
        waitTime += time;
    };

    void setTimeOfCompletion(int _timeOfCompletion)
    {
        timeOfCompletion = _timeOfCompletion;
    };

    void setIsFinished(bool _finished)
    {
        isFinished = _finished;
    }
    string getCId() const
    {
        return cId;
    };

    int getServiceTime() const
    {
        return serviceTime;
    }

    int getNextSeriviceTime() const
    {
        return nextCpuTime;
    };

    int getArrivalTime() const
    {
        return arrivalTime;
    };
    int getPriority() const
    {
        return priority;
    };
    long getWaitTime() const
    {
        return waitTime;
    };

    int getTimeOfCompletion() const
    {
        return timeOfCompletion;
    };

    bool getIsFinished() const
    {
        return isFinished;
    }
    void operator=(Customer p);
};

// Operator overloads when we assign a customer to another
void Customer::operator=(Customer p)
{
    cId = p.getCId();
    serviceTime = p.getServiceTime();
    nextCpuTime = p.getNextSeriviceTime();
    arrivalTime = p.getArrivalTime();
    priority = p.getPriority();
    waitTime = p.getWaitTime();
    timeOfCompletion = p.getTimeOfCompletion();
    isFinished = p.getIsFinished();
}

// We are using this for comparison of two customer
bool operator<(const Customer &p1, const Customer &p2)
{
    return p1.getServiceTime() < p2.getServiceTime();
};

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

// Stored the serivice types
ServiceType *ServiceTypes[3];

// Stores the customers
Customer *customers[20];

// stores no of customers and no of service types
int noOfCustomers, noOfServiceTypes;

// reads a single line customer data and token the string with delimeter " "
// and converts data to Customer class
bool readCustomerData(string line, int no)
{
    bool validInput = true;
    int cols = 0;

    // gets the next token separated by the delimeter and we should have only 3 values
    // separated by delimeter " "
    char *token = strtok(const_cast<char *>(line.c_str()), delim);
    cols++;
    bool validNumerical = true;
    Customer *customer = new Customer();
    while (token != nullptr)
    {
        switch (cols)
        {

        // it should be customer Id
        case 1:
        {
            customer->setCID(token);
            break;
        }

        // it should be arrival time
        case 2:
        {
            int num;
            if (isNumber(token))
            {

                try
                {
                    //converts string value to integer
                    num = stoi(token);
                    customer->setArrivalTime(num);
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

        // it should be service type
        case 3:
        {
            string str = token;
            if (str.compare("MW") == 0)
            {
                customer->setSeriviceTime(ServiceTypes[0]->getTime());
                customer->setNextServiceTime(ServiceTypes[0]->getTime());
            }
            else if (str.compare("MD") == 0)
            {
                customer->setSeriviceTime(ServiceTypes[1]->getTime());
                customer->setNextServiceTime(ServiceTypes[1]->getTime());
            }
            else if (str.compare("DD") == 0)
            {
                customer->setSeriviceTime(ServiceTypes[2]->getTime());
                customer->setNextServiceTime(ServiceTypes[2]->getTime());
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

    // we successfully tokenized, store the customer data
    if (validInput)
    {
        customers[no] = customer;
    }
    return validInput;
}


// Reads service type data and stored in a class
// We are reading the line
// 1st line should represent MW
// 2nd line should represent MD
// 3rd line should represent DD
bool readServiceTypeData(string line, int service)
{
    bool validInput = true;
    int num;

    try
    {
        if (isNumber(line))
        {
            //converts string value to interger
            num = stoi(line);
            switch (service)
            {
            case 0:
            {
                ServiceType *serviceType = new ServiceType("MW", num);
                ServiceTypes[0] = serviceType;
                break;
            }
            case 1:
            {
                ServiceType *serviceType = new ServiceType("MD", num);
                ServiceTypes[1] = serviceType;
                break;
            }
            case 2:
            {
                ServiceType *serviceType = new ServiceType("DD", num);
                ServiceTypes[2] = serviceType;
            }
            break;
            default:
                validInput = false;
                break;
            }
        }
        else
        {
            validInput = false;
        }
    }
    catch (const exception &e)
    {
        // we got exception converting to int , mean it is not a valid integer value
        validInput = false;
    }
    return validInput;
}

// display customer data 
void displayCustomerData(ofstream *outfile)
{
    cout << endl;
    //*outfile << endl;
    for (int i = 0; i < noOfCustomers; i++)
    {
        Customer *customer = customers[i];
        if (customer != NULL)
        {
            cout << customer->getCId() << "," << customer->getArrivalTime() << "," << customer->getServiceTime() << endl;
            //*outfile << customer->getCId() << "," << customer->getArrivalTime() << "," << customer->getServiceTime() << endl;
        }
    }
}

// Read data from the input file ip.txt
bool readDataFromFile(ofstream *outFile)
{
    noOfServiceTypes = 0;
    noOfCustomers = 0;
    bool validInput = true;

    ifstream inputFile("ip.txt");

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            string inputLine = line;
            // first 3 lines , considering as service types
            if (noOfServiceTypes < 3)
            {
                if (readServiceTypeData(inputLine, noOfServiceTypes++))
                {
                }
                else
                {
                    cout << "Not A Valid Input For The Service Time\n";
                    *outFile << "Not A Valid Input For The Service Time\n";
                    validInput = false;
                    break;
                }
            }
            else
            {
                // exlcluding first 3 lines , we are considering as customer data
                if (readCustomerData(inputLine, noOfCustomers++))
                {

                    cout << "No of customer" << noOfCustomers;
                }
                else
                {
                    cout << "Not A Valid Input For Customer Data\n";
                    *outFile << "Not A Valid Input For Customer Data\n";
                    validInput = false;
                    break;
                }
            }
        }
    }
    inputFile.close();
    return validInput;
}

// Copy customer data form source to destination ustomer object
void copyCustomerData(Customer* source , Customer* dest){
    dest->setCID(source->getCId());
    dest->setSeriviceTime(source->getServiceTime());
    dest->setNextServiceTime(source->getNextSeriviceTime());
    dest->setArrivalTime(source->getArrivalTime());
    dest->setPriority(source->getPriority());
    dest->addWaitTime(source->getWaitTime());
    dest->setTimeOfCompletion(source->getTimeOfCompletion());
    dest->setIsFinished(source->getIsFinished());
}


// copy data from an source array to destination array
Customer **copyData(int size, Customer *source[], Customer *dest[])
{
    // copy the customers data
    for (int i = 0; i < noOfCustomers; i++)
    {
        Customer *cust = new Customer();
        copyCustomerData(source[i],cust);
        dest[i] = cust;
    }
    return dest;
}


// Update a customer data with time of completion and finished flag
void updateCustomer(Customer* updatedCustomer){
    for(int i=0;i<noOfCustomers;i++){
        Customer * cust = customers[i];
       if(cust!= NULL)
        // got the required customer to update
        if(cust->getCId().compare(updatedCustomer->getCId())==0){
         cust->setTimeOfCompletion(updatedCustomer->getTimeOfCompletion());
         cust->setIsFinished(updatedCustomer->getIsFinished());
         break;
       }
    }
}

// initilize the list if customer data to nuLL
void initializeNull(int size,Customer* source[]){
    for(int i=0;i<size;i++){
        source[i]=NULL;
    }

}

// Inserts data to a loc where it is set as NULL in source list
void insertData(Customer *source[], Customer *data)
{
    int i = 0;
    for(int i=0;i<noOfCustomers;i++)
    if(source[i] == NULL)
    {   
        Customer *cust = new Customer();
        source[i] = data;
        break;
    }
}

// Deletes data from start and shifts the data to the start after deleting
void deleteDataFromStart(Customer *source[])
{
    Customer *cust = source[0];
    if (cust != NULL)
    {
        for (int i = 1; i < noOfCustomers; i++)
        {
            source[i - 1] = source[i];
        }
        source[noOfCustomers - 1] = NULL;
    }
}

// Checks if list is empty ie set all as null
bool isEmpty(Customer *source[])
{
    for (int i = 0; i < noOfCustomers; i++)
    {
        if (source[i] != NULL)
        {
            return false;
            break;
        }
    }
    return true;
}

// Calculates the waiting time and writes output to the file
void calculateWaitingTime(ofstream* outfile)
{
    Customer *sortedCustomers[noOfCustomers];
    copyData(noOfCustomers, customers, sortedCustomers);

    // sort the customer data on arrival time
    Customer *temp;
    for (int i = 0; i < noOfCustomers - 1; ++i)
    {
        for (int j = 0; j < noOfCustomers - i - 1; ++j)
        {
            if (sortedCustomers[j]->getArrivalTime() > sortedCustomers[j + 1]->getArrivalTime())
            { //smallest to largest
                temp = sortedCustomers[j];
                sortedCustomers[j] = sortedCustomers[j + 1];
                sortedCustomers[j + 1] = temp;
            }
        }
    }

    // start serving the customer
    int time = 0,finished=0;
    cout << "Started executiong customers";

    // copied the oringinal customers
    Customer *copy[noOfCustomers];

    // stores the next customer to execute
    Customer *schedule[noOfCustomers];
    initializeNull(noOfCustomers,schedule);

    // two counter to execute the service
    Customer *runCounter1 = NULL, *runCounter2 = NULL;
    copyData(noOfCustomers, sortedCustomers, copy);

    // this loop considers if counters are idle at first i.e no customer arrived
    while (true)
    {
        if (sortedCustomers[0]->getArrivalTime() > time)
        {
            ++time;
        }
        else
        {
            break;
        }
    }

    // runs loop as long as we have not serviced all the customers
    while (finished < noOfCustomers)
    {

        // this loops adds all the customers that has arrived to schedule list
        // the schedule list works as queue of customer to execute next
        while (true)
        {

            // schedule the processes which has arrived on the time
            if (!isEmpty(copy) && copy[0]->getArrivalTime() <= time)
            {
                insertData(schedule, copy[0]);
                deleteDataFromStart(copy);
            }
            else
            {
                break;
            }
        }
        // counter is idle , check if we have customer waiting or not
        if (runCounter1 ==NULL || runCounter2==NULL)
        {
            // counter 1 is empty and we have customer in queue
            if(runCounter1==NULL && schedule[0] != NULL)
            {
                runCounter1 = schedule[0];
                deleteDataFromStart(schedule);
            }

            // counter 2 is empty and we have customer in queue
            if (runCounter2==NULL && schedule[0] != NULL)
            {
                runCounter2 = schedule[0];
                deleteDataFromStart(schedule);
            }
    
        }

       
        // checks if counter has completed the execution of the customer
        if (runCounter1 != NULL && runCounter1->getNextSeriviceTime() <= 0)
        {
            // update counter 1 as done and customer completion time
            if (!runCounter1->getIsFinished())
            {
                runCounter1->setTimeOfCompletion(time);
                runCounter1->setIsFinished(true);
                cout<<endl;
                cout << "counter1:" << runCounter1->getCId() << "->" << time << endl;
                updateCustomer(runCounter1);
                runCounter1 = NULL;
                finished = finished + 1;
            }

            // schedule next customer is available
            if (!isEmpty(schedule))
            {
                if (schedule[0] != NULL)
                {
                    runCounter1 = schedule[0];
                    deleteDataFromStart(schedule);
                }
            }
        }

        // checks if counter2 completed the execution of the customer
        if (runCounter2 != NULL && runCounter2->getNextSeriviceTime() <= 0)
        {
             // update counter 2 as done and customer completion time
            if (!runCounter2->getIsFinished())
            {
                runCounter2->setTimeOfCompletion(time);
                runCounter2->setIsFinished(true);
                cout<<endl;
                cout << "coutnter2:" << runCounter2->getCId() << "->" << time << endl;
                updateCustomer(runCounter2);
                runCounter2 = NULL;
                finished = finished + 1;
            }

            // schedule next customer to counter 2 if any
            if (!isEmpty(schedule))
            {
                if (schedule[0] != NULL)
                {
                    runCounter2 = schedule[0];
                    deleteDataFromStart(schedule);
                }
            }
        }

        // update service time
        if (runCounter1 != NULL)
        {
            runCounter1->setNextServiceTime(runCounter1->getNextSeriviceTime() - 1);
        }

        if (runCounter2 != NULL)
        {
            runCounter2->setNextServiceTime(runCounter2->getNextSeriviceTime() - 1);
        }

        ++time;
    }

    // we have completed the execution display the data
    // computes the waiting time
    int totalWaitingTime = 0;
    for (int i = 0; i < noOfCustomers; i++)
    {
        
        Customer *customer = customers[i];
        if (customer != NULL)
        {

            customer->addWaitTime(customer->getTimeOfCompletion()-customer->getArrivalTime());
            totalWaitingTime = totalWaitingTime+customer->getWaitTime();
            cout << customer->getCId() << "," << customer->getArrivalTime() << "," << customer->getTimeOfCompletion()<<","<<customer->getWaitTime() << endl;
            *outfile << customer->getCId() << "," << customer->getArrivalTime() << ","<< customer->getTimeOfCompletion()<<","<<customer->getWaitTime() << endl;;
        }
    }
    double waitTime = (double)totalWaitingTime/noOfCustomers;
    std::setprecision(2);
    cout<<fixed<<setprecision(1)<<"Average waiting time:"<<waitTime;
    *outfile<<fixed<<setprecision(1)<<"Average waiting time:"<<waitTime;
}

// Checks if customer id is unique
bool isCustomerIdUnique(){
    for(int i=0;i<noOfCustomers-1;i++){
        Customer* cust = customers[i];
        for(int j=i+1;j<noOfCustomers;j++){
           if(cust->getCId().compare(customers[j]->getCId())==0){
               return false;
               break;
           }
        }
    }
    return true;
}


// Main method
int main()
{
    int noOfProcess;
    ofstream outFile;
    outFile.open("op.txt");
    if (readDataFromFile(&outFile))
    {
        if(isCustomerIdUnique()){
        displayCustomerData(&outFile);
        calculateWaitingTime(&outFile);
        }else{
            cout<<"Customer Id Is Not Unique\n";
            outFile<<"Customer Id Is Not Unique\n";
        }
    
    }
    //cout << "test";
    outFile.close();

    for(int i=0;i<noOfCustomers;i++){
        delete customers[i];
    }

    return 0;
}
