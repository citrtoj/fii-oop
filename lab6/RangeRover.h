#pragma once
#include "Car.h"

class RangeRover final : public Car {
public:
	RangeRover() : Car(74, 15, 300) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual double FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};