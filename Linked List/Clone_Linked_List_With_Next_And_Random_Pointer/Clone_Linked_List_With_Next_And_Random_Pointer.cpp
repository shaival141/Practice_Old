/**
 * Create the copy of node 1 and insert it between node 1 & node 2 in original Linked List, create the copy of 2 and insert it between 2 & 3. 
 * Continue in this fashion, add the copy of N afte the Nth node
 * 
 * Now copy the random link in this fashion original->next->random= original->random->next;  //TRAVERSE TWO NODES.
 * This works because original->next is nothing but copy of original and Original->random->next is nothing but copy of random.
 * 
 * Now restore the original and copy linked lists in this fashion in a single loop,
 * original->next = original->next->next; copy->next = copy->next->next; 
 * 
 * Ensure that original->next is NULL and return the cloned list
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

Node *clone(Node *head)
{
    Node *curr = head;
    Node *temp;
    while (curr)
    {
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;
    while (curr)
    {
        curr->next->random = curr->random->next;
        curr = curr->next ? curr->next->next : curr->next;
    }
    Node *orig = head;
    Node *copy = head->next;
    temp = copy;
    while (orig && copy)
    {
        orig->next = orig->next ? orig->next->next : orig->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        orig=orig->next;
        copy=copy->next;
    }
    return temp;
}

int main()
{
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;
    // 2's random points to 1
    start->next->random = start;
    // 3's and 4's random points to 5
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;
    // 5's random points to 2
    start->next->next->next->next->random = start->next;

    cout << "Original list : \n";
    print(start);
    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);
    return 0;
}