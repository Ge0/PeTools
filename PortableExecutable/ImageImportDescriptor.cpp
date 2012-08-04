#include "PortableExecutable.h"

PortableExecutable::ImageImportDescriptor::ImageImportDescriptor(const IMAGE_IMPORT_DESCRIPTOR& imageImportDescriptor, DWORD dwNumberOfImports) {
	m_imageImportDescriptor = imageImportDescriptor;
	m_numberOfImports = dwNumberOfImports;
}

DWORD& PortableExecutable::ImageImportDescriptor::NumberOfImports() {
	return m_numberOfImports;
}

std::vector< PortableExecutable::Import >& PortableExecutable::ImageImportDescriptor::Imports() {
	return m_imports;
}


DWORD PortableExecutable::ImageImportDescriptor::GetOriginalFirstThunk() const {
	return m_imageImportDescriptor.OriginalFirstThunk;
}


std::string& PortableExecutable::ImageImportDescriptor::Name() {
	return m_moduleName;
}

DWORD PortableExecutable::ImageImportDescriptor::GetFirstThunk() const {
	return m_imageImportDescriptor.FirstThunk;
}
