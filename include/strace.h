/*
** strace.h for strace in /home/ubuntu/rendu/AUSP_strace
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Mon May 12 23:46:57 2014 chauvo_t
** Last update Thu May 15 18:39:30 2014 chauvo_t
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <err.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ptrace.h>
# include <sys/types.h>
# include <sys/user.h>
# include <sys/wait.h>
# include <unistd.h>

# define FAILURE 0
# define SUCCESS 1
# define EXIT 2

# define MAX_SYSCALL 313
# define SYSCALL_OPCODE 0x050f

typedef struct	s_prototype
{
  char		*name;
  int		nb_params;
  char		*params[6];
  char		*ret_type;
}		t_prototype;

typedef struct	s_types
{
  char		*name;
  void		(*print_fct)(unsigned long long int register_value);
}		t_types;

typedef enum
  {
    false = 0,
    true = 1
  }		t_bool;

/*
** print_syscalls.c
*/
void	print_args(int syscall_number, struct user_regs_struct *registers);
int	print_syscall(int syscall_number, struct user_regs_struct *registers);

/*
** print_types.c
*/
void	print_int(unsigned long long int register_value);
void	print_long(unsigned long long int register_value);
void	print_uint(unsigned long long int register_value);
void	print_ulong(unsigned long long int register_value);
void	print_pointer(unsigned long long int register_value);

/*
** print_types2.c
*/
void	print_string(unsigned long long int register_value);
void	print_unimplemented(unsigned long long int register_value);
void	print_nothing(unsigned long long int register_value);

/*
** trace.c
*/
int	step_instruction(pid_t pid, int *status);
int	analyse_registers(struct user_regs_struct *registers,
			  pid_t pid, int *status);
int	trace_process(pid_t pid);
int	trace_by_pid(pid_t pid);
int	trace_by_cmd(char **cmd);

#endif /* !STRACE_H_ */