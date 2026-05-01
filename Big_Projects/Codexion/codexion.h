#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

# define FIFO 1
# define EDF 2

typedef struct s_args
{
	int			number_of_coders;
	long long	time_to_burnout;
	long long	time_to_compile;
	long long	time_to_debug;
	long long	time_to_refactor;
	int			number_of_compiles_required;
	long long	dongle_cooldown;
	int			scheduler_type;
}	t_args;

typedef enum e_coder_state
{
	COMPILING,
	DEBUGGING,
	REFACTORING,
	WAITING
}	t_coder_state;

typedef struct s_coder
{
	int					coder_number;
	long long			time_since_last_compile;
	long long			deadline;
	long long			time_to_burnout;
	t_coder_state		status;
	int					compile_count;
	struct s_simulation	*sim;
}	t_coder;

typedef struct s_heap_node
{
	t_coder		*coder;
	long long	priority;
	long long	arrival_time;
}	t_heap_node;

typedef struct s_dongle
{
	int				number;
	short			dongle_is_available;
	long long		how_much_to_rest;
	long long		toked_at;
	long long		toked_by;
	short			left_coder;
	short			right_coder;
	t_heap_node		queue[2];
	int				queue_size;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
}	t_dongle;

typedef struct s_simulation
{
	t_args				args;
	t_dongle			*dongles;
	t_coder				*coders;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		sim_mutex;
	pthread_cond_t		cond_lock;
	long long			start_time;
	int					threads_at_barrier;
	volatile short		stop_simulation;
}	t_simulation;

/* utils.c */
short		is_full_digit(char *s);
long long	ft_atoi(const char *s);
long long	get_current_time_ms(void);
void		destroy_dongle_mutexes(t_simulation *sim);
short		null_error_message(void);
short		input_error_message(void);

/* args.c */
t_args		convert_args(int argc, char **argv);
short		is_empty_args(t_args args);

/* heap.c */
void		heap_push(t_dongle *dongle, t_coder *coder, long long priority, \
long long arrival);
t_coder		*heap_extract_min(t_dongle *dongle);

/* dongle.c */
void		try_acquire_dongle(t_dongle *d, t_coder *c, t_simulation *sim);
void		release_dongle(t_dongle *d, t_simulation *sim);
t_dongle	*find_dongle_for_coder(t_simulation *sim, int coder_n, int side);
void		wake_all_dongles(t_simulation *sim);

/* simulation.c */
void		*run_simulation(void *arg);
void		coder_work(t_coder *coder, t_simulation *sim);

/* simulation_utils.c */
void		safe_print(t_simulation *sim, int id, const char *msg);
void		sleep_action(t_simulation *sim, long long ms_time);
void		apply_fairness_wait(t_simulation *sim);
void		wait_barrier(t_simulation *sim, t_coder *coder);

/* monitor.c */
void		*run_monitor(void *arg);

/* main.c */
short		initialize_all_mutexes(t_simulation *sim);

/* init.c */
void		init_dongles(t_simulation *sim);
void		init_coders(t_simulation *sim);

/* error_message.c */
short		null_error_message(void);
short		input_error_message(void);
short		initialize_simulation_error_message(void);
short		mutex_error_message(void);

#endif
