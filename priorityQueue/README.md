# Notice about priority queue data field
I'm going to be using this priority queue in an upcoming project of mine, so ignore the references to mars.

As of now the data field of a node_t is a function pointer to a void function with no params, specifically task-based functions. For testing purposes I've set pq_deleteMax to return the priority of the deleted item instead of the address of a task function, and you can see this reflected in the main testing.

The copy of this in my future project will reflect what the documentation states:

pq_deleteMax: Removes the highest priority task from the priority queue and returns the function pointer 'data'
