#pragma once

#include <string>
#include <vector>
#include <tuple>
#include  <exception>
#include <map>
#include <boost/optional.hpp>

typedef std::vector< std::tuple<char, double, double, double> > ATOM_ARRAY;
typedef std::vector< std::string > split_vector_type;

struct XYZProperties {
    std::string names;
    std::string dtype;
    std::string convs;
};

class XYZReader {
    std::int64_t atoms_len;
    std::string atoms_desc;
    ATOM_ARRAY atoms;
    split_vector_type latticeResult;
    split_vector_type propertyResult;
    double timeResult;

public:
    void load(const std::string& filename);
    void parse_Lattice_properties(std::string& instr,
        split_vector_type& latticeResult,
        split_vector_type& propertyResult,
        double& timeResult);
};

int parse_int(const std::string& instr);
boost::optional<bool> parse_bool(const std::string& instr);

class XYZHeadParser {

/*
    std::map<char, bool>  fmt_map = { 'R': ('d', float),
               'I' : ('i', int),
               'S' : (object, str),
               'L' : ('bool', parse_bool) }
               */
    std::vector<std::string> properties_list;
    std::vector<std::string> dtypes;
    std::vector<std::string> converters;

/*
    void parse_properties(const std::vector<std::string>& prop_vec) {
        for name, ptype, cols in zip(fields[::3], fields[1::3], [int(x) for x in fields[2::3]]) :
            if ptype not in('R', 'I', 'S', 'L') :
                raise ValueError('Unknown property type: ' + ptype)
                ase_name = REV_PROPERTY_NAME_MAP.get(name, name)

                dtype, converter = fmt_map[ptype]
                if cols == 1 :
                    dtypes.append((name, dtype))
                    converters.append(converter)
                else:
        for c in range(cols) :
            dtypes.append((name + str(c), dtype))
            converters.append(converter)

            properties[name] = (ase_name, cols)
            properties_list.append(name)

            dtype = np.dtype(dtypes)
            return properties, properties_list, dtype, converters

    }
    */

};
