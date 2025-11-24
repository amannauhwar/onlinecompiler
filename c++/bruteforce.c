#include <iostream> [cite: 689]
#include <string> [cite: 690]
using namespace std; [cite: 691]

int main() { [cite: 692]
    string text, pattern; [cite: 693]

    cout << "Enter paragraph:\n"; [cite: 694]
    getline(cin, text); [cite: 695]
    cout << "Enter word/pattern to search: "; [cite: 696]
    getline(cin, pattern); [cite: 697]

    int n = text.length(); [cite: 698]
    int m = pattern.length(); [cite: 700]
    bool found = false; [cite: 701]

    // Brute force pattern matching [cite: 702]
    for (int i = 0; i <= n - m; i++) { [cite: 703]
        int j; [cite: 704]
        for (j = 0; j < m; j++) { [cite: 705]
            if (text[i + j] != pattern[j]) [cite: 707]
                break; [cite: 708]
        } [cite: 706]
        if (j == m) { // pattern matched fully [cite: 709]
            cout << "Pattern found at index: " << i << endl; [cite: 711]
            found = true; [cite: 712]
        } [cite: 713]
    } [cite: 714]

    if (!found) [cite: 715]
        cout << "Pattern not found.\n"; [cite: 716]

    return 0; [cite: 717]
} [cite: 718]