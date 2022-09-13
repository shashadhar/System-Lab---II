Assingment7 CS 515
------------------
Version Used : C++11

Description : 

The graph is created using adjacency list by reading the vertices and all the edges from the input file provided. The original graph, red sub-graph
and red sub-graph and the cycles are printed in the output file provided as input.

Task carried out:

1. Read the input file name and output file name:
    -- Read the input file name and output file name.
    -- The file names should be without spaces and with proper format
	
2. Read the no of vertices of the graph
   -- The no of vertices of the graph is read from the input file. 
   Constraint checked:
      -- The no of vertices of the graph should be valid interger.
 
3. Read the color of the vertices of the graph
    -- The color of the each vertices read from the input file and stored as a list in colors list.
	Constraint checked:
      -- The color shoud be valid character with value "r" or "b".
	  -- The no of color should be same as no of vertices of the graph
	
4. Read the edges the graph
   -- The edges are read from the input file and stored in edges list , each each is a class with source and destination as vertice no.
   Constraint checked:
      -- The edge should have a valid interger value.
	  -- The value of the edges nodes should be in the range of 0 to (no of vertices - 1)(including)
	  -- The edges list should terminate with -1 
5. Create graph and print
   -- The graph is created from the edges as an adjacency list and printed in the output file provides
   Ex :
   Original graph
   0-> 1, 2, 3
   1-> 0, 3, 4, 7
   2-> 0, 3, 5
   3-> 0, 1, 2, 6
   4-> 1, 7, 8
   5-> 2, 6, 9
   6-> 3, 5, 7
   7-> 1, 4, 6, 8
   8-> 4, 7, 9
   9-> 5, 8
6. Create red sub-graph and blue sub-graph
   -- The read sub-graph and blue sub-graph is created from the edges and printed in the output file
   Ex:
   Red sub graph
   0-> 2, 3
   2-> 0, 3, 5
   3-> 0, 2, 6
   5-> 2, 6
   6-> 3, 5

   Blue sub graph
   1-> 4, 7
   4-> 1, 7, 8
   7-> 1, 4, 8
   8-> 4, 7, 9
   9-> 8

7. DFS traversal and detection of cycles 
   -- DFS traversal is used to detect the cycles from the graph and color cycles are printed in the output file
   -- Atmost 2 cycles are printed
   Ex:
   Red cycles
   0->2->3->0 color (r-r-r-r)
   2->3->6->5->2 color (r-r-r-r-r)
   Blue cycles
   1->4->7->1 color (b-b-b-b)
   4->7->8->4 color (b-b-b-b)
   Multi color cycles
   0->1->3->0 color (r-b-r-r)
   0->1->3->2->0 color (r-b-r-r-r)   
   
8. Output file contents (op.txt)  
Original graph
0-> 1, 2, 3
1-> 0, 3, 4, 7
2-> 0, 3, 5
3-> 0, 1, 2, 6
4-> 1, 7, 8
5-> 2, 6, 9
6-> 3, 5, 7
7-> 1, 4, 6, 8
8-> 4, 7, 9
9-> 5, 8

Red sub graph
0-> 2, 3
2-> 0, 3, 5
3-> 0, 2, 6
5-> 2, 6
6-> 3, 5

Blue sub graph
1-> 4, 7
4-> 1, 7, 8
7-> 1, 4, 8
8-> 4, 7, 9
9-> 8
Red cycles
0->2->3->0 color (r-r-r-r)
2->3->6->5->2 color (r-r-r-r-r)
Blue cycles
1->4->7->1 color (b-b-b-b)
4->7->8->4 color (b-b-b-b)
Multi color cycles
0->1->3->0 color (r-b-r-r)
0->1->3->2->0 color (r-b-r-r-r)

9. The input file contents(ip.txt)
10
r b r r b r r b b b
0 1, 0 2, 0 3, 1 3, 1 4, 1 7, 2 3, 2 5, 3 6, 4 7, 4 8, 5 6, 5 9, 6 7, 7 8, 8 9, -1   