#ifndef SET_INCLUDED
#define SET_INCLUDED    1 

#include <iostream>

class set {

	// Private type for internal set use only; here we are
	// using a binary search tree implementation
	struct treenode {
	   int value;
	   treenode* left;
	   treenode* right;

	   treenode(int val)
	      : value(val),
	        left(NULL),
	        right(NULL)
	   { }
	};

	// Fields of the BST-based set object
	size_t set_size;
	treenode* root;

	// This is a recursive helper function that should create and return an exact
	// copy of the tree structure rooted at original
	static treenode* copynodes(treenode* original);

	// This is a recursive helper function that should deallocate all of the
	// nodes in the tree structure rooted at node
	static void deallocatenodes(treenode* node);

	// This is a recursive helper function called by print to output all of the
	// values of the tree in sorted order using an in-order traversal
	static void printhelper(std::ostream &out, treenode* node){
		if (node != NULL) {
			if (node->left != NULL) {
				printhelper(out, node->left);
				out << ", ";
			}
			out << node->value;
			if (node->right != NULL) {
				out << ", ";
				printhelper(out, node->right);
			}
		}
	}

public:

	// Default ordered set is empty
	set() : set_size(0), root(NULL) { }

	// Copy constructor
	set(const set &s) : set_size(s.set_size), root(NULL) {
		root = copynodes(s.root);
	}

	// Copy assignment
	set& operator=(const set &s) {
		if (&s != this) {
			deallocatenodes(root);
			root = copynodes(s.root);
			set_size = s.set_size;
		}
		return *this;
	}

	// Returns true if the value i is in the ordered set
	bool contains(int i) const;

	// Insert the value i in the ordered set, if it is not already 
	// there;  Return true if the value was inserted, and false if
	// it was already there
	bool insert(int i);

	// Remove the value i from the ordered set if it is there, but
	// do nothing if it is not;  Return true if the value was 
	// removed, and false if it was not there
	//
	// WE WILL NOT IMPLEMENT THIS FOR THE ASSIGNMENT
	bool remove(int i) {
		throw "remove not implemented";
	}

	// Remove everything from the set
	void clear();

	// Returns the number of items in the set
	size_t size() const;

	// Returns whether or not the set is currently empty
	bool empty() const;

	// Print out the contents of the set, in order from smallest to largest
	void print(std::ostream &out) const {
		out << "{";
		printhelper(out, root);
		out << "}";
		std::cout<<std::endl;
	}

	// Destructor
	~set() {
		deallocatenodes(root);
	}
};

inline std::ostream& operator<<(std::ostream &out, const set &s) {
	s.print(out);
	return out;
}

#endif

