Assingment7 CS 515
------------------
Version Used : C++11 <br>
Question : https://github.com/shashadhar/System-Lab-II/blob/main/Ass7/CS515_22_Assign7_update.pdf <br>
Description : 

The graph is created using adjacency list by reading the vertices and all the edges from the input file provided. The original graph, red sub-graph
and red sub-graph and the cycles are printed in the output file provided as input.

Task carried out:<br>

1. Read the input file name and output file name:
   <br> -- Read the input file name and output file name.
    -- The file names should be without spaces and with proper format
	
2. Read the no of vertices of the graph
   <br>-- The no of vertices of the graph is read from the input file. 
   Constraint checked:
      <br>-- The no of vertices of the graph should be valid interger.
 
3. Read the color of the vertices of the graph
   <br> -- The color of the each vertices read from the input file and stored as a list in colors list.
	Constraint checked:
    <br>  -- The color shoud be valid character with value "r" or "b".
	 <br> -- The no of color should be same as no of vertices of the graph
	
4. Read the edges the graph
  <br> -- The edges are read from the input file and stored in edges list , each each is a class with source and destination as vertice no.
   Constraint checked:
    <br>  -- The edge should have a valid interger value.
	 <br> -- The value of the edges nodes should be in the range of 0 to (no of vertices - 1)(including)
	 <br> -- The edges list should terminate with -1 
5. Create graph and print
   <br>-- The graph is created from the edges as an adjacency list and printed in the output file provides
   Ex :<br>
   Original graph<br>
   0-> 1, 2, 3<br>
   1-> 0, 3, 4, 7<br>
   2-> 0, 3, 5<br>
   3-> 0, 1, 2, 6<br>
   4-> 1, 7, 8<br>
   5-> 2, 6, 9<br>
   6-> 3, 5, 7<br>
   7-> 1, 4, 6, 8<br>
   8-> 4, 7, 9<br>
   9-> 5, 8<br>
6. Create red sub-graph and blue sub-graph
   <br>-- The read sub-graph and blue sub-graph is created from the edges and printed in the output file
   Ex:<br>
   Red sub graph<br>
   0-> 2, 3<br>
   2-> 0, 3, 5<br>
   3-> 0, 2, 6<br>
   5-> 2, 6<br>
   6-> 3, 5<br>
<br>
   Blue sub graph<br>
   1-> 4, 7<br>
   4-> 1, 7, 8<br>
   7-> 1, 4, 8<br>
   8-> 4, 7, 9<br>
   9-> 8<br>

7. DFS traversal and detection of cycles <br>
   <br>-- DFS traversal is used to detect the cycles from the graph and color cycles are printed in the output file
   <br>-- Atmost 2 cycles are printed
   Ex:<br>
   Red cycles<br>
   0->2->3->0 color (r-r-r-r)<br>
   2->3->6->5->2 color (r-r-r-r-r)<br>
   Blue cycles<br>
   1->4->7->1 color (b-b-b-b)<br>
   4->7->8->4 color (b-b-b-b)<br>
   Multi color cycles<br>
   0->1->3->0 color (r-b-r-r)<br>
   0->1->3->2->0 color (r-b-r-r-r)   <br>
   
8. Output file contents (op.txt)  <br>
Original graph<br>
0-> 1, 2, 3<br>
1-> 0, 3, 4, 7<br>
2-> 0, 3, 5<br>
3-> 0, 1, 2, 6<br>
4-> 1, 7, 8<br>
5-> 2, 6, 9<br>
6-> 3, 5, 7<br>
7-> 1, 4, 6, 8<br>
8-> 4, 7, 9<br>
9-> 5, 8<br>
<br>
Red sub graph<br>
0-> 2, 3<br>
2-> 0, 3, 5<br>
3-> 0, 2, 6<br>
5-> 2, 6<br>
6-> 3, 5<br>
<br>
Blue sub graph<br>
1-> 4, 7<br>
4-> 1, 7, 8<br>
7-> 1, 4, 8<br>
8-> 4, 7, 9<br>
9-> 8<br>
Red cycles<br>
0->2->3->0 color (r-r-r-r)<br>
2->3->6->5->2 color (r-r-r-r-r)<br>
Blue cycles<br>
1->4->7->1 color (b-b-b-b)<br>
4->7->8->4 color (b-b-b-b)<br>
Multi color cycles<br>
0->1->3->0 color (r-b-r-r)<br>
0->1->3->2->0 color (r-b-r-r-r)<br>
<br>
9. The input file contents(ip.txt)<br>
10<br>
r b r r b r r b b b<br>
0 1, 0 2, 0 3, 1 3, 1 4, 1 7, 2 3, 2 5, 3 6, 4 7, 4 8, 5 6, 5 9, 6 7, 7 8, 8 9, -1   