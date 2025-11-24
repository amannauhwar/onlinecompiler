#include <iostream> [cite: 436]
#include <queue> [cite: 437]
using namespace std; [cite: 438]

int main() { [cite: 439]
    priority_queue<int> pq; // max-priority queue [cite: 440]

    // Insertion [cite: 441]
    pq.push(50); [cite: 442]
    pq.push(30); [cite: 443]
    pq.push(40); [cite: 444]
    pq.push(10); [cite: 445]

    cout << "Priority Queue (Max first): "; [cite: 446]
    priority_queue<int> temp = pq; [cite: 447]
    while (!temp.empty()) { [cite: 448]
        cout << temp.top() << " "; [cite: 449]
        temp.pop(); [cite: 450]
    } [cite: 451]
    cout << endl; [cite: 452]

    // Deletion (removes highest priority) [cite: 453]
    cout << "Deleted: " << pq.top() << endl; [cite: 454]
    pq.pop(); [cite: 454]

    cout << "After Deletion: "; [cite: 455]
    temp = pq; [cite: 456]
    while (!temp.empty()) { [cite: 459]
        cout << temp.top() << " "; [cite: 460]
        temp.pop(); [cite: 461]
    } [cite: 462]

    return 0; [cite: 463]
} [cite: 464]