#include "IntVector.h"
#include "IntVectorIterator.h"
#include <stdexcept>

using namespace std;

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
	fNumberOfElements = aNumberOfElements;
	fElements = new int[fNumberOfElements];

	for (size_t i = 0; i < fNumberOfElements; i++)
	{
		fElements[i] = aArrayOfIntegers[i];
	}
}

IntVector::~IntVector()
{
	delete[] fElements;
}

size_t IntVector::size() const
{
	return fNumberOfElements;
}

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex)
{
	if (aSourceIndex < fNumberOfElements && aTargetIndex < fNumberOfElements) 
	{
		int temp = fElements[aSourceIndex];
		fElements[aSourceIndex] = fElements[aTargetIndex];
		fElements[aTargetIndex] = temp;
	}
	else 
	{
		throw out_of_range("Illegal vector indices");
	}
}

void IntVector::sort(const IntSorter& aSorter)
{
	aSorter(*this);
}

const int IntVector::operator[](size_t aIndex) const
{
	if (aIndex < fNumberOfElements)
	{
		return fElements[aIndex];
	}

	throw out_of_range("Invalid index.");
}

IntVectorIterator IntVector::begin() const
{
	return IntVectorIterator(*this);
}

IntVectorIterator IntVector::end() const
{
	return IntVectorIterator(*this, size());
}

