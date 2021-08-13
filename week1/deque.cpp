#include <vector>
#include "test_runner.h"

using namespace std;

template <typename T>
class Deque {
public:
    /*    конструктор по умолчанию;
    константный метод Empty, возвращающий true, если дек не содержит ни одного элемента;
    константный метод Size, возвращающий количество элементов в деке;
    T& operator[](size_t index) и const T& operator[](size_t index) const;
    константный и неконстантный метод At(size_t index), генерирующий стандартное исключение out_of_range, если индекс больше или равен количеству элементов в деке;
    константные и неконстантные версии методов Front и Back, возвращающих ссылки на первый и последний элемент дека соответственно;
    методы PushFront и PushBack.*/

    bool Empty() const {
        return front.empty() && back.empty();
    }

    size_t Size() const {
        return front.size() + back.size();
    }

    T& operator[](size_t index) {
        if(index >= front.size()) {
            return back[index - front.size()];
        }

        return front[front.size() - index - 1];
    }

    const T& operator[](size_t index) const {
        return this->operator[](index);
    }

    T& At(size_t index) {
        if(index >= Size()) {
            throw out_of_range("");
        }

        return this->operator[](index);
    }

    const T& At(size_t index) const {
        return this->At(index);
    }

    T& Front() {
        if(front.empty()) return back.front();
        return front.back();
    }

    const T& Front() const {
        return Front();
    }

    T& Back() {
        if(back.empty()) return front.front();
        return back.back();
    }

    const T& Back() const {
        return Back();
    }

    void PushFront(const T& value) {
        front.push_back(value);
    }

    void PushBack(const T& value) {
        back.push_back(value);
    }


private:
    vector<T> front;
    vector<T> back;
};


void TestDequeBack() {
    Deque<int> d;
    d.PushBack(1);
    d.PushBack(2);
    d.PushBack(3);
    d.PushBack(4);
    d.PushBack(5);
    d.PushBack(6);

    ASSERT(!d.Empty());
    ASSERT_EQUAL(d.Size(), 6);

    ASSERT_EQUAL(d.At(0), 1);
    ASSERT_EQUAL(d.At(1), 2);
    ASSERT_EQUAL(d.At(2), 3);
    ASSERT_EQUAL(d.At(3), 4);
    ASSERT_EQUAL(d.At(4), 5);
    ASSERT_EQUAL(d.At(5), 6);

    ASSERT_EQUAL(d[0], 1);
    ASSERT_EQUAL(d[1], 2);
    ASSERT_EQUAL(d[2], 3);
    ASSERT_EQUAL(d[3], 4);
    ASSERT_EQUAL(d[4], 5);
    ASSERT_EQUAL(d[5], 6);

    d[1] = 11;
    ASSERT_EQUAL(d[1], 11);

    try {
        d.At(8);
        ASSERT(false);
    } catch (const out_of_range& e) {
        ASSERT(true);
    } catch (...) {
        ASSERT(false);
    }

    ASSERT_EQUAL(d.Front(), 1);
    ASSERT_EQUAL(d.Back(), 6);

}

void TestDequeFront() {
    Deque<int> d;
    d.PushFront(1);
    d.PushFront(2);
    d.PushFront(3);
    d.PushFront(4);
    d.PushFront(5);
    d.PushFront(6);

    ASSERT(!d.Empty());
    ASSERT_EQUAL(d.Size(), 6);

    ASSERT_EQUAL(d.At(0), 6);
    ASSERT_EQUAL(d.At(1), 5);
    ASSERT_EQUAL(d.At(2), 4);
    ASSERT_EQUAL(d.At(3), 3);
    ASSERT_EQUAL(d.At(4), 2);
    ASSERT_EQUAL(d.At(5), 1);

    ASSERT_EQUAL(d[0], 6);
    ASSERT_EQUAL(d[1], 5);
    ASSERT_EQUAL(d[2], 4);
    ASSERT_EQUAL(d[3], 3);
    ASSERT_EQUAL(d[4], 2);
    ASSERT_EQUAL(d[5], 1);

    d[1] = 11;
    ASSERT_EQUAL(d[1], 11);

    try {
        d.At(8);
        ASSERT(false);
    } catch (const out_of_range& e) {
        ASSERT(true);
    } catch (...) {
        ASSERT(false);
    }

    ASSERT_EQUAL(d.Front(), 6);
    ASSERT_EQUAL(d.Back(), 1);

}

void TestDequeSimple() {
    Deque<int> d;

    d.PushFront(1);
    d.PushBack(2);
    d.PushBack(3);
    d.PushBack(4);
    d.PushFront(5);
    d.PushFront(8);
    d.PushFront(3);

    ASSERT(!d.Empty());
    ASSERT_EQUAL(d.Size(), 7);

    ASSERT_EQUAL(d.At(0), 3);
    ASSERT_EQUAL(d.At(1), 8);
    ASSERT_EQUAL(d.At(2), 5);
    ASSERT_EQUAL(d.At(3), 1);
    ASSERT_EQUAL(d.At(4), 2);
    ASSERT_EQUAL(d.At(5), 3);
    ASSERT_EQUAL(d.At(6), 4);

    ASSERT_EQUAL(d[0], 3);
    ASSERT_EQUAL(d[1], 8);
    ASSERT_EQUAL(d[2], 5);
    ASSERT_EQUAL(d[3], 1);
    ASSERT_EQUAL(d[4], 2);
    ASSERT_EQUAL(d[5], 3);
    ASSERT_EQUAL(d[6], 4);

    d[1] = 11;
    ASSERT_EQUAL(d[1], 11);

    try {
        d.At(8);
        ASSERT(false);
    } catch (const out_of_range& e) {
        ASSERT(true);
    } catch (...) {
        ASSERT(false);
    }

    ASSERT_EQUAL(d.Front(), 3);
    ASSERT_EQUAL(d.Back(), 4);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestDequeSimple);
    RUN_TEST(tr, TestDequeFront);
    RUN_TEST(tr, TestDequeBack);
}