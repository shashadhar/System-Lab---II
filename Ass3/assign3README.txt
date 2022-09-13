Assingment3 CS 515
------------------
Version Used : C++11

Task carried out:
1. The Bank's service type is read from the file and service type information is loaded in ServiceType class.
        -- The first 3 lines of input file "ip.txt" is considered as Service type information.
		-- The 1st line is considered as MW serive type with the time as input.
		-- The 2nd line is considered as MD serive type with the time as input.
		-- The 3rd line is considered as DD service type with the time as input.
		-- The validation checks if proper interger value is added as input or not , the proper error message is displayed to the "op.txt" file
		   if input is not valid.
		-- After reading the service time for the service types "readServiceTypeData()" values are stored in list of classes of ServiceTypes
		   ex: ServiceType *serviceType = new ServiceType("MW", num);
		
		
2. The Bank's customer details are read from the file and information is stored in Customer class.
        -- After the first 3 lines are read as service type , next input file lines are read as customer data.
		-- Each line is read and split into token using the delimeter " ", each line should have 3 values: customerId, arrival time and service type.
		-- If a line has more values then proper error message is displayed.
		-- The input line is splitted using the delimeter and following constraints are checked.
              -- The input line should have only 3 values.
              -- The service type should be one of the values of "MW","MD" and "DD".
              -- The arrival time should be valid integer.
        -- The input line values are read,splitted and converted to Customer class object in the method "readCustomerData()".
		      -- The Customer service time is updated as per the service type from the ServiceTypes list.
     		  --Ex : Customer *customer = new Customer();
			         customer->setCID(token);
                 	 customer->setArrivalTime(num);
					 customer->setSeriviceTime(ServiceTypes[0]->getTime());
					 
3. The customer service time and completion time is calculated in the method "calculateWaitingTime()" using the following strategy.
    -- All the customers list are set to customers array with each customer informations.
	-- Created a next list of customers as "sortedCustomers" sorted with arrivalTime as that the customer who arrives before should be served before.
    -- Two running counters are created as "runCounter1","runCounter2" to keep track of service customer.
    -- A queue list as "schedule" is maintained to keep track of the next available customer to serve.
    -- A timer value is added to keep track of the time.
    -- The "schedule" list is added with customers who has arrived on or before timer value "time";
	   -- Ex : 
	        // schedule the processes which has arrived on the time
            if (!isEmpty(copy) && copy[0]->getArrivalTime() <= time)
            {
                insertData(schedule, copy[0]);
                deleteDataFromStart(copy);
            }
    -- Once customer is added in "schedule" list ,I have checked if any of counter is empty or idle , if so , serve the customer		
        -- EX:
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
    -- For each customer in execution and reduced its execution time as time proceeds. Once the execution time reaches
       - zero, the customer is flagged is finished and completion time and no of finished customer updated.
    -- After a customer completes execution , new customer from schedule list to put in running counter.
    -- If any running counter is idle or empty and schedule list is not empty , serve the customer.
    -- The customer is served one by one and continues as long as we are not done with serviing all the customer.	

4. Calculation of average waiting time and waiting time
    -- The waiting time is calculated as (completion time - arrival time) for each customer.
	-- The average waiting time is calculated by taking the sum of all customer wait time divided by total customers.
	
5. The following constraints are checked and proper message displayed in op.txt file.
   -- The service type time should be of integer value.
   -- The first 3 lines should be service type time data.
   -- The customer data is considered excluding the first 3 lines(which are considered as service types data).
   -- The customer data should have 3 value. Customer Id,Arrival time and Service Type.
   -- Service Type of customer data should be any of "MW", "MD" and "DD.
   -- The arrival time of customer should be a valid integer.
   -- The customer id of customer should be unique.
	
5. The output of the execution is printed in "op.txt" file.
    -- Customer Id, arrival time, completiong time, waiting time.
	-- Ex 
	101,0,15,15
    102,0,10,10
    103,2,20,18
    104,4,45,41
    105,10,30,20
    Average waiting time:20.8
6. Content of ip.txt
15
10
30
101 0 MW
102 0 MD
103 2 MD
104 4 DD
105 10 MD

7. Content of op.txt file
101,0,15,15
102,0,10,10
103,2,20,18
104,4,45,41
105,10,30,20
Average waiting time:20.8


   
 
