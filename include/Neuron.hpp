#ifndef NEURON_HPP
#define NEURON_HPP

#include <iostream>
#include <cmath>

#define RELU 1
#define SIGMOID 2
#define TANH 3

class Neuron {
public:
	Neuron(double value);
	Neuron(double value, int activationFunction);

	void setValue(double value);
	void activateNeuron();
	void differentiate();

	double getValue() {
		return this->value;
	}

	double getActivatedValue(){
		return this->activatedValue;
	}

	double getDifferentiatedValue() {
		return this->differentiatedValue; 
	}

private:
	double value;
	double activatedValue;
	double differentiatedValue;
	int activationFunction;
};

#endif