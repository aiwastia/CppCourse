// Building a car and a bike based on different objects shared or not (dependencies)
#include <iostream>
#include <cmath>
#include <vector>
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
    double wheelpressure, wheelsize;
    int seatprice,wheelprice;
    //vector<Seat*> seats;
    
    Vehicle(int,int,color_type,material_type,double,double,float,brand_type);
    int price() {return seatprice+wheelprice+brand_veh+col*2+pow(max_speed/10.,2)*10 ;}
};


Vehicle :: Vehicle(int a, int b, color_type c, material_type ms,double wp, double ws,
                   float speed, brand_type bbr) :
            nseat(a), nwheel(b), col(c), mat_seat(ms),wheelpressure(wp), wheelsize(ws),
            max_speed(speed), brand_veh(bbr) {
                
                Seat seat_veh(mat_seat,col);
                Wheel wheel_veh(wheelpressure,wheelsize);
                
                seatprice=nseat*seat_veh.price();
                wheelprice=nwheel*wheel_veh.price();
                /*for (int i=0; i<nseat; i++) {
                    seats.push_back(new Seat(mat_seat, col));
                    seatprice+=seats[i]->price();
                    std::cout << seatprice << std::endl;
                }*/
}



class Car : public Vehicle {
public:
    int doorprice,vehprice;
    
    Car(int, color_type, material_type, brand_type);
    int price() {return doorprice+vehprice;}
};


Car :: Car(int ns, color_type col, material_type mat, brand_type br) :
        Vehicle(ns,4,col,mat,2,0.4,120,br) {
            
            Door door_car(true,true,col);
            Vehicle veh(ns,4,col,mat,2,0.4,120,br);
            
            doorprice=4*door_car.price();
            vehprice=10*veh.price();
}


class Bike : public Vehicle {
public:
    int pedalprice,vehprice;
    
    Bike(color_type, material_type, brand_type);
    int price() {return pedalprice+vehprice;}
};


Bike :: Bike(color_type col, material_type mat, brand_type br) :
            Vehicle(1,2,col,mat,0.2,0.6,30,br) {
                
                Pedal pedal_bike(0.1,0.01,false);
                Vehicle veh(1,2,col,mat,0.2,0.6,30,br);
                
                pedalprice=2*pedal_bike.price();
                vehprice=veh.price();
            }

int main() {
    Car myfirstcar(5,yellow,leather,VW);
    Bike myfirstbike(black,cloth,Yamaha);
    
    cout << myfirstcar.nwheel << endl;
    cout << myfirstcar.price() << endl;
    cout << myfirstbike.nwheel << endl;
    cout << myfirstbike.price() << endl;
    
    return 0;
}
























