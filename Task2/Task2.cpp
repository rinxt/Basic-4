#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city_name;
    std::string street_name;
    int house_number;
    int apartment_number;

public:
    Address() {}
    Address(std::string city_name, std::string street_name, int house_number, int apartment_number) {
        this->city_name = city_name;
        this->street_name = street_name;
        this->house_number = house_number;
        this->apartment_number = apartment_number;
    }

    std::string get_output_address() {
        return city_name + ", " + street_name + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
    }

    std::string get_city_name() const {
        return city_name;
    }
};

void sort_addresses(Address* addresses, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (addresses[j].get_city_name() > addresses[j+1].get_city_name()) {
                Address temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j+1] = temp;
            }
        }
    }
}

int main() {
    std::ifstream input_file("in.txt");
    std::ofstream output_file("out.txt");
    int n;
    input_file >> n;

    Address* addresses = new Address[n];

    for (int i = 0; i < n; i++) {
        std::string city_name;
        std::string street_name;
        int house_number;
        int apartment_number;
        input_file >> city_name >> street_name >> house_number >> apartment_number;
        Address new_address(city_name, street_name, house_number, apartment_number);
        addresses[i] = new_address;
    }

    sort_addresses(addresses, n);

    output_file << n << std::endl;
    for (int i = 0; i < n; i++) {
        output_file << addresses[i].get_output_address() << std::endl;
    }

    delete[] addresses;

    return 0;
}
