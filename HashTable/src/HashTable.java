/* Anuarbekob Alisher
 * ID:202193390
 * Assignment #3
 * Code in Java (version 16.01) 
 */

import java.util.*; // library for accessing to arrays and other utilities 

public class HashTable {
	
	// made them private to prevent direct access from other classes
	private static int capacity = 13; // table size given in assignment
	
	private Integer [] list = new Integer[capacity]; //represent table itself. 
	//I pick array type of Integer in order to use null to indicate empty spot
	
	//primary hush function
	int hushFunc1(int value) {
		int hushed = value % capacity;
		return hushed;
	}
	//secondary hash function
	int hushFunc2(int value) {
		int hash1 = hushFunc1(value);
		int hash2 = 7 - (value % 7); 
		int result;
		int i = 1; // iteratively make it greater to get different index in each iteration
		while(true) {
			
			result = (hash1 + hash2 * i) % capacity; // hash function given in assignment
			
			i++; //make it 1 time greater
			
			if(list[result] == null) {
				return result; //if index given by hash function is empty -> return result to add function
			}
			
			
		}
}
	//function for adding values
	boolean add(int value) { 
		int hash1 = hushFunc1(value);
		int hash2 = hushFunc2(value);
		if(list[hash1] == null) {//if true number will be inserted using primary function
			list[hash1] = value;
			return true;
		}else if (list[hash1] != null && list[hash2] == null){ // if true -> use secondary function
			list[hash2] = value;
			return true;
		}else { //if table is full then return false 
			System.out.println("Table is full. Item can not be inserted");
			return false;
		}
	}
	// remove items from table. "Remove" was done iteratively.
	boolean remove(int value) { 
		for(int i = 0; i < capacity; i++) {
			if(list[i] == value) { //if value equal to the item at index i then reassign to index i "null"
				list[i] = null;
				return true;
			}
		}return false;
	}
	
	//for convenience I implemented actual number of items in table 
	void size() { 
		int counter = 0;
		for(int i = 0; i < capacity; i++) {
			if(list[i] != null) {
				counter++;
			}
		} System.out.println("Number of integer in Hash Table: " + counter);
	}
	
	// for convenience I implemented print function
	
	void print() {
		System.out.println(Arrays.toString(list)); // converting Array to String and output to console
	}
}


