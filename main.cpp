#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal {
public:
    // 생성자
    Animal() {
        cout << "Animal Constructor" << endl;
    }

    // 순수 가상 함수: 자식 클래스에서 반드시 구현해야 합니다.
    virtual void makeSound() = 0;

    // 가상 소멸자: 자식 클래스 소멸자가 올바르게 호출되도록 합니다.
    virtual ~Animal() {
        cout << "Animal Destuctor" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << "Dog Constructor" << endl;
    }

    void makeSound() override {
        cout << "왈! 왈!" << endl;
    }

    ~Dog() {
        cout << "Dog Destuctor" << endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        cout << "Cat Constructor" << endl;
    }

    void makeSound() override {
        cout << "냥~ 냥~" << endl;
    }

    ~Cat() {
        cout << "Cat Destuctor" << endl;
    }
};

class Cow : public Animal {
public:
    Cow() {
        cout << "Cow Constructor" << endl;
    }

    void makeSound() override {
        cout << "음머~ 음머~" << endl;
    }

    ~Cow() {
        cout << "Cow Destuctor" << endl;
    }
};

class Zoo {
private:
    Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
    int size;             // 동물의 수

public:
    Zoo() : size(0) {}

    // 동물을 동물원에 추가하는 함수
    void addAnimal(Animal* animal) {
        if (size >= 10) {
            cout << "Zoo is full!" << endl;
            return;
        }
        animals[size++] = animal;
    }

    // 동물원에 있는 모든 동물의 소리와 행동을 출력하는 함수
    void performActions() {
        for (int i = 0; i < size; i++) {
            animals[i]->makeSound();
        }
    }

    // Zoo 소멸자: 동물 객체 메모리 해제
    ~Zoo() {
        for (int i = 0; i < size; i++) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int random = rand() % 3; // 0, 1, 2 중 랜덤 선택
    if (random == 0) {
        return new Dog();
    }
    else if (random == 1) {
        return new Cat();
    }
    else {
        return new Cow();
    }
}

int main() {
    srand(time(0)); // 랜덤 시드 초기화

    Zoo zoo1;

    // 동물 랜덤 생성 및 추가
    for (int i = 0; i < 5; i++) {
        zoo1.addAnimal(createRandomAnimal());
    }

    // 동물원에 있는 모든 동물들의 소리 출력
    zoo1.performActions();

    // Zoo 소멸자가 동적 할당된 메모리를 자동으로 해제합니다.
    return 0;
}