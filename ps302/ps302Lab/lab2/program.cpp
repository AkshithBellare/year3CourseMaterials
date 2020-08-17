#include<iostream>
#include <vector>
#include <unordered_map>

class Inspector {
   private: 
        std::string m_name;
        int m_inspector_id{0};
        double m_per_of_stamping{0};
        double m_pro_of_failing_to_stamp{0};
    public: 
        Inspector() = default;

        Inspector(int id): m_inspector_id{id} {}

        void set_per_of_stamping(double percent) {
           m_per_of_stamping = percent; 
        }

        void set_pro_of_failing_to_stamp(double den) {
            m_pro_of_failing_to_stamp = (1/den);
        }

        double get_per_of_stamping() {
            return m_per_of_stamping;
        }

        double get_pro_of_failing_to_stamp() {
            return m_pro_of_failing_to_stamp;
        }

        void set_name_of_inspector(std::string name) {
            m_name = name;
        }

        std::string get_name_of_inspector() {
            return m_name;
        }

        void print_inspector_details() {
            std::cout << "Inspector name: " << m_name << std::endl;
            std::cout << "Probability of failing to stamp: " << m_pro_of_failing_to_stamp << std::endl;
            std::cout << "Percentage of products stamped: " << m_per_of_stamping << std::endl;
            std::cout << std::endl;
        }
};

int main() {
    double total_failed_inspections{0};
    int number_of_inspectors{0};
    std::cout << "Enter the number of inspectors: " ;
    std::cin >> number_of_inspectors;
    std::unordered_map<std::string, Inspector> inspectorMap;
    for(int i=0; i<number_of_inspectors; ++i) {
        std::string name;
        std::cout << "Enter the name of the inspector: " ;
        std::cin >> name;
        inspectorMap.insert(make_pair(name, Inspector{i}));
        Inspector inspector = inspectorMap[name];
        inspector.set_name_of_inspector(name);

        std::cout << "Enter the probaility of failing to stamp: ";
        double prob{0};
        std::cin >> prob;
        inspector.set_pro_of_failing_to_stamp(prob);

        std::cout << "Enter the percentage of products stamped: ";
        double per{0};
        std::cin >> per;
        inspector.set_per_of_stamping(per);
        total_failed_inspections += inspector.get_per_of_stamping() * inspector.get_pro_of_failing_to_stamp();
    }

    std::cout << "Enter the name of the instructor: ";
    std::string name;
    std::cin >> name;
    Inspector ins = inspectorMap[name];
    std::cout << "solution: " << (ins.get_per_of_stamping() * ins.get_pro_of_failing_to_stamp()) / (total_failed_inspections);
    return 0;
}
//int main() {
//    double total_failed_inspections{0};
//    int num_of_inspectors{0};
//    std::cout << "Enter the number of Inspectors: ";
//    std::cin >> num_of_inspectors;
//    std::unordered_map<std::string, Inspector> inspectorMap;
//    std::vector<Inspector> inspectorList;
//    for(int i=0; i<num_of_inspectors; ++i) {
//        inspectorList.push_back(Inspector{i});
//    }
//
//    std::cout << "Enter Name of Inspectors: " << std::endl;
//    for(int i=0; i<num_of_inspectors; ++i) {
//        std::string name;
//        std::cin >> name;
//        inspectorList[i].set_name_of_inspector(name);
//        inspectorMap.insert(make_pair(name, Inspector{i}));
//        inspectorMap[name].set_name_of_inspector(name)
//    }
//
//    std::cout << "Enter the percentage of products stamped: " << std::endl;
//    for(int i=0; i<num_of_inspectors; ++i) {
//        double percent;
//        std::cout << inspectorList[i].get_name_of_inspector() << ": ";
//        std::cin >> percent;
//        inspectorList[i].set_per_of_stamping(percent);
//    }
//
//    std::cout << "Enter the probability of failing to stamp: " << std::endl;
//    for(int i=0; i<num_of_inspectors; ++i) {
//        double prob;
//        std::cout << inspectorList[i].get_name_of_inspector() << ": ";
//        std::cin >> prob;
//        inspectorList[i].set_pro_of_failing_to_stamp(prob);
//        total_failed_inspections += inspectorList[i].get_per_of_stamping() * inspectorList[i].get_pro_of_failing_to_stamp();
//    }
//    
//    for(int i=0; i<num_of_inspectors; i++) {
//        inspectorList[i].print_inspector_details();
//    }
//
//    std::cout << "Enter the name of the inspector:" ;
//    std::string name_query;
//    std::cin >> name_query;
//
//}