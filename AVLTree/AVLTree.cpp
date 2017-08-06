// AVLTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "Tree.h"
#include "AVLTree.h"

using namespace std;

int main () {
	Tree aux;

	aux.addNode (1);
	aux.addNode (2);
	aux.addNode (3);
	aux.addNode (4);
	aux.addNode (5);
	aux.addNode (6);
	aux.addNode (7);
	aux.addNode (8);
	aux.addNode (9);
	aux.addNode (10);
	aux.addNode (1);
	aux.addNode (5);
	aux.addNode (7);
	aux.addNode (9);
	aux.addNode (10);

	cout << aux.toString ();

	_getch ();

	return 0;
}

