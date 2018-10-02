// Project 4 Structs and Pointers
// CS 202 Due 9/19/18 11:59pm
// Gabriel Aguiar

#include <iostream>
#include <fstream>

using namespace std;

// Sensor class
class Sensor {
	public:
	Sensor();
	Sensor(char* type, float Extracost);
    Sensor::Sensor(const Sensor &obj) {
        ptr = new int;
        *ptr = *obj.ptr; // copy the value
    }

	// get data
	char* getType();
	float getExtracost();
	int getGpsCnt();
	int getCameraCnt();
	int getLidarCnt();
	int getRadarCnt();
	// set data
	void setType(char &type, ifstream &inputStream);
	void setExtracost(float &extracost, ifstream &inputStream);
	void resetGpsCnt(ifstream &inputStream);
	void resetCameraCnt(ifstream &inputStream);
	void resetLidarCnt(ifstream &inputStream);
	void resetRadarCnt(ifstream &inputStream);
	// standard functions
	void print();
    bool Sensor::operator==(const Sensor &other) const {
        // Compare the values, and return a bool result.
    }
	
	private:
    int *ptr;
    char* m_type; //, a C-string char array of 256 max characters (name of sensor type), valid strings for
                  //Sensor m_type are "gps", "camera", "lidar", "radar", "none".
    float m_extracost; // a float (additional rent cost per day for the car that carries the sensor, for
                       // "gps":=$5.0/day, for "camera":=$10.0/day, for "lidar":=$15.0/day, for
                       //"radar":=$20.0/day, for "none":=$0.0/day)
    static int gps_cnt; // a static int member (keeps track of existing gps-type sensors)
    static int camera_cnt; // a static int member (keeps track of existing camera-type sensors)
    static int lidar_cnt; // a static int member (keeps track of existing lidar-type sensors)
    static int radar_cnt; // a static int
};
