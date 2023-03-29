#pragma once
#include "Car.h"

class Volvo final : public Car {
public:
	Volvo() : Car(50, 6.6, 180) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual double FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};