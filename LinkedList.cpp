#include "LinkedList.h"

void LinkedList::append(int data)
{
    Node *tmp = new Node(data); //creates a new temporary node
    if (head == nullptr) //if the head is empty, the head = to the new node with data
    {
        head = tmp;
    }
    else //if the node is not empty, point to the next node and append there
    {
        tail->next = tmp;
    }
    tail = tmp;
}

void LinkedList::prepend(int data)
{
    Node *tmp = new Node(data); //creates a new temporary Node

    if (head == nullptr) //if the head is empty, set the tail to the new node
    {
        tail = tmp;
    }
    tmp->next = head; 
    head = tmp;
}

bool LinkedList::search(int data)
{
    Node *tmp = head; //point to the head

    while(tmp != nullptr) //loop through while the head is empty
    {
        if (tmp->data == data) return true; //if the head = what im looking for .. success
        tmp = tmp->next; //move tmp to the next node

    }
    return false; //if data is not in the list this will trigger
}

bool LinkedList::remove(int data)
{
    Node *tmp = head; //sets the tempory node to the head
    Node *prev = nullptr; //makes the node before the head point to null

    while(tmp != nullptr) //loop while tmp is still in the list
    {
        if(tmp->data == data) //if the is data stored in the head
        {
            if(tmp == head)//check to see if we are deleting the head
            {
                head = tmp->next; //set head to the next node in the chain
            }
            else
            {
                prev->next = tmp->next; //sets the previous node's next to the next node in the chain
            }
            if(tmp == tail) //checks to see if the tail is getting deleted
            {
                tail = prev; //set the tail to the previous node in the chain
            }
            delete tmp; //delete the current node
            return true;
        }
        prev = tmp; //sets the previous node to the current temporary node
        tmp = tmp->next; //move the temporary node to the next node
    }
    return false; 
} 

void LinkedList::display(ostream &os)
{
    Node *tmp = head; //set the current temporary node to the head
    while(tmp != nullptr) // loop while temporary is still in the list
    {
        os << tmp->data << endl; //output the data stored in the current node
        tmp = tmp->next; //move the temporary node to the next node
    }
}

LinkedList::~LinkedList()
    {
        Node *tmp = head; //sets tmp to the head of the list
        while(tmp != nullptr) //while there are nodes in the list, loop
        {
            head = head->next; //move the head to the next node
            delete tmp; //delete the current node saved in tmp
            tmp = head; //set tmp to the new head
        }
        tail = nullptr; //set tail to nullptr

    }

ostream &operator<<(ostream &os, LinkedList &right)
    {
        right.display(os); //calls the display method for the LinkedList
        return os; //returns the updated ostream
    }
