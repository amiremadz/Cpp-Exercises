/*
 * mymain.c
 *
 *  Created on: Dec 1, 2016
 *      Author: Amir
 */



#include "knn.h"



/* Features for all the test data */
static float _X[DATA_COUNT][FEATURE_COUNT];
/* Labels for all the data */
static int _Y[DATA_COUNT];
/* Parameters for multiple KNNs (including the constant) */

/* Multiple _predictors */
static KNN_t _predictors[BATCH_COUNT];
static float _params[BATCH_COUNT][FEATURE_COUNT*REFERENCE_COUNT];
static int _labels[BATCH_COUNT][REFERENCE_COUNT];
const char * k_data_filename = "data.txt";
const char * k_params_filename = "params.txt";


/***********************************************************************************************************************
*
* Loads all test features and labels from the file data.txt and stores them in the arrays _X and _Y.
*
***********************************************************************************************************************/
static void loadDataFromFile() {
    int i, j;

    int label;
    FILE *fid;

    fid = fopen(k_data_filename, "r");

    if (fid == NULL) {
        printf("bad filename");
        exit(0);
    }

    for (i = 0; i < DATA_COUNT; i++) {
        for (j = 0; j < FEATURE_COUNT; j++) {
            fscanf(fid, "%f", &_X[i][j]);
	}
    }
    for (i = 0; i < DATA_COUNT; i++) {
        fscanf(fid, "%i", &label);
        _Y[i] = (int) label;
    }
    fclose(fid);
}

/***********************************************************************************************************************
*
* Loads parameters for all KNNs from the files params.txt and labels.txt and stores them in the 2-D arrays _params and _labels
* Each row of the _params array contains all of the reference vectors for one KNN. Similarly, each row of the _labels array
* contains all of the reference labels for one KNN
* NOTE: we use the convention that the _params vector for a single KNN is ordered as : [refvec1, refvec2, refvec3, ... refvecN],
* where each refvec is a row of length FEATURE_COUNT
*
***********************************************************************************************************************/
static void loadParamsFromFile() {
    int i, j;

    FILE *fid;

    fid = fopen(k_params_filename, "r");

    if (fid == NULL) {
        printf("bad filename");
        abort();
    }

    for (i = 0; i < BATCH_COUNT; i++) {
        for (j = 0; j < FEATURE_COUNT*REFERENCE_COUNT; j++) {
            fscanf(fid, "%f", &_params[i][j]);
        }
        for (j = 0; j < REFERENCE_COUNT; j++){
            fscanf(fid, "%i", &_labels[i][j]);
        }

        /******************************************** YOUR CODE GOES HERE *********************************************/
        /* In the line below, initialize the ith KNN with the loaded parameters*/

        /**************************************************************************************************************/
        initialize(&_predictors[i], _params[i], _labels[i]);


    }
    fclose(fid);
}

/***********************************************************************************************************************
*
* Evaluates the performance of our KNN training algorithm.
*
***********************************************************************************************************************/
static void evaluateKNNPerformance(){
    unsigned int i, j;
    unsigned int positiveCount, negativeCount, falsePositiveCount, falseNegativeCount;

    float fpr, fnr;
    float *query;

    signed char prediction = 0;


    fpr = 0.f;
    fnr = 0.f;

    positiveCount = 0;
    negativeCount = 0;
    falsePositiveCount = 0;
    falseNegativeCount = 0;

    for (i = 0; i < BATCH_COUNT; i++) {
        for (j = i; j < DATA_COUNT; j += BATCH_COUNT) {
            query = _X[j];

            /****************************************** YOUR CODE GOES HERE *******************************************/
            /* In the line below, evaluate predictor on query and place the result in the variable prediction.        */
            /* Use a k value of 10                                                                                    */

            /**********************************************************************************************************/

            float likelihood;
            prediction = knn_predict(&_predictors[i], 10, query, &likelihood);

            if (_Y[j] == 1) {
                positiveCount++;
                if (prediction != 1) {
                    falseNegativeCount++;
                }
            } else if (_Y[j] == 0) {
                negativeCount++;
                if (prediction != 0) {
                    falsePositiveCount++;
                }
            }
        }
    }

    fpr = ((float) falsePositiveCount)/negativeCount;
    fnr = ((float) falseNegativeCount)/positiveCount;

    printf("fpr = %4.2f%%, fnr = %4.2f%%\n", 100*fpr, 100*fnr);
}

int main(void) {
    loadDataFromFile();
    loadParamsFromFile();
    evaluateKNNPerformance();
    return 0;
}


