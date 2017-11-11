#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int powDetermine(unsigned long long decimal){
  unsigned long long powof2 = 2;
    unsigned long long exponent = 1;
    //determining amount of bits needed to represent the number
    while(decimal>=powof2){
      powof2*=2;
      exponent++;
    }
    return exponent;
}
void bitrepre(unsigned long long decimal, char bitrep[], int exponent){
    //initilizing variables
    //printf("Decimal is %llu\n", decimal);
    //initilizing the bits
    bitrep[exponent-1]='\0';
    bitrep[exponent]='\0';
    //printf("Pow is %llu, exp is %llu, len is at %lu\n", powof2, exponent, strlen(bitrep));
    unsigned long long keeper=2;
    char dig;
    for(long long x = exponent-1; x>=0; x--){
      //printf("x is at %llu\n", x);
      //determining if a bit needs to be a 1 or a 0
      if(decimal%keeper!=0){
        dig = '1';
        decimal-=(keeper/2);
      } else if (decimal%keeper==0){
        dig = '0';
      }
      bitrep[x]=dig;
      keeper*=2;
    }
}
char* decToBinary(unsigned long long decimal){
  int exponent = powDetermine(decimal);
  char* bitRep = (char*)malloc(sizeof(char)*exponent);
  bitrepre(decimal, bitRep, exponent);

  return bitRep;
}
