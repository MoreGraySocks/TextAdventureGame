#include <iostream>
#include "String.h"

using namespace std;


String::String() {}
String::String(const char* _str) : str{ _str } {}
String::String(const String& _other) { *this = _other; }

String::~String() {}

size_t String::Length() const {

	int count = 0;
	for (int i = 0; this->str[i]; i++) {
		count++;
	}

	return count;
}

char& String::CharacterAt(size_t _index) {

	char output = '0';

	if (_index < this->Length()) {
		output = this->str[_index];
	}

	return output;
}

const char& String::CharacterAt(size_t _index) const {

	char output = '0';

	if (_index < this->Length()) {
		output = this->str[_index];
	}

	return output;
}

bool String::EqualTo(const String& _other) const {

	if (this->str == _other.str) { return true; }
	else { return false; }
}

String& String::Append(const String& _str) {

	this->str += _str.str;

	return *this;
}

String& String::Prepend(const String& _str) {

	this->str = _str.str + this->str;

	return *this;
}

const char* String::CStr() const {

	string input = this->str;
	char* output = new char[this->Length() + 1];
	output[this->Length()] = '\0';
	for (int i = 0; i < this->Length(); i++) {
		output[i] = input[i];
	}

	return output;
}

String& String::ToLower() {

	for (int i = 0; this->str[i]; i++) {
		if (65 <= str[i] && str[i] <= 92) {
			str[i] += 32;
		}
	}

	return *this;
}

String& String::ToUpper() {

	for (int i = 0; this->str[i]; i++) {
		if (97 <= str[i] && str[i] <= 122) {
			str[i] -= 32;
		}
	}

	return *this;
}

size_t String::Find(const String& _str) {

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
					return startIndex;
				}
			}
		}
	}

	return -1;
}

size_t String::Find(size_t _startIndex, const String& _str) {              
	                                                         
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
					return startIndex;
				}
			}
		}
	}

	return -1;
}

String& String::Replace(const String& _find, const String& _replace) {         
	
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

	//}
			
	//	}

	//}

	//this->str = bufferStr;

	return *this;
}

String& String::ReadFromConsole() {

	string input = "";
	cout << "Write something" << endl;
	cin >> input;
	this->str = input;

	return *this;
}

String& String::WriteToConsole() {

	cout << this->str << endl;

	return *this;
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