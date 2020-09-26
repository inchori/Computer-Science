#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node (int x) {
        key = x;
        left = right = NULL;
    }
};

// Binary Tree Traversal inorder
void inorder(Node* temp) {
    if (!temp) return;

    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

// Binary Tree Traversal preorder
void preorder(Node *temp) {
    if (!temp) return;
    cout << temp->key << " ";
    preorder(temp->left);
    preorder(temp->right);
}

// Binary Tree Traversal postorder
void postorder(Node *temp) {
    if (!temp) return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->key << " ";
}

// Insert element in binary treee
void insert(Node *temp, int key) {
    queue<Node*> q;
    q.push(temp);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(key);
            break;
        } else q.push(temp->left);

        if (!temp->right) {
            temp->right = new Node(key);
            break;
        } else q.push(temp->right);
    }
}

void deleteDeepest(Node *root, Node *d_node) {
    queue<Node*> q;
    q.push(root);

    Node *temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete(d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else q.push(temp->right);
        }

        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            } else q.push(temp->left);
        }
    }
}

Node *deletion(Node *root, int key) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->key == key) return NULL;
        else return root;
    }
    queue<Node*> q;
    q.push(root);
    Node *temp;
    Node *key_node = NULL;

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->key == key) key_node = temp;
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    if (key_node != NULL) {
        int x = temp->key;
        deleteDeepest(root, temp);
        key_node->key = x;
    }
    return root;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    inorder(root);
    int key = 12;

    insert(root, key);
    cout << endl;
    inorder(root);
    cout << endl;

    root = deletion(root, key);
    inorder(root);
    return 0;
}