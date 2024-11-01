#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class ForwardList
{
    Node* head;

public:
    ForwardList() : head(nullptr) {}

    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAfterValue(int prevValue, int value)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == prevValue)
            {
                Node* newNode = new Node(value);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Value " << prevValue << " not found in the list." << endl;
    }

    void clear()
    {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void printList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~ForwardList()
    {
        clear();
    }
};

int main()
{
    ForwardList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    cout << "List after sort at beginning: ";
    list.printList();
    list.insertAfterValue(20, 25);
    cout << "List after sort 25 after the node with value 20: ";
    list.printList();
    list.clear();
    cout << "List after clearing: ";
    list.printList();
}