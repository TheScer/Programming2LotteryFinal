#include <iostream>
#include <string>
#include<exception>
using namespace std;

class Node
{
private:
	int number;
	

public:
	//apparently the pointers have to be public which I probably wasted like 5 hours on
	Node* next;
	Node* prev;

	//default constructor
	Node() {
		number = 1;
		next = NULL;
		prev = NULL;
	}

	//constructor
	Node(Node*& head, Node*& tail, int num){
		number = 1;
		next = NULL;
		prev = NULL;
	}

	//accessor functions
	int AccessNumber(Node* pointer) {
		return pointer->number;
	}

	Node* StartListHead(Node*& head, int number) {
		Node* temp = new Node;
		temp->number = number;
		temp->next = NULL;
		head = temp;
		
		return head;
	}

	Node* StartListTail(Node*& head, int number = 1) {
		//Node* temp = new Node;
		//temp->number = number;
		//temp->next = NULL;
		Node* tail = head;

		return tail;
	}

	Node* CreateList(Node*& head, Node*& tail, int number)
	{
		Node* temp = head;
		temp->number = number;
		temp->next = NULL;
		head = temp;
		tail = temp;

		for (int x = 1; x < 40; x++)
		{
			temp = new Node; //creates a new node and puts the address into temp
			temp->number = (x+1); //assigns the data of the node at address temp to 2
			temp->prev = tail; //assigns the tail address(previous node address) to prev of 2nd node
			tail->next = temp; //NOW that we have 2 values, the tail is set to temp which has the address of the 2nd node
			//which links the first node to the 2nd node

			tail = temp;//sets the tail to the address of the 2nd node

			cout << "testing, this is number " << x << " of the linked list" << endl;
			cout << temp->number<<endl;
		}

		//sets the previous value of the head to the tail 
		head->prev = tail; 

		//to make the list circular, 
		tail->next = head;
		//now, the tails next value points to the first node or "head"

		return head;
	};

	int* DrawnPicks(Node*& head)
	{
		int travel;
		int tempNum = 0;
		Node* final = head;
		Node* temp = head;
		int picks[6];

		//outer for loop so that it picks the 6 values for the drawn picks
		for (int a = 0; a < 6;a++) {

			travel = (rand() % 100) + 1; //randomizes the travel distance


			//if the travel number is even traverses the list forwards
			if (travel % 2 == 0) {
				for (int z = 0; z < travel; z++) {
					temp->next;
					temp = next;
				}
				final = temp; //makes final pointer = temp pointer
				tempNum = final->number; //looks at final pointer -> number to store later
			}
			//if the travel number is odd it traverses the list backwards
			else if (travel % 2 == 1) {
				for (int z = 0; z < travel; z++) {
					temp->prev;
					temp = prev;

				}
				final = temp;
				tempNum = final->number;
				cout << "final->numbers when odd" << endl;//testing to see what values we're getting
				cout<< tempNum<<endl; //testing to see what values we're getting
			}
			picks[a] = tempNum;
			cout << "this is picks " << a << endl;//testing to see what values we're getting
			cout << picks[a]<<endl;//testing to see what values we're getting
		}
		return picks;
	}
};

int main() {

	Node HEAD;

	Node* head = &HEAD;
	Node* tail = &HEAD;

	int number;
	number = 1;
	int temp;
	int* draws;

	head= HEAD.CreateList(head, tail, number);

	//head = HEAD.StartListHead(head, number);
	//tail = Test.StartListTail(head, number);

	//HEAD.CreateList(head, tail, number);
	draws = HEAD.DrawnPicks(head);


	//num = (rand() % 40) + 1;
	//this will return a random number between 1 and 40

	static string NumWords[6]= {"first", "second", "third", "fourth", "fifth", "sixth"};
	int MyNums[6] = {};

	cout << "Hello, and welcome to the L-O-T-T-E-R-Y Game. You will be asked to enter 6 different numbers";
	cout << "between the range of 1 - 40. Remember, each number can only be picked once.GOOD LUCK.";
	cout << endl;

	for (int x = 0; x < 6; x++) {
		cout << "please enter your "<< NumWords[x]<< " number between 1 and 40: ";
		cin >> temp;

		try{
			if (temp<41 && temp>0) {
				MyNums[x]=temp;
				cout << endl << endl;
			}
			else if (temp == MyNums[0]) {
				throw "You've already entered that number. Enter another number between 1-40";
			}
			else if(temp<1 || temp>40) {
				throw "Your number was INVALID, enter another number between 1-40";
			}
		}
		catch (char const* e) {
			cout << e << endl;
		};
	};

	for (int b = 0; b < 6;b++) {
		cout << "*(draws + " << b << ") : ";
		cout << *(draws + b) << endl;
	}
	

	return 0;
};

//example pointer
//int* p declares p as a pointer to an integer
//int x
//int* p = &x inserts the address of x into p
// cout<<p<< gives the address
//cout<<*p<< gives the value stored at the address (value that x holds)
