#pragma once
#include "Car.h"

class Seat final : public Car {
public:
	Seat() : Car(35, 3.4, 172) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual double FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};