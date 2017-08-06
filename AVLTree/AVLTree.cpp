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

	aux.addNode (9);
	aux.addNode (5);
	aux.addNode (10);
	aux.addNode (0);
	aux.addNode (6);
	aux.addNode (11);
	aux.addNode (-1);
	aux.addNode (1);
	aux.addNode (2);

	aux.delNode (10);

	cout << aux.toString ();

	cout << "\n" << aux.minNode () << " " << aux.maxNode () << " " << aux.exists (7);

	_getch ();

	return 0;
}

