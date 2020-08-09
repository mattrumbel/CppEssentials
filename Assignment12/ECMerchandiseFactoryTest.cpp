//
//  ECMerchandiseFactory.cpp
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#include "ECMerchandiseFactory.h"
#include <iostream>

using namespace  std;

//*****************************************************
// now test code

void TestTennisOrdering()
{
    ECTennisShoe *ps1 = ECMerchandiseTennisShop::Instance().OrderTennisShoe(11);
    ECTennisBallCan *pc1 = ECMerchandiseTennisShop::Instance().OrderTennisBallCan();
    ECTennisBag *pb1 = ECMerchandiseTennisShop::Instance().OrderTennisBag();
    // switch to Nike
    ECMerchandiseTennisShop ::Instance().ChooseVendor(TENNIS_NIKE);
    ECTennisShoe *ps2 = ECMerchandiseTennisShop::Instance().OrderTennisShoe(10);
    ECTennisBallCan *pc2 = ECMerchandiseTennisShop::Instance().OrderTennisBallCan();
    ECTennisBag *pb2 = ECMerchandiseTennisShop::Instance().OrderTennisBag();
    // switch to Head
    ECMerchandiseTennisShop ::Instance().ChooseVendor(TENNIS_HEAD);
    ECTennisShoe *ps3 = ECMerchandiseTennisShop::Instance().OrderTennisShoe(12);
    ECTennisBallCan *pc3 = ECMerchandiseTennisShop::Instance().OrderTennisBallCan();
    ECTennisBag *pb3 = ECMerchandiseTennisShop::Instance().OrderTennisBag();
    
    // dump out statistics
    cout << "Total number shoes sold: " << ECMerchandiseTennisShop::Instance().GetNumShoesSold() << endl;
    cout << "Total number of ball cans sold: " << ECMerchandiseTennisShop::Instance().GetNumBallcansSold() << endl;
    cout << "Total number of bags sold: " << ECMerchandiseTennisShop ::Instance().GetNumBagsSold() << endl;
    cout << "Total number of balls sold: " << ECMerchandiseTennisShop ::Instance().GetTotNumBallsSold() << endl;
    cout << "Total number of racquet capacity in bag sold: " << ECMerchandiseTennisShop ::Instance().GetTotRacquetBagCapaictySold() << endl;
    cout << "Total revenue: " << ECMerchandiseTennisShop ::Instance().GetTotRevenue() << endl;
    
    delete ps1;
    delete pc1;
    delete pb1;
    delete ps2;
    delete pc2;
    delete pb2;
    delete ps3;
    delete pc3;
    delete pb3;
}

int main()
{
    TestTennisOrdering();
    return 0;
}

