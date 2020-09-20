//
// Created by Azazel on 28.02.20.
//

#include <iostream>
#include <vector>

using  namespace std;

class Heap {
public:
    vector <int> heap_;
    int size_ = 0;
    void siftUp(int num);
    void siftDown(int num);
    void insert(int num);
    int extractMax();
    void reset();
};

//Просеять элемент вниз
void Heap::siftDown(int num) {
    //Если потомок существует
    while (num * 2 + 1 < size_) {
        //Берем максимум
        int max = num * 2 + 1;
        if (heap_[num * 2 + 1] < heap_[num * 2 + 2]) max = num * 2 + 2;
        //Если элемент больше максимального потомка, выходим, тк он на своем месте
        if (heap_[num] >= heap_[max]) return;
        //Иначе меняем местами и идем дальше
        swap(heap_[num], heap_[max]);
        num = max;
    }
}

//Просеять элемент вверх
void Heap::siftUp(int num) {
    //Пока элемент больше отца и не корень дерева
    while (heap_[num] > heap_[(num - 1) / 2] && num > 0) {
        //Меняем местами отца и элемент
        swap(heap_[num], heap_[(num - 1) / 2]);
        num = (num - 1) / 2;
    }
}

//Добавить элемент
void Heap::insert(int num) {
    //Добавил, увеличил, просеял снизу вверх на свое место
    heap_.push_back(num);
    ++size_;
    siftUp(size_ - 1);
}

//Вытащить максимум и удалить
int Heap::extractMax() {
    //Временное хранение максимума
    int max = heap_[0];
    //Перезапись максимума на последний лист
    heap_[0] = heap_.back();
    //Удаление дубликата на последнем листе
    heap_.pop_back();
    --size_;
    //Просеял сверху вниз на свое место
    siftDown(0);
    //Вернул максимум
    return max;
}

//Очистить кучу
void Heap::reset() {
    size_ = 0;
    heap_.clear();
}


int main() {
    int k, n;
    char request;
    cin >> k;
    Heap heap;
    for (int i = 0; i < k; ++i) {
        cin >> request;
        if (request == '1') {
            heap.reset();
        } else if (request == '2') {
            cin >> n;
            heap.insert(n);
        } else {
            //Проверим, что куча не пуста и извлечем максимум
            if (heap.size_ > 0) cout << heap.extractMax() << endl;
                //Иначе ошибка
            else cout << "CANNOT" << endl;
        }
    }
    return 0;
}
