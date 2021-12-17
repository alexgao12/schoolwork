#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;



void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);
int indexOfDouble(const vector<double>&, double);

int main(int argc, char *argv[]){
    vector <double> angles, coefficients;
    string input;
    double angle;
    
    readData(argv[1], angles, coefficients);
    if(!isOrdered(angles)){
        reorder(angles, coefficients);
    }
    
    while(true){
        cout << "Angle: ";
        cin >> angle;
        cout << endl;
        cout << interpolation(angle, angles, coefficients) << endl;
        
        while(input != "Yes" && input != "No"){
            cout << "Continue? (Enter Yes or No)";
            cin >> input;
            cout << endl;
        }

        if(input == "No"){
            return 0;
        }
        input = "";
    }
    
    return 0;
}

void readData(const string& filename, vector<double>& angles, vector<double>& coefficients){
    ifstream fin(filename);
    double angle, coefficient;

    if(!fin.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    while(fin >> angle >> coefficient){
        angles.push_back(angle);
        coefficients.push_back(coefficient);
    }
}
double interpolation(double angle, const vector<double>& angles, const vector<double>& coefficients){
    int index1, index2;

    if(indexOfDouble(angles, angle) != -1){
        return coefficients.at(indexOfDouble(angles, angle));
    }
    for(unsigned i = 1; i < angles.size(); ++i){
        if(angles.at(i - 1) < angle && angle < angles.at(i)){
            index1 = i - 1;
            index2 = i;
        }
    }

    return  coefficients.at(index1) + ((angle - angles.at(index1))/(angles.at(index2) - angles.at(index1)))*(coefficients.at(index2) - coefficients.at(index1));

}
bool isOrdered(const vector<double>& angles){
    if(angles.size() == 0 ){
        return true;
    }
    double min = angles.at(0);

    for(unsigned i = 1; i < angles.size(); ++i){
        if(min > angles.at(i)){
            return false;
        }
        min = angles.at(i);
    }
    return true;
}
void reorder(vector<double>& angles, vector<double>& coefficients){
    double mina;
    int index;

    for(unsigned i = 0; i < angles.size(); ++i){
        mina = angles.at(i);
        index = i;
        for(unsigned q = i; q < angles.size(); ++q){
            if(angles.at(q) < mina){
                index = q;
                mina = angles.at(q);
            }
        }
        swap(angles.at(i), angles.at(index));
        swap(coefficients.at(i), coefficients.at(index));

    }
}
int indexOfDouble(const vector<double>& doubles, double value){
    for(unsigned i = 0; i < doubles.size(); ++i){
        if(doubles.at(i) == value){
            return i;
        }
    }
    return -1;
}