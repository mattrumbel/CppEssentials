//
//  ECMerchandise.h
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandise_hpp
#define ECMerchandise_hpp

#include <string>

/*
Imagine you are hired to write an onliine Tennis merchandise 
ordering software (if you have never ordered tennis items 
online, search it up and there are quite a few such ratailers). 
To be specific, you need to support tennis ordering of: 
- tennis shoe
- tennis ball cans (each can hold a small number of balls)
- tennis bags (each bag can hold several racquets). 
As you know, there are different vendors: Adidas, Nike and Head, 
among others. Note: the retailer wants the flexibility of adding 
a new vendor or removing a specific vendor. Thus, you want to 
use a design pattern to make tennis ordering (in particular, object creation)
 flexible so that your code can be easily 
 modified to allow different vendors.
 */

// your code goes here

using namespace std;

class ECMerch {
    public:
        ECMerch() {};
        virtual ~ECMerch() {};
        virtual void setPrice(int p) {price = p;};
        virtual int getPrice() {return price;};
    private:
        int price;
};

class ECTennisShoe : public ECMerch {
    public:
        ECTennisShoe(int p, int s) : size(s) {setPrice(p);};
        ~ECTennisShoe() {};
        void setSize(int s) {size = s;};
        int getSize() {return size;};
        void setBrand(string b) {brand = b;};
        string getBrand() {return brand;};
    private:
        int size;
        string brand;
};

class ECTennisBallCan : public ECMerch {
    public:
        ECTennisBallCan(int p, int nballs) : num_balls(nballs) {setPrice(p);};
        ~ECTennisBallCan() {};
        void setNumBalls(int n) {num_balls = n;};
        int getNumBalls() {return num_balls;};
        void setBrand(string b) {brand = b;};
        string getBrand() {return brand;};
    private:
        int num_balls;
        string brand;
};

class ECTennisBag : public ECMerch {
    public:
        ECTennisBag(int p, int capacity) : raquet_capacity(capacity) {setPrice(p);};
        ~ECTennisBag() {};
        int getRaquetCapacity() {return raquet_capacity;};
        void setRaquetCapacity(int cap) {raquet_capacity = cap;};
        string getBrand() {return brand;};
        void setBrand(string brand_name) {brand = brand_name;};
    private:
        int raquet_capacity;
        string brand;
};


#endif /* ECMerchandise_hpp */
