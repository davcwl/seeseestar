#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
private:
    //Attributes
    int id;
    std::string name;
    double latitude;
    double longitude;
public:
    //Getters
    int getId() const;
    const std::string& getName() const;
    double getLatitude() const;
    double getLongitude() const;

    //Setters
    void setId(int id);
    void setName(const std::string& name);
    void setLatitude(double latitude);
    void setLongitude(double longitude);

    //Helpers
    std::string toString() const;

    //Contructors
    Node(); //Default
    Node(int id, const std::string& name, double latitude, double longitude);
};

#endif // NODE_H
