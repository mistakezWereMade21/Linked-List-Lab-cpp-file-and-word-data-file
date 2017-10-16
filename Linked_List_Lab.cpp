// Linked_List_Lab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <array>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

using namespace std;

template <class T>
class ListNode
{
public:
	T value;
	ListNode<T> *next;

	ListNode(T nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}
};

template <class T>
class NumberList
{
protected:
	ListNode<T> *head;
	ListNode<T> *tail;
public:
	//Constructor
	NumberList()
	{
		head = nullptr;
		tail = nullptr;
	}
	
	bool isEmpty();
	bool add(T);
	bool remove(T);
	int getFrequencyOf();
	bool contains(T);

	//Destructor
	/*Removes all entries from this list.
	post  List contains no items, and the count of items is 0. */
	~NumberList()
	{
		ListNode<T> *currentNode;
		ListNode<T> *nextNode;

		currentNode = head;

		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;

			delete currentNode;

			currentNode = nextNode;

		}
	}
};

template <class T>
class ListInterface : public NumberList<T>
{
private:
	int itemCount = 0;
public:

	/** Sees whether the list is empty.
	@return True if the list is empty, or false if not. */
	bool isEmpty()
	{
		if (!tail)
		{
			return true;
		}
		return false;
	}

	/**Adds a new entry to the list.
	post  If successful, newEntry is stored in the list and
	the count of items in the list has increased by 1.
	param newEntry The object to be added as a new entry.
	return True if addition was successful, or false if not. */
	bool add(T newEntry)
	{
		ListNode<T> *newNode;
		ListNode<T> *currentNode;
		bool returnStatus = true;

		newNode = new ListNode<T>(newEntry);

		itemCount++;
		if (isEmpty())
		{
			tail = newNode;
			head = tail;
		}
		else
		{
			currentNode = tail;

			while (currentNode->next) 
				currentNode = currentNode->next;

			currentNode->next = newNode;
			head = currentNode->next;
		}
		return returnStatus;
	}

	/*Removes one occurrence of a given entry from this list, if possible.
	post  If successful, anEntry has been removed from the list and the count of
	items in the list has decreased by 1.
	param anEntry  The entry to be removed.
	return  True if removal was successful, or false if not.*/
	bool remove(T anEntry)
	{
		ListNode<T> *currentNode;
		ListNode<T> *prevNode;

		currentNode = tail;
		prevNode = currentNode;
		bool returnStatus = true;

		if (currentNode->value == anEntry)
		{
			currentNode = currentNode->next;
			delete tail;
			tail = currentNode;
		}
		else
		{

			while (currentNode != nullptr && currentNode->value != anEntry)
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode->value == anEntry && head->value == anEntry)
			{
				prevNode->next = currentNode->next;
				//delete currentNode;
				//delete head;
				head = prevNode;

			}
			else if (currentNode->value == anEntry)
			{
				prevNode->next = currentNode->next;
				delete currentNode;
			}
		}
		if (itemCount != 0)
		{
			itemCount--;
		}
		return returnStatus;
	}

	/*Counts the number of times a given entry appears in list.
	param anEntry  The entry to be counted.
	return  The number of times anEntry appears in the list. */
	int getFrequencyOf() const
	{
		return itemCount;
	}

	/*Tests whether this list contains a given entry.
	param anEntry  The entry to locate.
	return  True if list contains anEntry, or false otherwise. */
	bool contains(T anEntry)
	{
		ListNode<T> *currentNode;

		currentNode = tail;


		while (currentNode)
		{
			if (currentNode->value == anEntry)
			{
				return true;
			}
			else
			{
				currentNode = currentNode->next;
			}
		}
		return false;
	}
	//To display the entire linked list
	void displayList()
	{
		itemCount = 0;
		ListNode<T> *currPtr = tail;
		while (currPtr != nullptr)
		{
			
			itemCount++;
			cout << "Node " << "value ";
			cout << "itemCount " << itemCount << "= " << currPtr->value << endl;
			currPtr = currPtr->next;
		}

	}
	};


int main()
{
	ListInterface<string> nodeList;
	string buffer;
	ifstream read_input_file("Words.txt");

	string repeat_response;
	string response;
	string itemName;
	cout << "Building the linked list of strings:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		nodeList.add(buffer);
	}
	exit;
		cout << "Do you want to display the list?" << endl;
		cin >> response;
		if (response == "Yes" || response == "yes")
		{
			nodeList.displayList();
		}
		cout << "Do you want to remove an item?" << endl;
		cin >> response;
		if (response == "Yes" || response == "yes")
		{
			cout << "Enter the item name" << endl;
			cin >> itemName;
			if (nodeList.contains(itemName))
			{
				cout << "Your response " << itemName << " is here.\n";
				cout << "Preparing to remove. Stand by..." << endl;
				nodeList.remove(itemName);
				cout << "Item Count is now " << nodeList.getFrequencyOf() << " nodes." << endl;
				cout << "Press any key and Enter." << endl;
			}
			else
			{
				cout << "ERROR! Your response " << itemName << " is not in the list." << endl;
				cout << "Press any key and Enter." << endl;
			}

		}
		cin >> repeat_response;
	cout << "All done!" << endl;
	system("pause");
	return 0;
}



/*
To make an array have linked lists

DynamicArray<LinkedList<int>> dynamicList

That is a declaration, not a class!!!




*/