#include <iostream>

#include "antidebug.hpp"

using namespace std;

int AntidebugLayer::process(vector<uint8_t>& data, ClerkSection& extra) {
	cout << "[AntidebugLayer] processing." << endl;
	const uint8_t shellcode[] = {
		0x65, 0x48, 0x8B, 0x04, 0x25, 0x30, 0x00, 0x00, 0x00,
		0x48, 0x8B, 0x48, 0x60,
		0x80, 0x79, 0x02, 0x00,
		0x74, 0x0E,
		0x33, 0xD2,
		0x48, 0x8D, 0x4A, 0xFF,
		0xB8, 0x00, 0x00, 0x00, 0x00,
		0x48, 0xF7, 0xF0
	};
	extra.append(shellcode, sizeof(shellcode));
	cout << "[AntidebugLayer] Finished writing shellcode." << endl;

	return 0;
}
