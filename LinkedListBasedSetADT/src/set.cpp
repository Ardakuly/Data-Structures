#include <iostream>
#include "set.h"



set::treenode* set::copynodes(treenode *original){
	treenode* newNode;
	treenode* isornot;
	if(original ==  NULL ){
		 std::cout<< "Nothing in the set for copying"<<std::endl;
		 isornot = NULL;
	}else{
		newNode = new treenode(original->value);
		newNode->left = copynodes(original->left);
		newNode->right = copynodes(original->right);
		isornot = newNode;
	}

	return isornot;
}


void set::deallocatenodes(treenode* node){
	if(node == NULL){
		std::cout<<"Nothing in BTS"<<std::endl;
	}else{
		deallocatenodes(node->left);
		deallocatenodes(node->right);
		delete(node);
	}
}


bool set :: contains(int i) const{
	treenode* tempnode = root;
	bool isornot;
	while(tempnode == NULL){
		if(tempnode -> value == i ){
			isornot = true;
			break;
		}else if(tempnode -> value > i) {
			tempnode = tempnode -> left;
			isornot = false;
		}else if(tempnode-> value < i){
			tempnode = tempnode -> right;
			isornot = false;
		}
	} return isornot;
}

bool set::insert(int i){

	bool cheching;
	treenode* iterator=root;
	while(1){
		if(iterator == NULL){
			root = new treenode(i);
			iterator = root;
			set_size++;
			cheching = false;
			return cheching;
		}else if(iterator->value == i){
			std::cout<<"Value "; std::cout<<i; std::cout<<" already exist"<<std::endl;
			cheching = true;
			return cheching;
		}else if((iterator->value > i) && (iterator -> left != NULL)){
			iterator=iterator->left;
			cheching = false;
		}else if((iterator->value>i) && (iterator->left == NULL)){
			treenode* newNode = new treenode(i);
			iterator->left = newNode;
			set_size++;
			cheching = false;
			return cheching;
		}else if((iterator->value < i) && (iterator -> right != NULL)){
			iterator=iterator->right;
			cheching = false;
		}else if((iterator->value<i) && (iterator->right == NULL)){
			treenode* newNode = new treenode(i);
			iterator->right = newNode;
			set_size++;
			cheching = false;
			return cheching;
		}
	}
}


void set::clear(){
	deallocatenodes(root);
}

size_t set:: size() const{
	return set_size;
}

bool set::empty() const{
	if(root == NULL){
		return true;
	}else{
		return false;
	}
}
