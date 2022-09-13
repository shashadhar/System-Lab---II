Assingment6 CS 515
------------------
Version Used : C++11

Description : 

The Bloom filter is created and displayed as binary strings. The member queries are performed for non inserted elements.
FP collisons causes and probability is calculated and displayed. The inserted elements should be unique and withing int range.

Task carried out:

1. Hash functions :
    -- The no of hash functions are read from file.
    -- The hash functions are read from file and created the hash functions class "HashFunction" with value as a,b and c.
	-- All the hash functions are stored in a list
	-- Each hash function should be unique
	Constraint checked:
	   -- The value of no of hash functions should be valid integer
	   -- The value of a,b and c of each hash function should be a valid integer 
2. Creation of Bloom filter
   -- The element to be inserted are read from file and stored
   -- For each element, we have calculated the hash value for each hash function 
   -- The hash value as treated as index and that index is set as 1
   Constraint checked:
      -- The value of element to be inserted should be of valid interger type and can be any value with int range.
   Bloom filter:
    -- The Boom Filter is
       | 1 | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |  
3. Creation of query elements 
    -- The query elements are created from the values which are not inserted into the bloom filter.
	
4. Creation of False Positive (FP) and Fraction Of False Positives (probability)
   -- For each query elements, hash function is run and checked if all the hash value is set as 1
   -- If all hash valued indexex are set as 1 , the element is considered as FP case	
   -- The probability is calculated as total FP cases divided by total query elements
   Ex : Fraction Of False Positives , p = 0.83
6. Calculation of collision cases 
   -- For each query elements if found False positive, the no of collision causes are calculated and displayed
   -- Atmost "m" elements of collision causes are displayed
   -- To get the causes
        -- The hash index for the query element is found first
        -- Then we look for inserted elements for which this index is set using the hash function
        -- The element hash pair is stored in ElementHashPairs class 	
            -- This class stored all the list of ElementHashPair which sets the particular index
            -- Ex: elementHashPairsList[1] - Stores all the "element and hash pair" for the index 1 (which is set 1) 			
   -- Ex: 13,  False Positive (Y) : Collision cases : <4,1><4,2>   
7. Display of member queries
   -- Member queries are displayed after user press "Enter" key

8. Output file contents

m = 2
n = 10
k = 4
The Boom Filter is
| 1 | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |

Membership queries

12,  False Positive (Y) : Collision cases : <7,2><7,1>
13,  False Positive (Y) : Collision cases : <4,1><4,2>
14,  False Positive (N)
15,  False Positive (Y) : Collision cases : <4,2><4,1>
16,  False Positive (Y) : Collision cases : <7,1><7,2>
17,  False Positive (Y) : Collision cases : <11,2><11,1>
Fraction Of False Positives , p = 0.83     