#include <iostream>
#include "String.h"

using namespace std;


String::String() {}
String::String(const char* _str) : str{ _str } {}
String::String(const String& _other) { *this = _other; }

String::~String() {}

size_t String::Length() const {  //finds the lengths of the string

	int count = 0;
	for (int i = 0; this->str[i]; i++) {
		count++;
	}

	return count; //returns the length at a size_t value
}

char& String::CharacterAt(size_t _index) {  //finds the character located at a certain index in the string

	char output = '0';

	if (_index < this->Length()) {
		output = this->str[_index];
	}

	return output; //returns the character at the index
}

const char& String::CharacterAt(size_t _index) const {  //character at but works with a const character

	char output = '0';

	if (_index < this->Length()) {
		output = this->str[_index];
	}

	return output; //returns the character at the index
}

bool String::EqualTo(const String& _other) const {  //checks to see if _other and the string are the same

	if (this->str == _other.str) { return true; }      //returns 1 if true
	else { return false; }                             //returns 0 if false
}

String& String::Append(const String& _str) {  //adds _str to the end of the string

	this->str += _str.str;

	return *this; //return does not matter, the function is performing an action
}

String& String::Prepend(const String& _str) {  //adds _str to the start of the string

	this->str = _str.str + this->str;

	return *this; //return does not matter, the function is performing an action
}

const char* String::CStr() const {  //converts the pointer into a writeable output

	string input = this->str;
	char* output = new char[this->Length() + 1];
	output[this->Length()] = '\0';
	for (int i = 0; i < this->Length(); i++) {
		output[i] = input[i];
	}

	return output; //returns the writeable output
}

String& String::ToLower() {  //converts all letters in the string to lowercase

	for (int i = 0; this->str[i]; i++) {
		if (65 <= str[i] && str[i] <= 92) {
			str[i] += 32;
		}
	}

	return *this; //return does not matter, the function is performing an action
}

String& String::ToUpper() {  //converts all letters in the string to uppercase

	for (int i = 0; this->str[i]; i++) {
		if (97 <= str[i] && str[i] <= 122) {
			str[i] -= 32;
		}
	}

	return *this; //return does not matter, the function is performing an action
}

size_t String::Find(const String& _str) {  //Finds the starting index of the first instance of _str in the string

	bool counting = false;
	int counter = 0;
	for (int i = 0; i < this->Length(); i++) {
		if (this->str[i] == _str[0]) {
			for (int i2 = 0; i2 < _str.Length(); i2++) {
				int startIndex = i;
				if (counting == false) {
					counter = i; 
					counting = true; 
				}

				if (this->str[counter] == _str[i2]) {
					counter++;
				}
				else {
					counting = false;
					counter = 0;
					break;
				}

				if (i2 == (_str.Length()-1)) {
					counting = false;
					counter = 0;
					return startIndex; //returns the starting index of _str if it finds an instance
				}
			}
		}
	}

	return -1; //returns '-1' if it does not find and instance
}

size_t String::Find(size_t _startIndex, const String& _str) {  //Finds the starting index of the first instance after a certain index of _str in the string             
	                                                         
	bool counting = false;
	int counter = 0;
	for (int i = _startIndex; i < this->Length(); i++) {
		if (this->str[i] == _str[0]) {
			for (int i2 = 0; i2 < _str.Length(); i2++) {
				int startIndex = i;
				if (counting == false) {
					counter = i;
					counting = true;
				}

				if (this->str[counter] == _str[i2]) {
					counter++;
				}
				else {
					counting = false;
					counter = 0;
					break;
				}

				if (i2 == (_str.Length() - 1)) {
					counting = false;
					counter = 0;
					return startIndex; //returns the starting index of _str if it finds an instance after the given index
				}
			}
		}
	}

	return -1; //returns '-1' if it does not find and instance
}

String& String::Replace(const String& _find, const String& _replace) {  //replaces all instances of _find with _replace in the string
	
	int counter = 0;
	int findCounter = 0;

	for (int i = 0; i < this->Length(); i++) {

		if (Find(i, _find) != -1) {
			findCounter++;
			i += _find.Length();
		}
	}

	int loopCounter = 0;

	while (loopCounter < findCounter) {
		int len = this->Length() - _find.Length() + _replace.Length();

		string beforeFind;
		string afterFind;

		for (int i2 = 0; i2 < Find(_find); i2++) {
			beforeFind += this->str[i2];
		}

		counter = 0;
		for (int i2 = Find(_find) + _find.Length(); i2 < this->Length(); i2++) {
			afterFind += this->str[i2];
			counter++;
		}

		this->str = beforeFind + _replace.str + afterFind;
		loopCounter++;
	}

	//for (int i = 0; i < this->Length(); i++) {
	//	if (Find(i, _find) == -1) {
	//		break;
	//	}
	//	else {
	//if (_find.Length() == _replace.Length()) {
	//	counter = Find(i, _find);
	//	for (int i2 = 0; i2 < _replace.Length(); i2++) {
	//		this->str[counter] = _replace[i2];
	//		counter++;
	//	}
	//}
	//else {
	//counter = 0;
	//for (int i2 = 0; i2 < len; i2++) {
	//	if (i2 == Find(i, _find)) {
	//		for (int i3 = 0; i3 < _replace.Length(); i3++) {
	//			bufferStr->str[i2] = _replace[i3];
	//			i2++;
	//		}
	//		counter += Find(i, _find) + _find.Length();
	//	}
	//	else {
	//		bufferStr->str[i2] = this->str[counter];
	//		counter++;
	//		
	//	}
	//}
	//this->str = bufferStr->str;

	return *this; //return does not matter, the function is performing an action
}

String& String::ReadFromConsole() {  //reads the users input and saves it to the string

	cin >> this->str;

	return *this; //return does not matter, the function is performing an action
}

String& String::WriteToConsole() {  //writes the string to the console

	cout << this->str << endl;

	return *this; //return does not matter, the function is performing an action
}

bool String::operator==(const String& _other) {   
	return EqualTo(_other);
}

bool String::operator!=(const String& _other) {
	return !EqualTo(_other);
}

char& String::operator[](size_t _index) {             

	return CharacterAt(_index);
}

const char& String::operator[](size_t _index) const {

	return CharacterAt(_index); 
}                                   