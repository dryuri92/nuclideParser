#ifndef SRC_REACTIONS_H_
#define SRC_REACTIONS_H_
#include <vector>
#include <map>
#include <iostream>
#include "../extern/pugiData/pugixml.h"

namespace openbps {


//?
//struct s_nuclides_ {

//    std::string nuclide_name;
//    double nuclide_conc;
//    int nuclide_ind;
//    double nuclide_mass;

//};

struct s_xs_ {
    std::string xsname;
    std::string xstype;
    std::vector<double> rxs_;
    std::vector<double> xs_;
};

class Composition {
public:
    size_t nuclide_number;
    size_t energy_number;
    std::string name;
    Composition(){};
    Composition(pugi::xml_node node);
    ~Composition() {std::cout << "Composition " + name + " destroyed\n";};

private:
    //std::vector<s_nuclides_>  nuclides_;
    std::vector<s_xs_>  xslib_;
    std::map<size_t, std::vector<double>> energies_;
    std::vector<std::string> namenuclides_;
    std::vector<double> spectrum_;
    std::vector<double> conc_;
    std::vector<double> flux_;
    void parse_compos_xml_(pugi::xml_node node);
    s_xs_ parse_xs_xml_(pugi::xml_node node);

}



void read_reactions_xml();
extern std::vector<Composition> compositions;
extern std::map<std::string, int> composmap;
extern size_t indexall;
}

#endif /* SRC_REACTIONS_H_ */