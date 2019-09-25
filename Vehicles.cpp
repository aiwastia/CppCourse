// Building a car and a bike based on different objects shared or not (dependencies)

class Color{
    char color[];
    int price;
    enum {}
    // case thing for equivalence to price
    
};

class Material{
    char material[];
    int price;
    enum {}
    // case thing for equivalence to price
    
};

class Brand{
    char brand[]
    int price
    enum {}
    // case thing for equivalence to price
};

class Wheel{
    double size; //diameter in m
    double pressure; //pressure in bar
public:
    Wheel(double a, double b) : size(a), pressure(b) {}
    int price() {return round(size*10+pressure*5) ;}
};

class Seat{
    Material mat;
    Color col;
public:
    Seat(Material a, Color b) : mat(a), col(b) {}
    int price() {return mat.price+col.price ;}
};

class Door{
    int child_security
    int electric_window
    Color col
public:
    Door(bool a, bool b, Color c) : col(c) {
        if (a) {child_security=1;} else {child_security=0;}
        if (b) {electric_window=1;} else {electric_window=0;}
    }
    int price() {return 300+electric_window*80+child_security*20+col.price ;}
};

class Pedal{
    double weight, width //in kilograms and m
    int grips
public:
    Pedal(double a, double b, bool c) : weight(a), width(b) {
        if (c) {grips=1;} else {grips=0;}
    }
    int price() {return round(1/weight+0.1/width)+30*grips ;}
};

class Vehicle{
    int nseat,nwheel;
    Color col
    Material mat_seat
    double wheelpressure, wheelsize
    int max_speed;
    Brand brand_veh
public:
    Vehicle(int a, int b, Color c, Material ms, double wp, double ws, int speed, Brand bbr) :
        nseat(a), nwheel(b), col(c), mat_seat(ms), wheelpressure(wp), wheelsize(ws),
        max_speed(speed), brand_veh(bbr) {}
    Wheel wheel_veh(wheelsize,wheelpressure)
    Seat seat_veh(mat_seat,col)
    int price() {return nseat*seat_veh.price+nwheel*wheel_veh.price+brand_veh.price
        +col.price*2+max_speed**2 ;}
};

class Car : public Vehicle {
public:
    Car(int ns, char col, char br) : Vehicle(ns,4,120,col,br) {}
};

class Bike : public Vehicle {
public:
    Bike(char col, char br) : Vehicle(1,2,30,col,br) {}
};

int main{
    Car myfirstcar(5,"Grey","Opel")
    Bike myfirstbike("Black","Equalizer")
};
























