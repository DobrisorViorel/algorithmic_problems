/*


1. Folosind programare generică și POO, se va construi un arbore BST (fără autoechilibrare) având criteriu de ordonare a < b.

a) Se va implementa o metodă care calculează adâncimea arborelui (nodul rădăcină are adâncimea 1).

b) Se va implementa o metodă care verifică dacă arborele este echilibrat (pentru fiecare nod, 
diferența dintre adâncimile subarborelui stâng și cel drept în modul nu depășește 1)

*/

template<class T>
struct BinarySearchNode {
    T data;
    BinarySearchNode<T> *left{nullptr};
    BinarySearchNode<T> *right{nullptr};

    explicit BinarySearchNode(T data) : data(data) {}

    virtual ~BinarySearchNode() = default;
};

template<class T>
BinarySearchNode<T> *node_insert(BinarySearchNode<T> *root, T const &data) {
    if (root == nullptr) {
        return new BinarySearchNode<T>(data);
    }

    if (data < root->data) {
        root->left = node_insert(root->left, data);
    } else if (root->data < data) {
        root->right = node_insert(root->right, data);
    } else { ;
    }
    return root;
}

template<class T>
int height(BinarySearchNode<T> *root) {
    if (root == nullptr) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? 1 + left : 1 + right);
}

template<class T>
bool echilibrat(BinarySearchNode<T> *root) {
    if (root == nullptr)
        return true;
    int left = height(root->left);
    int right = height(root->right);

    if (abs(left - right) <= 1 && echilibrat(root->left) && echilibrat(root->right))
        return true;
    return false;
}

template<class T>
class ArboreBST {
    BinarySearchNode<T> *root{nullptr};

public:
    ArboreBST() = default;

    void adauga(T const &data) {
        root = node_insert(root, data);
    }

    int calculeazaAdancime() {
        height(root);
    }

    bool esteEchilibrat() {
        return echilibrat(root);
    }
};