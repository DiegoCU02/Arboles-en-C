#include<bits/stdc++.h>
#include "bst.hpp"

using namespace std;

int main(){
	bst arbol1;
	bst arbol2;
	arbol1.insert(4);
	arbol1.insert(3);
	arbol1.insert(2);
	arbol1.insert(1);
	arbol1.insert(5);
	arbol1.insert(6);
	arbol1.insert(7);
	arbol1.insert(9);
	arbol1.print();
	cout<<endl;

	//2do arbol
	arbol2.insert(4);
	arbol2.insert(3);
	arbol2.insert(2);
	arbol2.insert(1);
	arbol2.insert(5);
	arbol2.insert(6);
	arbol2.insert(7);
	arbol2.insert(9);
	arbol2.print();
	
	arbol1.print_inorder(arbol1.root);
	arbol2.print_inorder(arbol2.root);
	cout<<endl;
	/*tree_node *x=arbol.search(7);
	x=arbol.predecessor(x);
	cout<<x->key;
	*/
	cout<<endl;
	cout<<arbol1.diametro();
	cout<<endl;
	cout<<arbol1.perfecto();
	cout<<endl;
	bool a;
	a=arbol1.iguales(arbol1.root,arbol2.root);
	cout<<a;
	
}

