// Hashing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Реализация хеш-таблицы в C++

#include <iostream>
#include <list>
using namespace std;

class Hash
{
    int size;    
    
    // Указатель на массив, содержащий  size
    list<int>* table;
public:
   
    Hash(int V);  // Конструктор

    // вставляет ключ в хэш-таблицу
    void insertItem(int x);

    // удаляет ключ из хэш-таблицы
    void deleteItem(int key);

    // хэш-функция для сопоставления значений с ключом
    int hashFunction(int key) {
        int  i = 0, x = 1;
        int c= x % 5;
        int d= x % 7;
        printf("%i\n", x);
        int* h=0;
        h[i] = (h[i - 1]+ c * i + d * i*i) % size;
        return h[i];
    }

   
    void displayHash();
};


Hash::Hash(int b)
{
    this->size = b;
    table = new list<int>[size];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // получить хэш-индекс ключа
    int index = hashFunction(key);

    // найти ключ в (индексном) списке
    list <int> ::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    // если ключ найден в хэш-таблице, удалите его
    if (i != table[index].end())
        table[index].erase(i);
}



// функция для отображения хэш-таблицы
void Hash::displayHash() {
    for (int i = 0; i < size; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    // массив, содержащий ключи для сопоставления
    int a[] = { 15, 11, 27, 8, 12 };
    int n = sizeof(a) / sizeof(a[0]);
    
    // вставляем ключи в хэш-таблицу
    Hash h(7);   //  - size в  хэш-таблице
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // удалить 12 из хэш-таблицы
    h.deleteItem(12);

    // отображение таблицы Hash
    h.displayHash();

    return 0;
}

