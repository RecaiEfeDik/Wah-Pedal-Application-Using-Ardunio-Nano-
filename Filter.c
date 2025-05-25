
#include "Filter.h"

float a_array[8][3] = {
	{1, -1.9416, 0.9658},
	{1, -1.8390, 0.9336},
	{1, -1.6964, 0.9040},
	{1, -1.5188, 0.8774},
	{1, -1.3112, 0.8543},
	{1, -1.0796, 0.8350},
	{1, -0.8262, 0.8198},
	{1, -0.5590, 0.8089}
};

float b_array[8][3] = {
	{0.0171, 0, -0.0171},
	{0.0332, 0, -0.0332},
	{0.0480, 0, -0.0480},
	{0.0613, 0, -0.0613},
	{0.0728, 0, -0.0728},
	{0.0825, 0, -0.0825},
	{0.0901, 0, -0.0901},
	{0.0956, 0, -0.0956}
};


float* insert_and_shift(float input, float* x)
{
	float* output = (float*)malloc(sizeof(float) * 3);
	output[0] = input;
	for(uint8_t i=0; i<2; i++)
		output[i+1] = x[i];
		
	return output;
}

float calculate_output(float* x, float* y, uint8_t filter_index)
{
	float y_n = b_array[filter_index][0]*x[0] + b_array[filter_index][1]*x[1] +  b_array[filter_index][2]*x[2] - a_array[filter_index][1]*x[1] + - a_array[filter_index][2]*x[2];
	return y_n; 
}