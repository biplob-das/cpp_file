#include<bits/stdc++.h>
using namespace std;

int p[100]; // Profit array
int w[100]; // Weight array
float r[100]; // Profit-to-weight ratio array

// Function to calculate the profit-to-weight ratio
void Ratio(int n) {
    for (int i = 0; i < n; i++) {
        r[i] = (float)p[i] / (float)w[i];
    }
}

// Knapsack function (assuming arrays are pre-sorted)
void Knapsack(int n, int m) {
    Ratio(n);
    int sum = 0; // To store the total profit
    int i;

    for (i = 0; i < n; i++) {
        if (w[i] > m) {
            break;
        } else {
            sum += p[i];
            m -= w[i];
        }
    }

    // Adding the fractional part of the profit (if needed)
    if (i < n) {
        sum += r[i] * m;
    }

    // Printing the results
    cout << "The max profit is: " << sum << endl;
    cout << "Solution vector:" << endl;
    for (int j = 0; j < n; j++) {
        cout << r[j] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter m (capacity of knapsack) and n (number of items):" << endl;
    cin >> m >> n;

    cout << "Enter profit array (sorted by profit-to-weight ratio in descending order):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Enter weight array (corresponding weights of the items):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    Knapsack(n, m);

    return 0;
}
