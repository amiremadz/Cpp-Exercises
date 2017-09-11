/*
 * knn.h
 *
 *  Created on: Dec 1, 2016
 *      Author: Amir
 */

#ifndef KNN_H_
#define KNN_H_

#include <stdio.h>
#include <stdlib.h>


#define BATCH_COUNT 4    //number of predictors
#define DATA_COUNT 100   //number of classification data samples
#define REFERENCE_COUNT 300 //number of reference feature vectors per classifier
#define FEATURE_COUNT 3 //number of features

typedef struct{
	signed char prediction;
	float features[FEATURE_COUNT*REFERENCE_COUNT];
	float labels[REFERENCE_COUNT];
} KNN_t;


typedef struct{
	float dist;
	int label;
} dist_t;

void initialize(KNN_t* knn, const float* features, const int* labels);

signed char knn_predict(const KNN_t* knn, int k, const float* input, float* likelihood);

float compute_l1(const float* arr1, const float* arr2);


#endif /* KNN_H_ */
