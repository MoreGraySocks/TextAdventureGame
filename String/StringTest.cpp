#include "StringTest.h"
#include "String.h"
#include <iostream>

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

	str1->WriteToConsole();        //testing costructors //testing write to console
	str2->WriteToConsole();
	str3->WriteToConsole();
	str4->WriteToConsole();
	phrase->WriteToConsole();
	phrase2->WriteToConsole(); cout << endl;

	cout << "index should be 7. Index:" << phrase->Find(*str3) << endl;                       //testing find
	cout << "index should be 8. Index:" << phrase2->Find(7, *str3) << endl; cout << endl;     //testing find at index

	phrase2->WriteToConsole();
	phrase2->Replace("Diamond", "Emerald");      //testing replace //same length
	phrase2->WriteToConsole();
	phrase2->Replace("Emerald", "Opal");         //shorter
	phrase2->WriteToConsole();
	phrase2->Replace("Opal", "Sapphire");        //longer
	phrase2->WriteToConsole(); cout << endl;

	str3->WriteToConsole();                //testing length     
	cout << "length:" << str3->Length() << endl; cout << endl;

	str2->ToLower();                       //testing to lower
	str2->WriteToConsole();
	str2->ToUpper();                       //testing to upper
	str2->WriteToConsole(); cout << endl;

	cout << str3->CharacterAt(str3->Length() - 1) << endl;                  //testing character at //within index
	cout << str2->CharacterAt(str3->Length() - 1) << endl; cout << endl;    //outside index

	cout << str1->EqualTo(*str2) << endl;                 //testing equal to  //false
	cout << str1->EqualTo(*str4) << endl; cout << endl;   //true

	str1->WriteToConsole(); 
	str1->Append(*str2);                  //testing append
	str1->WriteToConsole(); 
	str1->Prepend(*str2);                 //testing prepend
	str1->WriteToConsole(); cout << endl;

	cout << str3->CStr() << endl; cout << endl;       //testing c str

	str1->ReadFromConsole();             //testing read from console
	str1->WriteToConsole();              //testing write to console


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

	cout << "end of code" << endl;
}
