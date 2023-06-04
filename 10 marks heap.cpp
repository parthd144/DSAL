#include <iostream>
using namespace std;

class Heap {
    private:
        int* heapArray;
        int maxSize;
        int currentSize;

    public:
        Heap(int size) {
                maxSize = size;
            heapArray = new int[maxSize];
            currentSize = 0;
    }

    ~Heap() {
        delete[] heapArray;
    }

    void insert(int value) {
        if (currentSize == maxSize) {
            cout << "Heap is full. Cannot insert value." << endl;
            return;
        }
        heapArray[currentSize] = value;
        trickleUp(currentSize);
        currentSize++;
    }

    int remove() {
        if (currentSize == 0) {
            cout << "Heap is empty. Cannot remove element." << endl;
            return -1;
        }
        int rootValue = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        trickleDown(0);
        return rootValue;
    }

    int getMaximum() {
        if (currentSize == 0) {
            cout << "Heap is empty. No maximum value." << endl;
            return -1;
        }
        return heapArray[0];
    }

    int getMinimum() {
        if (currentSize == 0) {
            cout << "Heap is empty. No minimum value." << endl;
            return -1;
        }
        int minIndex = (currentSize - 2) / 2 + 1;
        for (int i = minIndex + 1; i < currentSize; i++) {
            if (heapArray[i] < heapArray[minIndex]) {
                minIndex = i;
            }
        }
        return heapArray[minIndex];
    }

    private:
        void trickleUp(int index) {
            int parentIndex = (index - 1) / 2;
            int value = heapArray[index];
            while (index > 0 && heapArray[parentIndex] < value) {
                heapArray[index] = heapArray[parentIndex];
                index = parentIndex;
                parentIndex = (index - 1) / 2;
        }
        heapArray[index] = value;
    }

    void trickleDown(int index) {
        int largerChildIndex;
        int value = heapArray[index];
        while (index < currentSize / 2) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = leftChildIndex + 1;
            if (rightChildIndex < currentSize && heapArray[rightChildIndex] > heapArray[leftChildIndex]) {
                largerChildIndex = rightChildIndex;
            } else {
                largerChildIndex = leftChildIndex;
            }
            if (value >= heapArray[largerChildIndex]) {
                break;
            }
            heapArray[index] = heapArray[largerChildIndex];
            index = largerChildIndex;
        }
        heapArray[index] = value;
    }
};

int main() {
    int size;
    cout << "Enter the number of students: ";
    cin >> size;
    Heap heap(size);
    for (int i = 0; i < size; i++) {
        int marks;
        cout << "Enter the marks for student " << (i + 1) << ": ";
        cin >> marks;
        heap.insert(marks);
    }
    int maximum = heap.getMaximum();
    int minimum = heap.getMinimum();
    cout << "Maximum marks: " << maximum << endl;
    cout << "Minimum marks: " << minimum << endl;
    return 0;
}
