#include <string>
#include <iostream>
using namespace std;
/*
工厂模式：
遵从设计模式原则，对简单工厂进行改造，cetate方法下放到各个子工厂
*/
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
    virtual Fruit* create() = 0;
    virtual ~Factory() {}
};

class AppleFactory : public Factory
{
public:
    Fruit* create() override
    {
        return new Apple();
    }
    ~AppleFactory() {}
};

class BananaFactory : public Factory
{
public:
    Fruit* create() override
    {
        return new Banana();
    }
    ~BananaFactory() {}
};

class PealFactory : public Factory
{
public:
    Fruit* create() override
    {
        return new Peal();
    }
    ~PealFactory() {}
};

int main()
{
    Factory* factory = new AppleFactory();
    Fruit* fruit = factory->create();
    fruit->eat();
    delete fruit;
    delete factory;
}