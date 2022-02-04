#include "CocktailShakerSort.h"
#include "IntVector.h"
#include "IntVectorIterator.h"

using namespace std;

void CocktailShakerSort::operator()(IntVector& aContainer) const {
    size_t beginIndex = 0;
    size_t endIndex = aContainer.size() - 1;

    do
    {
        for (int i = beginIndex; i <= endIndex - 1; i++) {
            if (aContainer[i] > aContainer[i + 1]) {
                aContainer.swap(i, i+1);
            }
        }
        endIndex = endIndex - 1;
        for (int i = endIndex; i >= beginIndex + 1; i--) {
            if (aContainer[i] < aContainer[i - 1]) {
                aContainer.swap(i, i-1);
            }
        }
        beginIndex = beginIndex + 1;
    } while (beginIndex < endIndex);
}