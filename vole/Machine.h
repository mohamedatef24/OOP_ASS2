#pragma once
#include "Memory.h"
#include "Register.h"
#include "Instruction.h"
#include "Counter.h"
#include "IR.h"
//#include "Memory.cpp"
//#include "Register.cpp"
//#include "Instruction.cpp"
//#include "Counter.cpp"
//#include "IR.cpp"
#include <fstream>
#include <vector>
#include <deque>
using namespace std;
class Machine
{
	bool steps;
	vector <Instruction> instructions;
	Memory memory[16][16];
	Register reg[16];
	IR instructionReg;
	Counter counter;
public:
	Machine();

	~Machine();

	void excute();

	void sigleStep(bool single);

	void print();

	void loadInstructions();

	void clear();

	static string toHex(int dec);

	static unsigned short toDec(string hexString);
	
	static unsigned short toDec(char& hexChar);
    
	string fractionToBinary(float fraction, int numBits);
    
	string floattobin(float value);
    
	string binaryToHex(const string& binaryString);
    
	string addBinary(string a, string b);
    
	string int_to_binary(long long num);
    
	long binary_to_int(string Binary_num);

	float floattodec(string binary);
};

