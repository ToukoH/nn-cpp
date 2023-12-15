#ifndef LAYER_HPP
#define LAYER_HPP

#include <iostream>
#include <eigen/Eigen/Dense>
#include "Neuron.hpp"

class Layer {
public:
	Layer(int size);
	Layer(int size, int activationFunction);
	
	void setValue(int index, double value);
	void setNeuron(std::vector<Neuron *> neurons) {
		this -> neurons = neurons;
	}

    std::vector<double> getActivatedValues();
    std::vector<Neuron *> getNeurons() {
    	return this -> neurons;
	}

	Eigen::MatrixXd valuesToMatrix();
	Eigen::MatrixXd actValsToMatrix();
	Eigen::MatrixXd diffValsToMatrix();

private:
	int size;
	std::vector<Neuron *> neurons;
};

#endif
