
#include "XYZReader.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

//#include <boost/test/unit_test.hpp>
#include "StrUtils.h"

bool my_test()
{
    XYZReader  test_object;
    split_vector_type SplitVecResult;
    split_vector_type latticeResult;
    split_vector_type propertyResult;
    double timeResult;
    std::vector< std::string > lattice_properties;

    std::string instr = "Lattice=\"5.44 0.0 0.0 0.0 5.44 0.0 0.0 0.0 5.44\" Properties=species:S:1:pos:R:3 Time=0.0";
    boost::trim_if(instr, boost::is_any_of("\t ")); // could also use plain boost::trim
    split_in_args(lattice_properties, instr);
    return true;
}

