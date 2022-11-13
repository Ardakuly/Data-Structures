/* Course: MECE 603
 * Anuarbekob Alisher
 * ID:202193390
 * Assignment #3 "Custom HashTable"
 * Code in Java (version 16.01) 
 */


public class Executer extends HashTable {

	public static void main(String[] args) {
		
		HashTable myTable = new HashTable(); // Create pointer and pointed to new object called "myTable"
		
		myTable.add(5); //calling method ".add()" using object
		myTable.add(28);
		myTable.add(19);
		myTable.add(15);
		myTable.add(20);
		myTable.add(33);
		myTable.add(12);
		myTable.add(17);
		myTable.add(3);
		myTable.add(78);
		myTable.add(78);

		
		
		myTable.remove(78); // calling method ".remove()" using object
		
		
		myTable.size(); // calling method ".size() using object"
		
		myTable.print(); // printed values can be seen in Console

		
	}

}
