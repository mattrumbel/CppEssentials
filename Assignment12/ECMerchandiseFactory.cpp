#include "ECMerchandiseFactory.h"

// Implementations

// Adidas
ECTennisShoe* AdidasFactory::OrderTennisShoe(int size) {
    return new ECTennisShoe(20, size);
}

ECTennisBallCan* AdidasFactory::OrderTennisBallCan() {
    return new ECTennisBallCan(5, 3);
}

ECTennisBag* AdidasFactory::OrderTennisBag() {
    return new ECTennisBag(18, 6);
}


// Nike
ECTennisShoe* NikeFactory::OrderTennisShoe(int size) {
    return new ECTennisShoe(15, size);
}

ECTennisBallCan* NikeFactory::OrderTennisBallCan() {
    return new ECTennisBallCan(6, 4);
}

ECTennisBag* NikeFactory::OrderTennisBag() {
    return new ECTennisBag(12, 4);
}


// Head
ECTennisShoe* HeadFactory::OrderTennisShoe(int size) {
    return new ECTennisShoe(10, size);
}

ECTennisBallCan* HeadFactory::OrderTennisBallCan() {
    return new ECTennisBallCan(4, 3);
}

ECTennisBag* HeadFactory::OrderTennisBag() {
    return new ECTennisBag(10, 3);
}



ECMerchandiseTennisShop ECMerchandiseTennisShop::my_shop = ECMerchandiseTennisShop();

ECMerchandiseTennisShop::~ECMerchandiseTennisShop() {
    delete curr_factory;
}

ECMerchandiseTennisShop& ECMerchandiseTennisShop::Instance() {
    return my_shop;
}

ECTennisShoe* ECMerchandiseTennisShop::OrderTennisShoe(int sz) {
    
    ECTennisShoe* shoe = curr_factory->OrderTennisShoe(sz);
    num_shoes_sold++;
    total_revenue += shoe->getPrice();
    return curr_factory->OrderTennisShoe(sz);
}

ECTennisBallCan* ECMerchandiseTennisShop::OrderTennisBallCan() {
    ECTennisBallCan* can = curr_factory->OrderTennisBallCan();
    total_balls_sold += can->getNumBalls();
    total_revenue += can->getPrice();
    num_ball_cans_sold++;

    return can;
}

ECTennisBag* ECMerchandiseTennisShop::OrderTennisBag() {
    ECTennisBag* bag = curr_factory->OrderTennisBag();
    total_racquet_capacity_sold += bag->getRaquetCapacity();
    total_revenue += bag->getPrice();
    num_bags_sold++;

    return bag;
}

void ECMerchandiseTennisShop::ChooseVendor(TENNIS_VENDOR vendor) {
    if (curr_vendor == vendor) return;

    curr_vendor = vendor;
    delete curr_factory;

    switch(curr_vendor) {
        case TENNIS_ADIDAS : curr_factory = new AdidasFactory(); break;
        case TENNIS_NIKE : curr_factory = new NikeFactory(); break;
        case TENNIS_HEAD : curr_factory = new HeadFactory(); break;
    }
}

int ECMerchandiseTennisShop::GetNumShoesSold() const {
    return num_shoes_sold;
}

int ECMerchandiseTennisShop::GetNumBallcansSold() const {
    return num_ball_cans_sold;
}

int ECMerchandiseTennisShop::GetNumBagsSold() const {
    return num_bags_sold;
}

int ECMerchandiseTennisShop::GetTotNumBallsSold() const {
    return total_balls_sold;
}

int ECMerchandiseTennisShop::GetTotRacquetBagCapaictySold() const {
    return total_racquet_capacity_sold;
}

int ECMerchandiseTennisShop::GetTotRevenue() const {
    return total_revenue;
}