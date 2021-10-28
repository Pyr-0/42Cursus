
// //example of insert of nodes in a linked list covering edge cases with a single linked list
// LLNode *create_new_node(LLNode *snake_head, LLNode *node)
// {
// 	if(snake_head == NULL)
// 	{
// 		snake_head = node;
// 		return (snake_head);
// 	}
// 	LLNode *previous = NULL;
// 	LLNode *a = snake_head;
// 	while(a && a->data < node->data)
// 	{
// 		previous = a;
// 		a = a->next;
// 	}
// 	if(previous == NULL)
// 	{
// 		node->next = snake_head;
// 		snake_head = node;
// 	}
// 	else 
// 	{
// 		previous->next = node;
// 		node->next = a;
// 	}
// 	return (snake_head);
// }

// //example of insert of nodes in a linked list covering edge cases with a double linked list
// void create_new_node_2(LLNode **snake_head, LLNode *node)
// {
// 	LLNode **a = snake_head;
// 	while(*a && (*a)->data < node->data)
// 		a = &((*a)->next);
// 	node->next = *a;
// 	*a = node;
// }

// void print_linked_list(LLNode *snake_head)
// {
// 	while(snake_head)
// 	{
// 		printf("%d\n", snake_head->data);
// 		snake_head = snake_head->next;
// 	}
// 	printf("NULL\n");
// }

// int main()
// {
// 	{
// 		LLNode *snake_head = NULL;
		
// 		LLNode node10 = {.data = 10, .next = NULL	};
// 		LLNode node1 = {.data = 1, .next = NULL	};
// 		LLNode node4 = {.data = 4, .next = NULL	};
// 		LLNode node6 = {.data = 6, .next = NULL	};
// 		LLNode node3 = {.data = 3, .next = NULL	};
	
// 		snake_head = create_new_node(snake_head, &node10);
// 		snake_head = create_new_node(snake_head, &node1);
// 		snake_head = create_new_node(snake_head, &node4);
// 		snake_head = create_new_node(snake_head, &node6);
// 		snake_head = create_new_node(snake_head, &node3);
		
// 		print_linked_list(snake_head);
// 	}
// 	{
// 		LLNode *snake_head = NULL;
		
// 		LLNode node10 = {.data = 10, .next = NULL	};
// 		LLNode node1 = {.data = 1, .next = NULL	};
// 		LLNode node4 = {.data = 4, .next = NULL	};
// 		LLNode node6 = {.data = 6, .next = NULL	};
// 		LLNode node3 = {.data = 3, .next = NULL	};

// 		create_new_node_2(&snake_head, &node10);
// 		create_new_node_2(&snake_head, &node1);
// 		create_new_node_2(&snake_head, &node4);
// 		create_new_node_2(&snake_head, &node6);
// 		create_new_node_2(&snake_head, &node3);
// 		create_new_node_2(&node_starts_)

// 		print_linked_list(snake_head);
// 	}
// 	return 0;
// }