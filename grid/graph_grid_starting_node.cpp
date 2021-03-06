#include "graph_grid_starting_node.h"
#include "graph_grid.h"
#include <numeric> 

using namespace std;

double Grid_search::dist_from_T0(Point* traj_nd, node g_nd) {
    double dist; 
    dist = sqrt(pow((traj_nd -> latitude - g_nd.lat), 2) + 
                    pow((traj_nd -> longitude - g_nd.longitude), 2));
    return dist; 
}  

void Grid_search::add_range_to_Q(Grid* grid, Graph* graph, int col, int row, int range, Point* traj_nd, priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t>& PQ){
    // Needs to be done separately per loop: hor-top, hor-bot,...
    int left  = max(0, col - range);
    int right = min(grid -> num_columns - 1, col + range);
    int upper = min(grid -> num_rows - 1, row + range);
    int lower = max(0, row - range);

    int starting_idx, ending_idx;
    int num_columns = grid -> num_columns;
    int num_rows    = grid -> num_rows;

   if (grid -> num_rows - 1 >= row + range){
        /* horizontal top */
        starting_idx = num_columns * upper + left;
        ending_idx   = num_columns * upper + right;
        int pos1 = grid -> cell_offset[starting_idx];
        int pos2 = grid -> cell_offset[ending_idx + 1]; 
        for (int k = pos1; k < pos2; k++){
                int nd_id = grid -> cell_nodes_list[k];
                Gpair grid_nd;
                grid_nd.first  = nd_id;
                grid_nd.second = dist_from_T0(traj_nd, graph -> nodes[nd_id]);
                cout<<"horizontal top, nd_id and distance to T0: "<<grid_nd.first<<" "<<grid_nd.second<<endl;
                PQ.push(grid_nd);
            }}
    
    if(upper > lower){
    /* horizontal bottom */
        if (row >= range){
            starting_idx = num_columns * lower + left;
            ending_idx   = num_columns * lower + right;

            int pos1 = grid -> cell_offset[starting_idx];
            int pos2 = grid -> cell_offset[ending_idx + 1]; 
            for (int k = pos1; k < pos2; k++){
                int nd_id = grid -> cell_nodes_list[k];
                Gpair grid_nd;
                grid_nd.first  = nd_id;
                grid_nd.second = dist_from_T0(traj_nd, graph -> nodes[nd_id]);
                cout<<"horizontal bottom, nd_id and distance to T0: "<<grid_nd.first<<" "<<grid_nd.second<<endl;
                PQ.push(grid_nd);
                }
        }

    int index_i;
    if (col >= range){
    /* vertical left */   
        for (int i =  row - range + 1; i <=  min(row + range - 1, num_rows - 1); i++){
            int a = row - range + 1;
            int b = row + range - 1;
            index_i = (num_columns * i)  + left;
            int pos1 = grid -> cell_offset[index_i];
            int pos2 = grid -> cell_offset[index_i + 1]; 
                for (int k = pos1; k < pos2; k++){
                    int nd_id = grid -> cell_nodes_list[k];
                    Gpair grid_nd;
                    grid_nd.first = nd_id;
                    grid_nd.second = dist_from_T0(traj_nd, graph -> nodes[nd_id]);
                    cout<<"vertical left, nd_id and distance to T0: "<<grid_nd.first<<" "<<grid_nd.second<<endl;
                    PQ.push(grid_nd);
            }}}

        if (grid -> num_columns - 1 >= col + range){
            /* vertical right */
            int a = row - range + 1;
            int b = row + range - 1;
            for (int i =  max(row - range + 1, 0); i <=  row + range - 1; i++){
                index_i = (num_columns * i)  + right;
                int pos1 = grid -> cell_offset[i];
                int pos2 = grid -> cell_offset[i+ 1]; 
                    for (int k = pos1; k < pos2; k++){
                        int nd_id = grid -> cell_nodes_list[k];
                        Gpair grid_nd;
                        grid_nd.first = nd_id;
                        grid_nd.second = dist_from_T0(traj_nd, graph -> nodes[nd_id]);
                        cout<<"vertical right, nd_id and distance to T0: "<<grid_nd.first<<" "<<grid_nd.second<<endl;
                        PQ.push(grid_nd);
                }}}}
                cout<<"add_Range to Q fine\n";
    return;
}

bool Grid_search::range_check(Grid* grid, Point* traj_nd, Graph* graph, priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t> PQ){
    double graph_max_x = graph -> max_long;
    double graph_max_y = graph -> max_lat;

    double dist_peak = grid -> dist_to_peak;
    int col = floor(traj_nd -> longitude/ grid -> size);
    int row = floor(traj_nd -> latitude/ grid -> size);
    double T0_x = traj_nd -> longitude;
    double T0_y = traj_nd -> latitude;

    if (PQ.empty()){
         while(PQ.empty() && grid -> curr_range <= max(grid -> num_columns - 1, grid -> num_rows - 1)){
            add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
            grid -> curr_range++;
            /* when the range contains no cell, the curr range is 0, when is contains 1 cell the curr range is 1, then 9 cells range 2.....*/
     }
     if(grid -> curr_range < grid -> max_range){
         add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
     }
    }

    bool within_range = true;

    double left_limit = max(0.00, T0_x - dist_peak);
    int left = max(0, col - grid -> curr_range) + 1;
    double left_bd = left * grid -> size;

    double right_limit = min(graph_max_x, T0_x + dist_peak);
    int right = min(grid -> num_columns - 1, col + grid -> curr_range);
    double right_bd = right * grid -> size;

    double upper_limit = min(graph_max_y, T0_y + dist_peak);
    int upper = min(grid -> num_rows - 1, row + grid -> curr_range);
    double upper_bd = upper * grid -> size;
    
    double lower_limit = max(0.0, T0_y - dist_peak);
    int lower = max(0, row - grid -> curr_range) + 1;
    double lower_bd = lower * grid -> size;

    if (left_limit <= left_bd || right_limit >= right_bd || upper_limit >= upper_bd || lower_limit <= lower_bd){ 
        cout<<"not within range\n";
        within_range = false;
    }
    return within_range;
}

priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t> Grid_search::GridSearch(Graph* graph, Grid* grid, Point* traj_nd){
    priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t> PQ;
    int col = floor(traj_nd -> longitude/ grid -> size);
    int row = floor(traj_nd -> latitude/ grid -> size);

    while(PQ.empty() && grid -> curr_range <= max(grid -> num_columns - 1, grid -> num_rows - 1)){
        add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
        cout<<"before increasing the range\n";
        grid -> curr_range++; 
    }
    if (PQ.empty()){
        cerr<<"The trajectory point is not inside the grid";
        }

    else{
        add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
        grid -> dist_to_peak = PQ.top().second; 
        cout<<"before range checking\n";

        bool enough_range = range_check(grid, traj_nd, graph, PQ);
        if (!enough_range) {
            cout<<"range not enough\n";
            grid -> curr_range++;
            add_range_to_Q(grid, graph, col, row, grid -> curr_range,traj_nd, PQ);
            cout<<"added one more range\n";
        }
    }
    return PQ;
}


Gpair Grid_search::next_closest_node(Graph* graph, Grid* grid, Point* traj_nd, priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t>& PQ){ 
    int col = floor(traj_nd -> longitude/ grid -> size);
    int row = floor(traj_nd -> latitude/ grid -> size);
    Gpair closest_nd;

    // if (PQ.empty()){
        // cerr<<"The trajectory point is not inside the grid";
    // }
    // else{
        closest_nd = PQ.top();
        PQ.pop();
        grid -> dist_to_peak = PQ.top().second; 
        cout<<"PQ.top().first and second: "<<PQ.top().first<<" "<<PQ.top().second<<endl;
        bool enough_range = range_check(grid, traj_nd, graph, PQ);
        if (!enough_range) {
            grid -> curr_range++;
            cout<<"range not enough after taking the closest node out\n";
            add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
            cout<<"range added for next closest node\n";
        }
    // }
    return closest_nd;
}


vector<Gpair> Grid_search::next_n_nodes(Graph* graph, Grid* grid, Point* traj_nd, int n_cans, double radius){
    priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t> PQ;
    int col = floor(traj_nd -> longitude/ grid -> size);
    int row = floor(traj_nd -> latitude/ grid -> size);

    while(PQ.empty() && grid -> curr_range <= max(grid -> num_columns - 1, grid -> num_rows - 1)){
        add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
        grid -> curr_range++; 
    }

    add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ); // always include one more layer of what's touched already
    grid -> dist_to_peak = PQ.top().second; 

    bool enough_range = range_check(grid, traj_nd, graph, PQ); // check if the additional layer that just got added can be touched but the searching radius, if it's touched, add one more layer
    if (!enough_range) {
        grid -> curr_range++;
        add_range_to_Q(grid, graph, col, row, grid -> curr_range,traj_nd, PQ);
    }

    if (PQ.top().second >= radius){
        cerr << "Please increase searching range to at least: "<<PQ.top().second<<endl;
    }

    vector<Gpair> next_n;
    for (int i = 0; i < PQ.size(); i++){
        if(PQ.top().second <= radius){ 
            Gpair g = PQ.top();
            next_n.push_back(g);
            PQ.pop();
            }
        else{
            break;
        }}

    while (next_n.size() < n_cans && next_n.back().second <= radius){
        grid -> curr_range++;
        add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
        for (int i = 0; i < PQ.size(); i++){
            if(PQ.top().second <= radius){ 
                Gpair g = PQ.top();
                next_n.push_back(g);
                PQ.pop();
                }
            else{
                break;
            }}         
        }
        return next_n; // in ascending order by the distance to trajectory node;   
}


priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t> Grid_search::k_nodes(Graph* graph, Grid* grid, Point* traj_nd, int k){
    priority_queue<Gpair, vector<Gpair>, Comp_dist_to_t> PQ;
    int col = floor(traj_nd -> longitude/ grid -> size);
    int row = floor(traj_nd -> latitude/ grid -> size);

    while(PQ.size() < k){
        add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
        grid -> curr_range++; 
    }

    add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ); // always include one more layer of what's touched already
    grid -> dist_to_peak = PQ.top().second; 

    bool enough_range = range_check(grid, traj_nd, graph, PQ); // check if the additional layer that just got added can be touched but the searching radius, if it's touched, add one more layer
    if (!enough_range) {
        grid -> curr_range++;
        add_range_to_Q(grid, graph, col, row, grid -> curr_range, traj_nd, PQ);
    }

    return PQ;  
}
