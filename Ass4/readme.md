Assingment4 CS 515
------------------
Version Used : C++11

Question : https://github.com/shashadhar/System-Lab-II/blob/main/Ass4/CS515_22_Assign4.pdf <br>

Task carried out:
1. The Binary tree node values are read from the file and tokenized. Tree nodes are created and stored in a linked list. 
       	-- Each line is read and split into token using the delimeter " ", each line should have 3 values: Node value, left subtree and right subtree.
		-- If a line has more values then proper error message is displayed.
		-- The input line is splitted using the delimeter and following constraints are checked.
              -- The input line should have only 3 values.
              -- The values should be a valid integer.
        -- The input line values are read,splitted and converted to TreeNode object in the method "readNodeData()".
		        --Ex :TreeNode *node = new TreeNode();
			          node->data = num;
                 	  node->left = num;
					  node->right = num;
		
		
2. The binary tree is constructed in the method "constructBinaryTree()" with the help of a queue.
    -- First root node is enqueued in the queue.
	-- Dequeued a node from the queue and stored in processed node , the value of right and left value is checked.
             -- If left value is 1 , the new node from the list is inserted in binary tree as left child of processed node and new node is enqueued in the queue.
             -- if right value is 1, the new node from the list is inserted in binary tree as right child of processed node and new node is enqueued in the queue. 
             -- If left or right is 0, NULL is set to left and 	right child of processed node		
    -- The task is performed as long as queue is not empty and binary tree is formed			 
       
					 
3. The preorder and inorder traversal of the binary tree is printed in op.txt file.

4. The left tilted is tree is created (method name - leftTiltTree()) using the following strategy.
    -- Get the height of left subtree and right subtree
    -- If right subtree height is more than left subtree , swap the left and right child link.
	
5. The preorder and inorder traversal of the tilted binary tree is printed in op.txt file.	
	
6. The following constraints are checked and proper message displayed in op.txt file.
   -- The input line should have 3 value. Node value, Left subtree and Right subtree.
   -- The values should be a valid integer.
   -- The nodes value should be unique.
   -- The count of node should not be more or less than the required nodes to create the binary tree.
	
7. The output of the execution is printed in "op.txt" file.
Input Binary Tree:
Preorder:297 319 282 124 530 287 471 376 173 214 424 
Inorder:319 282 297 471 287 376 173 530 214 124 424 

Tilted Binary Tree:
Preorder:297 124 530 287 376 173 471 214 424 319 282 
Inorder:173 376 287 471 530 214 124 424 297 282 319 

8. Content of ip.txt
297 1 1
319 0 1
124 1 1
282 0 0
530 1 1
424 0 0
287 1 1
214 0 0
471 0 0
376 0 1
173 0 0

9. Content of op.txt file
Input Binary Tree:
Preorder:297 319 282 124 530 287 471 376 173 214 424 
Inorder:319 282 297 471 287 376 173 530 214 124 424 

Tilted Binary Tree:
Preorder:297 124 530 287 376 173 471 214 424 319 282 
Inorder:173 376 287 471 530 214 124 424 297 282 319


   
 
