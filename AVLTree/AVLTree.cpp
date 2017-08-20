// AVLTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "Tree.h"
#include "AVLTree.h"

using namespace std;

int main() {
	Tree aux;
	
	aux.addNode(1);
	cout << aux.exists(1) << endl;
	aux.delMax();
	cout << aux.exists(1) << endl;

	_getch();

	return 0;
}

