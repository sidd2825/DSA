#include<iostream>
#include<stack>
#include<string>
using namespace std;

class BTNODE {
    BTNODE* left;
    BTNODE* right;
    char data;
public:
    BTNODE() {
        left = right = NULL;
        data = '\0';
    }

    friend class ExpressionTree;
};

class ExpressionTree {
    BTNODE* root;
public:
    ExpressionTree() {
        root = NULL;
    }

    void create(string);
    void inorder(BTNODE*);
    void preorder(BTNODE*);
    void postorder(BTNODE*);
    void Delete_tree(BTNODE*);
    friend int main();
};

void ExpressionTree::create(string s) {
    stack<BTNODE*> s1;
    BTNODE* t1, * t2, * t3;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (isalnum(s[i])) {
            t1 = new BTNODE;
            t1->data = s[i];
            s1.push(t1);
        } else {
            t1 = new BTNODE;
            t1->data = s[i];

            t2 = s1.top(); s1.pop();
            t3 = s1.top(); s1.pop();

            t1->left = t2;
            t1->right = t3;

            s1.push(t1);
        }
    }
    if (!s1.empty()) {
        root = s1.top();
        s1.pop();
    }
}

void ExpressionTree::inorder(BTNODE* t) {
    if (t != NULL) {
        inorder(t->left);
        cout << "\t" << t->data;
        inorder(t->right);
    }
}

void ExpressionTree::preorder(BTNODE* t) {
    if (t != NULL) {
        cout << "\t" << t->data;
        preorder(t->left);
        preorder(t->right);
    }
}

void ExpressionTree::postorder(BTNODE* t) {
    if (t == NULL) {
        return;
    }

    stack<BTNODE*> s1, s2;
    s1.push(t);

    while (!s1.empty()) {
        t = s1.top();
        s1.pop();
        s2.push(t);

        if (t->left != NULL) s1.push(t->left);
        if (t->right != NULL) s1.push(t->right);
    }

    while (!s2.empty()) {
        cout << "\t" << s2.top()->data;
        s2.pop();
    }
}

void ExpressionTree::Delete_tree(BTNODE* t) {
    if (t != NULL) {
        Delete_tree(t->left);
        Delete_tree(t->right);
        delete t;
    }
}

int main() {
    ExpressionTree E;
    string s;
    int ch;

    do {
        cout << "\n *****MENU*******";
        cout << "\n 1. CREATE";
        cout << "\n 2. INFIX";
        cout << "\n 3. PREFIX";
        cout << "\n 4. POSTFIX";
        cout << "\n 5. DELETE";
        cout << "\n 6. EXIT";
        cout << "\n --------------------";
        cout << "\n Enter your choice = ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\n Enter prefix expression = ";
            cin >> s;
            E.create(s);
            break;

        case 2:
            if (E.root == NULL) {
                cout << "\n Tree is empty";
            } else {
                cout << "\n Infix expression = ";
                E.inorder(E.root);
            }
            break;

        case 3:
            if (E.root == NULL) {
                cout << "\n Tree is empty";
            } else {
                cout << "\n Prefix expression = ";
                E.preorder(E.root);
            }
            break;

        case 4:
            if (E.root == NULL) {
                cout << "\n Tree is empty";
            } else {
                cout << "\n Postfix expression = ";
                E.postorder(E.root);
            }
            break;

        case 5:
            if (E.root == NULL) {
                cout << "\n Tree is empty";
            } else {
                E.Delete_tree(E.root);
                E.root = NULL;
                cout << "\n Tree is deleted";
            }
            break;

        case 6:
            cout << "\n Exiting...";
            break;

        default:
            cout << "\n Enter correct choice";
        }
    } while (ch != 6);

    return 0;
}

