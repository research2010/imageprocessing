#include "MserParametersCollector.h"

ParametersCollector::ParametersCollector() {

	registerInput(_delta, "delta", pipeline::Optional);
	registerInput(_minArea, "min area", pipeline::Optional);
	registerInput(_maxArea, "max area", pipeline::Optional);
	registerInput(_maxVariation, "max variation", pipeline::Optional);
	registerInput(_minDiversity, "min diversity", pipeline::Optional);
	registerInput(_darkToBright, "dark to bright", pipeline::Optional);
	registerInput(_brightToDark, "bright to dark", pipeline::Optional);
	registerOutput(_parameters, "mser parameters");
}

void
ParametersCollector::updateOutputs() {

	if (!_parameters)
		_parameters = new MserParameters();

	if (_delta.isSet())
		_parameters->delta        = (int)*_delta;

	if (_minArea.isSet())
		_parameters->minArea      = (int)*_minArea;

	if (_maxArea.isSet())
		_parameters->maxArea      = (int)*_maxArea;

	if (_maxVariation.isSet())
		_parameters->maxVariation = *_maxVariation;

	if (_minDiversity.isSet())
		_parameters->minDiversity = *_minDiversity;

	if (_darkToBright.isSet())
		_parameters->darkToBright = *_darkToBright;

	if (_brightToDark.isSet())
		_parameters->brightToDark = *_brightToDark;
}
