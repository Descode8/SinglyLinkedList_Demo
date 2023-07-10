/*****************************************************************************************************************************************************
This program demonstrates a singly Linked List                                                                                                       *
   1.) LL are the data structures that are used to store data items in a linear fashion but non-contiguous locations                                 *
   2.) A LL is a collection of nodes that contain a data part and a next pointer that contains the memory address of the next element in the list.   *
   3.) The last element in the list has its next pointer set to nullptr, thereby indicating the end of the list.                                     *
   4.) The first element of the list is called the Head.                                                                                             *
   5.) The linked list supports various operations like insertion, deletion, traversal, etc.                                                         *
      ... LL are expensive as far as their traversal is concerned since we cannot randomly access the elements like arrays.                          *
      ... However, insertion-deletion operations are less expensive when compared arrays.                                                            *
   6.) In case of dynamic memory allocation, linked lists are preferred over arrays.                                                                 *
   7.) LL are faster than vectors, the speed at which a node can be inserted or deleted                                                              *
                                                                                                                                                     *
Applications:                                                                                                                                        *
   Stacks, Queues, undo button of any application like Microsoft Word, Paint, etc..., GPS navigation: a linked list of map data; travelling from     *
   origin to destination is an example of traversing through all nodes, rerouting by a GPS is an example of Add and Remove operations of a map       *                                                                                                                                                   
******************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/********************************************************************************************************************************************************
struct Node is the node to the linked list. Since a linked list is a self-referential data structure, it contains data members and a pointer to itself. *
The struct represents a single node in the list, a struture that contains the data stored                                                               *                                                  
*********************************************************************************************************************************************************/

struct Node{
   int data; // stores data in the node
   Node *next; // points to itself, points to the address of next node
} *newNode, *temp, *head = nullptr, *tail = nullptr, *curr; // struct variables; these are global, can be passed as a parameter

/*********************************************************************
Prototypes: functions that will retrieve various info of Linked List *
**********************************************************************/

void insertAtEnd();
void insertAtFront();
void display(struct Node*);
void reverseDisplay(struct Node*);
void EONode(struct Node*, int);
int listLength(int);
int getSum(struct Node*);
int getMax(struct Node*);
int getMin(struct Node*);
void freeList(struct Node*);
void endProgram(struct Node*);
void getHead(struct Node*);
void getMid(struct Node*, int);
void getTail(struct Node*);
void call(struct Node*, int);

/*
void push(struct Array*, int);
void insert(struct Array*, int, int);
void remove(struct Array*, int);
int linearSearch(struct Array*, int);
int countOccurrences(struct Array*, int);
int binarySearch(struct Array*, int);
void bubbleSort(struct Array*);
int get(struct Array*, int);
bool set(struct Array*, int, int);
int max(struct Array*);
int min(struct Array*);
void reverse(struct Array*);
void shiftLeft(struct Array*);
void shiftRight(struct Array*);
void rotate(struct Array*);
void swap(int*, int*);
int sum(struct Array*);
void random(struct Array*);
*/

/********************************************************************************
In main, prompt user for input. Use input to call functions implementing the LL *
*********************************************************************************/

int main(){
   
   char input;
   cout << "\n******* Create Singly Linked List: *******\n Stack or Queue? (s/q): ";
   cin >> input;

   if(input == 's'){ 
      insertAtFront();
   }
   else if(input == 'q'){ 
      insertAtEnd();
   }
   else{
      cout << "\nPlease enter 's' or 'q' only...or 'x' to end program: ";
      cin >> input;

      if(input == 'x'){
         endProgram(head);
      }
      else if(input == 's'){
         insertAtFront();
      }
      else if(input == 'q'){
         insertAtEnd();
      }
      else{
         main();
      } 
   }
}

/*****************************************************************************************
This function will store each node created by user to the end of the Linked List (stack) *
******************************************************************************************/

void insertAtEnd(){
  
   int input;
   bool create = true;

   cout << "Enter integers to start LL or 0 to end program: ";
   cin >> input;

   if(input == 0){
      cout << "No LL created...restart program...";
   }
   else{
   //create a new node in the LL
      newNode = new Node;
      newNode -> data = input;
      newNode -> next = nullptr;
   // only one node in LL currently, set both head & tail 
      head = tail = newNode; 

      do{
         cout << "Enter integers to store at the end of LL or 0 to end program: ";
         cin >> input;

         if(input == 0){
            create = false;
            display(head);
         }
         else{
         //create a new node in the LL
            newNode = new Node;
            newNode -> data = input;
            newNode -> next = nullptr;
         // now, set tail to point to the new node in the list, tail is currently one node behind the new node
            tail -> next = newNode;
            tail = tail -> next;
         } 
      }while(create);  
   }
}

/****************************************************************************************
This function will store each node created by user to the beginning of the Linked List  *
*****************************************************************************************/

void insertAtFront(){
   
   int input;
   bool create = true;

   cout << "Enter an integers to start LL or 0 to end program: ";
   cin >> input;

   if(input == 0){
      cout << "No LL created...restart program...";
   }
   else{
   //create a new node in the LL
      newNode = new Node;
      newNode -> data = input;
      newNode -> next = head;
   // now, set tail to point to the new node in the list, tail is currently one node behind the new node 
      head = tail = newNode;

      do{
         cout << "Enter an integer to store at the beginning of LL or 0 to end program: ";
         cin >> input;

         if(input == 0){
            create = false;
            display(head);
         }
         else{
         //create a new node in the LL
            newNode = new Node;
            newNode -> data = input;
            newNode -> next = head;
      
            head = newNode; 
         }
      }while(create);  
   }
}

/*******************************************************************************************************
This function will display user input in Linked List format and call the other functions in a sequence *
********************************************************************************************************/

void display(struct Node* head){
   
   unsigned int len = 0;
// temp accesses starting address of LL through head
   temp = head; 

   puts("\n***** Here is your Linked List *****");

   while(temp != nullptr){
      if(temp -> next == nullptr){
         printf("[%d] -> NULL\n", temp -> data);
      }
      else{
         printf("[%d] -> ", temp -> data);
      }
      temp = temp -> next;
      len++;
   }

   puts("\n***** Here is your list in reverse *****");
   reverseDisplay(head);
   puts("NULL\n");
   EONode(head, len);
   call(head, len);
   //insertAt(head, len); 
}

/******************************************************************************************************************************************
This function will display the Linked List in reverse using recursion. Recursion uses "the call stack" so it prints in a backwards manner *
*******************************************************************************************************************************************/

void reverseDisplay(struct Node* head){

   if(head != nullptr){
      reverseDisplay(head -> next);
      printf("[%d] -> ", head -> data); 
   }
}

/**************************************************************************
This function will find and display 'every other node' in the Linked List *
***************************************************************************/

void EONode(struct Node* head, int len){
   
   puts("\n***** Here is EON in your Linked List *****");
   temp = head;

   for(int i = 1; i <= len; i++){
      if(i % 2 != 0){
         printf("[%d] -> ", temp -> data);
      }
      temp = temp -> next;
   }
   puts("NULL");  
}

/*********************************************
This function will only call other functions *
**********************************************/

void call(struct Node* head, int len){
   
   printf("\nThe length of the Linked List: %d", listLength(len));
   printf("\nThe sum of all of the integers in the Linked List: %d", getSum(head));
   printf("\nThe largest number in the Linked List: %d", getMax(head));
   printf("\nThe smallest number in the Linked List: %d", getMin(head));
   getHead(head);
   getMid(head, len);
   getTail(head);
   endProgram(head);
}


/********************************************************
This function will return the length of the Linked List *
*********************************************************/

int listLength(int len){ return len; }

/*******************************************************************************
This function will find and display the sum of all integers of the Linked List *
********************************************************************************/

int getSum(struct Node* head){
   int sum = 0; 
   temp = head;
   
   while(temp != nullptr){
      sum += temp -> data;
      temp = temp -> next;
   }
   return sum;
}

/**************************************************************************
This function will find and display the largest number in the Linked List *
***************************************************************************/

int getMax(struct Node* head){
   
   int max = head -> data;
   temp = head;

   while(temp != nullptr){
      if(temp -> data > max){
         max = temp -> data;
      }
      temp = temp -> next;
   }
   return max;
}

/***************************************************************************
This function will find and display the smallest number in the Linked List *
****************************************************************************/

int getMin(struct Node* head){
   
   int min = head -> data;
   temp = head;

   while(temp != nullptr){
      if(temp -> data < min){
         min = temp -> data;
      }
      temp = temp -> next;
   }
   return min;
}

/*************************************************************
This function will display the first node in the Linked List *
**************************************************************/

void getHead(struct Node* head){
   
   int firstNode = head -> data;
   printf("\nHead node: [%d]", firstNode);
}

/**************************************************************************
This function will find and display the middle node(s) in the Linked List *
***************************************************************************/

void getMid(struct Node* head, int len){
   
   temp = head;
   int mid, midL, midR, i;
   
   if(len == 1){
      cout << "\nThere's no middle node because there's only one node! ";
   }
   else if(len == 2){
      cout << "\nThere's no middle node because there's two nodes! ";
   }
// even number of nodes, two middle nodes
   else if(len % 2 == 0){ 
      for(i = 1; i < (len / 2); i++){
         temp = temp -> next;
      }
      midL = temp -> data;
      midR = temp -> next -> data;
      printf("\nMiddle nodes: [%d] and [%d]", midL, midR); 
   }
// odd number of nodes, one true middle node
   else{ 
      for(i = 1; i <= (len / 2); i++){
         temp = temp -> next;
      }
      mid = temp -> data;
      printf("\nMiddle node: [%d]", mid);
   }
}

/************************************************************
This function will display the last node in the Linked List *
*************************************************************/

void getTail(struct Node* head){
   
   int lastNode = head -> data;
   temp = head;

   if(head -> next == nullptr){
      printf("\nThere is only one node: [%d]", lastNode);
   }
   else{
   // if temp -> next points to nullptr, then it indicates you're on the last node 
      while(temp -> next != nullptr){ 
         temp = temp -> next;
         lastNode = temp -> data;
      }
      printf("\nTail node: [%d]", lastNode);
   }
}

/***************************************************************
This function will delete or free each node in the Linked List *
****************************************************************/

void freeList(struct Node* head){
   while(head != nullptr){
      head = head -> next;
      free(head);
   }
}

/***********************************************************************
This function will clear the input buffer and properly end the program *
************************************************************************/

void endProgram(struct Node* head){
   freeList(head);
   cin.clear();
   exit(1);
}