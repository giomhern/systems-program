#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct point {
    double x;
    double y;
};

struct circle {
    struct point center;
    double radius;
};
struct square {
    struct point upper_left;
    double side_length;
};

struct rectangle {
    struct point upper_left;
    double width, height;
};

union shape {
    struct circle c;
    struct square s;
    struct rectangle r;
    //char tag; // int tag is not readable in the codebase
    enum shape_tag tag;
};

enum shape_tag{
    CIRCLE,
    SQUARE,
    RECTANGLE
};

struct tagged_shape{
    shape.u.c.center.x = 10;
    shape.u.c.center.y = 10;
    shape.u.c.radius = 5;
    shape.tag = CIRCLE;
    double d  = shape.u.r.width;
};

double shape_area(shape s){
    switch(s.tag){
        case CIRCLE:
            return M_PI * s.u.c.radius * s.u.c.radius;
        case SQUARE:
            return s.u.s.side_length * s.u.s.side_length;
        case RECTANGLE:
            return s.u.r.width * s.u.r.height;
        default:
            fprintf(stderr, "bad shape tag\n")
            exit(1);
    }
};

int main(){
    struct point points[5]; // valid way to make an array 
    struct point* points = (struct point*) malloc(sizeof(struct point*) * 5); // valid array

    struct point* qs[5]; // array of pointers to points
    struct point* qs_2 = (struct point*) malloc(sizeof(struct point*) * 5);
    // valid array of pointers to points 
    // to use the above 
    qs[0] =  point_new(0, 0);
    qs_2[1] =  point_new(1, 1);

    // array of pointers needs ->  && array needs the . (i.e point.x)
    // array of structs needs the . (i.e point.x) && array of pointers needs the ->
    return 0;
};
