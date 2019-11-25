#include <iostream>  
using namespace std;  
 
// Node class  
class Node {   
int key;   Node* left;   Node* right;  
 
 public: Node() {    
 key=-1;    left=NULL;    right=NULL;   
 };     
 void setKey(int aKey) { key = aKey; };   
 void setLeft(Node* aLeft) { left = aLeft; };   
 void setRight(Node* aRight) { right = aRight; };   
 int Key() { return key; };   
 Node* Left() { return left; };  //left subtree 
 Node* Right() { return right; };  //right subtree
 };  
 
// Tree class  

class Tree {   
Node* root;   
public:    
Tree();    
~Tree();    
Node* Root() { return root; };    
void addNode(int key);    
void inOrder(Node* n);    
void preOrder(Node* n);    
void postOrder(Node* n);  
int maxdepth(Node *root);
 private:    
 void addNode(int key, Node* leaf);   //function overloading//polymorphysm?huhuhu
  void freeNode(Node* leaf); }; // Constructor   '
  
   Tree::Tree() { root = NULL; } // Destructor   
    Tree::~Tree() { freeNode(root); } // Free the node  //desctructor     
	void Tree::freeNode(Node* leaf) {   
	 if ( leaf != NULL ) {     
	  freeNode(leaf->Left());      
	 freeNode(leaf->Right());      
	 delete leaf;  }    //no need extra pointer
	 }
	 
	 void Tree::addNode(int key) 
	 { // No elements. Add the root     
	 if ( root == NULL ) {      
	 cout << "add root node ... " << key << endl;      
	 Node* n = new Node();      
	 n->setKey(key);      
	 root = n;     
	 } else {      
	 cout << "add other node ... " << key << endl;      
	 addNode(key, root); }     
	 } // Add a node (private)     
	
	int Tree::maxdepth(Node *root)// maximum depth
	{
		int ldepth,rdepth;
		if(root==NULL)
			return 0;
		else{
			ldepth=maxdepth(root->Left());
			rdepth=maxdepth(root->Right());	//recursive			   
		}
		if(ldepth<=rdepth)
			return rdepth+1;
		else
			return ldepth+1;
	}
	 void Tree::addNode(int key, Node* leaf)//creating bst
	  {     
	 if ( key <= leaf->Key() ) {      //recursive	//smaller to the left
	 if ( leaf->Left() != NULL )       //cannot insert in the middle
	 addNode(key, leaf->Left());      
	 else { 
	 Node* n = new Node();       
	 n->setKey(key);       
	 leaf->setLeft(n);      
	 }     
	 }     
	 else {      
	 if ( leaf->Right() != NULL )       
	 addNode(key, leaf->Right());      
	 else { Node* n = new Node();       
	 n->setKey(key); leaf->setRight(n);     
	 }     
	 }    
	 } // Print the tree in-order       // Traverse the left sub-tree, root, right sub-tree
	     
	 void Tree::inOrder(Node* n) {     
	 if ( n ) { 
	 inOrder(n->Left());      
	 cout << n->Key() << " ";     
	 inOrder(n->Right());     
	 }   
	  } // Print the tree pre-order       // Traverse the root, left sub-tree, right sub-tree    
	  
	  void Tree::preOrder(Node* n) {    
	   if ( n ) {      cout << n->Key() << " ";      
	  preOrder(n->Left());      preOrder(n->Right());   
	    }    
	  } // Print the tree post-order       // Traverse left sub-tree, right sub-tree, root    
	  void Tree::postOrder(Node* n) {     if ( n ) 
	  {      
	  postOrder(n->Left());      postOrder(n->Right());      
	  cout << n->Key() << " ";    
	   }    
	  } 
// Test main program  
int main() {  
Tree* tree = new Tree();   
tree->addNode(30);  
 tree->addNode(10); 
   tree->addNode(20);   
   tree->addNode(40);   
   tree->addNode(4);   
   tree->addNode(50);   
   tree->addNode(15);  
   cout << "In order traversal" << endl;   
   tree->inOrder(tree->Root());   cout << endl;   
   cout << "Pre order traversal" << endl;   
   tree->preOrder(tree->Root()); cout << endl;   
   cout << "Post order traversal" << endl;   
   tree->postOrder(tree->Root());   cout << endl;  
   cout<<"maximum depth of the tree:";
   cout<<tree->maxdepth(tree->Root())<<endl;
    delete tree;   
	return 0;  
	}  
