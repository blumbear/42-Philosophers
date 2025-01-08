/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:29 by tom               #+#    #+#             */
/*   Updated: 2024/12/30 18:53:50 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

# define TAKE_FORK_PROMPT " has taken a fork\n"
# define EAT_PROMPT " is eating\n"
# define SLEEP_PROMPT " is sleeping\n"
# define THINK_PROMPT " is thinking\n"
# define DIE_PROMPT " died\n"

# define TAKE_FORK_PROMPT_SIZE 18
# define EAT_PROMPT_SIZE 11
# define SLEEP_PROMPT_SIZE 13
# define THINK_PROMPT_SIZE 13
# define DIE_PROMPT_SIZE 6

typedef enum s_action
{
	e_take_fork,
	e_eat,
	e_sleep,
	e_think,
	e_die,
}	t_action;

/**
 * @brief The struct who contain basical data
 * 
 * @param int The number of philosophers and also the number of forks.
 * @param int If a philosopher didn’t start eating time_to_die milliseconds
 * since the beginning of their last meal or the beginning of the simulation,
 * they die.
 * @param int The time it takes for a philosopher to eat.
 * During that time, they will need to hold two forks.
 * @param int The time a philosopher will spend sleeping.
 * @param int  If all philosophers have eaten at least 
 * number_of_times_each_philosopher_must_eat times, the simulation stops.
 * If not specified, the simulation stops when a philosopher dies.
 * 
 */
typedef struct s_env
{
	int				n_philo;
	long long		t_eat;
	long long		t_sleep;
	long long		t_die;
	long long		m_eat;
	long long		t_start;
	bool			death;
	pthread_mutex_t	print;
	struct s_philo	*philo;
}	t_env;

typedef struct s_philo
{
	int				id;
	bool			eating;
	bool			sleeping;
	bool			thinking;
	bool			alive;
	bool			left_fork;
	bool			right_fork;
	long			last_eat;
	long			last_sleep;
	long			nb_meal;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	pthread_mutex_t	fork;
	t_env			*env;
}	t_philo;

typedef enum s_error
{
	e_undefine_error,
	e_too_few_arguments,
	e_too_many_arguments,
	e_arg_contain_char,
}	t_error;

/******************************************************************************/
/*                                                                            */
/* error_handler                                                              */
/*                                                                            */
/******************************************************************************/

void	ft_error(char *error, t_error error_code);

/******************************************************************************/
/*                                                                            */
/* init                                                                      */
/*                                                                            */
/******************************************************************************/

bool	check_arg(int ac, char **av, t_env *env);
bool	var_init(t_env	*data, char	**av);

/******************************************************************************/
/*                                                                            */
/* io                                                                         */
/*                                                                            */
/******************************************************************************/

void	ft_putnbr_fd(signed int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);

/******************************************************************************/
/*                                                                            */
/* utils                                                                      */
/*                                                                            */
/******************************************************************************/

int		print_data(t_philo *philo, t_action act, int time);
long	get_time(void);
int		ft_strcmp(char *first, char *second);
int		ft_atoi(const char	*str);
bool	ft_all_isdigit(char *str);
void	*ft_calloc(size_t	nmemb, size_t	size);
