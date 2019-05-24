#ifndef __BINARYSEARCHTREE__H__
#define __BINARYSEARCHTREE__H__ 

#include "default.h"

typedef struct t_bst_node {

	string key;
	string data;

	t_bst_node * left_child ;
	t_bst_node * right_child ;

} bst_node ; 


class BinarySearchTree {


	private :
			
			bst_node * root ;
			void destroyBST(bst_node * node);		
			
			bst_node * getNodeFromKey(bst_node * node, string num) ;
			bst_node * findParent(string num) ;
		


	public :

			BinarySearchTree() ;
			~BinarySearchTree() ;
			
			bst_node * creatNewNode(string key, string data);
						
			bst_node * getNodeFromKey(string num) ;
				
			void insert(string key, string data);
		
			void inOrderPrint();
			void inOrderPrint(bst_node * leaf) ;
			string getData(string key) ;
};

#endif 
