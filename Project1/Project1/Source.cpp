#include <iostream>;
using namespace std;

struct queue {
    int a[1000];

    //��� ����� ���������� ���������� ������, �� �����
    //������� ��������� �� �� ��������� �������, �
    //�� ��������� �� ��� (��������������).

    //���, � ���������, �������� ��� ��������� ������� �� �������
    //������� �������� head == tail
    int head = 0;    //������ ������� ��������.
    int tail = 0;    //������ ��������, ���������� �� ���������.

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
            //������, ������� ������� ������� �� ������ �������.
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