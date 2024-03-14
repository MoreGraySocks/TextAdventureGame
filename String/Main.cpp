#include <iostream>
#include "String.h"

using namespace std;

int main() {
	String* str1 = new String();
	str1->str = "Platinum";

	String* str2 = new String();
	str2->str = "Gold";

	String* str3 = new String("Diamond");

	String* str4 = new String(*str1);

	String* phrase = new String("I am a Diamond");

	String* phrase2 = new String("Diamond Diamond");


	str4->WriteToConsole();

	phrase2->Replace("Diamond", "Emerald");
	phrase2->Replace("Emerald", "Opal");
	phrase2->Replace("Opal", "Sapphire");

	cout << phrase2->str << endl;

	cout << "index should be 7. Index:" << phrase->Find(*str3) << endl;
	cout << "index should be 8. Index:" << phrase2->Find(7, *str3) << endl;

	str3->WriteToConsole(); 
	cout << str3->Length() << endl;

	str2->ToLower();
	str2->WriteToConsole();
	str2->ToUpper();
	str2->WriteToConsole();

	cout << str3->CharacterAt(str3->Length() - 1) << endl;
	cout << str2->CharacterAt(str3->Length() - 1) << endl;

	cout << str1->EqualTo(*str2) << endl;

	cout << str1->str << endl;
	str1->Append(*str2);
	cout << str1->str << endl;
	str1->Prepend(*str2);
	cout << str1->str << endl;

	cout << str3->Length() << endl;
	cout << str3->CStr() << endl;

	str1->ReadFromConsole();
	str1->WriteToConsole();


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