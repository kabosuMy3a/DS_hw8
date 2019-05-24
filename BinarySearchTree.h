#ifndef __BINARYSEARCHTREE__H__
#define __BINARYSEARCHTREE__H__ 

#include "default.h"

typedef struct t_bst_node {

	string key;
	string data;

	t_bst_node * left_child ;
	t_bst_node * right_child ;
	//t_bst_node * parent ;

} bst_node ; 


class BinarySearchTree {


	private :
			bst_node * root ;
			void destroyBST(bst_node * node);		
			
			bst_node * getNodeFromKey(bst_node * node, string num) ;
			bst_node * findParent(string num) ;
			//bst_node * findParent2(int num) ;

			//void replaceNode(bst_node * beforeNode, bst_node * afterNode);
			//void copyValue(bst_node * copiedNode, bst_node * copyFromNode);


	public :

			BinarySearchTree() ;
			~BinarySearchTree() ;
			
			bst_node * creatNewNode(string key, string data);
						
			bst_node * getNodeFromKey(string num) ;
				
			void insert(string key, string data);
			string getData(string key);	

			//void deletion(int key); 		

			void inOrderPrint();
			void inOrderPrint(bst_node * leaf) ;
			//bst_node * getMinFromRightChild(bst_node * leaf);
};


#endif 
