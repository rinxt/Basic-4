#include <iostream>
#include <fstream>
#include <string>

class Address {
public:
    Address() {}
    Address(std::string city, std::string street, int house_num, int apt_num)
        : city_(city), street_(street), house_num_(house_num), apt_num_(apt_num) {}

    std::string get_output_address() {
        return city_ + ", " + street_ + ", " + std::to_string(house_num_) + ", " + std::to_string(apt_num_);
    }

private:
    std::string city_;
    std::string street_;
    int house_num_;
    int apt_num_;
};

int main() {
    system("chcp 1251");

    std::ifstream fin("in.txt");
    int n;
    fin >> n;
    Address* addresses = new Address[n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int house_num, apt_num;
        fin >> city >> street >> house_num >> apt_num;
        Address address(city, street, house_num, apt_num);
        addresses[i] = address;
    }
    fin.close();

    std::ofstream fout("out.txt");
    fout << n << std::endl;

    for (int i = n - 1; i >= 0; i--) {
        fout << addresses[i].get_output_address() << std::endl;
    }
    fout.close();

    delete[] addresses;

    return 0;
}
