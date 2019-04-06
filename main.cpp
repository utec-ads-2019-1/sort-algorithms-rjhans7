#include <iostream>
#include <assert.h>
#include <string>

#include "mocker.cpp"
#include "tester.cpp"
#include "bubble.h"
#include "select.h"
#include "insert.h"
#include "shell.h"
#include "quick.h"
#include "merge.h"

using namespace std;

#define NUMBER_OF_TESTS 100

Mocker mocker;

void executeTests();
void printArray(int *, size_t);
void compareIntegers(void *, void *);

int main(int argc, char* argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tSorts Practice" << endl;
    cout << "===========================================================" << endl << endl;

    executeTests();

    return EXIT_SUCCESS;
}

void compareIntegers(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}

void executeTests() {
    for (int i = 0; i < NUMBER_OF_TESTS; ++i) {
        size_t size = mocker.generateRandomInt();
        int *array = mocker.generateRandomIntArray(size);
        Tester::integerSorts(array, size, compareIntegers);
        cout << "Passed test: " << i + 1 << endl;
    }
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
