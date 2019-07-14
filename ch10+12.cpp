#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
//Doubly Linked List Program
//5 option program. Add, Delete, show list, reverse order, and Exit
//Nodes have two pointers referencing previous and next nodes
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/1/19

using namespace std;
// define a node for storage and linking
class node {
public:
	string name;
	node *next;//next pointer for linked list
	node *prev; //previous pointer making it a doubly linked list
};

class linkedList {
public:
	linkedList() :top(NULL) {}//starts out empty
	bool empty() { return top == NULL; }//if user enters nothing
	node *getTop() { return top; }
	void setTop(node *n) { top = n; }
	void add(string);//add charaters or names to the list
	int menu();
	void remove(string);//deleting list items.
	~linkedList();
	void reversePrint(); // to print backwards
	friend ostream& operator << (ostream&, const linkedList&); // default output is in-order print.
private:
	node *top;
	node *end; // used for reverse print 
};

int main() {
	linkedList l;
	cout << l.empty() << endl;
	int option = 0;
	string s;
	bool go = true;
	while (go) {
		option = l.menu();
		switch (option) {
		case 1: cout << "enter a name: "; cin >> s; l.add(s); break;
		case 2: cout << "enter name to be deleted: "; cin >> s; l.remove(s); break;
		case 3: cout << l; break;
		case 4: l.reversePrint(); break; //print in reverse
		case 5: cout << "exiting" << endl; go = false; break;//exit program
		}
	}
	// l goes out of scope and calls ~linkedList()
}

void linkedList::remove(string s) {
	bool found = false;
	node *curr = getTop(), *prev = NULL;//current
	while (curr != NULL) {

		// match found, delete
		if (curr->name == s) {
			found = true;

			// found at top
			if (prev == NULL) {
				node *temp = getTop();
				
				curr = curr->next;
				curr->prev = NULL; //set prev link of the new head to NULL
				if (temp == end)
					end = NULL;//set end to NULL if top and end are the same				

				setTop(curr);
				delete(temp);

				// found in list - not top
			}
			else {
				prev->next = curr->next;

				node *temp = curr->next;
				if (temp != NULL)
					temp->prev = prev;
				else
					end = prev; //set end to the previous node if removing the last node
			
				delete(curr);
			}
		}

		// not found, advance pointers
		if (!found) {
			prev = curr;
			curr = curr->next;
		}

		// found, exit loop
		else curr = NULL;
	}
	if (found)cout << "Deleted " << s << endl;
	else cout << s << " Not Found " << endl;
}

void linkedList::add(string s) {
	node *n = new node();
	n->name = s;
	n->next = NULL;
	n->prev = NULL; //new node's prev link starts as null

	// take care of empty list case
	if (empty()) {
		top = n;
		end = n; //if adding to empty list, top and end are the same

	// take care of node belongs at beginning case
	}
	else if (getTop()->name > s) {
		n->next = getTop();
		getTop()->prev = n; //if adding to the top, set previous top's previous link to the new node
		setTop(n);

		// take care of inorder and end insert
	}
	else {

		// insert in order case
		node *curr = getTop(), *prev = curr;
		while (curr != NULL) {
			if (curr->name > s)break;
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL) { // search found insert point
			n->next = curr;
			prev->next = n;
			n->prev = prev; //link up the previous nodes
			curr->prev = n; 
		}

		// take care of end of list insertion
		else if (curr == NULL) {// search did not find insert point
			prev->next = n;
			n->prev = prev;
			end = n;
		}
	}
}

ostream& operator << (ostream& os, const linkedList& ll) {
	//linkedList x = ll; // put this in and the code blows up - why?
	node *n = ll.top;
	if (n == NULL)cout << "List is empty." << endl;
	else
		while (n != NULL) {
			os << n->name << endl;
			n = n->next;
		}
	return os;
}

// return memory to heap
linkedList::~linkedList() {
	cout << "~linkedList called." << endl;
	node *curr = getTop(), *del;
	while (curr != NULL) {
		del = curr;
		curr = curr->next;
		delete(del);
	}
}

int linkedList::menu() {
	int choice = 0;
	while (choice < 1 || choice > 5) {
		cout << "\nEnter your choice" << endl;
		cout << " 1. Add a name." << endl;
		cout << " 2. Delete a name." << endl;
		cout << " 3. Show list." << endl;
		cout << " 4. Show reverse list. " << endl; // to be implemented by students
		cout << " 5. EXIT " << endl;
		cin >> choice;
	}
	return choice;
}

void linkedList::reversePrint() {
	//start at the end of the list
	node *n = end;

	if (n == NULL)
		cout << "List is empty." << endl; //list is empty if end is null
	else {
		while (n != NULL) {
			//print the list from end to top
			cout << n->name << endl;
			n = n->prev;
		} //end while
	} //end else
} //end reversePrint()