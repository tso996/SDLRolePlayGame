//
//  ECS.hpp
//  SDLRolePlayGame
//
//  Created by Joe on 14/06/2022.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <stdio.h>
#include <iostream>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept{
    static ComponentID typeID = getComponentID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
public:
    Entity* entity;
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    
    virtual ~Component(){}
};

class Entity{
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    
    
public:
    void update(){
        for(auto& c : components) c->update();
        for(auto& c : components) c->draw();
    }
    
    void draw(){
        
    }
    
    bool isActive() const {return active;}
    
    void destroy(){ active = false; }

    template <typename T> bool hasComponent() const{
        return componentBitSet[getComponentID<T>];
    }
    
};


#endif /* ECS_hpp */
