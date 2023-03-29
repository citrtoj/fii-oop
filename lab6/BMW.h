#pragma once
#include "Car.h"

class BMW final : public Car {
public:
	BMW() : Car(42, 4.6, 194) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual double FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};