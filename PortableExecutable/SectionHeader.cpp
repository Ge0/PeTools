#include "PortableExecutable.h"

PortableExecutable::SectionHeader::SectionHeader() {

}

PortableExecutable::SectionHeader& PortableExecutable::SectionHeader::operator=(const IMAGE_SECTION_HEADER& structImageSectionHeader) {
	m_imageSectionHeader = structImageSectionHeader;
	return *this;
}

std::string PortableExecutable::SectionHeader::GetName() const {
	return std::string((const char*)m_imageSectionHeader.Name);
}

DWORD PortableExecutable::SectionHeader::GetVirtualSize() const {
	return m_imageSectionHeader.Misc.VirtualSize;
}

DWORD PortableExecutable::SectionHeader::GetVirtualAddress() const {
	return m_imageSectionHeader.VirtualAddress;
}

DWORD PortableExecutable::SectionHeader::GetSizeOfRawData() const {
	return m_imageSectionHeader.SizeOfRawData;
}

DWORD PortableExecutable::SectionHeader::GetPointerToRawData() const {
	return m_imageSectionHeader.PointerToRawData;
}

DWORD PortableExecutable::SectionHeader::GetPointerToRelocations() const {
	return m_imageSectionHeader.PointerToRelocations;
}

DWORD PortableExecutable::SectionHeader::GetPointerToLineNumbers() const {
	return m_imageSectionHeader.PointerToLinenumbers;
}

WORD PortableExecutable::SectionHeader::GetNumberOfRelocations() const {
	return m_imageSectionHeader.NumberOfRelocations;
}

WORD PortableExecutable::SectionHeader::GetNumberOfLineNumbers() const {
	return m_imageSectionHeader.NumberOfLinenumbers;
}

DWORD PortableExecutable::SectionHeader::GetCharacteristics() const {
	return m_imageSectionHeader.Characteristics;
}

VOID PortableExecutable::SectionHeader::SetName(LPSTR szNewName) {
	memset(m_imageSectionHeader.Name, '\0', 8);
	::strcpy_s((char*)m_imageSectionHeader.Name, 7, (LPSTR)szNewName);
	m_imageSectionHeader.Name[7] = '\0';
}

VOID PortableExecutable::SectionHeader::SetVirtualSize(DWORD dwNewVirtualSize) {
	m_imageSectionHeader.Misc.VirtualSize = dwNewVirtualSize;
}

VOID PortableExecutable::SectionHeader::SetVirtualAddress(DWORD dwNewVirtualAddress) {
	m_imageSectionHeader.VirtualAddress = dwNewVirtualAddress;
}

VOID PortableExecutable::SectionHeader::SetSizeOfRawData(DWORD dwNewSizeOfRawData) {
	m_imageSectionHeader.SizeOfRawData = dwNewSizeOfRawData;
}

VOID PortableExecutable::SectionHeader::SetPointerToRawData(DWORD dwNewPointerToRawData) {
	m_imageSectionHeader.PointerToRawData = dwNewPointerToRawData;
}

VOID PortableExecutable::SectionHeader::SetPointerToRelocations(DWORD dwNewPointerToRelocations) {
	m_imageSectionHeader.PointerToRelocations = dwNewPointerToRelocations;
}

VOID PortableExecutable::SectionHeader::SetPointerToLineNumbers(DWORD dwPointerToLineNumbers) {
	m_imageSectionHeader.PointerToLinenumbers = dwPointerToLineNumbers;
}

VOID PortableExecutable::SectionHeader::SetNumberOfRelocations(WORD wNewNumberOfRelocations) {
	m_imageSectionHeader.NumberOfRelocations = wNewNumberOfRelocations;
}

VOID PortableExecutable::SectionHeader::SetNumberOfLineNumbers(WORD wNewNumberOfLineNumbers) {
	m_imageSectionHeader.NumberOfLinenumbers = wNewNumberOfLineNumbers;
}

VOID PortableExecutable::SectionHeader::SetCharacteristics(DWORD dwNewCharacteristics) {
	m_imageSectionHeader.Characteristics = dwNewCharacteristics;
}
