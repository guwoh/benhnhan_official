#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {0, 1, 2, 3, 4};
    vector<int> b;
    int temp;

    cout << "\nArray before deletion: ";
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    cout << "\nAssign elements of a to b";
    cout << "\nChoose the index of the element to delete (0 to 4): ";
    cin >> temp;

    // Ensure the input is within valid range
    if(temp < 0 || temp >= a.size()) {
        cout << "\nInvalid index!";
        return 1;
    }

    // Copy elements except the one to be deleted
    for(int i = 0; i < a.size(); i++) {
        if(i != temp) {
            b.push_back(a[i]);
        }
    }

    cout << "\nArray after deleting element at index " << temp << ": ";
    for(int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}
