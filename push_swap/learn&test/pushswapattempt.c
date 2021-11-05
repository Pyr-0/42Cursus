
typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
} t_stacks;

enum e_error_type
{
	ERROR_TYPE_NO_ERROR = 0,
	ERROR_TYPE_TOO_NEGATIVE,
	ERROR_TYPE_TOO_POSITIVE,
	ERROR_TYPE_DOUBLE_NUMBER,
	// ...
};

typedef struct s_exception_state
{
	enum e_error_type type;
};


void	ft_stack_append_elem(t_stack *stack, int elem)
{
	ft_stack_push(stack, elem);
	ft_stack_rotate(stack);
}


bool	input(t_stacks *stacks, char *argv[])
{
	// ...
}

bool	check_doubles(t_stacks *stacks, t_exception_state *state)
{
	// ...
	{
		state->state = ERROR_TYPE_DOUBLE_NUMBER;
		return (false);
	}
}

bool	check(t_stacks *stacks)
{
	return check_doubles(stacks) && check_wrong_numbers(stacks);
}


bool	prepare(t_stacks *stacks, char **argv)
{
	return input(stacks, argv) && check(stacks);
}

static char *error_messages[] = {
	[ERROR_TYPE_NO_ERROR] = "No error",
	[ERROR_TYPE_TOO_NEGATIVE] = "Number too negative",
	[...]
}

void	ft_stack_destroy(t_stack *stack)
{
	while (!ft_stack_is_empty(stack))
		ft_stack_pop();
}

void	ft_stacks_destroy(t_stacks *stacks)
{
	ft_stack_destroy(&stacks->a);
	ft_stack_destroy(&stacks->b);
}

int main(int argc, char *argv[])
{
	t_stacks  			stacks;
	t_exception_state	exception_state;

	if (!prepare(&stacks, argv, &exception_state)) {
		printf("Error: %s\n", error_messages[exception_state.type]);  // Similar to strerror() - look it up
	} else {
		calculate_solution(&stacks);
	}
	ft_stacks_destroy(&stacks);
}


int algo1(t_Ourobouros **snake_head, int input)
while (input[i])