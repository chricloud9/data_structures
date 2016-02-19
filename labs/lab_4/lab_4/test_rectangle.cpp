#include <iostream>
#include "Rectangle.h"
using namespace std;
int main(){
    Point2D point(1,2);
    Point2D zero;
    Point2D twothree(2,3);
    Point2D threetwo(3,2);
    Point2D twotwo(2,2);
    point.set(3,4);
    cout << twothree.x() << twothree.y() <<endl;
    Rectangle r1(zero,twothree);
    Rectangle r2(zero,threetwo);
    print_rectangle(r1);
    print_rectangle(r2);
    cout << r1.is_point_within(twotwo) << endl;
    cout << r1.is_point_within(threetwo) << endl;
    cout << r2.is_point_within(twotwo) << endl;
    cout << r1.is_point_within(twothree) << endl;
    cout << "above should all be true,false,true,false" << endl;
    r1.add_point(twotwo);
    r2.add_point(twotwo);
    print_rectangle(r1);
    print_rectangle(r2);
    vector<Point2D> p_in_both;
    p_in_both=points_in_both(r1,r2);
    cout << p_in_both.size() << "<-Should be 1\n" << p_in_both[0].x() << "<-should be 2\n"
    <<p_in_both[0].y()<<"<-should be 2"<<endl;

    return 0;
}