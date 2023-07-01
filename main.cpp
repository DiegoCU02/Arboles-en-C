#include<bits/stdc++.h>
#include "bst.hpp"

using namespace std;

int main(){
	bst arbol;
	arbol.insert(7);
	arbol.insert(5);
	arbol.insert(8);
	arbol.insert(9);
	arbol.insert(2);
	arbol.insert(1);
	arbol.insert(6);
	arbol.insert(4);
	arbol.print();
	cout<<endl;
	
	arbol.print_inorder(arbol.root);
	cout<<endl;
	arbol.print_postorder(arbol.root);
	cout<<endl;
	arbol.print_preorder(arbol.root);
	cout<<endl;
	arbol.print_decreciente(arbol.root);
	cout<<endl;
	tree_node *x=arbol.search(7);
	x=arbol.predecessor(x);
	cout<<x->key;
	cout<<endl;
	cout<<arbol.size();
	cout<<endl;
	cout<<arbol.diametro();
}