#include<bits/stdc++.h>
#include "bst.hpp"

using namespace std;

int main(){
	bst arbol1;
	arbol1.insert(4);
	arbol1.insert(3);
	arbol1.insert(2);
	arbol1.insert(1);
	arbol1.insert(5);
	arbol1.insert(6);
	arbol1.insert(7);
	arbol1.insert(9);
	arbol1.insert(13);
	arbol1.insert(11);
	arbol1.print();
	cout<<endl;

	/*tree_node *x=arbol.search(7);
	x=arbol.predecessor(x);
	cout<<x->key;
	*/
	arbol1.caminos();

	bool a;
	a=arbol1.esBST(arbol1.root);
	cout<<a;
	
}

