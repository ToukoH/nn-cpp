#include "../include/Neuron.hpp"

Neuron::Neuron(double value, double bias) {
	this -> setValue(value);
}

Neuron::Neuron(double value, int activationFunction, double bias) {
	this -> setValue(value);
	this -> setBias(bias);

	this -> activationFunction = activationFunction;
}

void Neuron::setValue(double value) {
	this -> value = value;
	activateNeuron();
	differentiate();
}

void Neuron::setBias(double bias) {
	this -> bias = bias;
}

void Neuron::activateNeuron() {
	double input = this -> value + this -> bias;

    switch (activationFunction) {
        case RELU:
            this -> activatedValue = input > 0 ? input : 0;
            break;

        case SIGMOID:
            this -> activatedValue = 1 / (1 + std::exp(-input));
            break;

        case TANH:
            this -> activatedValue = std::tanh(input);
            break;    

        default:
            this -> activatedValue = 1 / (1 + std::exp(-input));
            break;
    }
}

void Neuron::differentiate() {
	double input = this -> activatedValue + this -> bias;

	switch (activationFunction) {
		case RELU:
			this -> differentiatedValue = input ? 1 : 0;
			break;

		case SIGMOID:
			this -> differentiatedValue = (input * (1 - input));
			break;

		case TANH:
			this -> differentiatedValue = (1 - input * input);
			break;

		default:
			this -> differentiatedValue = (input * (1 - input));
			break;
	}
}
