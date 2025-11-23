#include "node.h"
#include <sstream>
//Contructor implementations

Node::Node()
    : id(-1), name("untitled node"), latitude(0.0), longitude(0.0) {}

Node::Node(int id, const std::string& name, double latitude, double longitude)
    : id(id), name(name), latitude(latitude), longitude(longitude) {}

//Getter implementations
int Node::getId() const {
    return this->id;
}

const std::string& Node::getName() const {
    return this->name;
}

double Node::getLatitude() const {
    return this->latitude;
}

double Node::getLongitude() const {
    return this->longitude;
}

//Setter implementations
void Node::setId(int id) {
    this->id = id;
}

void Node::setName(const std::string& name) {
    this->name = name;
}

void Node::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Node::setLongitude(double longitude) {
    this->longitude = longitude;
}

//Helper implementations
std::string Node::toString() const {
    std::ostringstream oss;
    oss << "Node("
        << "id=" << id
        << ", name=\"" << name << "\""
        << ", lat=" << latitude
        << ", lon=" << longitude
        << ")";
    return oss.str();
}
