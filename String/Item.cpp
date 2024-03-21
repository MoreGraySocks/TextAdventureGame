#include "Item.h"

Item::Item(){}
Item::Item(Point2D position) :GameObject{ position } {}

Item::~Item(){}

void Item::Description() {
	std::cout << "If you're seeing this, I did something wrong" << std::endl;
}

