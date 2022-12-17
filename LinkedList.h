#include <iostream>
#include <ostream>
using namespace std;

class Node
{
    public:
    int data; 
    Node *next;

    Node(): data(0), next(nullptr) {} //if nothing, point next to null
    Node(int data): data(data), next(nullptr) {} //if integer in parameters, store data and next points to null
    Node(int data, Node *next): data(data), next(next) {}
};
class LinkedList
{
    private:
    Node *head;
    Node *tail;
    public:
    LinkedList(): head(nullptr), tail(nullptr) {} //default .. points the head and tail to null
    ~LinkedList(); 
    
    void append(int data);
    void prepend(int data);
    bool search(int data);
    bool remove(int data);
    void display(ostream &os);
    friend ostream &operator<<(ostream &os, LinkedList &right);

};