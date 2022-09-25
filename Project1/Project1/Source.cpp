#include <iostream>;
using namespace std;

struct queue {
    int a[1000];

    //Для более лаконичной реализации работы, мы будем
    //хранить указатель не на последний элемент, а
    //на следующий за ним (несуществующий).

    //Это, в частности, позволит нам проверять очередь на пустоту
    //простым условием head == tail
    int head = 0;    //Индекс первого элемента.
    int tail = 0;    //Индекс элемента, следующего за последним.

    void push(int x) {
        a[tail] = x;
        tail++;
    }

    int pop() {
        if (head != tail) {
            head++;
            return a[head - 1];
        }
        else {
            //Ошибка, попытка извлечь элемент из пустой очереди.
        }
    }

    bool is_empty() {
        return head == tail;
    }
};

int main() {
    queue q;
    int k;
    int t = 0, l = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> l;
        q.push(l);
    }


}