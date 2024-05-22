#include <iostream>
#include <vector>

// 예제를 위한 구조체 정의
struct MyStruct {
    int id;
    std::string name;
};

int main() {
    // 구조체를 원소로 갖는 vector 생성
    std::list<MyStruct*> myVector;

    // 동적 할당된 구조체를 vector에 추가
    MyStruct* ptr1 = new MyStruct{1, "John"};
    MyStruct* ptr2 = new MyStruct{2, "Alice"};
    MyStruct* ptr3 = new MyStruct{3, "Bob"};

    myVector.push_back(ptr1);
    myVector.push_back(ptr2);
    myVector.push_back(ptr3);

    myVector.erase(myVector.begin());

    // 동적 할당된 메모리를 해제
    for (auto ptr : myVector) {
        delete ptr;
    }

    return 0;
}
