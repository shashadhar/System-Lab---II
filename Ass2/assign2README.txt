Assingment1 CS 515
------------------
Version Used : C++11

Task carried out:
 1. First number is read from the file as a string value and converted to to circular linked list representation
        -- The string is splitted using the method named "tokenizeAndCreateList()" of each node with maximum digit lenth of 5.
		-- When splitting the valid input string is checked using the method "bool isNumber(const string &str)" which discard invalid input
		   and proper output message displayed. 
  1. Second number is read from the file as a string value and converted to to circular linked list representation
        -- The string is splitted using the method named "tokenizeAndCreateList()" of each node with maximum digit lenth of 5.
		-- When splitting the valid input string is checked using the method "bool isNumber(const string &str)" which discard invalid input
		   and proper output message displayed.   
 3. For Invalid input string appropriate message in output file "op.text" is generated. It checks the following
    (a). Should not contain the decimal value.
    (b). Should not contain the alphabet.
 If input is valid then go to next step to perfrom the operation.

 4. Operations performed

    1.Comprasion between numbers.
        --- The comparison of numbers are done from the circular linked list representaion using the method "int compare(CircularLinkedList *second)"
	    --- The method returns 1 if first number is greater, returns -1 if second number is greater and -1 if both are same
		--- The proper output is printed in op.txt file after comparison
	    --- Ex: Number1:1,32456,78989
                Number2:132
                First number is bigger than the second number

    2.Addition of the numbers.
         --- The addition of the numbers are done using the method "void perfromAddition(CircularLinkedList *firstNumber, CircularLinkedList *secondNumber)"
		 --- The result is stored in a third circular list and output is added in op.txt file
		 --- The addition is performed using carry forward method
		 --- Ex: Number1:1,32456,78989
                 Number2:132
                 First number is bigger than the second number
                 Sum :
                 1,32456,79121
                 Substraction:
                 1,32456,78857
  
    3.Subtraction of the numbers.
       --- The Subtraction of the numbers are done (bigger to smaller) using the method "subtraction()"
	   --- The result is stored in a third circular list and output is added in op.txt file
	   --- The addition is performed using borrow forward method
       --- Ex: Number1:1,32456,78989
               Number2:132
               First number is bigger than the second number
               Sum :
               1,32456,79121
               Substraction:
               1,32456,78857
 
    4. Program have a printlist() which takes the circular list pointer and file pointer "printList(CircularLinkedList *number, ofstream *file)".
	   --- The CircularLinkedList *number is number representation in circular linked list and *file is the file pointer to print in a file.
       --- Ex: Number1:1,32456,78989
                 Number2:132
                 First number is bigger than the second number
                 Sum :
                 1,32456,79121
                 Substraction:
                 1,32456,78857


     Ex- Contents of "ip.text"
          13245678989
          132
        After executing the program
       
        Contents of op.txt file
          Number1:1,32456,78989

          Number2:132

          First number is bigger than the second number
          Sum :
          1,32456,79121
          Substraction:
          1,32456,78857
 
