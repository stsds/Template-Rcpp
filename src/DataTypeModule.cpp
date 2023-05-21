
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