Project Overview:

This project is a menu-driven C++ console application designed to demonstrate and compare core operations on two fundamental data structures: a doubly linked list and a circular linked list. The program provides an interactive text-based interface that allows users to insert, delete, search, and display nodes within each list type independently.

The focus of the project is on understanding pointer-based data structures, memory management, and how different linked list implementations affect traversal and manipulation logic.

Motivation:

This project was created to reinforce concepts from data structures coursework, particularly linked list behavior beyond simple singly linked lists. By implementing both a doubly linked list and a circular linked list in the same program, the project highlights the structural and logical differences between the two while providing hands-on practice with pointer manipulation and dynamic memory allocation in C++.

Technologies Used:

C++ – core programming language
Standard Library (iostream) – input/output handling

Data Structure Design:

Designed two custom node structures:

Doubly Linked List (Node)

Stores integer data

Maintains prev and next pointers

Allows bidirectional traversal

Circular Linked List (NodeC)

Stores integer data

Maintains a single next pointer

Last node links back to the head, forming a loop

Each list is managed independently with its own head pointer and supporting operations.

Application Features:

Menu-driven interface for user interaction
Insert nodes at the beginning, after a given position, or at the end
Delete nodes from the beginning, end, or by position
Search for a node based on its value
Display list contents in a readable format
Separate workflows for doubly linked and circular linked lists
Continuous execution until the user exits with esc

What I Learned:

How doubly linked lists differ from circular linked lists in traversal and deletion logic
Practical experience with pointer manipulation and dynamic memory allocation
Handling edge cases such as empty lists and single-node lists
Designing a menu-based program to route user input to the correct operations
The importance of structuring code into clear, reusable functions

Future Improvements:

Improve input validation and error handling for invalid positions
Refactor search operations to be fully key-based rather than position-assisted
Standardize memory management practices (new / delete) across all list operations
Add support for additional data types beyond integers
Modularize the menu system to reduce repetition in main()

Notes

This project was built as a learning-focused exercise to strengthen understanding of linked list data structures in C++. It is intended for educational use and experimentation rather than production deployment, and it serves as a foundation for more advanced data structure and algorithm implementations.
