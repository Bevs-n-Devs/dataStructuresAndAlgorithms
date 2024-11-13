#include <iostream>

/**
 * Object Oriented Programming (OOP) is based on 4 principles
 * 
 * 4 Pillars of OOP
 *      * Abstraction : Hiding unnecessary properties/methods from external users
 *      * Encapsulation : Hiding properties/methods from external use/manipulation
 *      * Inheritance : When a child class inherits properties and/or methods from a parent class
 *      * Polymophism : When the same function behaves in different ways for each object type (context)
 * 
 */


/**
 * Base/Parent Class
 * Containing the foundation of vehicle types
 */
class Vehicle{
    // In C++ class properties & methods are private
    // by default, so to make them available for external
    // use the 'public' keyword is used
    public:
    int wheels_count, door_count;
    bool engine_running;
    char* color;

    Vehicle(char* col=(char*)"blue"){
        engine_running = false;
        color = col;
    }
    /**
     * Permits polymorphism at runtime
     */
    virtual void drive() const {
        std::cout << "I am driving" << std::endl;
    };
    virtual void open_doors() const {
        std::cout << "I am opening the doors" << std::endl;
    };
    void reverse(){
        std::cout << "I am reversing" << std::endl;
    }
    void start_engine() {
        std::cout << "I am starting engine" << std::endl;
    }
    void stop_engine(){
        std::cout << "I am stopping engine" << std::endl;
    }
};

/**
 * Inheriting Base class "Vehicle"
 */
class Car: public Vehicle{
     
    private:
    /**
     * Example of Encapsulation, hiding this value
     * so the user cannot change it
     */
    const int cylinders = 4;

    /**
     * Example of Abstraction
     * setting this method private as it is not
     * needed externally by the user, and should 
     * not be changed.
     * Sets the door & wheel count for the Car
     */
    void set_structure(){
        this->door_count = 4;
        this->wheels_count = 4;
    }
    public:
    Car(char* colr){
        color = colr;
        set_structure();
        std::cout << "I am a new " << color << " car, rolling all " << this->wheels_count << " tires." << std::endl;
    }

    /**
     * Polmorphism Example
     * The base/parent class function is overwritten
     * with this new implementation for this class 
     */
    void drive() const override {
        std::cout << "I am a new " << color << " car driving, rolling all " << this->wheels_count << " tires." << std::endl; 
    }

    void open_doors() const override {
        std::cout << "Opening all " << this->door_count << " doors" << std::endl;
    };
};

class Truck: public Vehicle{
    private:
    const int cylinders = 8;
    /**
     * Sets the door & wheel count for the Truck
     */
    void set_structure(){
        this->door_count = 2;
        this->wheels_count = 4;
    }

    public:
    Truck(char* colr){
        set_structure();
        color = colr;
        std::cout << "I am a new " << color << " truck" << std::endl;
    }

    void open_doors() const override {
        std::cout << "Opening " << this->door_count << " doors" << std::endl;
    };
};

int main() {
    Truck *truck = new Truck((char*)"red");
    Car *car = new Car((char*)"green");
    truck->drive();
    car->drive();
    truck->open_doors();
    car->open_doors();
}