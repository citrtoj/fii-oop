#pragma once
#include "Car.h"

class Dacia final : public Car {
public:
	Dacia() : Car(2000, 30, 120) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual unsigned int FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};