#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <iostream> 
#include <fstream> 
#include <cmath>
#include <cstdlib>
#include <vector>
#include "../preprocessing/scale_projection.h"

#define TRAJ_VAL_SIZE (4)
#define LON_LAT_COMMA_SHIFT (7)
#define DEF_TRAJ {0, 0, 0};

using namespace std;

typedef struct point {
    double longitude;
    double latitude;
    double timestamp;
} Point;

typedef struct tedge {
    Point* src; 
    Point* trg;
    double cost;
} Tedge;

typedef struct trajectory {
    int length; //nPoints
    uint32_t traceId;
    uint32_t subId; 
    vector<Point*> points;
    vector<Tedge*> edges;
} Trajectory;


class Traj{
    public:
    /* adds a trajectory point to the points vector in the Trajectory, add an edge between every two points */
    void add_point(Trajectory* traj, double longitude, double latitude, int timestamp);

    /* reads the next k bytes from a given ifstream and stores it in the char* buffer given */
    void read_next_k_bytes(ifstream& file, char* buffer, int k);

    /* given a file ifstream; extract the next trajectory from a specified offset */
    void extract_next_trajectory(ifstream& file, int offset, Trajectory* traj, double min_long, double min_lat, double lat_scale, double lon_scale);

    /* reads k consecutive trajectories from a given file and stores it in a Trajectory vector */
    vector<Trajectory> read_trajectories(string file_path, int k, double min_long, double min_lat, double lat_scale, double lon_scale);

    /* extracts the kth trajectory in the file; k >= 0 */
    Trajectory read_trajectory_k(string file_path, int k, double min_long, double min_lat, double lat_scale, double lon_scale);

    void write_traj(Trajectory* traj, string file_name);

    /* frees all the malloc'ed memory for the points and edges in a trajectory */
    void cleanup_trajectory(Trajectory* traj);

    /* calculate the cost for every edge in the trajectory */
    void calc_traj_edge_cost(Trajectory* traj);

    /* return the length in meter of the trajectory */
    double calc_traj_length(Trajectory* traj);

    /* return the number of trajectories in a file */
    int num_trajectories(string file_path); 

    /* to read .txt input files */
    vector<Trajectory> read_txt_trajectories(string file_path, double min_long, double min_lat, double lat_scale, double lon_scale);
    
    /* to read pre-processed .txt input files */
    vector<Trajectory> read_processed_trajectories(string file_path, double min_long, double min_lat, double lat_scale, double lon_scale);

};

#endif