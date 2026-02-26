#include <iostream>
#include <vector>
#include <map>
using namespace std;

enum class VehicleType{
    CAR,
    BIKE,
    TRUCK
};

class Vehicle{
    string licensePlate;
    VehicleType vehtype;
    string color;

    public:

        Vehicle(string lp, VehicleType vtype, string col){
            licensePlate = lp;
            vehtype = vtype;
            color = col;
        }

        string getLicensePlate(){
            return licensePlate;
        }

        VehicleType getVehicleType(){
            return vehtype;
        }

        void displayVehicleInfo(){
            string vtype;
            switch (vehtype){
                case VehicleType::CAR: vtype = "CAR";
                case VehicleType::BIKE: vtype = "BIKE";
                case VehicleType::TRUCK: vtype = "TRUCK";
            }

            cout << "==VEHICLE DETAILS==" << endl;
            cout << "LICENSE PLATE: " << licensePlate << endl;
            cout << "VEHICLE TYPE: " << vtype << endl;
            cout << "VEHICLE COLOR: " << color << endl;
            cout << "===========" << endl;
        }
};

enum class ParkingSpotType{
    COMPACT,
    REGULAR,
    LARGE
};

class ParkingSpot{
    int spotNumber;
    ParkingSpotType stype;
    bool isAvailable;
    Vehicle* vehicle;

    public:

        ParkingSpot(int num, ParkingSpotType type){
            spotNumber = num;
            stype = type;
            isAvailable = true;
            vehicle = nullptr;
        }

        int getSpotNum(){
            return spotNumber;
        }

        ParkingSpotType getSpotType(){
            return stype;
        }

        bool isSpotAvailable(){
            return isAvailable;
        }

        bool canFitVehicle(Vehicle* vehObj){
            if(!vehObj){
                return false;
            }

            if(!isAvailable) return false;

            switch (vehObj->getVehicleType()){
                case VehicleType::BIKE: return true;

                case VehicleType::CAR: return stype != ParkingSpotType::COMPACT;

                case VehicleType::TRUCK: return stype == ParkingSpotType::LARGE;
            }

            return false;
        }

        bool park(Vehicle* vehObj){
            if(!vehObj) return false;

            // if(!canFitVehicle(vehObj)) return false;

            if(isAvailable){
                isAvailable = false;
                vehicle = vehObj;
                cout << "VEHICLE PARKED !! " << vehObj->getLicensePlate() << endl;
                return true;
            }
            return false;
        }

        Vehicle* removeVehicle(){
            if(!vehicle) return nullptr;

            isAvailable = true;
            Vehicle* tv = vehicle;
            vehicle = nullptr;
            cout << "VEHICLE REMOVED !! " << tv->getLicensePlate() << endl;

            return tv;
        }
};

class ParkingLot{
    vector<ParkingSpot*> pSpots;
    map<string, ParkingSpot*> occupiedSpots;
    int totalSpots;
    int availableSpots;

    public:

        ParkingLot(int compactN, int regularN, int largeN){
            int spotNumber  = 1;

            for(int i=0;i<compactN;i++){
                ParkingSpot* ps = new ParkingSpot(spotNumber, ParkingSpotType::COMPACT);
                pSpots.push_back(ps);
                spotNumber++;
            }

            for(int i=0;i<regularN;i++){
                ParkingSpot* ps = new ParkingSpot(spotNumber, ParkingSpotType::REGULAR);
                pSpots.push_back(ps);
                spotNumber++;
            }

            for(int i=0;i<largeN;i++){
                ParkingSpot* ps = new ParkingSpot(spotNumber, ParkingSpotType::LARGE);
                pSpots.push_back(ps);
                spotNumber++;
            }

            totalSpots = compactN + regularN + largeN;
            availableSpots = totalSpots;
            cout << "TOTAL SPOTS: " << totalSpots << endl;
        }

        int getTotalSpots(){
            return totalSpots;
        }

        int getAvailableSpots(){
            return availableSpots;
        }

        bool parkVehicle(Vehicle* vehObj){
            if(!vehObj) return false;

            if(availableSpots==0){
                cout << "NO SPOTS AVAILABLE !! " << endl;
                return false;
            }

            if(occupiedSpots.find(vehObj->getLicensePlate()) != occupiedSpots.end()){
                cout << "VEHICLE ALREADY PARKED !! " << vehObj->getLicensePlate() << endl;
                return false;
            }

            for(auto spot:pSpots){
                if(spot->canFitVehicle(vehObj)){
                    spot->park(vehObj);
                    occupiedSpots[vehObj->getLicensePlate()] = spot;
                    availableSpots--;
                    return true;
                }
            }

            cout << "CANT PARK VEHICLE !! " << vehObj->getLicensePlate() << endl;
            return false;
        }

        bool removeVehicle(Vehicle* vehObj){
            if(!vehObj) return false;

            if(occupiedSpots.find(vehObj->getLicensePlate()) == occupiedSpots.end()){
                cout << "VEHICLE NOT PARKED !! " << vehObj->getLicensePlate() << endl;
                return false;
            }

            ParkingSpot* parkedSpot = occupiedSpots[vehObj->getLicensePlate()];
            parkedSpot->removeVehicle();
            occupiedSpots.erase(vehObj->getLicensePlate());
            availableSpots++;
            return true;
        }

        void showParkedVehicles(){
            cout << "==ALL PARKED VEHICLES==" << endl;
            for(auto it: occupiedSpots){
                cout << it.first << endl;
            }
        }
};

int main(){

    ParkingLot* parkingLot = new ParkingLot(3,3,3);

    Vehicle* veh1 = new Vehicle("MH100", VehicleType::TRUCK, "red");
    Vehicle* veh2 = new Vehicle("MH101", VehicleType::TRUCK, "blue");
    Vehicle* veh3 = new Vehicle("MH102", VehicleType::TRUCK, "blue");
    Vehicle* veh4 = new Vehicle("MH103", VehicleType::TRUCK, "blue");

    cout << "TOTAL SPOTS: " << parkingLot->getTotalSpots() << endl;
    cout << "AVAILABLE SPOTS: " << parkingLot->getAvailableSpots() << endl;

    parkingLot->parkVehicle(veh1);
    cout << "AVAILABLE SPOTS: " << parkingLot->getAvailableSpots() << endl;
    parkingLot->parkVehicle(veh2);
    parkingLot->parkVehicle(veh3);
    cout << "AVAILABLE SPOTS: " << parkingLot->getAvailableSpots() << endl;
    parkingLot->parkVehicle(veh4);

    parkingLot->showParkedVehicles();

    parkingLot->removeVehicle(veh1);
    cout << "AVAILABLE SPOTS: " << parkingLot->getAvailableSpots() << endl;
    parkingLot->showParkedVehicles();

    return 0;
}