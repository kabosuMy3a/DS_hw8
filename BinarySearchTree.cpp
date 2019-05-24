#include "BinarySearchTree.h" 


BinarySearchTree::BinarySearchTree(){

	root = new bst_node() ;
	root = 0x0 ; 
	/* in BinarySearchTree::insert() 
	 * if (root==0x0) //new node will be root
	 * but it's not necessary 
	*/
}	


BinarySearchTree::~BinarySearchTree(){

	if (root != 0x0) destroyBST(root) ;
	

}


void BinarySearchTree::destroyBST(bst_node * node){


	if (node!=0x0) {

		destroyBST(node->left_child) ;
		destroyBST(node->right_child) ;
		
		delete node ;

	}
}


bst_node * BinarySearchTree::creatNewNode(string key, string data){


	bst_node * leaf = new bst_node() ;

	leaf->key = key;
	leaf->data = data;
	
	leaf->left_child = 0x0 ;
	leaf->right_child = 0x0 ;

	return leaf ;
}


void BinarySearchTree::inOrderPrint(){

	inOrderPrint(root) ; 

}

void BinarySearchTree::inOrderPrint(bst_node * leaf){
	
	if(leaf!=0x0){

		inOrderPrint(leaf->left_child);
		cout << "(" << leaf->key << ", " << leaf->data << ")" <<endl;
		inOrderPrint(leaf->right_child);
		
	}
}

bst_node * BinarySearchTree::getNodeFromKey(string num){

	return getNodeFromKey(root, num) ;

}

bst_node * BinarySearchTree::getNodeFromKey(bst_node * node, string num){

	if(node!=0x0){
	
		if (node->key == num) return node ;

		else if (node->key > num) return getNodeFromKey(node->left_child, num) ;
		
		else return getNodeFromKey(node->right_child, num) ;

	}
	
	else return 0x0 ;

}

bst_node * BinarySearchTree::findParent(string num){

	bst_node * parent = root ;

	while (parent!=0x0){

		if (parent->key == num){
			return 0x0 ;
		}	
	
		else if (parent->key > num ){

			if(parent->left_child) parent = parent->left_child ;
			else return parent ;

		}

		else{
		
			if(parent->right_child) parent= parent->right_child ; 
			else return parent ; 
		}

	}

	return 0x0 ;

}

void BinarySearchTree::insert(string key, string data){


	bst_node * branch = findParent(key) ;
	bst_node * leaf = creatNewNode(key,data) ;
	
	if(branch){

		if (branch->key > leaf->key) branch->left_child = leaf ;
		else branch->right_child = leaf ;

	}

	else if(root == 0x0 ) root = leaf ; //first leaf will be root.

	else cout << "<duplicate_val> is already in the tree" << endl ;
		
			
}

string BinarySearchTree::getData(string key){


	bst_node * target = getNodeFromKey(key);

	if (target != 0x0){
		return target->data;
	}
	else return "" ;

}
