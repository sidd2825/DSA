#include<iostream>
using namespace std;

class tree {
public:
    int a[20][20], visited[20];
    int v, e;

    tree() {
        for (int i = 0; i < 20; i++) {
            visited[i] = 0;
            for (int j = 0; j < 20; j++) {
                a[i][j] = 999;
            }
        }
    }

    void input();
    void display();
    void minimum();
};

void tree::input() {
    int l, u, w;
    cout << "Enter the number of branches (vertices): ";
    cin >> v;

    cout << "\nEnter the number of connections (edges): ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter the two branches connected (e.g., 1 2): ";
        cin >> l >> u;

        cout << "Enter the phone company charges for this connection: ";
        cin >> w;

        a[l - 1][u - 1] = a[u - 1][l - 1] = w;
    }
}

void tree::display() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (a[i][j] == 999)
                cout << "8"
                     << "\t";
            else
                cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void tree::minimum() {
    int total = 0;
    visited[0] = 1;

    for (int count = 0; count < v - 1; count++) {
        int min = 999, p = -1, q = -1;

        for (int i = 0; i < v; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < v; j++) {
                    if (visited[j] == 0 && a[i][j] < min) {
                        min = a[i][j];
                        p = i;
                        q = j;
                    }
                }
            }
        }

        if (p != -1 && q != -1) {
            visited[q] = 1;
            cout << "Minimum cost connection is " << (p + 1) << " -> " << (q + 1)
                 << "  with charge: " << min << endl;
            total += min;
        }
    }

    cout << "The minimum total cost of connecting all branches is: " << total << endl;
}

int main() {
    int ch;
    tree t;

    do {
        cout << "\n========== PRIM'S ALGORITHM ==========\n";
        cout << "1. Input\n2. Display\n3. Minimum\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\n******* INPUT YOUR VALUES *******\n";
            t.input();
            break;
        case 2:
            cout << "\n******* DISPLAY THE MATRIX *******\n";
            t.display();
            break;
        case 3:
            cout << "\n******* MINIMUM SPANNING TREE *******\n";
            t.minimum();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 4);

    return 0;
}

