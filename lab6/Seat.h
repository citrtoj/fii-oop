#pragma once
#include "Car.h"

class Seat final : public Car {
public:
	Seat() : Car(35, 3.4, 172) {};
private:
	virtual const char* Name() const override final;
	virtual unsigned int FuelCapacity() const override final;
	virtual double FuelConsumption() const override final;
	virtual unsigned int Speed(Weather weather) const override final;
};