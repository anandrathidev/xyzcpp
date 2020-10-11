
#include "XYZReader.h"

//#include <boost/test/unit_test.hpp>
bool my_test()
{
    XYZReader  test_object;
    split_vector_type SplitVecResult;
    split_vector_type latticeResult;
    split_vector_type propertyResult;
    double timeResult;
    std::string buf = "Lattice=\"5.44 0.0 0.0 0.0 5.44 0.0 0.0 0.0 5.44\" Properties=species:S:1:pos:R:3 Time=0.0";
    test_object.parse_Lattice_properties(buf, latticeResult, propertyResult, timeResult);
    return true;
}
