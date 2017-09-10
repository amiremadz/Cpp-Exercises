/*
 * knn.c
 *
 *  Created on: Dec 1, 2016
 *      Author: Amir
 */

#include "knn.h"


void initialize(KNN_t* knn, const float* features, const int* labels){
	//memcpy_s(knn->features, features, FEATURE_COUNT*REFERENCE_COUNT*sizeof(float));
	//memcpy_s(knn->labels, labels, sizeof(labels));
	int i;
	for(i=0; i < FEATURE_COUNT*REFERENCE_COUNT; i++)
			knn->features[i] = features[i];
	for(i=0; i < REFERENCE_COUNT; i++)
				knn->labels[i] = labels[i];

}


int cmpfunc(const void* a, const void* b){
	return ( (*(dist_t*)a).dist - (*(dist_t*)b).dist );
}


// input: DATA_COUNT
// features: FEATURE_COUNT*REFERENCE_COUNT
// labels: REFERENCE_COUNT
signed char knn_predict(const KNN_t* knn, int k, const float* input, float* likelihood){
	dist_t distance[REFERENCE_COUNT];
	int i, j;
	float feat[FEATURE_COUNT];
	float l1;
	float sum = 0.0;

	for(i = 0; i < REFERENCE_COUNT; i++){

		for(j = 0; j<FEATURE_COUNT; j++)
			feat[j] = knn->features[i*FEATURE_COUNT+j];

		l1 = compute_l1(feat, input);
		distance[i].dist = l1;
		distance[i].label = knn->labels[i];
	}

	qsort(distance, REFERENCE_COUNT, sizeof(dist_t), cmpfunc);

	for(i = 0; i < k; i++){
		sum += distance[i].label;
	}
	sum /= k;
	*likelihood = sum;
	return ((signed char)(sum+0.5));
}

float compute_l1(const float* arr1, const float* arr2){
	float l1_norm = 0;
	int i;
	for(i = 0; i<FEATURE_COUNT; i++)
		l1_norm +=  abs(arr1[i] - arr2[i]);
	return l1_norm;
}


