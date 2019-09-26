// Building a car and a bike based on different objects shared or not (dependencies)
#include <iostream>
#include <cmath>
using namespace std;


enum color_type { red=40,blue=50,yellow=25,grey=35,black=42,
    white=10,green=5,brown=37,purple=47,orange=20};

enum material_type { plastic=5,leather=50,fluff=35,cloth=30,warm=100 };

enum brand_type { Opel=300,Yamaha=200,VW=800,AR=1200,Porsche=1700 };


class Wheel{
    double size; //diameter in m
    double pressure; //pressure in bar
public:
    Wheel(double a, double b) : size(a), pressure(b) {}
    int price() {return int(size*10+pressure*5) ;}
};


class Seat{
    material_type mat;
    color_type col;
public:
    Seat(material_type a, color_type b) : mat(a), col(b) {}
    int price() {return mat+col ;}
};


class Door{
    int child_security;
    int electric_window;
    color_type col;
public:
    Door(bool a, bool b, color_type c) : col(c) {
        if (a) {child_security=1;} else {child_security=0;}
        if (b) {electric_window=1;} else {electric_window=0;}
    }
    int price() {return 300+electric_window*80+child_security*20+col ;}
};


class Pedal{
    double weight, width; //in kilograms and m
    int grips;
public:
    Pedal(double a, double b, bool c) : weight(a), width(b) {
        if (c) {grips=1;} else {grips=0;}
    }
    int price() {return int(1/weight+0.1/width)+30*grips ;}
};


class Vehicle{
public:
    int nseat,nwheel;
    color_type col;
    material_type mat_seat;
    float max_speed;
    brand_type brand_veh;

    //double wheelpressure, wheelsize;
    Vehicle(int a, int b, color_type c, material_type ms,// double wp, double ws,
            float speed, brand_type bbr) :
        nseat(a), nwheel(b), col(c), mat_seat(ms),// wheelpressure(wp), wheelsize(ws),
        max_speed(speed), brand_veh(bbr) {}
    //Wheel wheel_veh(double wheelsize, double wheelpressure);
    //Seat seat_veh(double mat_seat, double col);
    int price() {return // nseat*seat_veh(mat_seat,col).price +nwheel*wheel_veh(wheelsize,wheelpressure).price()
        +brand_veh
        +col*2+pow(max_speed,2) ;}
};

class Car : public Vehicle {
public:
    Car(int ns, color_type col, material_type mat, brand_type br) :
    Vehicle(ns,4,col,mat,//2,0.4,
            120,br) {}
    // SOMETHING WITH DOORS
};

class Bike : public Vehicle {
public:
    Bike(color_type col, material_type mat, brand_type br) :
    Vehicle(1,2,col,mat,//0.2,0.6,
            30,br) {}
    // SOMETHING WITH PEDALS
};

int main() {
    Car myfirstcar(5,grey,leather,Opel);
    Bike myfirstbike(black,plastic,Yamaha);
    
    cout << myfirstcar.price() << endl;
    cout << myfirstcar. << endl;
    
    return 0;
}
























