#include "PortableExecutable.h"

PortableExecutable::Import::Import() {

}

DWORD& PortableExecutable::Import::Ordinal() {
	return m_ordinal;
}

const DWORD& PortableExecutable::Import::Ordinal() const {
	return m_ordinal;
}

std::string& PortableExecutable::Import::Name() {
	return m_name;
}

DWORD& PortableExecutable::Import::OriginalVirtualAddressLocation() {
	return m_originalVirtualAddressLocation;
}

DWORD& PortableExecutable::Import::Type() {
	return m_type;
}
