#include <string>
#include <iostream>
using namespace std;

/*
抽象工厂模式，对工厂模式进一步优化，主要应对复杂产品问题，需要细化产品的组合成分
船分类：潜水艇，轮船，核潜艇
船组成部分：
1. 引擎：燃油机，电机，核动力机
2. 材质：木，铁，防水材质
3. 等
*/
//部件基类
class Engine
{
public:
    virtual void begin() = 0; //启动
    virtual ~Engine() {};
};

class CaiZhi
{
public:
    virtual void patch() = 0; //补充
    virtual ~CaiZhi() {};
};

//船基类
class Ship
{
public:
    Ship(Engine* engine, CaiZhi* caizhi) : m_engine(engine), m_caizhi(caizhi) {}
    virtual void Run()
    {
        m_caizhi->patch();
        m_engine->begin();
    }
    virtual ~Ship()
    {
        delete m_engine;
        delete m_caizhi;
    }
private:
    Engine* m_engine;
    CaiZhi* m_caizhi;
};

class Factory 
{
public:
    virtual Ship* create() = 0;
    virtual ~Factory() {};
};

// 燃油机
class RanyouEngine : public Engine
{
public:
    void begin() override
    {
        cout << "燃油机发动" << endl;
    }
    ~RanyouEngine() = default;
};

class DianEngine : public Engine
{
public:
    void begin() override
    {
        cout << "电机发动" << endl;
    }
    ~DianEngine() = default;
};

class HeEngine : public Engine
{
public:
    void begin() override
    {
        cout << "核动力机发动" << endl;
    }
    ~HeEngine() = default;
};

class Mutou : public CaiZhi
{
public:
    void patch() override
    {
        cout << "补充木头" << endl;
    }
    ~Mutou() = default;
};

class Tie : public CaiZhi
{
public:
    void patch() override
    {
        cout << "补充铁" << endl;
    }
    ~Tie() = default;
};

class FangShui : public CaiZhi
{
public:
    void patch() override
    {
        cout << "补充防水材料" << endl;
    }
    ~FangShui() = default;
};

class LunChuanFactory : public Factory 
{
public:
    Ship* create() override
    {
        return new Ship(new RanyouEngine(), new Mutou());
    }
    ~LunChuanFactory() = default;
}

class QiantingFactory : public Factory 
{
public:
    Ship* create() override
    {
        return new Ship(new DianEngine(), new FangShui());
    }
    ~QiantingFactory() = default;
}

int main()
{
    Factory* factory = new LunChuanFactory();
    Ship* ship = factory->create();
    ship->run();
    delete ship;
    delete factory;
}