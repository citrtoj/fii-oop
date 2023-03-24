#include "Dacia.h"

const char* Dacia::Name() const {
	return "Dacia";
}

unsigned int Dacia::FuelCapacity() const {
	return m_fuelCapacity;
}

unsigned int Dacia::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Dacia::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 8 * m_maxSpeed / 10;
		break;
	case Weather::Snow:
		return 6 * m_maxSpeed / 10;
		break;
	default:
		return m_maxSpeed;
	}
}