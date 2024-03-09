#include "main.h"
#include <fstream>
#include <ios>

void startRecording(std::string filename){
    filename = "/usd/" + filename;
    ofs.open(filename.c_str(), std::ios::out | std::ios::trunc);
    recording = true;
}
void stopRecording(){
    ofs.close();
    recording = false;
}
void trackLeftStick(double value){
    ofs<<value<<' ';
}
void trackRightStick(double value){
    ofs<<value<<' ';
}
void trackIntake(short state){
    ofs<<state<<' ';
};
void trackWings(bool state){
    ofs<<state<<' ';
}