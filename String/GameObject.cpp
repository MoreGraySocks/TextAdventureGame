#include "GameObject.h"

GameObject::GameObject() : m_position{ 0,0 } {}
GameObject::GameObject(Point2D position) : m_position{ position } {}

GameObject::~GameObject() {}