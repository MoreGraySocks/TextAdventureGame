#define _CRT_SECURE_NO_WARNINGS
#include "StringTest.h"
#include "String.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <chrono> 

StringTest::StringTest() {}
StringTest::~StringTest() {}

void StringTest::TestStringClass() {


	String* str1 = new String();
	str1->str = "Platinum";

	String* str2 = new String();
	str2->str = "Gold";

	String* str3 = new String("Diamond");

	String* str4 = new String(*str1);

	String* phrase = new String("I am a Diamond");

	String* phrase2 = new String("Diamond Diamond");

	testLength = false;
	testCharacterAt = false;
	testFind = false;
	testReplace = false;
	testToLowerToUpper = false;
	testEqualTo = false;
	testAppendPrepend = false;
	testCStr = false;
	testReadFromConsole = false;

	cout << "strings:" << endl;
	str1->WriteToConsole();        //testing constructors //testing write to console
	str2->WriteToConsole();
	str3->WriteToConsole();
	str4->WriteToConsole();
	phrase->WriteToConsole();
	phrase2->WriteToConsole(); cout << endl;

	str3->WriteToConsole();                //testing length     
	cout << "length should be 7. Length:" << str3->Length() << endl; cout << endl;
	if (str3->Length() == 7) { testLength = true; }

	cout << "char should be d. Char:";
	cout << str3->CharacterAt(str3->Length() - 1) << endl;                  //testing character at //within index
	cout << "char should be d. Char:";
	cout << str2->CharacterAt(str3->Length() - 1) << endl; cout << endl;    //outside index
	if (str3->CharacterAt(str3->Length() - 1) == 'd' && str2->CharacterAt(str3->Length() - 1) == '0') { testCharacterAt = true; }

	cout << "index should be 7. Index:" << phrase->Find(*str3) << endl;                       //testing find
	cout << "index should be 8. Index:" << phrase2->Find(7, *str3) << endl; cout << endl;     //testing find at index
	if (phrase->Find(*str3) == 7 && phrase2->Find(7, *str3) == 8) { testFind = true; }

	phrase2->WriteToConsole();
	phrase2->Replace("Diamond", "Emerald");      //testing replace //same length
	phrase2->WriteToConsole();
	if (phrase2->str == "Emerald Emerald") { testReplace = true; }
	phrase2->Replace("Emerald", "Opal");         //shorter
	phrase2->WriteToConsole();
	if (phrase2->str != "Opal Opal" || testReplace == false) { testReplace = false; }
	phrase2->Replace("Opal", "Sapphire");        //longer
	phrase2->WriteToConsole(); cout << endl;
	if (phrase2->str != "Sapphire Sapphire" || testReplace == false) { testReplace = false; }

	str2->ToLower();                       //testing to lower
	str2->WriteToConsole();
	if (str2->str == "gold") { testToLowerToUpper = true; }
	str2->ToUpper();                       //testing to upper
	str2->WriteToConsole(); cout << endl;
	if (str2->str != "GOLD" || testToLowerToUpper == false) { testToLowerToUpper = false; }

	cout << str1->EqualTo(*str2) << endl;                 //testing equal to  //false
	if (str1->EqualTo(*str2) == false) { testEqualTo = true; }
	cout << str1->EqualTo(*str4) << endl; cout << endl;   //true
	if (str1->EqualTo(*str4) != true || testEqualTo == false) { testEqualTo = false; }

	str1->WriteToConsole(); 
	str1->Append(*str3);                  //testing append
	str1->WriteToConsole(); 
	if (str1->str == "PlatinumDiamond") { testAppendPrepend = true; }
	str1->Prepend(*str3);                 //testing prepend
	str1->WriteToConsole(); cout << endl;
	if (str1->str != "DiamondPlatinumDiamond" || testAppendPrepend == false) { testAppendPrepend = false; }

	cout << str3->CStr() << endl; cout << endl;       //testing c str
	if (str3->CStr() == str3->str) { testCStr = true; }

	cout << "Write Something" << endl;
	str1->ReadFromConsole();             //testing read from console
	str1->WriteToConsole();
	cout << "Was the output correct? t/f" << endl;
	String* input = new String();
	cin >> input->str;
	cout << endl;

	input->ToLower();
	if (input->str == "true" || input->str == "t") { testReadFromConsole = true; }
	/*time_t now = time(NULL);
	String time;
	time.str = printf("%s", ctime(&now));*/

	auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
 
    time_t end_time = chrono::system_clock::to_time_t(end);
 

	cout << "Test completed: " << ctime(&end_time) << endl;
	cout << "The test results are: (0 = failure, 1 = success)" << endl;
	cout << "Length:" << testLength << endl;
	cout << "Character At:" << testCharacterAt << endl;
	cout << "Find:" << testFind << endl;
	cout << "Replace:" << testReplace << endl;
	cout << "To Lower and To Upper:" << testToLowerToUpper << endl;
	cout << "Equal To:" << testEqualTo << endl;
	cout << "Append and Prepend:" << testAppendPrepend << endl;
	cout << "C String:" << testCStr << endl;
	cout << "Read From Console:" << testReadFromConsole << endl;

	float counter = 0;
	if (testLength) { counter++; }
	if (testCharacterAt) { counter++; }
	if (testFind) { counter++; }
	if (testReplace) { counter++; }
	if (testToLowerToUpper) { counter++; }
	if (testEqualTo) { counter++; }
	if (testAppendPrepend) { counter++; }
	if (testCStr) { counter++; }
	if (testReadFromConsole) { counter++; }

	testPercentage = (counter / 9) * 100;
	cout << testPercentage << "% Success" << endl;

	//remember assign to nullptr & delete
	str1 = nullptr;
	delete str1;
	str2 = nullptr;
	delete str2;
	str3 = nullptr;
	delete str3;
	str4 = nullptr;
	delete str4;
	phrase = nullptr;
	delete phrase;
	phrase2 = nullptr;
	delete phrase2;
	input = nullptr;
	delete input;

	cout << "end of code" << endl;
}

void StringTest::WriteTestResultsToFile() {
	std::ofstream out;
	out.open("string_test_results.txt", std::ios::app);

	if (out.is_open()) {
		auto start = chrono::system_clock::now();
		auto end = chrono::system_clock::now();

		time_t end_time = chrono::system_clock::to_time_t(end);


		out << "\nTest completed: " << ctime(&end_time);
		out << "The test results are: (0 = failure, 1 = success)" << endl;
		out << "Length:" << testLength << endl;
		out << "Character At:" << testCharacterAt << endl;
		out << "Find:" << testFind << endl;
		out << "Replace:" << testReplace << endl;
		out << "To Lower and To Upper:" << testToLowerToUpper << endl;
		out << "Equal To:" << testEqualTo << endl;
		out << "Append and Prepend:" << testAppendPrepend << endl;
		out << "C String:" << testCStr << endl;
		out << "Read From Console:" << testReadFromConsole << endl;

		float counter = 0;
		if (testLength) { counter++; }
		if (testCharacterAt) { counter++; }
		if (testFind) { counter++; }
		if (testReplace) { counter++; }
		if (testToLowerToUpper) { counter++; }
		if (testEqualTo) { counter++; }
		if (testAppendPrepend) { counter++; }
		if (testCStr) { counter++; }
		if (testReadFromConsole) { counter++; }

		testPercentage = (counter / 9) * 100;
		out << testPercentage << "% Success" << endl;
	}
	else {
		cout << "Could not save to file" << endl;
	}
	out.flush();
	out.close();
}
