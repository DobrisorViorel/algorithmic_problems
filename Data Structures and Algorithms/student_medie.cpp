/*

Folosind noțiuni de POO și SDA, implementați următoarea variantă de listă simplu înlănțuită.

class Lista {

public:

    Lista();

    virtual ~Lista();

    void adaugaStudent(string nume, double medie);

    vector<int> returneazaIndecsiSortati();

};


Metoda adaugaStudent introduce un nou student în listă.

Metoda returneazaIndecsiSortati sortează toți studenții din listă descrescător după medie și în caz de egalitate, 
crescător după nume și apoi returnează un vector ce conține indecșii inițiali ai studenților din lista sortată. 

*/


#include <string>
#include <vector>
#include <utility>

using namespace std;

class Student {
private:
    string nume;
    double medie;
    int index;
public:
    Student(string &nume, double medie, int index) : nume(nume), medie(medie), index(index) {}

    int getIndex() const {
        return index;
    }

    bool operator<(const Student &std) const {
        if (medie != std.medie) {
            return medie > std.medie;
        }
        return nume < std.nume;
    }
};

struct Node {
    Student stud;
    Node *next{};
    Node(Student student, Node *next) : stud(std::move(student)), next(next) {}
    virtual ~Node() = default;
};

class Lista {
    Node *head{};
    int idx{};
public:
    Lista() = default;

    virtual ~Lista() {
        auto curr = head;

        while (curr != nullptr) {
            auto next = curr->next;
            curr->next = nullptr;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }

    void adaugaStudent(std::string nume, double medie) {
        head = new Node({nume, medie, idx}, head);
        idx++;
    }

    static Node *Sort(Node *inceput, Node *final) {
        if (inceput == final || inceput == nullptr || final == nullptr)
            return inceput;

        auto ppivot = inceput;
        auto curr = inceput;

        Student pivot = final->stud;
        while (inceput != final) {
            if (inceput->stud < pivot) {
                ppivot = curr;
                Student aux = curr->stud;
                curr->stud = inceput->stud;
                inceput->stud = aux;
                curr = curr->next;
            }
            inceput = inceput->next;
        }
        Student aux = curr->stud;
        curr->stud = pivot;
        final->stud = aux;
        return ppivot;
    }

    void sort(Node *inceput, Node *final) {
        if (inceput == nullptr)
            return;
        if (inceput == final)
            return;
        if (inceput == final->next)
            return;
        if (final == nullptr)
            return;

        auto ppivot = Sort(inceput, final);
        sort(inceput, ppivot);

        if (ppivot != nullptr && ppivot == inceput) {
            sort(ppivot->next, final);
        } else if (ppivot != nullptr) {
            sort(ppivot->next->next, final);
        }
    }


    static Node *ultimulNod(Node *head) {
        auto aux = head;
        while (aux->next != nullptr) 
            aux = aux->next;
        return aux;
    }

    std::vector<int> returneazaIndecsiSortati() {
        sort(head, ultimulNod(head));
        std::vector<int> idx_;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
            idx_.push_back(ptr->stud.getIndex());
        return idx_;
    }
};