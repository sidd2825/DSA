#include<iostream>
#include<string.h>
using namespace std;

class flight {
public:
    int am[10][10];
    char city_index[10][10];
    flight();
    int create();
    void display(int city_count);
};

flight::flight() {
    for (int i = 0; i < 10; i++) {
        strcpy(city_index[i], "xx");
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            am[i][j] = 0;
        }
    }
}

int flight::create() {
    int city_count = 0;
    int j, si, di, wt;
    char s[10], d[10], c;

    do {
        cout << "\n\tEnter Source City: ";
        cin >> s;

        cout << "\n\tEnter Destination City: ";
        cin >> d;

        si = -1;
        for (j = 0; j < city_count; j++) {
            if (strcmp(city_index[j], s) == 0) {
                si = j;
                break;
            }
        }

        if (si == -1) {
            strcpy(city_index[city_count], s);
            si = city_count;
            city_count++;
        }

        di = -1;
        for (j = 0; j < city_count; j++) {
            if (strcmp(city_index[j], d) == 0) {
                di = j;
                break;
            }
        }

        if (di == -1) {
            strcpy(city_index[city_count], d);
            di = city_count;
            city_count++;
        }

        cout << "\n\tEnter Distance From " << s << " to " << d << ": ";
        cin >> wt;

        am[si][di] = wt;

        cout << "\n\tDo you want to add more cities? (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return city_count;
}

void flight::display(int city_count) {
    cout << "\n\tAdjacency Matrix:\n\t  ";

    for (int i = 0; i < city_count; i++) {
        cout << city_index[i] << "\t";
    }
    cout << "\n";

    for (int i = 0; i < city_count; i++) {
        cout << city_index[i] << "\t";
        for (int j = 0; j < city_count; j++) {
            cout << am[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    flight f;
    int n, city_count = 0;
    char c;

    do {
        cout << "\n\t***** Flight Main Menu *****";
        cout << "\n\t1. Create";
        cout << "\n\t2. Adjacency Matrix";
        cout << "\n\t3. Exit";
        cout << "\n\tEnter your choice: ";
        cin >> n;

        switch (n) {
        case 1:
            city_count = f.create();
            break;
        case 2:
            f.display(city_count);
            break;
        case 3:
            return 0;
        default:
            cout << "\n\tInvalid choice!";
        }

        cout << "\n\tDo you want to continue in Main Menu? (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}

