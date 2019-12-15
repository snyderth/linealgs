#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>

#include "linalgs.h"
using namespace std;


int main(int argc, char** argv){
    float x;// = atof(argv[1]);
    float y;// = atof(argv[2]);

    srand(time(NULL));

    fstream fd;
    fd.open("time_data.csv", fstream::app | fstream::out);
    fd << "avg, max, maxInd\n";

    for(int k = 0; k < 1000; k++){
        vector<Point> trajectory;
        for(int i = 0; i < 5000; i++){
            Point pt = (point_s){(float)(rand() % 5000), (float)(rand() % 5000)};
            trajectory.push_back(pt);
        }


        vector<double> times;


        // vector<Point> trajectory;
        // for(float i = -5.0; i <=5.0; i+=0.1){
        //     trajectory.push_back(pt);
        //     xtraj.push_back(i);
        //     ytraj.push_back(pow(i, 3.0));
        // }

        chrono::time_point<chrono::high_resolution_clock> start, end;
        double largest_time = 0;
        int index;
        for(int i = 0; i < 10000; i++){

            x = rand() % 5000;
            y = rand() % 5000;

            Point ref = (point_s){x, y};
            int ind;
            start = chrono::high_resolution_clock::now();

            ind = close_to(trajectory, ref);

            end = chrono::high_resolution_clock::now();

            chrono::duration<double> elapsed_time = end - start;
            
            if(elapsed_time.count() > largest_time){
                largest_time = elapsed_time.count();
                index = ind;
            }

            times.push_back(elapsed_time.count());
            // cout << "Time: " << elapsed_time.count() << endl;
            cout << "The point closest to (" << x << ", " << y << ") on the line is (" << trajectory[ind].x << ", " << trajectory[ind].y << ")" << endl;
        }
        double sum_time = 0;
        for(int i = 0; i < times.size(); i++){
            sum_time += times[i];
        }
        cout << "Average runtime: " << sum_time / (double)(times.size()) << " seconds" << endl;

        int i = 0, j = 0;
        for(i; i < times.size(); i++){
            if(times[i] > times[j]){
                j = i;
            }
        }
        string run;
        run = to_string(sum_time / (double)(times.size())) + ", " + to_string(times[j]) + ", " + to_string(index) + "\n"; 

        fd << run;      
        fd.close();
        fd.open("time_data.csv", fstream::out | fstream::app);
        cout << "Longest result: " << times[j] << " seconds" << endl;
        cout << "In the longest time, the algorithm reached index " << index << " of the line" << endl;
    }

    fd.close();
}