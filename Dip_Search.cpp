#include <iostream>
#include <vector>
using namespace std;

int dip_search(const std::vector<int>& V) {
    int n = V.size();
    int last_dip = -1;
    for(int i = 0; i <= n-3; ++i) {
        if (V[i] == V[i+2] && V[i+1] < V[i]) {
            last_dip = i;
        }
    }
    return last_dip;
}

int main() {
    vector<int> V;
    int numElements;
    cout << "Enter number of elements: ";
    cin >> numElements;

    V.resize(numElements);

    cout << "Enter the elements: ";
    for(int i = 0; i < numElements; ++i) {
        cin >> V[i];
    }

    int result = dip_search(V);
    cout << "Last dip found at index: " << result << endl;

    return 0;
}