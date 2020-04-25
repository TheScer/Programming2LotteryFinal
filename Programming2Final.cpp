#include <iostream>
#include <string>
#include<exception>
#include<time.h>
#include<cstdlib>
using namespace std;

class Node
{
private:
	int number;


public:
	Node* next;
	Node* prev;

	bool isEmpty(Node* head)
	{
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	};

	void CreateList(Node first, Node*& head, Node*& tail, int number)
	{
		Node* temp = &first;
		temp->number = number;
		temp->next = NULL;
		head = temp;
		tail = temp;

		for (int x = 1; x < 40; x++)
		{
			temp = new Node; //creates a new node and puts the address into temp
			temp->number = (x + 1); //assigns the data of the node at address temp to 2
			temp->prev = tail; //assigns the tail address(previous node address) to prev of 2nd node
			tail->next = temp; //NOW that we have 2 values, the tail is set to temp which has the address of the 2nd node
			//which links the first node to the 2nd node

			tail = temp;//sets the tail to the address of the 2nd node

			cout << "testing, this is number " << x << " of the linked list" << endl;
			cout << temp->number << endl;
		}

		//sets the previous value of the head to the tail 
		head->prev = tail;

		//to make the list circular, 
		tail->next = head;
		//now, the tails next value points to the first node or "head"

	};

	int DrawnPicks(Node*& head, int travel)
	{
		Node* final = head;
		Node* temp = head;
		int TempNum = 0;

		//if the travel number is even traverses the list forwards
		if (travel % 2 == 0) {
			for (int z = 0; z < travel; z++) {
				temp->next;
				temp = temp->next;
			}
			cout << "final->number when travel is even" << endl;//testing to see what values we're getting
		}
		//if the travel number is odd it traverses the list backwards
		else if (travel % 2 == 1) {
			for (int z = 0; z < travel; z++) {
				temp->prev;
				temp = temp->prev;
			}
			cout << "final->number when travel is odd" << endl;//testing to see what values we're getting
		}

		final = temp; //makes final pointer = temp pointer
		final->number; //looks at final pointer -> number to store later
		TempNum = final->number;
		cout << " when travel: "<<travel << endl;//testing to see what values we're getting
		cout << final->number << endl; //testing to see what values we're getting

		head = temp; //resetting the head to the temp value so it traverses from that node

		final->next->prev = final->prev; //change the prev of the next node to the the prev of current node
		final->prev->next = final->next; //change the next of the previous node to the next of the previous node

		//now that  we changed the pointers of the next and previous node,
		//the current node still points to the next and prev, but has been removed from the list

		//delete final; 
		//CANNOT delete the node if I want to start from it next time
		//this will cause some memory leakage but in this project not much of a problem

		return TempNum;
	}
};

int main() {

	Node HEAD;
	Node* head = &HEAD;
	Node* tail = NULL;
	int number;
	number = 1;
	int temp;
	int draws[6] = {0,0,0,0,0,0 }; //initialize the drawn picks array
	srand(time(0)); //randomizes the seed for the rand function so its more random

	HEAD.CreateList(HEAD, head, tail, number);

	for (int a = 0; a < 6; a++) {
		int travel = 0;
		travel = (rand() % 100) + 1; //randomizes the travel distance
		//cout << "travel this amount: " << travel << endl; //more testing to see what travel
		draws[a] = HEAD.DrawnPicks(head, travel);
	}

	//num = (rand() % 40) + 1;
	//this will return a random number between 1 and 40

	static string NumWords[6] = { "first", "second", "third", "fourth", "fifth", "sixth" };
	int MyNums[6] = {};

	cout << "Hello, and welcome to the L-O-T-T-E-R-Y Game. You will be asked to enter 6 different numbers";
	cout << "between the range of 1 - 40. Remember, each number can only be picked once.GOOD LUCK.";
	cout << endl;

	for (int x = 0; x < 6; x++) {
		cout << "please enter your " << NumWords[x] << " number between 1 and 40: ";
		cin >> temp;

		try {
			if (temp < 41 && temp>0) {

				for (int y = 0; y < x; y++) {
					if (temp == MyNums[y]) {
						throw "You've already entered that number. Enter another number between 1-40";
					}
				}
				MyNums[x] = temp;
				cout << endl << endl;
			}
			else if (temp < 1 || temp>40) {
				throw "Your number was INVALID, enter another number between 1-40";
			}
		}
		catch (char const* e) {
			x--; //puts x back to the previous value in the for loop so you can redo your input
			cout << e << endl; //couts whatever error you got
		};
	};

	//displays all the human picks
	for (int b = 0; b < 6; b++) {
		cout << "human picks " << (b + 1) << " :";
		cout << MyNums[b] << endl;
	}

	//displays all the computer draws
	for (int b = 0; b < 6; b++) {
		cout << "computer draw " << (b + 1) << " :";
		cout << draws[b] << endl;
	}
	return 0;
};

//example pointer
//int* p declares p as a pointer to an integer
//int x
//int* p = &x inserts the address of x into p
// cout<<p<< gives the address
//cout<<*p<< gives the value stored at the address (value that x holds)