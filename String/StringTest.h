#pragma once
class StringTest
{
public:
	StringTest();
	~StringTest();

	void TestStringClass();

	void WriteTestResultsToFile();

private:
	bool testLength;
	bool testCharacterAt;
	bool testFind;
	bool testReplace;
	bool testToLowerToUpper;
	bool testEqualTo;
	bool testAppendPrepend;
	bool testCStr;
	bool testReadFromConsole;

	int testPercentage;
};

