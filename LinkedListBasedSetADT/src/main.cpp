#include "set.h"
#include <iostream>

void output(const set& s) {
	std::cout << s.size() << " " << s.empty() << " " << s << std::endl;
}

// This is a minimal testing file.... we will use something more complete
// for grading!!!
int main() {

	set s1;
	s1.insert(10);
	s1.insert(6);
	s1.insert(15);
	s1.insert(41);
	s1.insert(13);
	s1.insert(5);


	set s2(s1);

	set s3 = s2;


	s3.print(std::cout);
	s2.print(std::cout);
	s1.print(std::cout);

}
