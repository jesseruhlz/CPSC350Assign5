# CPSC350Assign5
Jesse Ruhl
Assignment 5

References:
"reading from file into binary tree and writing to a file". stackoverflow.com
"Inorder Tree Traversal|Iterative & Recursive". techidelight.com
"Implement a stack using a BST" stackoverflow.com
"Inheritance in C++". geeksforgeeks.org

Notes:
Rollback is not implemented.
Tried pushing the nodes of the tree to the stack
but kept receiving errors.
file format is the following
1. Number of individuals in file
2. *** a break between each student or faculty member
3. ID
4. Name
5. Level
4. GPA (for student); Department (for faculty)
5. Advisor ID (for student); Number of advisees (for faculty)
*6. (ONLY FOR FACULTY) N lines of advisee ids
last line for both files is *** to break for each individual