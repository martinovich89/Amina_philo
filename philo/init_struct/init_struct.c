#include "../philo.h"

t_glob_info    *init_globInf(t_glob_info *glb_info)
{
    
    glb_info->nb_philos = 0;
    glb_info->all_forks = 0;
    glb_info->time_to_sleep = 0;
    glb_info->time_to_eat = 0;
    glb_info->time_to_die = 0;
    glb_info->nb_of_meals = 1;
    return (glb_info);
}

// void init_philos(t_philo *philos)
// {
//     philo = malloc()
//     philos->id = 0;
//     philos->nb_fork = 0;
//     philos->nb_of_meals = 0;
// }



// void init_struct(t_glob_info *gl_inf, t_philo *philos)
// {
//     init_globInf(gl_inf);

// }