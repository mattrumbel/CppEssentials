#include <iostream>
#include <assert.h>
#include "EC2DShape.h"

using namespace std;

int main(void) {

    // basic point intersections
    ECRectangle *prect1 = new ECRectangle(1,1,5,7);
    ECRectangle *prect6 = new ECRectangle(0,2,3,9);

    cout << true << " : " << prect1->IsIntersectShape(*prect6) << endl;

    return 0;
}