#include <iostream>
#include <cstdlib>
#include <Windows.h>

#include "../PortableExecutable/PortableExecutable.h"

using namespace std;

DWORD ParseCharacteristics(LPCTSTR lpCharacteristics);

int main(int argc, char** argv) {
	DWORD dwCharacteristics;
	if(argc < 4) {
		printf("Usage: %s <pe file> <section name> <characteristics>\n", argv[0]);
		ExitProcess(-1);
	}
	
	try {
		dwCharacteristics = ParseCharacteristics(argv[3]);
		PortableExecutable pe(argv[1]);
		
		cout << "[*] Listing section headers." << endl;
		vector<PortableExecutable::SectionHeader>::iterator it = pe.SectionHeaders().begin();

		while(it != pe.SectionHeaders().end()) {
			cout << setw(9) << left << setfill(' ') << it->GetName() <<  " ";
			cout << "0x" << setw(8) << hex << setfill('0') << right << it->GetVirtualAddress() << endl;
			++it;
		}
		cout << "[*] Adding " << argv[2] << " section... with 0x" << ParseCharacteristics(argv[3]) << " in characteristics..." << endl;
		pe.AddSection(argv[2],  dwCharacteristics);
		cout << "[+] Normally done, check your pe!" << endl;
	} catch(const PortableExecutable::Exception& e) {
		cout << e.what() << endl;
		return -1;
	}

	return EXIT_SUCCESS;
}

DWORD ParseCharacteristics(LPCTSTR lpCharacteristics) {
	DWORD dwValue = 0;
	if(strlen(lpCharacteristics) == 10 && _strnicmp("0x", lpCharacteristics, 2) == 0) {
		sscanf_s(lpCharacteristics + 2, "%08X", &dwValue);
	}
	return dwValue;
}