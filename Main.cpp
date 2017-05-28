#include <iostream>
#include "B.h"
#include "Vector.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

double func(double x)
{
	return x*x;
}

string func2(string x)
{
	return x + "a";
}

void testArrays()
{
	Vector vc(5);
	vc[4] = 3;
	std::cout << " elem 3 is " << vc[4]<<"\n";
	std::cin.get();

	Vector vh(3);
	std::cout << " vh elem 3 is " << vh[2] << "\n";

	//assignment operator
	vh = vc;
	Vector vd = vc;
	std::cout << " vd elem 3 is " << vd[4] << "\n";
	std::cout << " vc elem 3 is " << vc[4] << "\n";
	std::cout << " vh elem 3 is " << vh[4] << "\n";
	std::cin.get();

	//copy constructor
	Vector vl(vc);
	std::cout << " vc elem 3 is " << vc[4] << "\n";
	std::cout << " vl elem 3 is " << vl[4] << "\n";
	std::cin.get();

	std::cout << " capacity " << vl.getCapacity() << "\n";
	vl.append(3);
	std::cout << " vl elem 6 is " << vl[5] << "\n";
	std::cout << " capacity " << vl.getCapacity() << "\n";
	vl.append(2);
	std::cout << " vl elem 7 is " << vl[6] << "\n";
	std::cout << " capacity " << vl.getCapacity() << "\n";
	std::cin.get();

	for (int i = 0; i < vl.getSize(); ++i)
		vl[i] = i;

	Vector newVL = vl.apply(func);

	for (int i = 0; i < newVL.getSize(); ++i)
	{
		std::cout << " elem " << i << " is " << newVL[i];
		std::cin.get();
	}

}



void testLinkedList()
{
	std::string st = "hello";
	Item it;
	it.key = st;
	it.next = NULL;

	LinkedList myList;

	myList.insertItem("a");
	myList.printList();
	myList.insertItem("b");
	myList.insertItem("c");
	myList.insertItem("d");
	//myList.insertItem("e");

	myList.printList();
	Item* mItem=myList.getMidItem();
	cout << " miditem " << mItem->key;
	cin.get();

	Item* nItem = myList.getItem("a");
	cout << "n item: " << nItem->key << "\n";
	cout << "n item next: " << nItem->next->key << "\n";
	cout << "n item next: " << nItem->next->next->key << "\n";
	cin.get();

	Item* head = myList.getHead();
	cout << "head item: " << head->key << "\n";
	cout << "head item next: " << head->next->key << "\n";
	cout << "head item next next: " << head->next->next->key << "\n";
	cout << "head item next next next: " << head->next->next->next->key << "\n";
	cin.get();

	myList.removeItem("c");
	myList.printList();

	myList.insertItem("g");
	myList.insertItem("g");
	myList.insertItem("g");
	myList.insertItem("g");
	myList.insertItem("g");
	myList.insertItem("g");
	myList.printList();

	myList.removeDuplicate();
	myList.printList();


	LinkedList myList2;
	myList2.insertItem("a");
	myList2.insertItem("a");
	myList2.insertItem("g");
	myList2.insertItem("g");
	myList2.insertItem("g");
	myList2.insertItem("g");

	myList2.printList();

	myList2.removeDuplicate();
	myList2.printList();

	string k = "x";
	string m = func2(k);
	std::cout << " str is " << m;
	std::cin.get();


	LinkedList* fList = myList.apply(func2);
	fList->printList();

	

	Item* xItem = fList->getMidItem();
	cout << " miditem " << xItem->key;
	cin.get();
	
	delete fList;
	//fList.printList();

	//LinkedList& newList = myList.apply2(func2);
	//newList.printList();

	myList.insertBegin("z");
	myList.printList();
	
	LinkedList bList(myList);
	cout << "done with copy constructor";
	cin.get();
	bList.printList();

	cout << "assign operator=";
	cin.get();
	bList = myList;
	bList.printList();

	LinkedList cList = myList2;
	cList.printList();

	LinkedList pList = myList.map(func2);
	cout << "apply2 done";
	cin.get();
	pList.printList();
	

}

void testStack()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	st.printData();

	std::cout << "top: " << st.top();
	std::cin.get();

	std::cout << "push 1: " << st.pop();
	st.printData();
	std::cout << "push 2: " << st.pop();
	st.printData();
	std::cout << "push 3: " << st.pop();
	st.printData();
	std::cout << "push 4: " << st.pop();
	st.printData();
	std::cin.get();

	//st.pop();



}

void testQueue()
{
	Queue<double> myQ;

	myQ.add(3);
	myQ.printData();
	myQ.add(4);
	myQ.printData();
	myQ.add(5);
	myQ.printData();
	myQ.add(6);
	myQ.printData();
	myQ.add(7);
	myQ.printData();

	std::cout << "pop " << myQ.pop();
	std::cin.get();

	myQ.printData();
}

void testInheritance()
{
	std::cout << "hey" << 1;
	std::cin.get();

	B ob(3);
	std::cout << "getH " << ob.getH() << "\n";
	std::cout << "getS " << ob.getS() << "\n";
	std::cout << "getF " << ob.getF() << "\n";
	std::cout << "getNumber" << ob.getNumber() << "\n";
	std::cin.get();
	C k(&ob);

}

int main() {
	
	//testArrays();
	//testLinkedList();
	//testStack();
	testQueue();
	return 0;
}