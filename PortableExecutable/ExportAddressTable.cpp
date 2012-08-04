 #include "PortableExecutable.h"


PortableExecutable::ExportAddressTable::ExportAddressTable() {

}

PortableExecutable::ExportAddressTable::ExportAddressTable(DWORD dwVirtualAddress, DWORD dwSize, const IMAGE_EXPORT_DIRECTORY& imageExportDirectory)
	: m_virtualAddress(dwVirtualAddress), m_size(dwSize), m_imageExportDirectory(imageExportDirectory) {

}

DWORD& PortableExecutable::ExportAddressTable::VirtualAddress() {
	return m_virtualAddress;
}
DWORD& PortableExecutable::ExportAddressTable::Size() {
	return m_size;
}
IMAGE_EXPORT_DIRECTORY& PortableExecutable::ExportAddressTable::ImageExportDirectory() {
	return m_imageExportDirectory;
}

std::vector< PortableExecutable::Export >& PortableExecutable::ExportAddressTable::Exports() {
	return m_exports;
}

const DWORD& PortableExecutable::ExportAddressTable::VirtualAddress() const {
	return m_virtualAddress;
}

const DWORD& PortableExecutable::ExportAddressTable::Size() const {
	return m_size;
}

const IMAGE_EXPORT_DIRECTORY& PortableExecutable::ExportAddressTable::ImageExportDirectory() const {
	return m_imageExportDirectory;
}

const std::vector< PortableExecutable::Export >& PortableExecutable::ExportAddressTable::Exports() const {
	return m_exports;
}
