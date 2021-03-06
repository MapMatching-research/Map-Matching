#include "preprocessing/graph.h"
#include "Stats/graph_for_hist.h"
#include "grid/graph_grid.h"
#include "grid/graph_grid_starting_node.h"
#include "preprocessing/graph_subsampling.h"
#include "DF_sol/disc_frechet.h"
#include "trajectories/trajectory.h"
#include "trajectories/trajectory_split.h"
#include "HMM/HMM.h"
#include <chrono>


int main(int argc, char** argv) {
    if(argc < 10) {
        cerr << "Not enough arguments; please provide all required inputs";
        return 1;
    }

    /* read processed graph from a given file */
    Graph after_graph = GRAPH_INIT;
    read_processed_graph(argv[1], &after_graph);

    double lon_min, lat_min, lat_scale, lon_scale;
    lon_min = after_graph.original_min_long;
    lat_min = after_graph.original_min_lat;
    lat_scale = after_graph.lat_scale;
    lon_scale = after_graph.lon_scale;

    auto start_grid = std::chrono::high_resolution_clock::now();

    Grid grid = GRID_INIT;

    std::string grid_size_str = argv[2];
    double grid_size = std::stod(grid_size_str);
    // double grid_size = 500.00;
    
    Build_grid build_grid;
    build_grid.make_grids(&after_graph, &grid, grid_size);

    auto elapsed_grid = std::chrono::high_resolution_clock::now() - start_grid;
    long long microseconds_grid = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_grid).count();

    cout<<"Building Grid Duration in microseconds: " << microseconds_grid << endl;

    Traj tjtr;

    vector<Trajectory> trajs = tjtr.read_trajectories(argv[3], 5, lon_min, lat_min, lat_scale, lon_scale);
    int number_traj = tjtr.num_trajectories(argv[3]);  

    /* london-geq50m-clean-unmerged-2016-10-09-greater-london.binTracks */
    /* saarland-geq50m-clean-unmerged-2016-10-09-saarland.binTracks */
    
    Traj_subsample traj_sub;
    std::string threshold_str = argv[4];
    double subsample_traj_thr = std::stod(threshold_str);

    Trajectory traj;
    Point* traj_nd;

    for(int i = 0; i < number_traj; i++) {
        cout<<"grid -> curr_range: "<<grid.curr_range<<endl;
        grid.curr_range = 0;

        traj = trajs[i];
        traj_nd = traj.points[0];
        tjtr.calc_traj_edge_cost(&traj);
        double traj_length = tjtr.calc_traj_length(&traj);
        traj_sub.subsample_traj(&traj, subsample_traj_thr);
        tjtr.write_traj(&traj, argv[5]);  

        HMM hmm;

        std::string sigma_str = argv[5];
        double sigma = std::stod(sigma_str);
        // double sigma = hmm.sigma_est(&after_graph, &grid, &traj); // this can be the default value if the input is missing

        std::string beta_str = argv[6];
        double beta = std::stod(beta_str);
        // double beta = hmm.beta_est(0.5, 100, 30); // this can be the default value if the input is missing

        std::string radius_str = argv[7];
        double radius = std::stod(radius_str);

        std::string num_candidate_str = argv[8];
        int num_candidate = std::stoi(num_candidate_str);

        auto start_HMM = std::chrono::high_resolution_clock::now();

        vector<int> best = hmm.best_path(&after_graph, &grid, &traj, num_candidate, sigma, beta, radius);

        vector<int> com_path = hmm.best_path_dijkstra(&after_graph, best);

        auto elapsed_HMM = std::chrono::high_resolution_clock::now() - start_HMM;
        long long microseconds_HMM = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_HMM).count();

        cout<<"finished nodes to nodes dijkstra\n";

        double HMM_length = hmm.HMM_path_cost(&after_graph, com_path);

        cout<<"Building Grid Duration in microseconds: " << microseconds_grid << endl;
        cout<<"grid size: "<<grid_size<<endl;
        cout<<"HMM sigma: "<<sigma<<endl;
        cout<<"HMM beta: "<<beta<<endl;
        cout<<"HMM radius: "<<radius<<endl;
        cout<<"HMM num candidate: "<<num_candidate<<endl;
        cout<<"HMM in microseconds: " << microseconds_HMM << endl;
        cout <<"length of trajectory :"<< traj.length << endl;
        cout<<"length of the traj: "<<traj_length<<endl;
        cout<<"length of the HMM matching path: "<<HMM_length<<endl;

        /* try to fit the HMM results into a freespace and see what's the frechet distance between this HMM results and traj */

        Graph HMM_graph = GRAPH_INIT;

        hmm.make_a_HMM_graph(&after_graph, com_path, &HMM_graph);

        outedge_offset_array(&HMM_graph);
        inedge_offset_array(&HMM_graph);

        cout<<"convert the path to graph\n";

        hmm.write_HMM_graph(&after_graph, com_path, argv[9]);

        vector<double> stats;
        // stats.push_back(fsgraph.eps);
        stats.push_back(microseconds_HMM);
        DF.write_path_json(&fsgraph, &traj, &after_graph, argv[10], stats);

        // FSgraph fsgraph = FSGRAPH_INIT; 
        // FSpair last_pair = min_eps(&HMM_graph, &traj, &fsgraph, 750.00);
        // cout<<"final fsgraph.eps: "<<fsgraph.eps<<endl;

        // cleanup(&fsgraph);
        // tjtr.cleanup_trajectory(&traj);
    }

    return 0;
}

