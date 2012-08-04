#include "PortableExecutable.h"

PortableExecutable::Export::Export() {

}
PortableExecutable::Export::Export(DWORD dwType, const std::string sName, DWORD dwVirtualAddress)
	: m_ordinal(0), m_type(dwType), m_name(sName), m_virtualAddress(dwVirtualAddress) {

}

WORD& PortableExecutable::Export::Ordinal() {
	return m_ordinal;
}

DWORD& PortableExecutable::Export::Type() {
	return m_type;
}

std::string& PortableExecutable::Export::Name() {
	return m_name;
}


DWORD& PortableExecutable::Export::VirtualAddress() {
	return m_virtualAddress;
}

const WORD& PortableExecutable::Export::Ordinal() const {
	return m_ordinal;
}

const DWORD& PortableExecutable::Export::Type() const {
	return m_type;
}

const std::string& PortableExecutable::Export::Name() const {
	return m_name;
}


const DWORD& PortableExecutable::Export::VirtualAddress() const {
	return m_virtualAddress;
}

