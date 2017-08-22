// AVLTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "Tree.h"
#include "AVLTree.h"

using namespace std;

int main() {
	Tree<Tree<int>> aux; 

	Tree<int> aux1;

	for (int i = 0; i < 5; i++) 
		aux1.addNode(i, 10);
	
	for (int i = 0; i < 5; i++)
		aux.addNode(i, aux1);
	
	cout << aux1;

	_getch();

	return 0;
}

