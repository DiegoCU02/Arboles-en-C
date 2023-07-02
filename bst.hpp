struct tree_node{
	int key;
	tree_node *parent;
	tree_node *left;
	tree_node *right;
	tree_node(int k){
		key = k;
		left = NULL;
		right = NULL;
	}
};

class bst{
	public:
		tree_node *root;
		bst(){
			root = NULL;
		}
		void insert(int k);
		void print(); //imprime de forma bonita el bst
		void print(std::string prefix, tree_node *x, bool isLeft);
		void print_inorder();
		void print_inorder(tree_node *x);
		void print_postorder();
		void print_postorder(tree_node *x);
		void print_preorder();
		void print_preorder(tree_node *x);
		void print_decreciente();
		void print_decreciente(tree_node *x);
		tree_node *min();
		tree_node *min(tree_node *x);
		tree_node *max();
		tree_node *max(tree_node *x);
		tree_node *search(int k);
		tree_node *sucessor(tree_node *x);
		tree_node *predecessor(tree_node *x);
		void transplant(tree_node *u, tree_node *v); 
		void remove(tree_node *z);
		void remove();
		//Parte 2:
		int size(); //cuenta el numero de nodos
		int size(tree_node *x);
		int diametro(); //encuentra la distancia maxima entre dos hojas
		int diametro(tree_node *x);
		int maxDepth(); //devuelve el número de nodos a lo largo de la raíz hasta el nodo más lejano, un árbol vacio tiene maxDepth()=0.
		int maxDepth(tree_node *x);
		tree_node *LCA(tree_node *x, tree_node *y); //devuelve el nodo más profundo que es ancestro de los nodos x e y.
		
		void caminos(); //imprimir el camino desde la raíz hacia c/u de sus hojas.
		void espejo();
		bool iguales(tree_node *x, tree_node *y);
		bool iguales(bst *x, bst *y);
		bool esBST(); //Para ser un árbol de búsqueda binaria: para cada nodo, todos los nodos en su sub-árbol izquierdo deben ser < que el nodo y todos los nodos del sub-árbol derecho deben ser > que el nodo.
		bool perfecto(); //determina si todos los nodos excepto la raíz tienen un hermano
		bool perfecto(tree_node *x);
		
};

void bst::print(){
    std::cout<<std::endl;
	print("", root, false);
	std::cout<<std::endl;
}

void bst::print(std::string prefix, tree_node *x, bool isLeft){
	if(x != NULL){
		std::cout<<prefix;
		if(prefix=="") 
			std::cout<<"\xBA\xCD\xCD\xCD\xCD\xCD";
		else
			std::cout<<(isLeft ? "\xBA\xCD\xCDL\xCD\xCD" : "\xC8\xCD\xCDR\xCD\xCD");
        std::cout<<x->key<<std::endl;
        print(prefix + (isLeft ? "\xBA     " : "      "), x->left, true);
        print(prefix + (isLeft ? "\xBA     " : "      "), x->right, false);
	}
}

void bst::insert(int k){
	tree_node *x = root;
	tree_node *y = NULL;
	tree_node *z = new tree_node(k);
	while(x != NULL){
		y = x;
		if(z->key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	} 
	z->parent = y;
	if(y == NULL)
		root = z;
	else if(z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void bst::print_inorder(){
    print_inorder(root);
}

void bst::print_inorder(tree_node *x){
    if(x != NULL){
    	print_inorder(x->left);
    	std::cout<<x->key;std::cout<<" ";
    	print_inorder(x->right);
	}
}

void bst::print_postorder(){
	print_postorder(root);
}

void bst::print_postorder(tree_node *x){
	if(x != NULL){
    	print_postorder(x->left);
    	print_postorder(x->right);
    	std::cout<<x->key;std::cout<<" ";	
	}
}

void bst::print_preorder(){
	print_preorder(root);
}

void bst::print_preorder(tree_node *x){
	if(x != NULL){
		std::cout<<x->key;std::cout<<" ";
    	print_preorder(x->left);
    	print_preorder(x->right);
	}
}

void bst::print_decreciente(){
	print_decreciente(root);
}

void bst::print_decreciente(tree_node *x){
	if(x != NULL){
		print_decreciente(x->right);
		std::cout<<x->key;std::cout<<" ";
    	print_decreciente(x->left);
	}
}

tree_node* bst::min(){
	tree_node *x=root;
	while(x->left != NULL){
		x=x->left;
	}
	return x;
}

tree_node* bst::min(tree_node *x){
	while(x->left != NULL){
		x=x->left;
	}
	return x;
}

tree_node* bst::max(){
	tree_node *x=root;
	while(x->right != NULL){
		x=x->right;																																																																																																																																																																																																																																																																																																																	
	}
	return x;
}

tree_node* bst::max(tree_node *x){
	while(x->right != NULL){
		x=x->right;
	}
	return x;
}

tree_node* bst::search(int k){
	tree_node *x=root;
	while(x != NULL and x->key != k){
		if(k<x->key){
			x=x->left;
		}
		else{
			x=x->right;
		}
	}
	return x;
}

tree_node* bst::predecessor(tree_node *x){
	if(x->left != NULL){
		return max(x->left);
	}
	else{
		tree_node *y = x->parent;
		while(y != NULL and y->left==x){
			x=y;
			y=x->parent;
		}
		return y;
	}
}

tree_node* bst::sucessor(tree_node *x){
	if(x->right != NULL){
		return min(x->right);
	}
	else{
		tree_node *y = x->parent;
		while(y != NULL and y->right==x){
			x=y;
			y=x->parent;
		}
		return y;
	}
}

void bst::transplant(tree_node *u, tree_node *v){
	if(u->parent == NULL){
		root=v;
	}
	else{
		if(u->parent->left == u){
			u->parent->left=v;
		}
		else{
			u->parent->right=v;
		}
		if(v != NULL){
			v->parent=u->parent;
		}
	}
}

void bst::remove(tree_node *z){
	tree_node *y;
	if(z->left == NULL){
		transplant(z,z->right);
	}
	else if(z->right == NULL){
		transplant(z,z->right);
	}
	else{
		y=min(z->right);
		if(z->right != y){
			transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	delete(z);
}

void bst::remove(){
	remove(root);
}

int bst::size(){
	return size(root);
}

int bst::size(tree_node *x){
	if(x != NULL){
		int contIzq = size(x->left);
		int contDer = size(x->right);
		int medio = 1;
		return contIzq + contDer + medio;
	}
	return 0;
}

int bst::diametro(){
	return diametro(root);
}

int bst::diametro(tree_node *x){
	if( x != NULL){
		int alturaIzq=maxDepth(x->left);
		int alturaDer=maxDepth(x->right);
		int diametroIzq=diametro(x->left);
		int diametroDer=diametro(x->right);
		int alturaMax;
		int diametroMax;
		if(alturaIzq>alturaDer){
			alturaMax=alturaIzq+1;
		}
		else{
			alturaMax=alturaDer+1;
		}

		if(diametroIzq>diametroDer){
			diametroMax = diametroIzq;
		}
		else{
			diametroMax = diametroDer;
		}
		if(alturaMax > diametroMax){
			return alturaMax;
		}
		else{
			return diametroMax;
		}


	}
	return 0;
}

int bst::maxDepth(){
	return maxDepth(root);
}

int bst::maxDepth(tree_node *x){
	if(x == NULL){
		return 0;
	}
	int leftDepth = maxDepth(x->left);
	int rightDepth = maxDepth(x->right);
	if(leftDepth > rightDepth){
		return 1+leftDepth;
	}
	else{
		return 1+rightDepth;
	}
}

tree_node* bst::LCA(tree_node *x,tree_node *y){
	tree_node *ancestro=root;
	 while(ancestro != NULL) {
        if(x->key < ancestro->key && y->key < ancestro->key) {
            ancestro = ancestro->left;
        }
		else if (x->key > ancestro->key && y->key > ancestro->key) {
            ancestro = ancestro->right;
        } 
		else{
            break;
        }
    }
    return ancestro;
} 

bool bst::iguales(bst* x, bst* y){
    return iguales(x->root, y->root);
}

bool bst::iguales(tree_node* x, tree_node* y){
    if(x == NULL and y == NULL){
        return 1;
    }
    if(x != NULL && y != NULL){
        if(x->key == y->key){
            bool left = iguales(x->left, y->left);
            bool right = iguales(x->right, y->right);
            return left and right;
        }
    }
    return 0;
}


bool bst::perfecto(){
	return perfecto(root);
}

bool bst::perfecto(tree_node *x){
	if(x == NULL){
		return true;
	}

    if(x->left != NULL && x->right != NULL){
		return perfecto(x->left) && perfecto(x->right);
	}
        
    else if(x->left == NULL && x->right == NULL){
		 return true;
	}
       
    else{
		 return false;
	}
}





