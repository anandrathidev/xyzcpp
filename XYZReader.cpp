#include "XYZReader.h"
#include "StrUtils.h"
#include <string>
#include <set>
#include <fstream>
#include <istream>
#include <iostream>
#include <boost/algorithm/string.hpp>

void XYZReader::load(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        // 1st Line os number of atoms
        if (std::getline(file, line)) {
            atoms_len = std::stoi(line);
        }
        // 2nd line Lattice and properties 
        if (std::getline(file, line)) {
            atoms_desc = line;
            //parse_Lattice_properties(atoms_desc, SplitVec);
            std::string buf = "Lattice=\"5.44 0.0 0.0 0.0 5.44 0.0 0.0 0.0 5.44\" Properties=species:S:1:pos:R:3 Time=0.0";
            parse_Lattice_properties(buf, this->latticeResult, this->propertyResult, this->timeResult);
        }

        while (std::getline(file, line)) {
            // using printf() in all tests for consistency
            std::cout << line.c_str() << std::endl;
        }
        file.close();
    }

}

int parse_int(const std::string& instr) {
    return std::stoi(instr);
}

boost::optional<bool> parse_bool(const std::string& instr) {
    //Parse bool to string
    std::map<std::string, bool> bproperties = { {"T", true }, {"F" , false}, {"True", true}, { "False" , false} };
    auto search = bproperties.find(instr);
    if (search != bproperties.end()) {
        return boost::optional<bool>(search->second);
    }
    return boost::none;
}


void XYZReader::parse_Lattice_properties(std::string& instr, 
    split_vector_type& latticeResult,
    split_vector_type& propertyResult,
    double& timeResult
    ) {
    //Lattice="5.44 0.0 0.0 0.0 5.44 0.0 0.0 0.0 5.44" Properties=species:S:1:pos:R:3 Time=0.0

    std::vector<std::string> dataLine;
    std::vector<std::string> lattice;
    std::vector<std::string> SplitVecResult;
    std::set<std::string> PType = { "R", "I", "S", "L" };
    boost::trim_if(instr, boost::is_any_of("\t ")); // could also use plain boost::trim
    boost::split(lattice, instr, boost::is_any_of("\""), boost::token_compress_on);
    // extract Lattice
    std::cout << lattice.size() << std::endl;
    if (lattice.size() > 0) {
        std::string lattice_str = boost::algorithm::replace_all_copy(lattice[1], "\"", "");
        boost::split(dataLine, lattice[2], boost::is_any_of(" "), boost::token_compress_on);
        boost::split(latticeResult, lattice[1], boost::is_any_of(" "), boost::token_compress_on);
    }
    if (lattice.size() > 1) {
        boost::split(lattice, lattice[2], boost::is_any_of(" "), boost::token_compress_on);
        boost::split(dataLine, lattice[1], boost::is_any_of("="), boost::token_compress_on);
        
        boost::split(propertyResult, dataLine[1], boost::is_any_of(":"), boost::token_compress_on);
        std::vector<std::string> propertyName;
        std::vector<std::string> propertyType;
        std::vector<std::string> propertyCols

        boost::split(dataLine, lattice[2], boost::is_any_of("="), boost::token_compress_on);
        timeResult = std::stod(dataLine[1]);
    }
}

