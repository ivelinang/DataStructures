#include <iostream>
#include "B.h"
#include "Vector.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Graph.h"
#include "HashTable.h"
#include "HashMap.h"

namespace {

};


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

	myList.printList();

	MyIterator ss = myList.begin();
	cout << "start";
	cout << endl;
	cin.get();

	MyIterator ee = myList.end();
	cout << "end";
	cout << endl;
	cin.get();

	bool compa = ss != ee;
	cout << "compare: " << compa;
	cin.get();



	for (MyIterator iter = myList.begin(); iter != myList.end(); ++iter)
	{
		cout << "element: " << *iter;
		cin.get();
	}
	

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

void testBinaryTree()
{
	BinarySearchTree bTree;
	bTree.include(8);
	bTree.include(4);
	bTree.include(2);
	bTree.include(6);
	bTree.include(5);
	bTree.include(10);
	bTree.include(20);

	/*
			8
		4		10
	2		6		20
		5				
	*/

	std::cout << "done with include";
	std::cin.get();

	bTree.printv2(bTree.getTopNode());
	//bTree.print(bTree.getTopNode());

	std::cout << "is in Tree? " << bTree.contains(1) << "\n";
	std::cout << "is in Tree v2? " << bTree.contains(1) << "\n";
	cin.get();

	std::cout << "pre-order traversal " << "\n";
	bTree.preOrderTraversal(bTree.getTopNode());
	std::cout << "post-order traversal " << "\n";
	bTree.postOrderTraversal(bTree.getTopNode());
	std::cout << "in-order traversal " << "\n";
	bTree.inOrderTraversal(bTree.getTopNode());
	cin.get();

	bTree.include(7);
	bTree.inOrderTraversal(bTree.getTopNode());
	cin.get();

}

void testGraph()
{
	Graph g;
	std::cout << " size " << g.size() << "\n";
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	g.addVertex("D");
	g.addVertex("E");
	g.addVertex("F");
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(0, 5);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(3, 2);
	g.addEdge(2, 1);

	std::set<int> nb = g.neighbours(0);
	for (auto iter = nb.begin(); iter != nb.end(); ++iter)
	{
		int x = *iter;
		std::cout << " neighbours "<< x << "\n";
		//std::cin.get();
	}
	std::cout << " dft " << "\n";
	g.depthFirstTraversal();
	std::cin.get();
	std::cout << " bft " << "\n";
	g.breadthFirstTraversal();
	std::cin.get();
	std::cout << " size " << g.size() << "\n";
	std::cout << "DONE";
	std::cin.get();

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

void testHashTable()
{
	HashTable hMap;
	Item myItem;
	myItem.key = "1";
	myItem.next = NULL;
	hMap.insertItem(&myItem);
	hMap.insertItem("2");
	hMap.insertItem("3");
	hMap.insertItem("4");
	hMap.insertItem("5");
	hMap.insertItem("6");
	hMap.insertItem("7");
	hMap.insertItem("8");
	hMap.printTable();
	std::cin.get();
}

void testHashMap()
{
	HashMap hmap;
	hmap.insertItem(1, "1");
	hmap.insertItem(2, "2");
	hmap.insertItem(3, "3");
	hmap.insertItem(4, "4");
	hmap.insertItem(5, "5");
	hmap.insertItem(6, "7");
	hmap.insertItem(14, "14");

	std::cout << "get 1 -> " << hmap.getItemByKey(1) << "\n";
	std::cout << "get 3 -> " << hmap.getItemByKey(3) << "\n";
	std::cout << "get 6 -> " << hmap.getItemByKey(6) << "\n";
	std::cout << "get 14 -> " << hmap.getItemByKey(14) << "\n";
	//std::cout << "get 13 -> " << hmap.getItemByKey(13) << "\n";

	std::cout << "get 16 -> " << "\n";
	try
	{
		auto v = hmap.getItemByKey(16);
	}
	catch (const std::exception&)
	{
		std::cout << "error get 16 -> " << "\n";
	}
	std::cin.get();
}

void testReferences()
{
	int a = 5;
	int &ref = a;
	ref = 6;
	int b = 7;
	ref = b;
	std::cout << "a is " << a << "\n";
	std::cout << "ref is " << ref << "\n";
	//but cannot reassign ref to point to b
	b++;
	std::cout << "a is " << a << "\n";
	std::cout << "ref is " << ref << "\n";
	//int &ref = b; //error
}

int main() {
	
	//testArrays();
	//testLinkedList();
	//testStack();
	//testQueue();
	testBinaryTree();
	//testGraph();
	//testHashMap();
	
	return 0;
}