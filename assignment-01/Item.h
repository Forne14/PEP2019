#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cmath>


// TODO: your code  goes here
class Item{
private:
    double latitude;
    double longitude;
    string ID;
    int time;


public:
    Item(double initLatitude, double initLongitude, string initID,int initTime)
    :latitude(initLatitude),longitude(initLongitude),ID(initID),time(initTime) {}

    Item()
    :latitude(0),longitude(0),ID(""),time(0)
    {}

    void setLongitude(double& newLongitude){
        longitude=newLongitude;
    };

    void setLatitude(double& newLatitude)
    {
        latitude=newLatitude;
    }

    void setID(string& newID){
        ID=newID;
    }

    void setTime(int& newTime){
        time=newTime;
    }

     double getLongitude() const{
        return longitude;
    }

    double getLatitude() const{
        return  latitude;
    }

    string getID() const{
        return ID;
    }

    int getTime() const{
        return time;
    }

    double distanceTo(const Item& otherItem) {

        double lat1Rad = (latitude/180)*M_PI;
        double lat2Rad = (otherItem.getLatitude()/180)*M_PI;
        double long1Rad = (longitude/180)*M_PI;
        double long2Rad = (otherItem.getLongitude()/180)*M_PI;

        double R = 6373000;

        double disLong = long2Rad-long1Rad;
        double disLat = lat2Rad-lat1Rad;
        double a = pow((sin(disLat/2)), 2) + cos(lat1Rad) * cos(lat2Rad) * pow((sin(disLong/2)), 2);
        double c = 2 * atan2( sqrt(a), sqrt(1-a) );
        double distance = R * c;
        return distance;
    }
};

ostream& operator<<(ostream& o, const Item& anItem ){
  return   o<<"{"
     <<anItem.getLatitude()
     <<", "
     <<anItem.getLongitude()
     <<", \""
     <<anItem.getID()
     <<"\", "
     <<anItem.getTime()
     <<"}";
}
// don't write any code below this line

#endif

