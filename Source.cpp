#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <regex>
#include <math.h>

using namespace std;

template <typename T>
class node {
public:
    T nodeValue;//data held by the node
    node<T>* next;//next node in the list

    //default constructor
    node() {
        next = nullptr;
    }

    //constructor with default parameter
    node(T item, node<T>* nextNode = nullptr) {
        nodeValue = item;
        next = nextNode;
    }
};

template <typename T>
void pushBackList(node<T>*& front, const T& item) {

    if (front == NULL) {

        front = new node<T>;
        front->nodeValue = item;
        front->next = NULL;
    }
    else {

        node<T>* newNode, * curr = front;

        while (curr->next != NULL)
            curr = curr->next;

        newNode = new node<T>;

        newNode->nodeValue = item;
        newNode->next = NULL;
        curr->next = newNode;
    }
}

template <typename T>
void writeList(node<T>* front) {

    cout << "The linked list representation of given polynomial: \n";

    while (front != NULL) {

        cout << front->nodeValue << " -->";
        front = front->next;
    }
    cout << "NULL";

}

int main()
{
    node<string>* front = NULL, * ptr, * ptr2;
    

    string str = "" ,bruh;
    cout << "Please enter a polinomial: ";
    cin >> str;
    string const delims{ "-+" };

    size_t beg, pos = 0;
    size_t found=0;
    string operand = "";
    while ((beg = str.find_first_not_of(delims, pos)) != string::npos)
    {
        string node = "";
        pos = str.find_first_of(delims, beg + 1);
        bruh = str.substr(beg, pos - beg);
        
        found = bruh.find('X');
        if (found != std::string::npos) {
            node.push_back(bruh[0]);
            node.push_back(bruh[1]);
            found = bruh.find('^');
            if (found != std::string::npos) {
                node.push_back(bruh[3]);
            }
            else
                node.push_back('1');
        }
        else
        {
            node.push_back(bruh[0]);
            node.push_back('X');
            node.push_back('0');
        }
      
            if (*(str.begin() + pos) == '-') {
                node.insert(0, "-");
            }

        pushBackList(front, node);
    }
    writeList(front);
    
    int opt = 0 ,i=0;
    double plynode, sum = 0,x;

    cout << "Select an operation:\n";
    cout << "1. Calculate polynomial value\n";
    cout << "2. Calculate integral\n";
    cout << "3. Exit\n";

    cin >> opt;

            if (opt == 1) {
                ptr = front;
                cout << "please enter x for your polynome";
                cin >> x;
                while (ptr->next != NULL) {

                        plynode = ptr->nodeValue[0] * pow(x, ptr->nodeValue[2]);
                        ptr = ptr->next;
                        sum= sum + plynode + (ptr->nodeValue[0] * pow(x, ptr->nodeValue[2]));
                        if (ptr->next != NULL)
                            ptr = ptr->next;
                        else
                            break;
         
                }
                cout << sum;
            }

                 if (opt == 2) {



                 }

                        if (opt == 3) {



                        }
        








    return 0;
}