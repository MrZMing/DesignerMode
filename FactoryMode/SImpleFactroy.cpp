#include <string>
#include <iostream>
using namespace std;
/*
简单工厂模式
水果工厂需要创建苹果梨香蕉
*/
enum FruitType{
    apple,
    banana,
    peal};
//抽象水果类,水果公共方法是被吃
class Fruit
{
public:
    virtual void eat() = 0; 
    virtual ~Fruit();
};

class Apple : public Fruit
{
public:
    void eat() override
    {
        cout << "苹果" << endl;
    }
    ~Apple(){}
};

class Banana : public Fruit
{
public:
    void eat() override
    {
        cout << "香蕉" << endl;
    }
    ~Banana(){}
};

class Peal : public Fruit
{
public:
    void eat() override
    {
        cout << "梨" << endl;
    }
    ~Peal(){}
};

class Factory
{
public:
    Fruit* create(const FruitType& type)
    {
        Fruit* fruit = nullptr;
        switch(type)
        {
            case FruitType::apple:
                fruit = new Apple();
                break;
            case FruitType::banana:
                fruit = new Banana();
                break;
            case FruitType::peal:
                fruit = new Peal();
                break;                
            // case default:
            //     break;
        }
        return fruit;
    }
};

int main()
{
    Factory* factory = new Factory();
    Fruit* fruit = factory->create(FruitType::apple);
    fruit->eat();
    delete fruit;
    delete factory;
}