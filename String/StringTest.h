#pragma once
class StringTest
{
public:
	StringTest();
	~StringTest();

	void TestStringClass();

	void WriteTestResultsToFile();

private:
	bool testLength = false;
	bool testCharacterAt = false;
	bool testFind = false;
	bool testReplace = false;
	bool testToLowerToUpper = false;
	bool testEqualTo = false;
	bool testAppendPrepend = false;
	bool testCStr = false;
	bool testReadFromConsole = false;
};

