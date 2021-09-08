# Data-Structures
This repository contains code for basic operations in different data structures in C language.<br />
I have worked hard to understand these basic operations in different data structures and written these bunch of codes by myself while understanding them.<br />
They are much simpler versions of code as compared of what we see on internet and books. To increase the knowledge of **Data** **Structures** I have made
them available to everyone. <br />
## Installation
The editor I recommend is [Atom](https://atom.io/).<br />
Then, you need to download some *packages* inside atom to make it run smoothly for all programming languages. The necessary ones are:
- script
- gpp-compiler
- atom-python-run
- minimap<br /><br />
You will need to download the [TDM-GCC](https://sourceforge.net/projects/tdm-gcc/) Compiler to run your programs directly through the Terminal.
### Linked List
Linked lists are collection of *nodes* linked to each other through pointers.<br />
Operations covered are:<br />
- Creation of a linked list
- Displaying of all the nodes
- Insertion in the beginning & in the end
- Insertion after and before a node
- Deletion of first and last node
- Deletion after and before a node
- Sorting the list in ascending order.<br />
### Circular Linked List
These are the linked lists  in which last node points to the first node. Hence, making it *circular*.<br />
Operations covered are:
- Creation of a circular linked list
- Displaying of elements
- Insertion in the beginning and the end
- Deletion of first and last element
- Deletion of complete list
### Double Linked List
These are the linked lists in which every node points to it's *predecessor* along with successor.<br />
Traversal of these lists can be done in both the directions. Same operations are covered in this.
### Stack
Stack is a data structure in which data is *pushed* one over the another. It follows the principle of **LIFO**(Last In First Out).<br />
Operations covered are:
- Push
- Pop
- Peek
#### I have implemented stacks using both arrays and linked lists.:+1:<br />
> Code for Paranthesis-Checker & Infix to Postfix expression is also provided.:sunglasses:
### Queue
These are the data structures in which data is put one after the another.It follows the principle of **FIFO**(First In First Out).<br />
Operations covered are:
- Insertion of elements
- Deletion of elements
- Deletion of complete queue
#### I have implemented queues using both arrays and linked lists.:+1:<br />
### Circular Queue
Circular Queue is a linear data structure in which the operations are performed based on **FIFO**(First In First Out) 
principle and the last position is connected back to the first position to make a circle. It is also called **'Ring Buffer'**.<br />
Insertion, Deletion & Display operations are covered.
### Priority Queue
Priority queue is an abstract data type which is like a regular queue but where additionally each element has a *"priority"* associated with it.
In a priority queue, an element with high priority is served before an element with low priority.<br />
Operations covered are:
- Insertion
- Deletion
- Sorting
- Display
### Trees
A tree is a data structure which has a hierarchichal representation of nodes. Trees are awesome especially the binary search trees.:simple_smile:<br />
Operations covered are:
- Creation of a tree
- Traversal of elements
  - PostOrder Traversal
  - InOrder Traversal
  - PreOrder Traversal
- Searching for a node
- Largest and Smallest node
- Height of the tree
- Total number of nodes
- Internal and External nodes
- Mirror Tree
- Deletion of nodes and complete tree
### Threaded Binary Tree
A binary tree is threaded by making all right child pointers that would normally be null point to the inorder successor of the node
and all left child pointers that would normally be null point to the inorder predecessor of the node.<br />
Two different functions are used to reach to the appropriate location for left & right pointers of leaf nodes. The result is printed using inorder traversal.<br />A two way threaded binary tree is fully implemented. 
### AVL Trees
These are very interesting type of trees. These are *self-balancing* binary search trees in which the difference between left & right subtrees should not be more than one. A **balancing factor** is assosiated with each node which indicates it's avlness.<br /><br />
  > Balance Factor(bf) = height of left subtree - height of right subtree
  
  
  It's allowed values are -1,0 and 1. After insertion in an AVL tree if *bf* is violated then avlness of tree is again set.<br />
Operations covered are:
- Creation of AVL tree
- Displaying of nodes
- Balance factor calculation
- Searching for a node
- Insertion using ***rotation***<br />
### Hash Table
Hash table is a very important data structure. Everyone uses hash tables because if you were to hash all the items and store them in a hash table, checking for virtually any element would happen quickly and at the same speed no matter how long is your dataset. Hash tables uses a **hash function** to map the *keys* to the corresponding values. Keys has to be unique.<br />
There are three ways to get a hash function:
1. Division method(The one I used)
2. Multiplication method
3. Universal method(best method)<br /><br />
Insert, Display & Search operations has been performed after making a hash table.
### Heaps
A heap is self-balancing binary tree in which all the nodes are arranged in a particular order. Heaps are visualized as an array of keys and values.<br />
  > Heaps are used to implement Priority Queues
  
There are two types of heaps:
1. Max Heap
2. Min Heap<br /><br />
I have only performed Insertion and Deletion operations on max heaps. Also, I have performed something called as max-heapify to maintain the principle of max heaps after insertion or deletion of an element.
<br />These are the data structures covered in the code.<br />

