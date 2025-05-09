#include <iostream>
#include <cstring>
using namespace std;

struct hash {
    long key;
    char name[100];
};

class HashFunction {
    hash h[10];

public:
    HashFunction();
    void insert();
    void display();
    int find(long);
    void Delete(long);
};

HashFunction::HashFunction() {
    for (int i = 0; i < 10; i++) {
        h[i].key = -1;
        strcpy(h[i].name, "NULL");
    }
}

void HashFunction::Delete(long k) {
    int index = find(k);
    if (index == -1) {
        cout << "\n\tKey Not Found";
    } else {
        h[index].key = -1;
        strcpy(h[index].name, "NULL");
        cout << "\n\tKey is Deleted";
    }
}

int HashFunction::find(long k) {
    for (int i = 0; i < 10; i++) {
        if (h[i].key == k) {
            cout << "\n\t" << h[i].key << " is Found at " << i << " Location With Name " << h[i].name;
            return i;
        }
    }
    return -1;
}

void HashFunction::display() {
    cout << "\n\t\tKey\t\tName";
    for (int i = 0; i < 10; i++) {
        cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].name;
    }
}

void HashFunction::insert() {
    char ans, n[100], ntemp[100];
    long k, temp;
    int hi, cnt = 0, flag = 0, i;

    do {
        if (cnt >= 10) {
            cout << "\n\tHash Table is FULL";
            break;
        }

        cout << "\n\tEnter a Telephone No: ";
        cin >> k;
        cout << "\n\tEnter a Client Name: ";
        cin >> n;

        hi = k % 10;

        if (h[hi].key == -1) {
            h[hi].key = k;
            strcpy(h[hi].name, n);
        } else {
            if (h[hi].key % 10 != hi) {
                temp = h[hi].key;
                strcpy(ntemp, h[hi].name);
                h[hi].key = k;
                strcpy(h[hi].name, n);

                flag = 0;
                for (i = hi + 1; i < 10; i++) {
                    if (h[i].key == -1) {
                        h[i].key = temp;
                        strcpy(h[i].name, ntemp);
                        flag = 1;
                        break;
                    }
                }
                for (i = 0; i < hi && flag == 0; i++) {
                    if (h[i].key == -1) {
                        h[i].key = temp;
                        strcpy(h[i].name, ntemp);
                        break;
                    }
                }
            } else {
                flag = 0;
                for (i = hi + 1; i < 10; i++) {
                    if (h[i].key == -1) {
                        h[i].key = k;
                        strcpy(h[i].name, n);
                        flag = 1;
                        break;
                    }
                }
                for (i = 0; i < hi && flag == 0; i++) {
                    if (h[i].key == -1) {
                        h[i].key = k;
                        strcpy(h[i].name, n);
                        break;
                    }
                }
            }
        }

        cnt++;
        cout << "\n\tDo You Want to Insert More Key? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

int main() {
    long k;
    int ch, index;
    char ans;
    HashFunction obj;

    do {
        cout << "\n\t***** Dictionary (ADT) *****";
        cout << "\n\t1. Insert";
        cout << "\n\t2. Display";
        cout << "\n\t3. Find";
        cout << "\n\t4. Delete";
        cout << "\n\t5. Exit";
        cout << "\n\tEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                cout << "\n\tEnter a Key Which You Want to Search: ";
                cin >> k;
                index = obj.find(k);
                if (index == -1)
                    cout << "\n\tKey Not Found";
                break;
            case 4:
                cout << "\n\tEnter a Key Which You Want to Delete: ";
                cin >> k;
                obj.Delete(k);
                break;
            case 5:
                return 0;
            default:
                cout << "\n\tInvalid Choice!";
        }

        cout << "\n\tDo You Want to Continue in Main Menu? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

