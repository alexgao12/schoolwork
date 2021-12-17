#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string payload;
    Node* next;
};

Node* newNode(string payload) {
    Node* nn = new Node();
    nn->payload = payload;
    nn->next = nullptr;
    return nn;
}

Node* loadGame(int n, vector<string> names) {
    Node* head = nullptr;
    Node* prev = nullptr;
    string name;

    for (int i = 0; i < n; ++i) {
        name = names.at(i);
        if (head == nullptr) {
            head = newNode(name); 
            prev = head;
        } else {
            prev->next = newNode(name);
            prev = prev->next;
        }
    }

    if (prev != nullptr) {
        prev->next = head;
    }
    return head;
}

void print(Node* start) { // prints list
    Node* curr = start;
    while (curr != nullptr) {
        cout << curr->payload << endl;
        curr = curr->next;
        if (curr == start) {
            break; // exit circular list
        }
    }
}

Node* runGame(Node* start, int k) { // josephus w circular list, k = num skips
    Node* curr = start;
    Node* prev = curr;
    //Node* tempNode = start;
    while (curr->next != curr) { // exit condition, last person standing
        for (int i = 0; i < k; ++i) { // find kth node
          if(i != 0){
            prev = prev->next;
          }
          curr = curr->next;
        }
        //cout << prev->payload << endl;
        /** fill in this code **/ // delete kth node
        prev->next = curr->next;
        //cout << curr->payload << " is being deleted" << endl;
        
        delete curr;
        prev = prev->next;
        curr = prev;
        cout << prev->payload << endl;
        // tempNode = tempNode->next;
        // prev = tempNode;
        // curr = tempNode;
        
        /** fill in this code **/
    }

    return curr; // last person standing
}

/* Driver program to test above functions */
int main() {
    int n=1, k=1, max; // n = num names; k = num skips (minus 1)
    string name;
    vector<string> names;

    // get inputs
    cin >> n >> k;
    while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input

    // initialize and run game
    Node* startPerson = loadGame(n, names);
    Node* lastPerson = runGame(startPerson, k);

    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    } else {
        cout << "error: null game" << endl;
    }
    return 0;
}

