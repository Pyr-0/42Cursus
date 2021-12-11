
#include "../"
struct s_config
{
	struct s_stack a;
	struct s_stack b;
};

void ft_config_print(struct s_config *config);

void ft_config_pa(struct s_config *config)
{
	ft_stack_push(&config->stack_b, ft_stack_pop(&config->stack_a));
}

void ft_config_sa(struct s_config *config)
{
	ft_stack_swap(&config->stack_a);
}

void ft_config_sb(struct s_config *config)
{
	ft_stack_swap(&config->stack_b);
}
