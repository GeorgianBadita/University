//
// Created by georg on 11/15/2019.
//
#include "NumberDiff.h"


void numberDiff(std::vector<int> *a, std::vector<int> *B) {
    int carry = 0;
    for(int i =0;i<a->size();i++){
        if(i >= B->size()){
            if(carry == 0){
                return;
            }
            else{
                if((*a)[i] == 0){
                    carry = -1;
                    continue;
                }
                else{
                    (*a)[i] = (*a)[i] + carry;
                    break;
                }
            }
        }
        else{
            (*a)[i] = (*a)[i] + carry;
            carry = 0;
            if((*a)[i] >= (*B)[i]){
                (*a)[i] = (*a)[i] - (*B)[i];
            }
            else{
                (*a)[i] = (*a)[i] - (*B)[i] + 10;
                carry = -1;
            }
        }
    }
}
