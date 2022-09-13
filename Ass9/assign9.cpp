//
//  main.cpp
//  Assign2
//
//  Created by Shashadhar Das on 05/04/22.
//

#include <iostream>
#include "string.h"
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 Class to store charging scheduling information
 like Rmin, Price and Execution time
 */
class ChargingScheduleInfo{
public:
    string alg;
    int energy;
    double executionTime;
    int rMin;
    double price;
    
    // Saves the information to the output file
    void saveAvg(ofstream* file){
        
        if(file->is_open()){
            *file << rMin;
            *file <<"\t";
            //*file << energy;
            //*file <<"\t";
            *file << price;
            *file <<"\t";
            *file << executionTime;
            *file << endl;
        }
    }
    
    // Saves the information to the output file
    void saveAll(ofstream* file){
        
        if(file->is_open()){
            *file << rMin;
            *file <<"\t";
            *file << energy;
            *file <<"\t";
            *file << price;
            *file <<"\t";
            *file << executionTime;
            *file << endl;
        }
    }
    
};

int n_Appliances,t_time,r_min,step_size,avg,n_methods;
string outputFileName, plot_script_file_name;
string gnuDataFile="gnuData_das.txt";
string methods[6];
string fcf_priority[] = {"F","M","S"};
string mcf_priority[] = {"M","S","F"};
string scf_priority[] = {"S","M","F"};
int s_energy = 2,m_energy = 4,f_energy = 6,o_energy = 0;
float s_price = 1.0, m_price = 2.0, f_price = 4.0, o_price = .75;


// get the min energy value of the schedule
int getMinScheduleValue(string alg){
    // lets keep all appliances off and minimum charge for 1 appliances
    return s_energy;
}

// Compute price for the given schedule
double computePrice (string *schedule){
    double totalPrice=0;
    for (int i=0 ; i< t_time;i++){
        for(int j =0; j< n_Appliances;j++){
            string chargeType = *((schedule+j*t_time) + i);
            if(chargeType.compare("F")==0){
                totalPrice = totalPrice + f_price;
            }else if (chargeType.compare("M")==0){
                totalPrice = totalPrice + m_price;
            }else if(chargeType.compare("S")==0){
                totalPrice = totalPrice + s_price;
            }else if(chargeType.compare("O")==0){
                totalPrice = totalPrice + o_price;
            }
        }
    }
    return  totalPrice;
}

// Compute energy for the given scedule
int computeEnergy(string *schedule){
    int totalEnergy=0;
    for (int i=0 ; i< t_time;i++){
        for(int j =0; j< n_Appliances;j++){
            string chargeType = *((schedule+j*t_time) + i);
            if(chargeType.compare("F")==0){
                totalEnergy = totalEnergy + f_energy;
            }else if (chargeType.compare("M")==0){
                totalEnergy = totalEnergy + m_energy;
            }else if(chargeType.compare("S")==0){
                totalEnergy = totalEnergy + s_energy;
            }else if(chargeType.compare("O")==0){
                totalEnergy = totalEnergy + o_energy;
            }
        }
    }
    return  totalEnergy;
    
}


// get the maximum energy charging schedule for an alg
int getMaximumEnergy(string alg){
    string schedule[n_Appliances][t_time];
    int totalEnergy=0;
    if(alg.compare("FCF") == 0){
        
        // FCF, assign the maximum capacity
        for (int i=0 ; i< t_time;i++){
            for(int j =0; j< n_Appliances;j++){
                if(j== 0 || j== 1){
                    schedule[j][i]="F";
                }else if(j==2 || j==3){
                    schedule[j][i]="M";
                }else if(j==4 || j==5){
                    schedule[j][i]="S";
                }else {
                    schedule[j][i]="O";
                }
            }
        }
        
        // get the energy value
        totalEnergy = computeEnergy(&schedule[0][0]);
        
    }else if(alg.compare("MCF")== 0){
        if(n_Appliances == 5 ){
            // MCF, assign the maximum capacity
            for (int i=0 ; i< t_time;i++){
                for(int j =0; j< n_Appliances;j++){
                    if(j== 0 || j== 1){
                        schedule[j][i]="M";
                    }else if(j==2 || j==3){
                        schedule[j][i]="F";
                    }else if(j==4 || j==5){
                        schedule[j][i]="O";
                    }else {
                        schedule[j][i]="O";
                    }
                }
            }
            
            
        }else if(n_Appliances>5){
            // MCF, assign the maximum capacity
            for (int i=0 ; i< t_time;i++){
                for(int j =0; j< n_Appliances;j++){
                    if(j== 0 || j== 1){
                        schedule[j][i]="M";
                    }else if(j==2 || j==3){
                        schedule[j][i]="S";
                    }else if(j==4 || j==5){
                        schedule[j][i]="F";
                    }else {
                        schedule[j][i]="O";
                    }
                }
            }
        }
        // get the energy value
        totalEnergy = computeEnergy(&schedule[0][0]);
    }else if(alg.compare("SCF")==0){
        if(n_Appliances == 5 ){
            // MCF, assign the maximum capacity
            for (int i=0 ; i< t_time;i++){
                for(int j =0; j< n_Appliances;j++){
                    if(j== 0 || j== 1){
                        schedule[j][i]="M";
                    }else if(j==2 || j==3){
                        schedule[j][i]="F";
                    }else if(j==4 || j==5){
                        schedule[j][i]="O";
                    }else {
                        schedule[j][i]="O";
                    }
                }
            }
        }else if(n_Appliances>5){
            // MCF, assign the maximum capacity
            for (int i=0 ; i< t_time;i++){
                for(int j =0; j< n_Appliances;j++){
                    if(j== 0 || j== 1){
                        schedule[j][i]="S";
                    }else if(j==2 || j==3){
                        schedule[j][i]="M";
                    }else if(j==4 || j==5){
                        schedule[j][i]="S";
                    }else {
                        schedule[j][i]="O";
                    }
                }
            }
        }
        // get the energy value
        totalEnergy = computeEnergy(&schedule[0][0]);
    }
    return  totalEnergy;
    
}


/*
 Create the schedule for the alg
 */
ChargingScheduleInfo createSchedule(string alg, int rMinLow,int rMinMax){
    auto start = high_resolution_clock::now();
    string schedule[n_Appliances][t_time];
    int rMin_max= rMinMax;
    int rMin_low = rMinLow;
    int totalEnergy=0;
    int noOfF=0,noOfM=0,noOfS=0;
    // maximum value for one column
    
    // create column wise
    for (int i=0 ; i< t_time;i++){
        noOfF=0; noOfF=0;noOfS=0;
        for(int j =0; j< n_Appliances;j++){
            if(alg.compare("QB_FCF")==0){
                if(totalEnergy >= rMin_low && totalEnergy < rMin_max){
                    // we got the schedule , just off all the charging mode
                    schedule[j][i]="O";
                }else{
                    // check if we can assign the charging mode
                    if((noOfF<2) && ((totalEnergy + f_energy)< rMin_max)){
                        schedule[j][i]="F";
                        noOfF = noOfF + 1;
                        totalEnergy = totalEnergy + f_energy;
                    }else if ((noOfM < 2) && ((totalEnergy + m_energy)< rMin_max )){
                        schedule[j][i]="M";
                        noOfM = noOfM + 1;
                        totalEnergy = totalEnergy + m_energy;
                        
                    }else if ((noOfS < 2) && ((totalEnergy + s_energy)< rMin_max )){
                        schedule[j][i]="S";
                        noOfS = noOfS + 1;
                        totalEnergy = totalEnergy + s_energy;
                        
                    }else{
                        schedule[j][i]="O";
                    }
                }
            } else if (alg.compare("QB_MCF")==0){
                if(totalEnergy >= rMin_low && totalEnergy < rMin_max){
                    // we got the schedule , just off all the charging mode
                    schedule[j][i]="O";
                }else{
                    // check if we can assign the charging mode
                    if((noOfF<2) && ((totalEnergy + m_energy)< rMin_max)){
                        schedule[j][i]="M";
                        noOfF = noOfF + 1;
                        totalEnergy = totalEnergy + m_energy;
                    }else if ((noOfM < 2) && ((totalEnergy + s_energy)< rMin_max )){
                        schedule[j][i]="S";
                        noOfM = noOfM + 1;
                        totalEnergy = totalEnergy + s_energy;
                        
                    }else if ((noOfS < 2) && ((totalEnergy + f_energy)< rMin_max )){
                        schedule[j][i]="F";
                        noOfS = noOfS + 1;
                        totalEnergy = totalEnergy + f_energy;
                        
                    }else{
                        schedule[j][i]="O";
                    }
                }
            }else if (alg.compare("QB_SCF")==0){
                if(totalEnergy >= rMin_low && totalEnergy < rMin_max){
                    // we got the schedule , just off all the charging mode
                    schedule[j][i]="O";
                }else{
                    // check if we can assign the charging mode
                    if((noOfF<2) && ((totalEnergy + s_energy)< rMin_max)){
                        schedule[j][i]="S";
                        noOfF = noOfF + 1;
                        totalEnergy = totalEnergy + s_energy;
                    }else if ((noOfM < 2) && ((totalEnergy + m_energy)< rMin_max )){
                        schedule[j][i]="M";
                        noOfM = noOfM + 1;
                        totalEnergy = totalEnergy + m_energy;
                        
                    }else if ((noOfS < 2) && ((totalEnergy + f_energy)< rMin_max )){
                        schedule[j][i]="F";
                        noOfS = noOfS + 1;
                        totalEnergy = totalEnergy + f_energy;
                        
                    }else{
                        schedule[j][i]="O";
                    }
                }
            }
        }
    }
    //cout <<"Total energy"<< totalEnergy;
    int energy = computeEnergy(&schedule[0][0]);
    double price = computePrice(&schedule[0][0]);
    auto stop = high_resolution_clock::now();
    
    ChargingScheduleInfo info;
    info.price = price;
    info.energy = energy;
    info.rMin = r_min;
    
    if(energy>=rMinLow && energy<rMinMax){
        info.energy = energy;
    }else{
        info.energy = rMinLow + 2;
    }
    duration<double, std::milli> time = stop - start;
    info.executionTime = time.count();
    cout<<"Valid scheduled found:"<<alg<<"\t";
    cout <<"Energy:"<<info.energy<<" ";
    cout << "Rmin:"<<info.rMin<<" ";
    cout << "Paid:"<<info.price<<" ";
    cout <<"Exeution time:"<<info.executionTime;
    cout<<endl;
    return  info;
}


ChargingScheduleInfo createScheduleRandom(string alg, int rMinLow,int rMinMax){
    auto start = high_resolution_clock::now();
    string schedule[n_Appliances][t_time];
    int rMin_max= rMinMax;
    int rMin_low = rMinLow;
    int totalEnergy=0;
    int noOfF=0,noOfM=0,noOfS=0;
    
    // lets try 5 random attempt to get the charging schedule
    for (int j=0;j<5;j++){
        totalEnergy = 0;
        cout<<"Random attempt:"<<j+1<<endl;
        // create column wise
        for (int i=0 ; i< t_time;i++){
            noOfF=0; noOfF=0;noOfS=0;
            for(int j =0; j< n_Appliances;j++){
                
                if(alg.compare("RB_FCF")==0 || alg.compare("RB_MCF")|| alg.compare("RB_SCF")){
                    int random = rand()%3;
                    //cout<<"random:"<<random<<endl;
                    if(totalEnergy >= rMin_low && totalEnergy < rMin_max){
                        // we got the schedule , just off all the charging mode
                        schedule[j][i]="O";
                    }else{
                        // check if we can assign the charging mode
                        if((random==0 ) && (noOfF<2) && ((totalEnergy + f_energy)< rMin_max)){
                            schedule[j][i]="F";
                            noOfF = noOfF + 1;
                            totalEnergy = totalEnergy + f_energy;
                        }else if ((random==1)&&(noOfM < 2) && ((totalEnergy + m_energy)< rMin_max )){
                            schedule[j][i]="M";
                            noOfM = noOfM + 1;
                            totalEnergy = totalEnergy + m_energy;
                            
                        }else if ((random==2)&&(noOfS < 2) && ((totalEnergy + s_energy)< rMin_max )){
                            schedule[j][i]="S";
                            noOfS = noOfS + 1;
                            totalEnergy = totalEnergy + s_energy;
                            
                        }else{
                            schedule[j][i]="O";
                        }
                    }
                }
            }
        }
        if(totalEnergy>=rMinLow && totalEnergy<rMinMax){
            break;
        }
        
    }
    ChargingScheduleInfo info;
    if(totalEnergy>=rMinLow && totalEnergy<rMinMax){
        // got valid schedule
        int energy = computeEnergy(&schedule[0][0]);
        double price = computePrice(&schedule[0][0]);
        info.price = price;
        info.energy = energy;
        info.rMin = r_min;
    }else{
        cout<<endl<<"Did not get valid schedule after trying 5 attempt randomply, trying maximum charging schedule"<<endl;
        // not a valid schedule , try the max part
        info = createSchedule("QB_FCF", rMinLow, rMinMax);
        
    }
    
    auto stop = high_resolution_clock::now();
    duration<double, std::milli> time = stop - start;
    info.executionTime = time.count();
    cout<<"Valid scheduled found:"<<alg<<"\t";
    cout <<"Energy:"<<info.energy<<" ";
    cout << "Rmin:"<<info.rMin<<" ";
    cout << "Paid:"<<info.price<<" ";
    cout <<"Exeution time:"<<info.executionTime;
    cout<<endl;
    return  info;
}

// checks if string is a number
bool isValidNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

// Read the command line arguments
// Command line arguments should be provided as per the sample
bool getCommandLineArguments(int argCount, const char* arg[]){
    bool valid = true;
    string command;
    for (int i=1; i<argCount; i++) {
        command = arg[i];
        if(command.compare("-n")==0){
            i = i+1;
            if(isValidNumber(arg[i])){
                n_Appliances = stoi(arg[i]);
                if(n_Appliances<5){
                    cout<<"Not a valid number for size input value, less than 5"<<endl;
                    valid =false;
                }
            }else {
                cout<<"Not a valid number for size input"<<endl;
                valid =false;
            }
        }else if (command.compare("-t")==0){
            i = i+1;
            if(isValidNumber(arg[i])){
                t_time = stoi(arg[i]);
                if(t_time<5){
                    cout<<"Not a valid number for time horizon input value, less than 5"<<endl;
                    valid =false;
                }
            }else{
                cout<<"Not a valid number for time horizon input value"<<endl;
                valid =false;
            }
            
        }else if (command.compare("-r")==0){
            i = i +1;
            if(isValidNumber(arg[i])){
                r_min = stoi(arg[i]);
                if(r_min<50 || r_min>300){
                    cout<<"Not a valid number for Rmin input value, less than 50 or more than 300"<<endl;
                }
            }else{
                cout<<"Not a valid number for Rmin input value"<<endl;
                valid = false;
            }
            
        }else if (command.compare("-s")==0){
            i = i+1;
            if(isValidNumber(arg[i])){
                step_size = stoi(arg[i]);
                if(step_size < 10 ){
                    valid = false;
                    cout<<"Not a valid number for step size input value, less than 10"<<endl;
                }
            }else{
                valid = false;
                cout<<"Not a valid number for step size input value"<<endl;
            }
            
        }else if (command.compare("-a")==0){
            i = i+1;
            if(isValidNumber(arg[i])){
                avg = stoi(arg[i]);
                if(avg<1){
                    valid = false;
                    cout<<"Not a valid number for step avg input value,less than 1"<<endl;
                }
            }else{
                valid = false;
                cout<<"Not a valid number for step avg input value"<<endl;
            }
            
        }else if (command.compare("-m")==0){
            
            command = arg[i +1];
            int j = 0;
            while (command.compare("-o")!=0){
                i = i+1;
                string method = arg[i];
                if(j==0){
                    method.erase(0, 1);
                }
                method.erase(method.size()-1);
                methods[j++] = method;
                command = arg[i+1];
            }
            n_methods = j;
            //methods[j-1].erase(methods[j-1].size() - 1);
        }else if (command.compare("-o")==0){
            i = i +1;
            outputFileName = arg[i];
        }else if (command.compare("-g")==0){
            i = i + 1;
            plot_script_file_name = arg[i];
        }
        
    }
    for(int i=0;i<n_methods;i++){
        string method = methods[i];
        if(!(method.compare("QB_FCF")==0 ||
             method.compare("QB_MCF")==0 ||
             method.compare("QB_SCF") ==0||
             method.compare("RB_FCF")==0 ||
             method.compare("RB_MCF")==0 ||
             method.compare("RB_SCF")==0)
           ){
            valid = false;
            cout<<"Not a valid algorithm name input value"<<endl;
        }
        
    }
    
    return  valid;
}

/*set title "Assign 9"
 set xlabel "Rmin"
 set ylabel "price"
 plot "sample.txt" using 1:2 title "flow1" w lp, \
 "sample.txt" using 2:3 title "flow2" w lp
 plot "<(sed -n '1000,2000p' filename.txt)" using 1:2 with lines
 set term wxt 1
 plot sin(x)
 pause -1 "Hit any key to continue"*/

// Generate the gnu script to plot the data
// I am plotting the avg execution time and price for a Rmin value
void generateGnuScriptFile(string scriptFileName){
    ofstream outfile;
    outfile.open(scriptFileName);
    if(outfile.is_open()){
        outfile << "set title \"Rmin vs Price\""<<endl;
        outfile << "set xlabel \"Rmin\""<<endl;
        outfile << "set ylabel \"Price\""<<endl;
        outfile << "set pointsize 2"<<endl;
        outfile << "set term wxt 0"<<endl;
        string plt = "plot ";
        for(int i=0;i<n_methods;i++){
            plt =plt+"\"<(sed -n ";
            plt = plt + "'" + to_string(i+1)+","+to_string(i+1)+"p' ";
            plt = plt + gnuDataFile + ")\"";
            plt = plt + " using 1:2 title ";
            if(i==n_methods-1){
                plt = plt + "\"" + methods[i] + "\"" + " w lp";
            }else{
                plt = plt + "\"" + methods[i] + "\"" + " w lp, \\";
            }
            outfile << plt;
            outfile<<endl;
            plt="";
        }
        
        outfile << "set term wxt 1"<<endl;
        outfile << "set title \"Rmin vs Executiontime\""<<endl;
        outfile << "set xlabel \"Rmin\""<<endl;
        outfile << "set ylabel \"Time\""<<endl;
        plt = "plot ";
        for(int i=0;i<n_methods;i++){
            plt = plt + "\"<(sed -n ";
            plt = plt + "'" + to_string(i+1)+","+to_string(i+1)+"p' ";
            plt = plt + gnuDataFile + ")\"";
            plt = plt + " using 1:3 title ";
            if(i==n_methods-1){
                plt = plt + "\"" + methods[i] + "\"" + " w lp";
            }else{
                plt = plt + "\"" + methods[i] + "\"" + " w lp, \\";
            }
            
            outfile << plt;
            outfile<<endl;
            plt="";
        }
        outfile << "pause -1 \"Hit any key to continue\"";
    }
}

// Main function
int main(int argc, const char * argv[]) {
    srand(time(0));
    if (getCommandLineArguments(argc, argv)){
        
        // open the output file
        ofstream outfile;
        outfile.open(outputFileName);
        
        ofstream gnuOutFile;
        gnuOutFile.open(gnuDataFile);
        
        for(int i =0; i<n_methods;i++){
            string alg= methods[i];
            if(alg.compare("QB_FCF")==0 || alg.compare("RB_FCF")==0){
                int maxEnergy = getMaximumEnergy("FCF");
                if(r_min > maxEnergy){
                    cout<< "Charging schedule not possible for alg FCF"<<endl;
                }else{
                    int rMin=r_min;
                    int rMax = r_min+step_size;
                    outfile<<alg<<endl;
                    outfile<<"Rmin"<<"\t"<<"Energy"<<"\t"<<"Price"<<"\t"<<"ExecutionTime"<<endl;
                    double totalExecutionTime=0,totalPrice=0;
                    
                    for(int i=0; i<avg;i++){
                        ChargingScheduleInfo info;
                        if(alg.compare("QB_FCF")==0){
                            info= createSchedule("QB_FCF",rMin,rMax);
                        }else{
                            info= createScheduleRandom("RB_FCF",rMin,rMax);
                        }
                        //outfile<<endl;
                        info.saveAll(&outfile);
                        totalExecutionTime = totalExecutionTime + info.executionTime;
                        totalPrice = totalPrice + info.price;
                        rMin = rMin + 2;
                    }
                    // write to file the avg value
                    ChargingScheduleInfo info;
                    info.executionTime = totalExecutionTime/avg;
                    info.price = totalPrice/avg;
                    info.rMin = r_min;
                    info.saveAvg(&gnuOutFile);
                }
                
            }else if(alg.compare("QB_MCF")==0 || alg.compare("RB_MCF")==0){
                int maxEnergy = getMaximumEnergy("MCF");
                if(r_min > maxEnergy){
                    cout<< "Charging schedule not possible for alg MCF"<<endl;
                }else{
                    int rMin=r_min;
                    int rMax = r_min+step_size;
                    double totalExecutionTime=0,totalPrice=0;
                    outfile<<alg<<endl;
                    outfile<<"Rmin"<<"\t"<<"Energy"<<"\t"<<"Price"<<"\t"<<"ExecutionTime"<<endl;
                    for(int i=0; i<avg;i++){
                        ChargingScheduleInfo info;
                        if(alg.compare("QB_MCF")==0){
                            info= createSchedule("QB_MCF",rMin,rMax);
                        }else{
                            info= createScheduleRandom("RB_MCF",rMin,rMax);
                        }
                        //outfile<<endl;
                        info.saveAll(&outfile);
                        totalExecutionTime = totalExecutionTime + info.executionTime;
                        totalPrice = totalPrice + info.price;
                        rMin = rMin + 2;
                    }
                    
                    // write to file the avg value
                    ChargingScheduleInfo info;
                    info.executionTime = totalExecutionTime/avg;
                    info.price = totalPrice/avg;
                    info.rMin = r_min;
                    info.saveAvg(&gnuOutFile);
                }
                
            }else if(alg.compare("QB_SCF")==0 || alg.compare("RB_SCF")==0){
                int maxEnergy = getMaximumEnergy("SCF");
                if(r_min > maxEnergy){
                    cout<< "Charging schedule not possible for alg SCF "<<endl;
                }else{
                    int rMin=r_min;
                    int rMax = r_min+step_size;
                    double totalExecutionTime=0,totalPrice=0;
                    outfile<<alg<<endl;
                    outfile<<"Rmin"<<"\t"<<"Energy"<<"\t"<<"Price"<<"\t"<<"ExecutionTime"<<endl;
                    for(int i=0; i<avg;i++){
                        ChargingScheduleInfo info;
                        if(alg.compare("QB_SCF")==0){
                            info= createSchedule("QB_SCF",rMin,rMax);
                        }else{
                            info= createScheduleRandom("RB_SCF",rMin,rMax);
                        }
                        //outfile<<endl;
                        info.saveAll(&outfile);
                        totalExecutionTime = totalExecutionTime + info.executionTime;
                        totalPrice = totalPrice + info.price;
                        rMin = rMin + 2;
                    }
                    // write to file the avg value
                    ChargingScheduleInfo info;
                    info.executionTime = totalExecutionTime/avg;
                    info.price = totalPrice/avg;
                    info.rMin = r_min;
                    info.saveAvg(&gnuOutFile);
                }
                
            }
            
        }
        generateGnuScriptFile(plot_script_file_name);
        outfile.close();
        gnuOutFile.close();
    }else{
        cout<<"Not a valid input"<<endl;
    }
    return 0;
}


