#include "scale_projection.h"

double Bounds::degree_to_radian(double a) {
    return a*M_PI/180.0;
}

double Bounds::geodesic_dist(double lat1, double lon1, double lat2, double lon2) {
    double lat_r_1= degree_to_radian(lat1);
    double lon_r_1= degree_to_radian(lon1);
    double lat_r_2= degree_to_radian(lat2);
    double lon_r_2= degree_to_radian(lon2);
    //haversine formula
    double dist=earth_r*acos(cos(lat_r_1)*cos(lat_r_2)*cos(lon_r_1-lon_r_2)+sin(lat_r_1)*sin(lat_r_2));
    return dist;
}

double Euc_distance::degree_to_radian(double a) {
    return a*M_PI/180.0;;
}

double Euc_distance::trans_range(double x) {
    return (1.0 + (x / M_PI))*0.5;
}

double Euc_distance::lat_mercator_proj(double lat) {
    double lat_r = degree_to_radian(lat);
    double y = log(tan(0.25 * M_PI + 0.5 * lat_r));
    return y;
}

double Euc_distance::euc_dist(double lat1, double lon1, double lat2, double lon2, 
                                double x_scale, double y_scale, double lon_min, double lat_min) {
                                    
    double x1 = degree_to_radian(lon1 - lon_min);
    double x2 = degree_to_radian(lon2 - lon_min);

    double y1 = lat_mercator_proj(lat1 - lat_min);
    double y2 = lat_mercator_proj(lat2 - lat_min);

    double dist = sqrt(pow((x2-x1)*x_scale,2.0)+pow((y2-y1)*y_scale,2.0));
    return dist;
}

void Euc_distance::calc_edge_cost(Graph* graph, double x_scale, double y_scale) {
    //calculate the cost for every edge in the graph
    for(int i = 0; i < graph -> n_edges; i++) {
        struct node src;
        struct node trgt;
        src = graph -> nodes[graph -> edges[i].srcid];
        trgt = graph -> nodes[graph -> edges[i].trgtid];
        graph -> edges[i].cost = euc_dist(src.lat, src.longitude, trgt.lat, trgt.longitude,
                                            x_scale, y_scale, graph -> min_long, graph -> min_lat);
    }
}
