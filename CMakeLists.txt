cmake_minimum_required(VERSION 3.21)
project(Project_8 C)

set(CMAKE_C_STANDARD 11)

include_directories(philo)

add_executable(Project_8
        philo/ft_philo_init.c
        philo/ft_philo_utils.c
        philo/philo.c
        philo/philo.h)
