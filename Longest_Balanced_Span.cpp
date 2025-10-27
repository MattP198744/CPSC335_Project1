#include <iostream>
#include <vector>
using namespace std;

pair<int, int> longest_balanced_span(const std::vector<int>& V) {
    pair<int, int> best = {-1, 0};
    int n = V.size();

    for(int s = 0; s < n; s++) {
        int sum = 0;
        for(int e = s+1; e < n; e++) {
            sum += V[e];
            if (sum == 0) {
                int length = (e-1) - s;
                if ((best == make_pair(-1, 0)) || (length > (best.second - best.first))) {
                    best = {s, e-1};
                }
            }
        }
    }
    return best;
}

int main() {
    vector<int> V;
    int numElements;
    cout << "Enter number of elements: ";
    cin >> numElements;

    V.resize(numElements);

    cout << "Enter the elements: ";
    for(int i = 0; i < numElements; i++) {
        cin >> V[i];
    }

    pair<int, int> result = longest_balanced_span(V);
    if (result.first != -1) {
        cout << "Longest balanced span found from index " << result.first << " to " << result.second << endl;
    } else {
        cout << "No balanced span found." << endl;
    }

    return 0;
}