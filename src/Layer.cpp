#include "../include/Layer.hpp"
using Eigen::MatrixXd;

Layer::Layer(int size) {
	this -> size = size;

	for (uint i = 0; i < size; i++) {
		Neuron *neuron = new Neuron(0.0);
		this -> neurons.push_back(neuron);
	}
}

Layer::Layer(int size, int acticationFunction) {
	this -> size = size;

	for (uint i = 0; i < size; i++) {
		Neuron *neuron = new Neuron(0.0, acticationFunction);
		this -> neurons.push_back(neuron);
	}
}

void Layer::setValue(int index, double value) {
	this->neurons.at(index)->setValue(value);
}

std::vector<double> Layer::getActivatedValues() {
	std::vector<double> values;

	for (uint i = 0; i<neurons.size(); i++) {
		double value = this -> neurons.at(i) -> getActivatedValue();
		values.push_back(value);
	}

	return values;
}

MatrixXd Layer::valuesToMatrix() {
	MatrixXd matrix(1, this -> neurons.size());

	for (int i = 0; i < this -> neurons.size(); i++) {
		matrix(0, i) = this -> neurons.at(i)->getValue();
	}

	return matrix;
}

MatrixXd Layer::actValsToMatrix() {
	MatrixXd matrix(1, this -> neurons.size());

	for (int i = 0; i < this -> neurons.size(); i++) {
		matrix(0, i) = this -> neurons.at(i)->getActivatedValue();
	}

	return matrix;
}

MatrixXd Layer::diffValsToMatrix() {
	MatrixXd matrix(1, this -> neurons.size());

	for (int i = 0; i < this -> neurons.size(); i++) {
		matrix(0, i) = this -> neurons.at(i)->getDifferentiatedValue();
	}

	return matrix;
}
