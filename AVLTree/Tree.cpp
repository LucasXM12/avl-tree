#include "stdafx.h"
#include "Tree.h"

#include <stdexcept>

template<typename dataType> Tree<dataType>::Tree() {
	this->root = NULL;
}

template<typename dataType> Tree<dataType>::~Tree() {
	if (this->root)
		delTree(this->root);
}

template<typename dataType> void Tree<dataType>::delTree(node* root) {
	if (root->left)
		delTree(root->left);

	if (root->right)
		delTree(root->right);

	delete root;
}

template<typename dataType> string Tree<dataType>::toString() const {
	if (!this->root)
		return "null";

	return toString(this->root);
}

template<typename dataType> string Tree<dataType>::toString(const node* root) const {
	string ret;

	if (root->left)
		ret = "(" + toString(root->left) + ")<-";

	ret += to_string(root->key);

	if (root->right)
		ret += "->(" + toString(root->right) + ")";

	return ret;
}

template<typename dataType> node* Tree<dataType>::newNode(const int& key) const {
	node* ret = new node();

	ret->key = key;
	ret->height = 1;
	ret->left = NULL;
	ret->right = NULL;

	return ret;
}

template<typename dataType> int Tree<dataType>::minNode() const {
	if (!this->root)
		throw exception("Empty tree");

	return minNode(this->root)->key;
}

template<typename dataType> node* Tree<dataType>::minNode(node* root) const {
	if (root->left)
		return minNode(root->left);

	return root;
}

template<typename dataType> int Tree<dataType>::maxNode() const {
	if (!this->root)
		throw exception("Empty tree");

	return maxNode(this->root)->key;
}

template<typename dataType> node* Tree<dataType>::maxNode(node* root) const {
	if (root->right != NULL)
		return maxNode(root->right);

	return root;
}

template<typename dataType> bool Tree<dataType>::exists(const int& key) const {
	if (!this->root)
		return false;

	return exists(key, this->root);
}

template<typename dataType> bool Tree<dataType>::exists(const int& key, const node* root) const {
	if (key == root->key)
		return true;
	else if (key < root->key)
		return root->left ? exists(key, root->left) : false;
	else
		return root->right ? exists(key, root->right) : false;
}

template<typename dataType> node* Tree<dataType>::leftRotate(node* root) {
	node* y = root->right;
	node* T2 = y->left;

	//Update conections:
	y->left = root;
	root->right = T2;

	//Update heights:
	root->height = height_update(root);
	y->height = height_update(y);

	return y;
}

template<typename dataType> node* Tree<dataType>::rightRotate(node* root) {
	node* x = root->left;
	node* T2 = x->right;

	//Update conections:
	x->right = root;
	root->left = T2;

	//Update heights:
	root->height = height_update(root);
	x->height = height_update(x);

	return x;
}

template<typename dataType> void Tree<dataType>::addNode(const int& key) {
	this->root = addNode(this->root, key);
}

template<typename dataType> node* Tree<dataType>::addNode(node* root, const int& key) {
	//Normal insertion:--------------------------- 
	if (root == NULL)
		return(newNode(key));

	if (key < root->key)
		root->left = addNode(root->left, key);
	else if (key > root->key)
		root->right = addNode(root->right, key);

	//Update height:---------------------------
	root->height = height_update(root);

	//Get balance factor:---------------------------
	int balance = balance_factor(root);

	//Balance this sub tree:---------------------------
	//LL Case:
	if (balance > 1 && key < root->left->key)
		return rightRotate(root);

	//RR Case:
	if (balance < -1 && key > root->right->key)
		return leftRotate(root);

	//LR Case:
	if (balance > 1 && key > root->left->key) {
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	//RL Case:
	if (balance < -1 && key < root->right->key) {
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	//If is balanced:
	return root;
}

template<typename dataType> void Tree<dataType>::delNode(const int& key) {
	this->root = delNode(this->root, key);
}

template<typename dataType> node* Tree<dataType>::delNode(node* root, const int& key) {
	//Normal deletion:---------------------------
	if (!root)
		return root;
	else if (key < root->key) //The node is on the left sub tree:
		root->left = delNode(root->left, key);
	else if (key > root->key) //The node is on the right sub tree:
		root->right = delNode(root->right, key);
	else { //The node is the current one:
		if (!root->left || !root->right) { //One or none children:
			node* aux = root->left ? root->left : root->right;

			//No child:
			if (!aux) {
				aux = root;
				root = NULL;
			}
			else //One child:
				*root = *aux;

			delete aux;
		}
		else { //Two children:
			node* aux = minNode(root->right);

			root->key = aux->key;

			root->right = delNode(root->right, aux->key);
		}
	}

	if (!root)
		return NULL;

	//Update height:---------------------------
	root->height = height_update(root);

	//Get balance factor:---------------------------
	int balance = balance_factor(root);

	//Balance this sub tree:---------------------------
	//LL Case:
	if (balance > 1 && balance_factor(root->left) >= 0)
		return rightRotate(root);

	//LR Case:
	if (balance > 1 && balance_factor(root->left) < 0) {
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	//RR Case:
	if (balance < -1 && balance_factor(root->right) <= 0)
		return leftRotate(root);

	//RL Case:
	if (balance < -1 && balance_factor(root->right) > 0) {
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	//If is balanced:
	return root;
}

template<typename dataType> void Tree<dataType>::delMin() {
	this->root = delNode(this->root, minNode());
}

template<typename dataType> void Tree<dataType>::delMax() {
	this->root = delNode(this->root, maxNode());
}

template<typename NODETYPE> Tree<dataType>::ostream& operator<<(ostream& os, const Tree<dataType>& tree) {
	return os << tree.toString();
}
