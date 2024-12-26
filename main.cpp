#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal {
public:
    // ������
    Animal() {
        cout << "Animal Constructor" << endl;
    }

    // ���� ���� �Լ�: �ڽ� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
    virtual void makeSound() = 0;

    // ���� �Ҹ���: �ڽ� Ŭ���� �Ҹ��ڰ� �ùٸ��� ȣ��ǵ��� �մϴ�.
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
        cout << "��! ��!" << endl;
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
        cout << "��~ ��~" << endl;
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
        cout << "����~ ����~" << endl;
    }

    ~Cow() {
        cout << "Cow Destuctor" << endl;
    }
};

class Zoo {
private:
    Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
    int size;             // ������ ��

public:
    Zoo() : size(0) {}

    // ������ �������� �߰��ϴ� �Լ�
    void addAnimal(Animal* animal) {
        if (size >= 10) {
            cout << "Zoo is full!" << endl;
            return;
        }
        animals[size++] = animal;
    }

    // �������� �ִ� ��� ������ �Ҹ��� �ൿ�� ����ϴ� �Լ�
    void performActions() {
        for (int i = 0; i < size; i++) {
            animals[i]->makeSound();
        }
    }

    // Zoo �Ҹ���: ���� ��ü �޸� ����
    ~Zoo() {
        for (int i = 0; i < size; i++) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int random = rand() % 3; // 0, 1, 2 �� ���� ����
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
    srand(time(0)); // ���� �õ� �ʱ�ȭ

    Zoo zoo1;

    // ���� ���� ���� �� �߰�
    for (int i = 0; i < 5; i++) {
        zoo1.addAnimal(createRandomAnimal());
    }

    // �������� �ִ� ��� �������� �Ҹ� ���
    zoo1.performActions();

    // Zoo �Ҹ��ڰ� ���� �Ҵ�� �޸𸮸� �ڵ����� �����մϴ�.
    return 0;
}