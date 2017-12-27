#include <string>
#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

class node {
public:
	student s;
	node * next;
};
node * head;

void remove() {
	if (head != 0) {
		int id;
		cout << "id:"; cin >> id;
		node * temp;
		node * prev;
		if (head->s.getid() == id) {
			temp = head;
			head = head->next;
			delete temp;
		}
		else {
			prev = head;
			while (prev->next != 0) {
				if (prev->next->s.getid() == id)
				{
					temp = prev->next;
					prev->next = prev->next->next;
					delete temp;
				}
				else
					prev = prev->next;
			}
		}
	}
}

void deleteall() {

	node * temp = head;
	node *temp2;
	while (temp!= 0)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head = 0;

}

void getmark() {
	string name;
	int sum = 0;
	node * temp = head;
	cout << "Enter name:";
	cin >> name;
	if (head == 0) 
		cout << "List is empty";
	else {
		while (temp != 0) {
			if (temp->s.getname() == name) {
				sum += temp->s.getmark1();
				sum += temp->s.getmark2();
				sum += temp->s.getmark3();
				cout << "Total mark: " << sum << endl;
			}
			temp = temp->next;
		}
	
	}
	
}

void insert(){
	node * newrec;
	newrec = new node;
	int temp;
	string name;
	cout << "id:";
	cin >> temp;
	newrec->s.setid(temp);

	cout << "name: ";
	cin >> name;
	newrec-> s.setname(name);

	cout << "Mark1: ";
	cin >> temp;
	newrec->s.setmark1(temp);

	cout << "Mark2: ";
	cin >> temp;
	newrec->s.setmark2(temp);

	cout << "Mark3: ";
	cin >> temp;
	newrec->s.setmark3(temp);


	newrec->next = 0;

	if (head == 0) head = newrec;

	else {
		node * temp;
		temp = head;
		while (temp->next != 0) temp = temp->next;
		temp->next = newrec;
	}
}

void print(){
	node *temp;
	temp = head;
	while (temp != 0) {
		cout << "Name:" << temp->s.getname() << "\n";
		cout << "ID:" << temp->s.getid() << "\n";
		cout << "Mark1: " << temp->s.getmark1() << "\n";
		cout << "Mark2: " << temp->s.getmark2() << "\n";
		cout << "Mark3: " << temp->s.getmark3() << "\n";
		temp = temp->next;
	}
}



void sort(){
	string tempname;
	int tempid;
	int tempmark1;
	int tempmark2;
	int tempmark3;
	node * temphead = head;
	int counter = 0;
	while (temphead != 0)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;
	for (int i = 0; i<counter; i++)
	{
		while (temphead->next != 0)
		{
			if (temphead->s.getid() > temphead->next->s.getid())
			{
				tempid = temphead->s.getid();
				temphead->s.setid(temphead->next->s.getid());
				temphead->next->s.setid(tempid);

				tempname = temphead->s.getname();
				temphead->s.setname(temphead->next->s.getname());
				temphead->next->s.setname(tempname);

				tempmark1 = temphead->s.getmark1();
				temphead->s.setmark1(temphead->next->s.getmark1());
				temphead->next->s.setmark1(tempmark1);

				tempmark2 = temphead->s.getmark2();
				temphead->s.setmark2(temphead->next->s.getmark2());
				temphead->next->s.setmark2(tempmark2);

				tempmark3 = temphead->s.getmark3();
				temphead->s.setmark3(temphead->next->s.getmark3());
				temphead->next->s.setmark3(tempmark3);
				temphead = temphead->next;
			}
			else
				temphead = temphead->next;
		}
		temphead = head;
	}
}


void main() {
	head = 0;
	int input = 0;
	while (input != 7) {
		cout << endl;
		cout << "1-Add a student" << endl;
		cout << "2-Sort all students" << endl;
		cout << "3-List all student" << endl;
		cout << "4-Get total mark for a student" << endl;
		cout << "5-Delete a student" << endl;
		cout << "6-Delete whole record" << endl;
		cout << "7-Exit" << endl << endl;
		
		cin >> input;
			switch (input) {
			case 1: insert(); break;
			case 2: sort(); break;
			case 3: print(); break;
			case 4: getmark(); break;
			case 5: remove(); break;
			case 6:deleteall();
			}
	}

}