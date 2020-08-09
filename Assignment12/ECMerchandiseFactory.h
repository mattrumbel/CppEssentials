//
//  ECMerchandiseFactory.hpp
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandiseFactory_hpp
#define ECMerchandiseFactory_hpp

#include "ECMerchandise.h"

// *********************************************************
// List of vendors
typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;


// *********************************************************
// merchandise factory

// your code goes here

// Abstract Factory
class AbstractBrandFactory {
    public:
        AbstractBrandFactory() {};
        virtual ~AbstractBrandFactory() {};
        virtual ECTennisShoe* OrderTennisShoe(int sz) = 0;
        virtual ECTennisBallCan* OrderTennisBallCan() = 0;
        virtual ECTennisBag* OrderTennisBag() = 0;
};

// Adidas factory
class AdidasFactory : public AbstractBrandFactory {
    public:
        AdidasFactory() {};
        ~AdidasFactory() {};
        ECTennisShoe* OrderTennisShoe(int size);
        ECTennisBallCan* OrderTennisBallCan();
        ECTennisBag* OrderTennisBag();
};

// Nike factory
class NikeFactory : public AbstractBrandFactory {
    public:
        NikeFactory() {};
        ~NikeFactory() {};
        ECTennisShoe* OrderTennisShoe(int size);
        ECTennisBallCan* OrderTennisBallCan();
        ECTennisBag* OrderTennisBag();
};

// Head factory
class HeadFactory : public AbstractBrandFactory {
    public:
        HeadFactory() {};
        ~HeadFactory() {};
        ECTennisShoe* OrderTennisShoe(int size);
        ECTennisBallCan* OrderTennisBallCan();
        ECTennisBag* OrderTennisBag();
};


// *********************************************************
// Merchandise creation: singleton pattern

class ECMerchandiseTennisShop
{
public:
    virtual ~ECMerchandiseTennisShop();
    static ECMerchandiseTennisShop &Instance();
    ECTennisShoe *OrderTennisShoe(int sz);
    ECTennisBallCan *OrderTennisBallCan();
    ECTennisBag *OrderTennisBag();
    void ChooseVendor(TENNIS_VENDOR vendor);
    int GetNumShoesSold() const;
    int GetNumBallcansSold() const;
    int GetNumBagsSold() const;
    int GetTotNumBallsSold() const;
    int GetTotRacquetBagCapaictySold() const;
    int GetTotRevenue() const;
    
private:
    // your code goes here
    static ECMerchandiseTennisShop my_shop;
    AbstractBrandFactory *curr_factory = new AdidasFactory();
    TENNIS_VENDOR curr_vendor;
    int num_shoes_sold;
    int num_ball_cans_sold;
    int num_bags_sold;
    int total_balls_sold;
    int total_racquet_capacity_sold;
    int total_revenue;
};


#endif /* ECMerchandiseFactory_hpp */
