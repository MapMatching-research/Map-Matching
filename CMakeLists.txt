cmake_minimum_required(VERSION 3.16)

project(sp-geo-map-matching)

include_directories(vendors/json/include/)

add_executable(preprocess preprocessing/scale_projection.cpp preprocessing/graph.cpp preprocessing/graph_subsampling.cpp main_preprocessing.cpp)
set_property(TARGET preprocess PROPERTY CXX_STANDARD 17)

#add_executable(hmm_matching preprocessing/graph.cpp grid/graph_grid.cpp preprocessing/scale_projection.cpp trajectories/trajectory.cpp trajectories/trajectory_split.cpp grid/graph_grid_starting_node.cpp HMM/HMM.cpp main_HMM.cpp)
#set_property(TARGET hmm_matching PROPERTY CXX_STANDARD 17)

add_executable(DFMP_matching preprocessing/graph.cpp preprocessing/scale_projection.cpp grid/graph_grid.cpp trajectories/trajectory.cpp trajectories/trajectory_split.cpp DF_sol/disc_frechet_grid.cpp DF_sol/freespace_dijkstra.cpp  grid/graph_grid_starting_node.cpp main_DFMP.cpp)
set_property(TARGET DFMP_matching PROPERTY CXX_STANDARD 17)

#add_executable(WDFMP_matching preprocessing/graph.cpp preprocessing/scale_projection.cpp grid/graph_grid.cpp trajectories/trajectory.cpp trajectories/trajectory_split.cpp DF_sol/disc_frechet_weak.cpp DF_sol/freespace_dijkstra.cpp  grid/graph_grid_starting_node.cpp main_DFMP.cpp)
#set_property(TARGET DFMP_matching PROPERTY CXX_STANDARD 17)

add_executable(naive_matching preprocessing/graph.cpp preprocessing/scale_projection.cpp grid/graph_grid.cpp grid/graph_grid_starting_node.cpp trajectories/trajectory.cpp trajectories/trajectory_split.cpp matching_using_sp/shared/shared.cpp matching_using_sp/naive_algorithm/naive.cpp matching_using_sp/naive_algorithm/naive_main.cpp)
set_property(TARGET naive_matching PROPERTY CXX_STANDARD 17)

add_executable(interleaved_matching preprocessing/graph.cpp preprocessing/scale_projection.cpp grid/graph_grid.cpp grid/graph_grid_starting_node.cpp trajectories/trajectory.cpp trajectories/trajectory_split.cpp matching_using_sp/shared/shared.cpp matching_using_sp/interleaved_algorithm/interleaved.cpp matching_using_sp/interleaved_algorithm/interleaved_main.cpp)
set_property(TARGET interleaved_matching PROPERTY CXX_STANDARD 17)

add_executable(kskip_matching preprocessing/graph.cpp preprocessing/scale_projection.cpp grid/graph_grid.cpp grid/graph_grid_starting_node.cpp trajectories/trajectory.cpp trajectories/trajectory_split.cpp matching_using_sp/shared/shared.cpp matching_using_sp/kskip_cover_matching/algorithm.cpp matching_using_sp/kskip_cover_matching/main.cpp)
set_property(TARGET kskip_matching PROPERTY CXX_STANDARD 17)
