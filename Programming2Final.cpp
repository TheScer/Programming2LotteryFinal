#include <iostream>
#include <string>
#include<exception>
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

	void CreateList(Node first,Node*& head, Node*& tail, int number)
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

	void DrawnPicks(Node*& head, int picks[6])
	{
		int travel;
		Node* final = head;
		Node* temp = head;

		//outer for loop so that it picks the 6 values for the drawn picks
		for (int a = 0; a < 6; a++) {

			travel = (rand() % 100) + 1; //randomizes the travel distance

			cout << travel << endl; //testing what it gives for travel

			//if the travel number is even traverses the list forwards
			if (travel % 2 == 0) {
				for (int z = 0; z < travel; z++) {
					temp->next;
					temp = temp->next;
				}
				final = temp; //makes final pointer = temp pointer
				final->number; //looks at final pointer -> number to store later
				cout << "final->number when travel is even" << endl;//testing to see what values we're getting
				cout << final->number << endl; //testing to see what values we're getting
			}
			//if the travel number is odd it traverses the list backwards
			else if (travel % 2 == 1) {
				for (int z = 0; z < travel; z++) {
					temp->prev;
					temp = temp->prev;

				}
				final = temp;
				final->number;
				cout << "final->number when travel is odd" << endl;//testing to see what values we're getting
				cout << final->number << endl; //testing to see what values we're getting
			}
			picks[a] = final->number;
			cout << "this is picks " << a << endl;//testing to see what values we're getting
			cout << picks[a] << endl;//testing to see what values we're getting
		}
	}
};

int main() {

	Node HEAD;
	Node* head = &HEAD;
	Node* tail = NULL;
	int number;
	number = 1;
	int temp;
	int draws[6];


	HEAD.CreateList(HEAD, head, tail, number);
	HEAD.DrawnPicks(head, draws);

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
				MyNums[x] = temp;
				cout << endl << endl;
			}
			else if (temp == MyNums[0]) {
				throw "You've already entered that number. Enter another number between 1-40";
			}
			else if (temp < 1 || temp>40) {
				throw "Your number was INVALID, enter another number between 1-40";
			}
		}
		catch (char const* e) {
			cout << e << endl;
		};
	};

	for (int b = 0; b < 6; b++) {
		cout << "draw "<< b <<" :";
		cout << *draws << endl;
	}


	return 0;
};

//example pointer
//int* p declares p as a pointer to an integer
//int x
//int* p = &x inserts the address of x into p
// cout<<p<< gives the address
//cout<<*p<< gives the value stored at the address (value that x holds)