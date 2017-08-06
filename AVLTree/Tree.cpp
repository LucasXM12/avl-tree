#include "stdafx.h"
#include "Tree.h"

Tree::Tree () {
	this->root = NULL;
}

Tree::~Tree () {
	if (this->root != NULL)
		delTree (this->root);
}

void Tree::delTree (node* root) {
	if (root->left != NULL)
		delTree (root->left);

	if (root->right != NULL)
		delTree (root->right);

	delete root;
}

string Tree::toString () const {
	if (this->root == NULL)
		return "null";

	return toString (this->root);
}

string Tree::toString (node* root) const {
	string ret;

	if (root->left != NULL)
		ret = "(" + toString (root->left) + ")<-";

	ret += to_string (root->data);

	if (root->right != NULL)
		ret += "->(" + toString (root->right) + ")";

	return ret;
}

Tree::node* Tree::newNode (int data) const {
	node* ret = new node ();

	ret->data = data;
	ret->left = NULL;
	ret->right = NULL;
	ret->height = 1;

	return ret;
}

Tree::node* Tree::minNode (node* root) {
	if (root->left != NULL)
		return minNode (root->left);

	return root;
}

Tree::node* Tree::leftRotate (node* root) {
	node* y = root->right;
	node* T2 = y->left;

	//Update conections:
	y->left = root;
	root->right = T2;

	//Update heights:
	root->height = height_update (root);
	y->height = height_update (y);

	return y;
}

Tree::node* Tree::rightRotate (node* root) {
	node* x = root->left;
	node* T2 = x->right;

	//Update conections:
	x->right = root;
	root->left = T2;

	//Update heights:
	root->height = height_update (root);
	x->height = height_update (x);

	return x;
}

void Tree::addNode (int data) {
	this->root = addNode (this->root, data);
}

Tree::node* Tree::addNode (node* root, int data) {
	//Normal insertion:--------------------------- 
	if (root == NULL)
		return(newNode (data));

	if (data < root->data)
		root->left = addNode (root->left, data);
	else
		root->right = addNode (root->right, data);

	//Update height:---------------------------
	root->height = height_update (root);

	//Get balance factor:---------------------------
	int balance = balance_factor (root);

	//Balance this sub tree:---------------------------
	//LL Case:
	if (balance > 1 && data < root->left->data)
		return rightRotate (root);

	//RR Case:
	if (balance < -1 && data > root->right->data)
		return leftRotate (root);

	//LR Case:
	if (balance > 1 && data > root->left->data) {
		root->left = leftRotate (root->left);

		return rightRotate (root);
	}

	//RL Case:
	if (balance < -1 && data < root->right->data) {
		root->right = rightRotate (root->right);

		return leftRotate (root);
	}

	//If is balanced:
	return root;
}

void Tree::delNode (int data) {
	this->root = delNode (this->root, data);
}

Tree::node* Tree::delNode (node* root, int data) {
	//Normal deletion:---------------------------
	if (root == NULL)
		return root;
	else if (data < root->data) //The node is on the left sub tree:
		root->left = delNode (root->left, data);
	else if (data > root->data) //The node is on the right sub tree:
		root->right = delNode (root->right, data);
	else { //The node is the current one:
		if (root->left == NULL || root->right == NULL) { //One or none children:
			node* aux = root->left ? root->left : root->right;

			//No child:
			if (aux == NULL) {
				aux = root;
				root = NULL;
			} else //One child:
				*root = *aux;

			delete aux;
		} else { //Two children:
			node* aux = minNode (root->right);

			root->data = aux->data;

			root->right = delNode (root->right, aux->data);
		}
	}

	if (root == NULL)
		return NULL;

	//Update height:---------------------------
	root->height = height_update (root);

	//Get balance factor:---------------------------
	int balance = balance_factor (root);

	//Balance this sub tree:---------------------------
	//LL Case:
	if (balance > 1 && balance_factor (root->left) >= 0)
		return rightRotate (root);

	//LR Case:
	if (balance > 1 && balance_factor (root->left) < 0) {
		root->left = leftRotate (root->left);

		return rightRotate (root);
	}

	//RR Case:
	if (balance < -1 && balance_factor (root->right) <= 0)
		return leftRotate (root);

	//RL Case:
	if (balance < -1 && balance_factor (root->right) > 0) {
		root->right = rightRotate (root->right);

		return leftRotate (root);
	}

	//If is balanced:
	return root;
}






