#include <iostream>

using namespace std;


template<typename T>
class List
{
public:
    List();
    ~List();
    void clear();
    void popFront();
    void popBack();
    void pushFront(T Data);
    void pushBack(T Data);
    void insert(T value, int index);
    void removeAt(int index);
    int GetSize(){return size;}
    T& operator[](const int index);

private:
    class Node
    {
    public:
        Node *pNext;
        T Data;
        Node(T Data=T(), Node *pNext=nullptr)
        {
            this->Data=Data;
            this->pNext=pNext;
        }
    };
    int size;
    Node*Head;
};

template<typename T>
List<T>::List()
{
    size = 0;
    Head = nullptr;
};

template<typename T>
List<T>::~List()
{
    clear();
};

template<typename T>
void List<T>::clear(){
    while (size){
        popFront();
    }
}

template<typename T>
void List<T>::popFront(){
    Node *temp = Head;
    Head = Head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::popBack(){
    removeAt(size-1);
}

template<typename T>
void List<T>::pushFront(T Data){
    Head = new Node(Data,Head);
    size++;
}

template<typename T>
void List<T>::pushBack(T Data){

    if (Head == nullptr){

        Head = new Node(Data);
    }
    else{

        Node *current = this->Head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(Data);
    }
    size++;
}

template<typename T>
void List<T>::insert(T Data, int index){

    if (index == 0){
        pushFront(Data);
    }else {
        Node *previous = this->Head;
        for (int i = 0;i < index - 1; i++) {
            previous = previous->pNext;
        }
        previous->pNext = new Node(Data, previous->pNext);
        size++;
    }


}
template<typename T>
void List<T>::removeAt(int index){
    if (index == 0){
        popFront();
    }else {
        Node *previous = this->Head;
        for (int i = 0;i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        size--;
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter{0};

    Node *current = this->Head;
    while (current != nullptr) {
        if (counter == index){
            return current->Data;
        }
        current = current->pNext;
        counter++;
    }
};

int main()
{
    List<int>lst;
    lst.pushFront(5);
    lst.pushFront(10);
    lst.pushFront(15);
    lst.pushFront(20);
    lst.pushFront(25);
    lst.pushFront(30);
    lst.pushBack(90);
    lst.popFront();
    lst.popBack();
    lst.insert(99,1);
    lst.removeAt(4);

    for (int i = 0; i < lst.GetSize(); ++i) {
        cout << lst[i] << endl;
    }

    lst.clear();
}
