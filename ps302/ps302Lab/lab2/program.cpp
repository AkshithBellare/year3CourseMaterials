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
           m_per_of_stamping = percent/100; 
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
        inspectorMap[name].set_name_of_inspector(name);

        std::cout << "Enter the probaility of failing to stamp: ";
        double prob{0};
        std::cin >> prob;
        inspectorMap[name].set_pro_of_failing_to_stamp(prob);

        std::cout << "Enter the percentage of products stamped: ";
        double per{0};
        std::cin >> per;
        inspectorMap[name].set_per_of_stamping(per);
        total_failed_inspections += inspectorMap[name].get_per_of_stamping() * inspectorMap[name].get_pro_of_failing_to_stamp();
    }

    std::cout << std::endl <<  "Enter the name of the instructor: ";
    std::string name;
    std::cin >> name;
    std::cout << "P( a package being checked by " << name << " ) = " << inspectorMap[name].get_per_of_stamping() << std::endl;
    std::cout << "P( " << name << " failing to check a package ) = " << inspectorMap[name].get_pro_of_failing_to_stamp() << std::endl;
    std::cout << "P( a package not stamped and checked by " << name << " ) = " <<  (inspectorMap[name].get_per_of_stamping() * inspectorMap[name].get_pro_of_failing_to_stamp()) / (total_failed_inspections) << std::endl;
    return 0;
}