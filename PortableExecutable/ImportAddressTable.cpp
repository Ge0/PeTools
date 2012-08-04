#include "PortableExecutable.h"

PortableExecutable::ImportAddressTable::ImportAddressTable() : m_virtualAddress(-1), m_size(-1) {

}

PortableExecutable::ImportAddressTable::ImportAddressTable(DWORD dwVirtualAddress, DWORD dwVirtualSize)
	: m_virtualAddress(dwVirtualAddress), m_size(dwVirtualSize) {

}

const DWORD& PortableExecutable::ImportAddressTable::VirtualAddress() const {
	return m_virtualAddress;
}

const DWORD& PortableExecutable::ImportAddressTable::Size() const {
	return m_size;
}

DWORD& PortableExecutable::ImportAddressTable::VirtualAddress() {
	return m_virtualAddress;
}

DWORD& PortableExecutable::ImportAddressTable::Size() {
	return m_size;
}

std::vector< PortableExecutable::ImageImportDescriptor >& PortableExecutable::ImportAddressTable::Modules() {
	return m_modules;
}

BOOL PortableExecutable::ImportAddressTable::operator()(const PortableExecutable::Import& i1, const PortableExecutable::Import& i2) const {
	return i1.Ordinal() < i2.Ordinal();
}
