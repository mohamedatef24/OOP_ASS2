#include "Machine.h"
#include <bitset>
#include <stdlib.h>

void makeChoice(Machine& chosenMachine) {
	start:
	short choice;
	cout<<"\nPlease pick : \n"
		<< " 1-> Clear memory\n 2-> Load data from file\n 3-> Run\n 4-> Single Step\n 5-> Halt\n 6-> Help\n 7-> Display stats\n-> ";
	cin >> choice;
	if (choice > 7 || choice < 1) exit(404); 
	switch (choice)
	{
	case 1:
		chosenMachine.clear();
		break;
	case 2:
		chosenMachine.loadInstructions();
		break;
	case 3:
		chosenMachine.excute();
		break;
	case(4):
		chosenMachine.sigleStep(1);
		break;
	case 5:
		exit(1);
		break;
	case 6:
		cout << "Op-code: 1. RXY - load R w/ bits from memory XY\n"
			 << "Op-code: 2. RXY - load R w/ bits XY\n"
			 << "Op-code: 3. RXY - store bits in R in memory address XY\n"
			 << "Op-code: 3. R00 - DISPLAY Rigester R on screen\n"
			 << "Op-code: 4. 0RS - move bits in register R to register S\n"
			 << "Op-code: 5. RST - add bits in register S and register T and put it in R ( two�s complement representations )\n"
			 << "Op-code: 6. RST - add bits in register S and register T and put it in R\n"
			 << "Op-code: B. RXY - if bits in R == bits in register 0, jump to memory address XY\n"
			 << "Op-code: C. HALT\n";
		break;
	case 7:
		chosenMachine.print();
		break;
	default:
		cout << "Wrong Entry!\n";
		break;
	}
	goto start;
}

int main() {
	cout << "\t\t====================[Welcome to vole machine simulator Project]====================\n";
	Machine* vole = new Machine;
	makeChoice(*vole); 
}