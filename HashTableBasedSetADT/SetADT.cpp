/*
 * SetADT.cpp
 *
 *  Created on: Sep 30, 2021
 *      Author: Ardakuly
 */
#include <ostream>
#include <list>
#include <cstdlib>
#include <math.h>
#include "set.h"

bool set::equal(const std::string& s1, const std::string& s2){
	int ascii1, ascii2;
	int i = 0;
	int index = s1.length()-1;
	bool truefalse;
	while(i != index){

		if((int)s1[i] < 97){
			ascii1 = (int)s1[i]+32;
		}else{
			ascii1 = (int)s1[i];
		}
		if((int)s2[i] < 97){
			ascii1 = (int)s2[i]+32;
		}else{
			ascii2 = (int)s2[i];
		}

		if(ascii1 == ascii2){
			truefalse = true;
		}else{
			truefalse =false;
			return truefalse;
		}


		i++;
	}
	return truefalse;
}

size_t set::hash(const std::string& s){
	double standdev  = standarddev();
	if(standdev <= 1.5){
		int asciival = (int)s[0];
		return asciival % bucket_array_size;
	}else{
		int asciival = (int)s[0];
		return asciival % bucket_array_size * 2;
	}

}

bool set::insert(std::string val){
	bool truefalse;
	int i = 0;
	size_t index;
	for ( std::string str : bucket_array[i]) {
		truefalse = equal(str, val);
		i++;
	 }

	if(truefalse == true){
		truefalse = false;
		return truefalse;
	}else{
		index = hash(val);
		bucket_array[index].push_back(val);
		truefalse = true;
		return truefalse;
	}

}

set::set(const set& s):
	bucket_array(new std::list<std::string>[s.set_size]),
	bucket_array_size(s.bucket_array_size),
	set_size(s.set_size)
	{
	int i;
	for ( std::string str : s.bucket_array[i]) {
		bucket_array[i].push_back(str);
		i++;
	}


}

set& set::operator=(const set& s){
	if(&s == this){
		int i;
		size_t index;
		bucket_array_size = s.bucket_array_size;
		set_size = s.set_size;
		for(std::string str : s.bucket_array[i]){
			index = hash(str);
			bucket_array[index].push_back(str);
			i++;
		}
	}return *this;
}

bool set::contains(std::string val) const{
	bool falsetrue;
	int i;
	for(std::string str : bucket_array[i]){
		falsetrue = equal(str, val);
		if(falsetrue == true){
			 return falsetrue;
		}
	}

	return falsetrue;
}




