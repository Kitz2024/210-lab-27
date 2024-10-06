// Kit Pollinger
//  210 - Lab - 18 | Movie Review

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    double ratings;
    string comments;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void addNodeToTail(double ratings, string comments)
{
}

int main()
{
    int userChoice;
    double ratings;
    string comments;
    char anotherReview;

    cout << "Which linked list method should we use?";
    cout << "[1] New nodes are added at the head of the linked list\n";
    cout << "[2] New nodes are added at the tail of the linked list\n";
    cin >> userChoice;

    return 0;
}