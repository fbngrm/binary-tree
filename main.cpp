/*
 Vorlesung "C++ für Java Programmierer"
 Medieninformatik Bachelor
 Aufgabe 3, Sommersemester 2012
 (C)opyright Hartmut Schirmacher
 http://hschirmacher.beuth-hochschule.de
 */

#include "assert.h"
#include <iostream>
#include <string>
using namespace std;

// include your own header files here...
#include "pair.h"
#include "less.h"
#include "greater.h"
#include "maptofirst.h"
//#include "order.h"
#include "tree.h"
//#include "map.h"

// you should define your own namespace for
// the templates/classes in this project
//using namespace mystl;

// explicit template instantiation for compiling / debugging
template class Pair<int, string> ;
template class Tree<int, Less<int> > ;
//template class Map<int, string>;

// list and count all nodes in a set using an iterator
template<class Container>
int printAndCount(Container & c) {

	int n = 0;
	for (typename Container::iterator i = c.begin(); i != c.end(); ++i, ++n) {
		cout << *i << " ";
		if (n == 20)
			break;
	}

	cout << "(" << n << " elements).";

	return n;
}

// list backwards and count all nodes in a set
template<class Container>
int printAndCountBackwards(Container & c) {
	int n = 0;
	typename Container::iterator i = c.end();
	while (i != c.begin()) {
		--i;
		cout << *i << " ";
		n++;
	}
	cout << endl;
	return n;
}

int main() {

	cout << "Starting..." << endl;

	/////////////////////////////////////////
	// TEST PAIR

	Pair<int, float> i_f(2, 3.14);
	Pair<int, float> i_f2(4, 3.14);
	Pair<string, string> s_s("Hello", "World!");
	cout << i_f << " " << s_s << endl;

	/////////////////////////////////////////
	// TEST ORDER
	Less<int> lessInt;
	cout << "2<3 == " << lessInt(2, 3) << endl;
	cout << "4<3 == " << lessInt(4, 3) << endl;
	Less<string> lessString;
	cout << "Hello<Priwet == " << lessString("Hello", "Priwet") << endl;
	cout << "Servus<Aloha == " << lessString("Servus", "Aloha") << endl;

	Greater<string> greaterString;
	cout << "Hello>Priwet == " << greaterString("Hello", "Priwet") << endl;
	cout << "Servus>Aloha == " << greaterString("Servus", "Aloha") << endl;
	Greater<float> greaterFloat;
	cout << "1.0>0.3 == " << greaterFloat(1.0, 0.3) << endl;
	cout << "3.1>3.2== " << greaterFloat(3.1, 3.2) << endl;
	cout << "3.2>3.2== " << greaterFloat(3.2, 3.2) << endl;

	/////////////////////////////////////////
	// TEST PAIR ORDER
	MapToFirst<int, float, Less> lessPair;
	cout << i_f << " < " << i_f2 << " == " << lessPair(i_f, i_f2) << endl;

	/////////////////////////////////////////
	// TEST TREE

	// construct empty tree
	Tree<int> t;
	cout << "empty tree: ";
	assert(printAndCount(t) == 0);
	cout << endl << endl;

	// insert elements in a certain order
	t.insert(4);
	t.insert(3);
	t.insert(2);
	t.insert(1);
	t.insert(5);
	cout << "tree 4-3-2-1-5: ";
	assert(printAndCount(t) == 5);
	cout << endl << "first: " << *t.first() << endl;
	cout << "last: " << *t.last() << endl;
	cout << endl;

	// test clear()
	t.clear();
	cout << "after clear(): ";
	assert(printAndCount(t) == 0);
	cout << endl;

	// construct empty tree
	Tree<int, Greater<int> > t2;
	cout << "empty tree: ";
	assert(printAndCount(t2) == 0);
	cout << endl;
	// insert elements in a certain order
	t2.insert(4);
	t2.insert(3);
	t2.insert(2);
	t2.insert(1);
	t2.insert(5);
	cout << "tree 4-3-2-1-5: ";
	//t.preOrder();
	assert(printAndCount(t2) == 5);
	cout << endl << "first: " << *t2.first() << endl;
	cout << "last: " << *t2.last() << endl;
	cout << endl;

	// test clear()
	t2.clear();
	cout << "after clear(): ";
	assert(printAndCount(t2) == 0);
	cout << endl;

	// try another insertion order
	t.insert(1);
	t.insert(2);
	t.insert(3);
	t.insert(5);
	t.insert(4);
	cout << "tree 1-2-3-5-4: ";
	assert(printAndCount(t) == 5);
	cout << endl << "first: " << *t.first() << endl;
	cout << "last: " << *t.last() << endl;
	cout << endl;

	// and yet another insertion sequence
	t.clear();
	t.insert(45);
	t.insert(4);
	t.insert(89);
	t.insert(9);
	t.insert(7);
	t.insert(3);
	t.insert(30);
	t.insert(33);
	t.insert(31);
	t.insert(34);
	t.insert(47);
	t.insert(46);
	t.insert(49);
	t.insert(48);
	t.insert(2);
	t.insert(1);
	t.insert(0);
	t.insert(429);
	t.insert(25);
	t.insert(300);
	cout << "20-element tree: ";
	assert(printAndCount(t) == 20);
	cout << endl << "first: " << *t.first() << endl;
	cout << "last: " << *t.last() << endl;
	cout << endl;

	// now we contruct a tree with a "reverse" order
	typedef Tree<float, Greater<float> > RevFloatTree;
	RevFloatTree ft;
	ft.insert(3.1);
	ft.insert(6.2);
	ft.insert(4.3332);
	ft.insert(17.20);
	cout << "reverse-sorted 4-float tree: ";
	assert(printAndCount(ft) == 4);
	cout << endl << "first: " << *ft.first() << endl;
	cout << "last: " << *ft.last() << endl;
	cout << endl;
	// if we list elements backwards, they should be
	//   in the same order as with the function Less<>
	cout << "listing backwards: ";
	assert(printAndCountBackwards(ft) == 4);
#if 0 // move this line down while your implementation proceeds...

	/////////////////////////////////////////
	// TEST MAP

	Pair<int,string> p42(42,"Douglas Adams");
	Pair<int,string> p3(3,"Nummer 3");
	Pair<int,string> p1(1,"Nummer 1");
	Pair<int,string> p7(7,"James Bond");
	string value;

	Map<int,string, MapToFirst<int,string,Less> > m;

	// insert pairs of (key,value)
	m.insert(p42);
	m.insert(p7);
	cout << "map 42-7: ";
	assert(printAndCount(m) == 2);

	// test finding elements via operator()
	cout << "find 42 in map: " << (value=m[42]) << endl;
	assert(value == p42.second());
	cout << "find 3 in map: " << (value=m[3]) << endl;
	assert(value == string());

	// direct write access via operator[]
	cout << "setting m[3] and m[1]." << endl;
	m[1] = p1.second();
	m[3] = p3.second();
	cout << "find 3 in map: " << (value=m[3]) << endl;
	assert(value == p3.second());

	cout << "resulting map: ";
	assert(printAndCount(m) == 4);

	// test first() and last(), min() and max()
	Map<int,string>::iterator first = m.first();
	Map<int,string>::iterator last = m.last();
	cout << "first in map: " << *first << endl;
	cout << "last in map: " << *last << endl;
	assert(first->first() == 1);
	assert(last->first() == 42);
	assert(m.min() == first->first());
	assert(m.max() == last->first());

#endif

	cout << "Success!" << endl;

	return 0;
}

