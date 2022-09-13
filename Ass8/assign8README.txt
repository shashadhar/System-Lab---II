Assingment8 CS 515
------------------
Version Used : C++11

Description.
Created a simple text based database using shell scripts in Linux (used Mac)

Task carried out:

1. Created script for CreateTable.tab:
    -- The script accepts a table name and field names (RollNo,Name,CPI).
	-- Example - ./createTable.sh CPI.tab RollNo Name CPI
	-- The no of arguments are checked and should be entered as per the example
	-- The fileds should be in the sequence as per example

	
2. Created script for Insert Record
   -- insertRecord.sh will be used to insert records into the table.
   -- Should enter valid table name with exact no of arguments
   -- First argument should be table name and column name sequence can be anything but prefix should be of "-r" or "-n" and "-c"
   -- "-c" -> CPI, "-r" -> RollNo , "-n" -> Name
   -- Constraint checked
       -- Should have a valid table name
       -- Valid number of arguments
	   -- The no of records argument should be numeric
	   -- CPI value should be numeric or decimal value 
	   
   -- Ex ./insertRecord.sh CPI.tab 2
         Enter RollNo
         2111cs14
         Enter Name [ shashadhar ]
         Enter cpi
         6
         2111cs14	shashadhar	6	

         Enter RollNo
         56
         Enter Name [ shashadhar ]
         Das
         Enter cpi
         7.8
         56	Das	7.8	

         2 record added in relation CPI.tab  
		 ./insertRecord.sh CPI.tab -r 67 -n "Das" -c 9.8
		 67	Das	9.6	
         Record added  with RollNo: 67,Name:Das,CPI:9.6
 
	
3. Created script for updating a record
   -- Will be used to update the record, can update CPI and Name
   -- Should enter valid table name and column name with valid number of arguments
   -- The column names can be in any sequence but should be prefix with "-r","-n","-c"
   -- Constraint check:
       -- Valid number of arguments and proper tableName with proper value
	   -- CPI value should be valid numerical value
   Ex: ./updateRecord.sh CPI.tab -r 45 -c 11
       RollNo found
       Record with RollNo 45 is updated in CPI.tab table
       ./updateRecord.sh CPI.tab -r 45 -n "Das" -c 6.7
	   RollNo found
       Record with RollNo 45 is updated in CPI.tab table
       	   
