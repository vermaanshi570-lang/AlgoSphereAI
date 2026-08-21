#include "algorithms.h"

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

// ================= ARRAY =================

void arrayAnalyzer() {

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int maximum = arr[0];
    int minimum = arr[0];

    for (int x : arr) {
        sum += x;
        maximum = max(maximum, x);
        minimum = min(minimum, x);
    }

    cout << "\nArray: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << "\nSum: " << sum;
    cout << "\nMaximum: " << maximum;
    cout << "\nMinimum: " << minimum;
    cout << "\nAverage: " << (double)sum / n << endl;
}


// ================= SEARCHING =================

int linearSearch(const vector<int>& arr, int target) {

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}


int binarySearch(const vector<int>& arr, int target) {

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}


void searchingModule() {

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nChoice: ";

    int choice;
    cin >> choice;

    int result;

    if (choice == 1) {

        result = linearSearch(arr, target);

    }
    else if (choice == 2) {

        sort(arr.begin(), arr.end());

        cout << "\nSorted array: ";

        for (int x : arr) {
            cout << x << " ";
        }

        cout << endl;

        result = binarySearch(arr, target);
    }
    else {

        cout << "Invalid choice.\n";
        return;
    }

    if (result == -1) {
        cout << "Element not found.\n";
    }
    else {
        cout << "Element found at index: "
             << result << endl;
    }
}


// ================= SORTING =================

void bubbleSort(vector<int>& arr) {

    for (int i = 0; i < arr.size() - 1; i++) {

        for (int j = 0;
             j < arr.size() - i - 1;
             j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void selectionSort(vector<int>& arr) {

    for (int i = 0; i < arr.size() - 1; i++) {

        int minIndex = i;

        for (int j = i + 1;
             j < arr.size();
             j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}


void insertionSort(vector<int>& arr) {

    for (int i = 1; i < arr.size(); i++) {

        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = key;
    }
}


void mergeSort(
    vector<int>& arr,
    int left,
    int right
) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);

    mergeSort(arr, mid + 1, right);

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}


void quickSort(
    vector<int>& arr,
    int low,
    int high
) {

    if (low >= high) {
        return;
    }

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {

            i++;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    int pivotIndex = i + 1;

    quickSort(arr, low, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, high);
}


void sortingModule() {

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n1. Bubble Sort";
    cout << "\n2. Selection Sort";
    cout << "\n3. Insertion Sort";
    cout << "\n4. Merge Sort";
    cout << "\n5. Quick Sort";

    cout << "\nChoice: ";

    int choice;
    cin >> choice;

    switch (choice) {

        case 1:
            bubbleSort(arr);
            break;

        case 2:
            selectionSort(arr);
            break;

        case 3:
            insertionSort(arr);
            break;

        case 4:
            mergeSort(arr, 0, n - 1);
            break;

        case 5:
            quickSort(arr, 0, n - 1);
            break;

        default:
            cout << "Invalid choice.\n";
            return;
    }

    cout << "\nSorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;
}


// ================= TWO POINTER =================

void twoPointerModule() {

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target sum: ";
    cin >> target;

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (sum == target) {

            cout << "Pair found: "
                 << arr[left]
                 << " + "
                 << arr[right]
                 << endl;

            return;
        }

        if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "No pair found.\n";
}


// ================= SLIDING WINDOW =================

void slidingWindowModule() {

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter window size: ";
    cin >> k;

    if (k <= 0 || k > n) {

        cout << "Invalid window size.\n";
        return;
    }

    int windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maximumSum = windowSum;

    for (int i = k; i < n; i++) {

        windowSum += arr[i];

        windowSum -= arr[i - k];

        maximumSum =
            max(maximumSum, windowSum);
    }

    cout << "Maximum window sum: "
         << maximumSum
         << endl;
}


// ================= HASHING =================

void hashingModule() {

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    unordered_map<int, int> frequency;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {

        int x;

        cin >> x;

        frequency[x]++;
    }

    cout << "\nFrequency:\n";

    for (auto& item : frequency) {

        cout << item.first
             << " -> "
             << item.second
             << endl;
    }
}


// ================= LINKED LIST =================

Node::Node(int value) {

    data = value;

    next = nullptr;
}


LinkedList::LinkedList() {

    head = nullptr;
}


void LinkedList::insertAtBeginning(int value) {

    Node* newNode =
        new Node(value);

    newNode->next = head;

    head = newNode;
}


void LinkedList::insertAtEnd(int value) {

    Node* newNode =
        new Node(value);

    if (head == nullptr) {

        head = newNode;

        return;
    }

    Node* current = head;

    while (current->next != nullptr) {

        current = current->next;
    }

    current->next = newNode;
}


void LinkedList::deleteValue(int value) {

    if (head == nullptr) {
        return;
    }

    if (head->data == value) {

        Node* temp = head;

        head = head->next;

        delete temp;

        return;
    }

    Node* current = head;

    while (
        current->next != nullptr &&
        current->next->data != value
    ) {

        current = current->next;
    }

    if (current->next != nullptr) {

        Node* temp = current->next;

        current->next =
            current->next->next;

        delete temp;
    }
}


void LinkedList::display() {

    if (head == nullptr) {

        cout << "List is empty.\n";

        return;
    }

    Node* current = head;

    while (current != nullptr) {

        cout << current->data;

        if (current->next != nullptr) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;
}


void linkedListModule() {

    LinkedList list;

    int choice;

    do {

        cout << "\n--- LINKED LIST ---\n";

        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Back\n";

        cout << "Choice: ";

        cin >> choice;

        int value;

        switch (choice) {

            case 1:

                cout << "Value: ";
                cin >> value;

                list.insertAtBeginning(value);

                break;

            case 2:

                cout << "Value: ";
                cin >> value;

                list.insertAtEnd(value);

                break;

            case 3:

                cout << "Value: ";
                cin >> value;

                list.deleteValue(value);

                break;

            case 4:

                list.display();

                break;

            case 5:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}


// ================= STACK =================

void stackModule() {

    stack<int> st;

    int choice;

    do {

        cout << "\n--- STACK ---\n";

        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Back\n";

        cout << "Choice: ";

        cin >> choice;

        int value;

        switch (choice) {

            case 1:

                cout << "Value: ";
                cin >> value;

                st.push(value);

                break;

            case 2:

                if (st.empty()) {

                    cout << "Stack is empty.\n";
                }
                else {

                    cout << "Removed: "
                         << st.top()
                         << endl;

                    st.pop();
                }

                break;

            case 3:

                if (st.empty()) {

                    cout << "Stack is empty.\n";
                }
                else {

                    cout << "Top: "
                         << st.top()
                         << endl;
                }

                break;

            case 4:

                cout << "Size: "
                     << st.size()
                     << endl;

                break;

            case 5:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}


// ================= QUEUE =================

void queueModule() {

    queue<int> q;

    int choice;

    do {

        cout << "\n--- QUEUE ---\n";

        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Back\n";

        cout << "Choice: ";

        cin >> choice;

        int value;

        switch (choice) {

            case 1:

                cout << "Value: ";
                cin >> value;

                q.push(value);

                break;

            case 2:

                if (q.empty()) {

                    cout << "Queue is empty.\n";
                }
                else {

                    cout << "Removed: "
                         << q.front()
                         << endl;

                    q.pop();
                }

                break;

            case 3:

                if (q.empty()) {

                    cout << "Queue is empty.\n";
                }
                else {

                    cout << "Front: "
                         << q.front()
                         << endl;
                }

                break;

            case 4:

                cout << "Size: "
                     << q.size()
                     << endl;

                break;

            case 5:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}


// ================= RECURSION =================

long long factorial(int n) {

    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}


int fibonacci(int n) {

    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1)
         + fibonacci(n - 2);
}


void recursionModule() {

    int n;

    cout << "\nEnter n: ";
    cin >> n;

    if (n < 0) {

        cout << "Enter positive number.\n";

        return;
    }

    cout << "Factorial: "
         << factorial(n)
         << endl;

    cout << "Fibonacci: "
         << fibonacci(n)
         << endl;
}


// ================= COMPLEXITY =================

void showComplexity() {

    cout << "\n=================================\n";
    cout << "       COMPLEXITY ANALYZER\n";
    cout << "=================================\n";

    cout << "Linear Search   : O(n)\n";
    cout << "Binary Search   : O(log n)\n";
    cout << "Bubble Sort     : O(n^2)\n";
    cout << "Selection Sort  : O(n^2)\n";
    cout << "Insertion Sort  : O(n^2)\n";
    cout << "Merge Sort      : O(n log n)\n";
    cout << "Quick Sort      : O(n log n) average\n";
    cout << "Two Pointer     : O(n)\n";
    cout << "Sliding Window  : O(n)\n";
    cout << "Hashing         : O(1) average\n";
    cout << "Linked List     : O(n)\n";
    cout << "Stack           : O(1) push/pop\n";
    cout << "Queue           : O(1) enqueue/dequeue\n";
}


// ================= AI =================

