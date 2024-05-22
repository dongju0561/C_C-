#include<iostream>
#include<list>
#include<cstring>


#define MAX_NAME_LENGTH 10
#define MAX_PHONE_LENGTH 20

typedef struct{
    int nAge;
    char* szName;
    char* szPhone;
}personalInfo;

using namespace std;

int main(){
    list<personalInfo*> list1;

    personalInfo* p1 = new personalInfo;
    p1->szName = new char[MAX_NAME_LENGTH];
    p1->szPhone = new char[MAX_PHONE_LENGTH];

    p1->nAge = 1;
    strcpy(p1->szName, "parkdongju");
    strcpy(p1->szPhone, "010-2993-5863");

    list1.push_front(p1);
    list1.push_front(p1);
    list1.push_front(p1);

    for (auto ptr : list1) {
        
        cout << "Age: " << ptr->nAge << ", Name: " << ptr->szName << ", Phone: " << ptr->szPhone << endl;
    }
    
    if (list1.size() >= 2) {

        cout << "start" << endl;
        auto it = std::next(list1.begin(),1); // 두 번째 요소를 가리키는 반복자
        personalInfo* pToDelete =*it; // 제거할 요소에 대한 포인터 저장
        list1.erase(it);

        delete[] pToDelete->szName;
        delete[] pToDelete->szPhone;
        delete pToDelete; // personalInfo 구조체 자체를 해제
    }
}