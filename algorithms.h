#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

using namespace std;

// Array
void arrayAnalyzer();

// Searching
int linearSearch(const vector<int>& arr, int target);
int binarySearch(const vector<int>& arr, int target);
void searchingModule();

// Sorting
void bubbleSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int left, int right);
void quickSort(vector<int>& arr, int low, int high);
void sortingModule();

// Two Pointer
void twoPointerModule();

// Sliding Window
void slidingWindowModule();

// Hashing
void hashingModule();

// Linked List
struct Node {
    int data;
    Node* next;

    Node(int value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void deleteValue(int value);
    void display();
};

void linkedListModule();

// Stack
void stackModule();

// Queue
void queueModule();

// Recursion
long long factorial(int n);
int fibonacci(int n);
void recursionModule();

// Complexity
void showComplexity();

// AI
void aiAssistant();

#endif