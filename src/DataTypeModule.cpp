/**
 * Copyright (c) 2023, King Abdullah University of Science and Technology
 * All rights reserved.
 *
 * Template project is an R  Template package provided by the STSDS group at KAUST
 *
 **/

#include <data-units/DataType.hpp>

/** Expose C++ class to R to be able to use Wrap and As
 *  Allows C++ to Send and Receive Class object from R
 **/
RCPP_EXPOSED_CLASS(DataType)

/** Expose C++ Object With the Given functions **/
RCPP_MODULE(DataTypeTest){
    using namespace Rcpp;
    class_<DataType>("DataType")
        .constructor<size_t,int>()
        .method("PrintValues",&DataType::PrintVal)
        ;
}