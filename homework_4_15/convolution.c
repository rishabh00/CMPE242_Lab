#include<stdio.h>
#include<math.h>
#include <stdlib.h> 

float gauss(float sigma, float x) {
    float expVal = -1 * (pow(x, 2) / pow(2 * sigma, 2));
    float divider = sqrt(2 * M_PI * pow(sigma, 2));
    return (1 / divider) * exp(expVal);
}


int main(){
    int no_input;

    float sigma = 1;

    printf("Enter number of value you want to enter: ");
    scanf("%d", &no_input);
    if( no_input <= 5 ){
        printf("Too small database, try again with large number (>5)\n");
        return  0;
    }

    float *array_ptr = malloc(no_input*sizeof(float));

    if( array_ptr == NULL )
        return 0;

    for(int i=0; i<no_input;i++){
        scanf("%f",&array_ptr[i]);
    }

    printf("Values :\n[");
    for(int i=0; i<no_input; i++){
        printf("%f ",array_ptr[i]);
    }
    printf("]\n\n");

    printf("Computting derivative with central difference kernel\n");
    printf("[");
    for(int index=1; index<no_input-1; index++){
        printf("%f ", (array_ptr[index+1] - array_ptr[index-1])/2);
    }
    printf("]\n\n");

    printf("Performing convolution with Gaussian kernel to remove noise (low pass filter)\n");
    printf("[");
    for(int index=0; index<no_input; index++){
        printf("%f ",gauss(sigma,array_ptr[index]) );
    }
    printf("]\n");

    return 0;
}


