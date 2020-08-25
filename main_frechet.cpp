/* here goes the main function which will call all the necessary function to preprocess the graph */
#include "graph.h" 
#include "graph_subsampling.h"
#include "disc_frechet_v2.h"
#include "trajectory.h"
#include "starting_node_look_up.h"

int main(int argc, char** argv) {

    if(argc < 2) {
        cerr << "Not enough arguments; please provide a file name next to the program name to be read\n\nExample: ./a.out saarland.txt\n";
        return 1;
    }

    //read graph from given file
    Graph graph = GRAPH_INIT;
    read_file(argv[1], &graph);
    // 
// 
    /* bounding box */
    double lat_min = graph.min_lat;
    double lat_max = graph.max_lat;
    double lon_min = graph.min_long;
    double lon_max = graph.max_long;
    // Bounds bd;
    // double g_dist1 = bd.geodesic_dist(lat_min,lon_min,lat_max,lon_min);
    // double g_dist2 = bd.geodesic_dist(lat_min,lon_max,lat_min,lon_min);
    // double g_dist3 = bd.geodesic_dist(lat_max,lon_max,lat_max,lon_min);
    // Euc_distance ed;
    // double e_dist, e_dist1, e_dist2, e_dist3;
    // /* calculate the "pixel" euclidean distance between the bounding points */
    // double lon_min_to_y = ed.lon_mercator_proj(lon_min, lon_min);
    // double lon_max_to_y = ed.lon_mercator_proj(lon_max, lon_min);
    // double lat_min_to_x = ed.lat_mercator_proj(lat_min, lat_min);
    // double lat_max_to_x = ed.lat_mercator_proj(lat_max, lat_min);   
    // e_dist1 = ed.euc_dist(lat_min_to_x,lon_min_to_y,lat_max_to_x,lon_min_to_y, 1, 1);
    // e_dist2 = ed.euc_dist(lat_min_to_x,lon_max_to_y,lat_min_to_x,lon_min_to_y,1 ,1);
    // /* calculates the cost of the edges */
    // double x_scale = (g_dist2+g_dist3)*0.5/e_dist2;
    // double y_scale = g_dist1/e_dist1;
    // ed.calc_edge_cost(&graph, x_scale, y_scale);


    // /* strongly connected componetns */
    // Graph SCC_graph = GRAPH_INIT;
    // scc_graph(&graph, &SCC_graph);
    // /* sub sampling */
    // subsampling(&SCC_graph, 40);
    // output_graph(&SCC_graph, "subsampled_scc.txt", x_scale, y_scale);
    // cout<<"done outputting graph"<<endl;

    // read processed graph from a given file
    Graph after_graph = GRAPH_INIT;
    read_processed_graph(argv[2], &after_graph);

    vector<Trajectory> trajs = read_trajectories("saarland-geq50m-clean-unmerged-2016-10-09-saarland.binTracks", 1, lon_min, lat_min);
    Trajectory traj = trajs[0];
    Point* traj_nd = traj.points[0];
    write_traj(&traj, "traj_frechet.dat");

    FSgraph fsgraph = FSGRAPH_INIT;
    // QH: make a prompt for the radius???
    // vector<FSedge*> nodes_within_dist = SearchNodes(&SCC_graph, traj_nd, 80, x_scale, y_scale);
    // cout<<"nodes_within_dist.size(): "<<nodes_within_dist.size()<<endl;
    // cout<<"nodes_within_dist[0] -> trg.vid: "<<nodes_within_dist[0] -> trg ->vid<<endl;
    // cout<<"[0]  "<<dist_from_T0(traj_nd, graph.nodes[nodes_within_dist[0] -> trg ->vid], x_scale, y_scale)<<endl;
    // cout<<"[1]  "<<dist_from_T0(traj_nd, graph.nodes[nodes_within_dist[1] -> trg ->vid], x_scale, y_scale)<<endl;
    // cout<<" lat: "<<graph.nodes[nodes_within_dist[0] -> trg -> vid].lat<<" lon: "<<graph.nodes[nodes_within_dist[0] -> trg ->vid].longitude<<endl;
    // cout<<" lat: "<<graph.nodes[nodes_within_dist[1] -> trg ->vid].lat<<" lon: "<<graph.nodes[nodes_within_dist[1] -> trg ->vid].longitude<<endl;
    // cout<<"traj_nd->latitude: " << traj_nd->latitude<<" traj_nd->longitude: "<< traj_nd->longitude<<endl;
//    
    cout<<min_eps(&after_graph, &traj, &fsgraph, 80, after_graph.x_scale, after_graph.y_scale)<<endl;
    write_fsgraph(&fsgraph, "fsgraph.dat");
    write_sur_graph(&fsgraph, &after_graph, "sur_graph_frechet.dat");
    cleanup(&fsgraph);
    cleanup_trajectory(&traj);
    return 0;
}