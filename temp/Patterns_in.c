// THIS IS A LIST OF PATTERNS FOUND IN C PROGRAMMING THAT HELPS TO UNDERSTAND TO USE THE LANGUAGE IN A WAY THAT BECOMES EASY TO UNDERSTAND AND TO IDENTIFY IN OTHER PEOPLESS CODE

/*
 * Guard pattern
 */
if (...)
	return (/* Either 0 or NULL, depending on the return type (pointer or integer) */);	// Unwrap pattern

/*
 * NULL guard pattern
 */
if (ptr == NULL)
	return (NULL);	// Unwrap pattern

/*
 * Malloc pattern
 */

// You often have a pointer of type T (often pre-initialized with NULL beforehand), let's call it "ptr"
ptr = malloc(sizeof(T));	// Malloc pattern (direct call)
if (ptr == NULL)	// NULL guard pattern
	return (NULL);	// Unwrap pattern / Function termination pattern
// <<Initialization pattern for the newly malloc'ed data here>>
return ptr;

/*
 * Many possible malloc patterns:
 */
ptr = malloc(10);	// Often a string of size 10
ptr = malloc(n);    // The size was precomputed somewhere else (often in a parameter, given to us by the caller)
ptr = malloc(12 * sizeof(T));	// Allocating an array, corresponding to T[12]
ptr = calloc(12, sizeof(T));	// Same as above, but the array will be initialized with bzero, malloc doesn't do that (so a bzero pattern will follow often after a malloc() call)


/*
 * Memset pattern
 */
i = 0;
while (i < n)
{
	ptr[i] = c;
	i = i + 1;
}

/*
 * BZero pattern, a type of initialization pattern (assuming T[n] to be initialized, stored in ptr)
 * It's a special case of the memset pattern
 */
i = 0;
while (i < n)
{
	ptr[i] = 0;	// Either 0 or NULL or '\0' depending on the type (number, pointer, or string)
	i = i + 1;
}


/*
 * String/Array copying pattern, a type of initialization pattern
 */
i = 0;
while (i < n)
{
	destination[i] = source[i];
	i = i + 1;
}


/*
 * "Cocktail-shaker" pattern
 */

while (1)
{
	if (/* condition, e.g. "are there no more bytes available to us?" */)
	{
		/* Resolve the situation, e.g. by reading more bytes */
		if (/* should_terminate */)
			break ;
	}
	else
	{
		/* Another pattern, assuming that the situation was resolved (e.g. we can be sure that we have bytes available) */
		/* e.g. by processing the bytes that are ready */
		if (/* should_terminate */)
			break ;
	}
}



/*
 * Variable block initialization pattern
 */
x = 0;
y = 0;
ptr = NULL;
...

/*
 * Loopy-printf pattern, a type of debugging pattern (don't forget to delete it before committing)
 */
while (index < limit)
{
	// Some random pattern here
	printf("...", str[index] /* some value relative to index */);
	// Some other random pattern here
	index = index + 1;
}


/*
 * While-for-equivalents
 */

int i = 0; // Init
while (i < 10)	// Condition
{
	printf("%d\n", i); // Body
	i = i + 1;	// Update
}

// Is the same as
for (int i = 0 /* Init */; i < 10 /* Condition */; i = i + 1 /* Update */)
{
	printf("%d\n", i);  // Body
}


/*
 * String iteration pattern (also for NULL-terminated arrays!)
 */
while (string[index] != '\0')
{
	// Some other pattern that will be repeated for every element (string[index])
	index = index + 1;
}

/*
 * String finding pattern (strchr, strrchr)
 */
while (string[index] != c)
{
	// Pattern in case the character wasn't found (often empty/nonexisting)
	index = index + 1;
}

/*
 * Literally the same pattern as above
 */
while (string[index] != c)
	index++;



/*
 * List patterns: Iteration
 */
elem = list_head;
while (elem != NULL)
{
	// Pattern that will be repeated for every list element here
	elem = elem->next;
}

/*
 * List patterns: Insertion (front)
 */
new_elem = /* Allocate a new element */;
new_elem->value = /* A value */;
new_elem->next = head;
head = new_elem;



/*
 * Funny things about pointers :D
 */

char *ptr;

*ptr          |     ptr[0]
*(ptr + 1)    |     ptr[1]
*(ptr + 2)    |     ptr[2]
...

&ptr[0]       |     ptr
&ptr[1]       |     (ptr + 1)
&ptr[2]       |     (ptr + 2)
...

