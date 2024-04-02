#include <iostream>
#include <vector>
#include "Queue.h"
#include "RecursiveLinearSearch.h"
#include "InsertionSort.h"

int main() {
    using namespace std;

    Queue<int> queue;
    vector<int> vec = {5, 2, 4, 6, 1, 3};
    int choice, target, lastOccurrence;

    cout << "Vector contents: ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    cout << std::endl;


    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push 10 values into the queue.\n";
        cout << "2. Display all elements in the queue.\n";
        cout << "3. Move the front element to the rear.\n";
        cout << "4. Perform insertion sort on the vector.\n";
        cout << "5. Find the last occurrence of a number in the vector.\n";
        cout << "6. Pop a number from the queue.\n";
        cout << "7. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
          case 1:
              for (int i = 1; i <= 10; ++i) {
                  queue.push(i);
              }
              cout << "10 values pushed into the queue.\n";
              break;
          case 2:
            {Queue<int> tempQueue = queue; // Assuming Queue supports copying
            cout << "Queue contents: ";
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
              cout << endl;
              break;}
          case 3:
              if (queue.size() >= 2) {
                  queue.move_to_rear();
                  cout << "Front element moved to the rear.\n";
              } else {
                  cout << "The queue does not contain enough elements to move.\n";
              }
              break;
            case 4:
                insertionSort(vec);
                cout << "Sorted vector: ";
                for (int val : vec) {
                    cout << val << " ";
                }
                cout << endl;
                break;
            case 5:
                cout << "Enter the target number: ";
                cin >> target;
                lastOccurrence = recursiveLastOccurrence(vec, target);
                cout << "Last occurrence of " << target << ": " << lastOccurrence << endl;
                break;
            case 6:
                if (!queue.empty()) {
                    queue.pop();
                    cout << "A number popped from the queue.\n";
                } else {
                    cout << "The queue is empty.\n";
                }
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
