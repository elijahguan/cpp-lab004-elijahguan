#include "Person.h"

// TODO: Implement default constructor and parameterized constructor with validation.
Person::Person()
    : name_("Unknown"), id_("0000"), email_("unknown@school.edu") {} //member initialization list; preferred over assigning inside the body

// Validate inputs and initialize members. Throws std::invalid_argument on bad input.
Person::Person(std::string name, std::string id, std::string email) {
    if (name.empty()) {
        throw std::invalid_argument("name cannot be empty");
    }
    if (id.empty()) {
        throw std::invalid_argument("id cannot be empty");
    }
	if (email.empty() || email.find('@') == std::string::npos) { //find returns index of first occurrence or std::string::npos if not found
        throw std::invalid_argument("invalid email");
    }

    name_ = std::move(name); //transfer resources when possible instead of copying string ie (name_ = name)
    id_ = std::move(id);
    email_ = std::move(email);
}

//TODO: Implement getName and setName methods.
const std::string& Person::getName() const noexcept {
    return name_;
}
void Person::setName(const std::string& name) {
    name_ = name;
}


// TODO: Implement getId and setId methods.
const std::string& Person::getId() const noexcept {
    return id_;
}
void Person::setId(const std::string& id) {
    id_ = id;
}

// TODO: Implement getEmail and setEmail methods.
const std::string& Person::getEmail() const noexcept {
    return email_;
}
void Person::setEmail(const std::string& email) {
	email_ = email;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getName() << " (" << person.getId() << ")";
    return os;
}
