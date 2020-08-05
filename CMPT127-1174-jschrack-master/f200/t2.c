typedef struct point{
	int x, y; // location in 2D space
} point_t;

typedef struct{
	size_t len; //number of points in the array
	point_t* points; // an array of len point_t structs
	int* colors; // an array of len colors, one per point
} point_array_t;

point_array_t* point_array_create( size_t len )
{
	point_array_t* new = malloc(sizeof(point_array_t));
	new->points = malloc(sizeof(point_t) * len);
	new->colors = malloc(sizeof(int) * len);
	new->len = len;
	if (new == NULL)
	{
		return 1;
	}
	return 0;
}