
find_package(MPI REQUIRED)
if (NOT MPI_FOUND)
    message(STATUS "find_package : NOT found MPI library")
else (NOT MPI_FOUND)
    message(STATUS "find_package : found MPI library")
    include_directories(${MPI_INCLUDE_PATH})
endif (NOT MPI_FOUND)
