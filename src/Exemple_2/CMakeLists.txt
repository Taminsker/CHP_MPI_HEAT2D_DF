

option(EXAMPLE_2 "Build Example_2" ON)

if(EXAMPLE_2)
    message("-- Example_2 ON")
else(EXAMPLE_2)
    message("-- Example_2 OFF")
endif(EXAMPLE_2)

if(EXAMPLE_2)
    add_executable(
        Example_2
        main.cpp
        listfunctions.cpp
        listfunctions.h
        )

    target_link_libraries(Example_2 HeatMPI)
    target_link_libraries(Example_2 ${MPI_LIBRARIES})

    set_target_properties(Example_2 PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
    set_target_properties(Example_2 PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif(EXAMPLE_2)
