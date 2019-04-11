#include "tester.h"

void integersBubble(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}
void integersSelect(void *elements, int start, int size) {
    int *array = (int*) elements;
    int minIndex = start;

    for (int j = start + 1; j < size; j++) {
        if (array[j] < array[minIndex]) {
            minIndex = j;
        }
    }

    swap(array[minIndex], array[start]);
}
void integersInsert(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] < array[second]) {
        swap(array[first], array[second]);
    }
}

void integersShell(void *elements, int start, int gap){
    int *array = (int*) elements;
    int temp =array[start];
    int i;
    for ( i= start; i>=gap && array[i-gap]>temp; i-=gap  )
        array[i]=array[i-gap];
    array[i]=temp;
}


Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        case selectsort: return new SelectSort(array, size);
        case insertsort: return new InsertSort(array, size);
        case shellsort: return new ShellSort(array, size);
        case quicksort: return new QuickSort(array, size);
        case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integersBubble;
        case selectsort: return &integersSelect;
        case insertsort: return &integersInsert;
        case shellsort: return &integersShell;
        default: throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    int temp[size];

    Algorithm algorithm[] = {shellsort /*, selectsort, insertsort, shellsort, quicksort, mergesort*/ };
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}