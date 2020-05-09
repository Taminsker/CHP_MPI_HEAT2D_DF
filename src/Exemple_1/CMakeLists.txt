

option(EXAMPLE_1 "Build Example_1" ON)

if(EXAMPLE_1)
    message("-- Example_1 ON")
else(EXAMPLE_1)
    message("-- Example_1 OFF")
endif(EXAMPLE_1)

if(EXAMPLE_1)
    add_executable(
        Example_1
        main.cpp
        listfunctions.cpp
        listfunctions.h
        )

    target_link_libraries(Example_1 HeatMPI)
    target_link_libraries(Example_1 ${MPI_LIBRARIES})

    set_target_properties(Example_1 PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
    set_target_properties(Example_1 PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif(EXAMPLE_1)
