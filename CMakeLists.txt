cmake_minimum_required(VERSION 3.21)
project(Philosophers_snino C)

set(CMAKE_C_STANDARD 99)

add_executable(Philosophers_snino philo/philo.c philo/ft_philo_init.c philo/ft_philo_utils.c)
