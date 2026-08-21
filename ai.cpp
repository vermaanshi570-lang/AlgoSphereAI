#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


// ==================================================
// LOWER CASE
// ==================================================

string lowerCase(string text)
{
    transform(
        text.begin(),
        text.end(),
        text.begin(),
        [](unsigned char c)
        {
            return tolower(c);
        }
    );

    return text;
}


// ==================================================
// DIFFICULTY DETECTION
// ==================================================

string detectDifficulty(string pattern, string problem)
{
    // HARD patterns
    if (
        pattern == "Dynamic Programming" ||
        pattern == "Graph Traversal" ||
        pattern == "Backtracking"
    )
    {
        return "Hard";
    }

    // EASY patterns
    if (
        pattern == "Array Traversal / Pattern Recognition" ||
        pattern == "Linked List Traversal" ||
        pattern == "Stack / LIFO" ||
        pattern == "Queue / FIFO" ||
        pattern == "Sorting"
    )
    {
        return "Easy";
    }

    // Medium by default
    return "Medium";
}


// ==================================================
// PRINT AI ANALYSIS
// ==================================================

void printAnalysis(
    string topic,
    string pattern,
    string approach,
    string hint,
    string solution,
    string time,
    string space,
    string explanation,
    string problemAnalysis)
{
    string difficulty =
        detectDifficulty(pattern, problemAnalysis);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                 AI ANALYSIS" << endl;
    cout << "==================================================" << endl;

    cout << endl;

    cout << "PROBLEM ANALYSIS:" << endl;
    cout << problemAnalysis << endl;

    cout << endl;

    cout << "DIFFICULTY:" << endl;
    cout << difficulty << endl;

    cout << endl;

    cout << "DSA TOPIC:" << endl;
    cout << topic << endl;

    cout << endl;

    cout << "PATTERN / ALGORITHM:" << endl;
    cout << pattern << endl;

    cout << endl;

    cout << "RECOMMENDED APPROACH:" << endl;
    cout << approach << endl;

    cout << endl;

    cout << "HINT:" << endl;
    cout << hint << endl;

    cout << endl;

    cout << "C++ SOLUTION:" << endl;
    cout << solution << endl;

    cout << endl;

    cout << "TIME COMPLEXITY:" << endl;
    cout << time << endl;

    cout << endl;

    cout << "SPACE COMPLEXITY:" << endl;
    cout << space << endl;

    cout << endl;

    cout << "AI EXPLANATION:" << endl;
    cout << explanation << endl;

    cout << endl;
    cout << "==================================================" << endl;
}


// ==================================================
// AI ASSISTANT
// ==================================================

void aiAssistant()
{
    cout << endl;

    cout << "==================================================" << endl;
    cout << "                  ALGOSPHERE AI" << endl;
    cout << "             DSA INTELLIGENT ASSISTANT" << endl;
    cout << "==================================================" << endl;

    cin.ignore(10000, '\n');

    string problem;

    cout << endl;
    cout << "Enter your DSA problem: ";

    getline(cin, problem);

    if (problem.empty())
    {
        cout << endl;
        cout << "Please enter a valid DSA problem." << endl;
        return;
    }

    string p = lowerCase(problem);

    cout << endl;
    cout << "Analyzing problem..." << endl;


    // ==================================================
    // KADANE'S ALGORITHM
    // ==================================================

    if (
        p.find("maximum subarray") != string::npos ||
        p.find("maximum sum subarray") != string::npos ||
        p.find("maximum sub-array") != string::npos ||
        p.find("largest subarray sum") != string::npos ||
        p.find("maximum sub array sum") != string::npos
    )
    {
        printAnalysis(

            "Array / Dynamic Programming",

            "Kadane's Algorithm",

            "Maintain the maximum subarray sum ending at "
            "the current position. At every element, decide "
            "whether to continue the previous subarray or "
            "start a new subarray.",

            "If currentSum + current element is worse than "
            "starting from the current element, start a new "
            "subarray.",

            R"(#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& arr)
{
    int currentSum = arr[0];
    int maximumSum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        currentSum =
            max(arr[i],
                currentSum + arr[i]);

        maximumSum =
            max(maximumSum,
                currentSum);
    }

    return maximumSum;
})",

            "O(n)",

            "O(1)",

            "Kadane's Algorithm avoids checking every "
            "possible subarray. We keep the best sum ending "
            "at the current position. If extending the "
            "previous subarray is harmful, we start a new "
            "subarray from the current element.",

            "The problem asks us to find the contiguous "
            "subarray having the maximum possible sum."
        );

        return;
    }


    // ==================================================
    // PREFIX SUM
    // ==================================================

    if (
        p.find("prefix sum") != string::npos ||
        p.find("range sum") != string::npos ||
        p.find("sum between index") != string::npos ||
        p.find("sum from l to r") != string::npos ||
        p.find("range query") != string::npos ||
        p.find("range queries") != string::npos
    )
    {
        printAnalysis(

            "Array / Prefix Sum",

            "Prefix Sum",

            "Build a prefix sum array where every position "
            "stores the cumulative sum from the beginning "
            "up to that index.",

            "For a range [L, R], use prefix[R] - prefix[L-1]. "
            "If L is 0, simply use prefix[R].",

            R"(#include <bits/stdc++.h>
using namespace std;

vector<long long> buildPrefix(
    vector<int>& arr)
{
    int n = arr.size();

    vector<long long> prefix(n);

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] =
            prefix[i - 1] + arr[i];
    }

    return prefix;
}

long long rangeSum(
    vector<long long>& prefix,
    int L,
    int R)
{
    if (L == 0)
        return prefix[R];

    return prefix[R]
         - prefix[L - 1];
})",

            "O(n) preprocessing, O(1) per query",

            "O(n)",

            "Prefix Sum stores cumulative information. "
            "After preprocessing, a range sum can be "
            "calculated in constant time without traversing "
            "the complete range again.",

            "The problem involves calculating sums over "
            "one or more ranges of an array efficiently."
        );

        return;
    }


    // ==================================================
    // UNSORTED TWO SUM
    // IMPORTANT: CHECK UNSORTED FIRST
    // ==================================================

    bool isUnsorted =
        p.find("unsorted") != string::npos;


    if (
        isUnsorted &&
        (
            p.find("two numbers") != string::npos ||
            p.find("two number") != string::npos ||
            p.find("two sum") != string::npos ||
            p.find("pair") != string::npos ||
            p.find("sum equal to target") != string::npos ||
            p.find("sum equals a target") != string::npos
        )
    )
    {
        printAnalysis(

            "Array / Hashing",

            "Hash Map / Two Sum",

            "Traverse the array once. For every element, "
            "calculate the number required to reach the "
            "target and check whether that number has "
            "already appeared in the hash map.",

            "For current value x, calculate "
            "required = target - x. If required already "
            "exists, the required pair has been found.",

            R"(#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(
    vector<int>& arr,
    int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        int required =
            target - arr[i];

        if (mp.find(required) != mp.end())
        {
            return {
                mp[required],
                i
            };
        }

        mp[arr[i]] = i;
    }

    return {};
})",

            "O(n) average",

            "O(n)",

            "Because the array is unsorted, the normal "
            "two-pointer technique cannot directly be used. "
            "A hash map allows us to remember previous "
            "elements and find the required complement in "
            "O(1) average time.",

            "The problem asks us to find two numbers whose "
            "sum equals a target in an unsorted array."
        );

        return;
    }


    // ==================================================
    // SORTED TWO POINTER
    // ==================================================

    if (
        !isUnsorted &&
        (
            p.find("two numbers") != string::npos ||
            p.find("two number") != string::npos ||
            p.find("two pointer") != string::npos ||
            p.find("pair") != string::npos ||
            p.find("two sum") != string::npos ||
            p.find("sum equal to target") != string::npos ||
            p.find("sum equals a target") != string::npos ||
            p.find("sorted array") != string::npos
        )
    )
    {
        printAnalysis(

            "Array / Two Pointer",

            "Two Pointer",

            "Place one pointer at the beginning and another "
            "at the end. Compare their sum with the target "
            "and move the appropriate pointer.",

            "If the current sum is smaller than the target, "
            "move the left pointer forward. If the sum is "
            "greater, move the right pointer backward.",

            R"(#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(
    vector<int>& arr,
    int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int sum =
            arr[left] + arr[right];

        if (sum == target)
        {
            return {
                arr[left],
                arr[right]
            };
        }

        if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {};
})",

            "O(n)",

            "O(1)",

            "Because the array is sorted, we can use two "
            "pointers. The left pointer represents the "
            "smaller value and the right pointer represents "
            "the larger value. Every pointer moves only in "
            "one direction, so the total time complexity "
            "is O(n).",

            "The problem asks us to find two elements whose "
            "sum equals a target. The array is sorted, so "
            "the two-pointer technique can be applied "
            "efficiently."
        );

        return;
    }


    // ==================================================
    // SLIDING WINDOW
    // ==================================================

    if (
        p.find("sliding window") != string::npos ||
        p.find("maximum window") != string::npos ||
        p.find("window size") != string::npos ||
        p.find("longest subarray") != string::npos
    )
    {
        printAnalysis(

            "Array / Sliding Window",

            "Sliding Window",

            "Maintain a window over the array instead of "
            "checking every possible subarray separately.",

            "Expand the right side of the window and shrink "
            "the left side whenever the required condition "
            "is violated.",

            R"(#include <bits/stdc++.h>
using namespace std;

int maximumWindowSum(
    vector<int>& arr,
    int k)
{
    int windowSum = 0;

    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int answer = windowSum;

    for (int i = k; i < arr.size(); i++)
    {
        windowSum += arr[i];
        windowSum -= arr[i - k];

        answer =
            max(answer, windowSum);
    }

    return answer;
})",

            "O(n)",

            "O(1)",

            "Sliding Window avoids recalculating the whole "
            "window again. When the window moves, we add "
            "the new element and remove the old element.",

            "The problem involves a contiguous range or "
            "window that needs to be expanded and/or "
            "shrunk efficiently."
        );

        return;
    }


    // ==================================================
    // HASHING
    // ==================================================

    if (
        p.find("duplicate") != string::npos ||
        p.find("frequency") != string::npos ||
        p.find("frequencies") != string::npos ||
        p.find("count occurrences") != string::npos ||
        p.find("hash map") != string::npos ||
        p.find("hash set") != string::npos
    )
    {
        printAnalysis(

            "Hashing",

            "Hash Map / Hash Set",

            "Use a hash map or hash set to store previously "
            "seen values or frequencies.",

            "Ask yourself what information should be stored "
            "while traversing the array.",

            R"(#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int>
getFrequency(vector<int>& arr)
{
    unordered_map<int, int> frequency;

    for (int x : arr)
    {
        frequency[x]++;
    }

    return frequency;
})",

            "O(n) average",

            "O(n)",

            "Hashing provides approximately constant-time "
            "lookup on average. This makes it useful for "
            "frequency counting, duplicate detection and "
            "complement-based problems.",

            "The problem requires storing information about "
            "elements so that it can be accessed quickly."
        );

        return;
    }


    // ==================================================
    // BINARY SEARCH
    // ==================================================

    if (
        p.find("binary search") != string::npos ||
        p.find("search in sorted") != string::npos ||
        p.find("sorted array") != string::npos ||
        p.find("find target in sorted") != string::npos
    )
    {
        printAnalysis(

            "Searching / Sorted Array",

            "Binary Search",

            "Repeatedly divide the search space into two "
            "halves.",

            "Compare the target with the middle element. "
            "Discard the half that cannot contain the target.",

            R"(#include <bits/stdc++.h>
using namespace std;

int binarySearch(
    vector<int>& arr,
    int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid =
            left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
})",

            "O(log n)",

            "O(1)",

            "Binary Search works because the array is sorted. "
            "Every comparison eliminates approximately half "
            "of the remaining search space.",

            "The problem asks us to search for an element "
            "inside sorted data."
        );

        return;
    }


    // ==================================================
    // SORTING
    // ==================================================

    if (
        p.find("sorting") != string::npos ||
        p.find("sort the array") != string::npos ||
        p.find("sort array") != string::npos ||
        p.find("sort elements") != string::npos
    )
    {
        printAnalysis(

            "Array / Sorting",

            "Sorting",

            "Arrange the elements in increasing or decreasing "
            "order before performing further operations.",

            "Check whether sorting can simplify the problem "
            "or make another technique possible.",

            R"(#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
})",

            "O(n log n)",

            "O(log n) auxiliary stack on average",

            "Sorting organizes the data and can make many "
            "problems easier, including two pointer, binary "
            "search and greedy problems.",

            "The problem requires arranging elements in a "
            "specific order."
        );

        return;
    }


    // ==================================================
    // LINKED LIST
    // ==================================================

    if (
        p.find("linked list") != string::npos ||
        p.find("linkedlist") != string::npos
    )
    {
        printAnalysis(

            "Linked List",

            "Linked List Traversal",

            "Use node pointers to traverse and manipulate "
            "the linked list.",

            "Follow the next pointer carefully. Handle the "
            "head node separately whenever required.",

            R"(struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void display(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
})",

            "O(n)",

            "O(1)",

            "A linked list stores elements in nodes connected "
            "through pointers. Traversal continues until the "
            "next pointer becomes null.",

            "The problem involves nodes connected through "
            "next pointers."
        );

        return;
    }


    // ==================================================
    // STACK
    // ==================================================

    if (
        p.find("stack") != string::npos ||
        p.find("balanced parentheses") != string::npos ||
        p.find("valid parentheses") != string::npos
    )
    {
        printAnalysis(

            "Stack",

            "Stack / LIFO",

            "Use Last-In-First-Out ordering to process "
            "elements.",

            "Think about whether the most recently inserted "
            "element should be processed first.",

            R"(#include <bits/stdc++.h>
using namespace std;

bool validParentheses(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty())
                return false;

            st.pop();
        }
    }

    return st.empty();
})",

            "O(n)",

            "O(n)",

            "A stack is useful when the most recent element "
            "needs to be accessed first. Parentheses matching "
            "is a classic stack problem.",

            "The problem requires Last-In-First-Out behavior "
            "or matching recently opened elements."
        );

        return;
    }


    // ==================================================
    // QUEUE
    // ==================================================

    if (
        p.find("queue") != string::npos ||
        p.find("fifo") != string::npos
    )
    {
        printAnalysis(

            "Queue",

            "Queue / FIFO",

            "Use First-In-First-Out ordering to process "
            "elements.",

            "The first element inserted should generally "
            "be processed first.",

            R"(#include <bits/stdc++.h>
using namespace std;

void processQueue(queue<int>& q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
})",

            "O(n)",

            "O(n)",

            "A queue follows FIFO ordering. Elements are "
            "inserted from the rear and removed from the front.",

            "The problem requires First-In-First-Out processing."
        );

        return;
    }


    // ==================================================
    // RECURSION
    // ==================================================

    if (
        p.find("recursion") != string::npos ||
        p.find("recursive") != string::npos ||
        p.find("factorial") != string::npos ||
        p.find("fibonacci") != string::npos
    )
    {
        printAnalysis(

            "Recursion",

            "Recursion",

            "Break the problem into smaller instances of "
            "the same problem.",

            "Always identify the base case before writing "
            "the recursive call.",

            R"(long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
})",

            "Depends on problem",

            "Depends on recursion depth",

            "A recursive function calls itself on a smaller "
            "version of the problem. Every recursive solution "
            "must have a proper base case.",

            "The problem can be divided into smaller instances "
            "of the same problem."
        );

        return;
    }


    // ==================================================
    // ARRAY
    // ==================================================

    if (
        p.find("array") != string::npos ||
        p.find("elements") != string::npos
    )
    {
        printAnalysis(

            "Array",

            "Array Traversal / Pattern Recognition",

            "First understand the input, output and constraints. "
            "Then identify whether traversal, hashing, sorting "
            "or another pattern is appropriate.",

            "Look for repeated work that can be optimized.",

            R"(for (int i = 0; i < arr.size(); i++)
{
    cout << arr[i] << " ";
})",

            "Depends on approach",

            "Depends on approach",

            "Arrays provide direct access to elements using "
            "indices. The correct algorithm depends on the "
            "constraints and required operation.",

            "The problem involves processing elements stored "
            "inside an array."
        );

        return;
    }


    // ==================================================
    // DEFAULT
    // ==================================================

    printAnalysis(

        "General DSA",

        "Pattern Recognition",

        "Break the problem into smaller parts and identify "
        "the underlying DSA pattern.",

        "Look for keywords such as array, subarray, pair, "
        "sorted, frequency, stack, queue, linked list, "
        "maximum sum or range query.",

        R"(// First identify:
// 1. Input
// 2. Output
// 3. Constraints
// 4. DSA pattern
// 5. Algorithm
// 6. Complexity)",

        "Depends on algorithm",

        "Depends on algorithm",

        "A good DSA solution starts with understanding the "
        "problem and constraints. Then we identify the "
        "appropriate pattern before writing code.",

        "The given problem does not match a specific "
        "implemented pattern yet."
    );
}