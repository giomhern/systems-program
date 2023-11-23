#include <stdlib.h>
#include <stdio.h>

struct point {
    double x, y;
};


void foo(){
    // no need for -> as just using the address
    struct point n;
    n.x = 1.0;

    // pointer differentiates --> use --> to access pointer member value
    struct point* q = (struct point*) malloc(sizeof(struct point));
    (*q).x = 12.0; // this is the same as q->x = 1.0;
}

struct point* point_new(double x, double y){
    struct point* res = (struct point*) malloc(sizeof(struct point));
    if(res == NULL){
        return NULL;
    }
    res->x = x;
    res->y = y;
    return res;
}

void point_free(struct point* p){
    free(p);
}

void point_show(struct point* p){
    printf("(%f, %f)\n", p->x, p->y);
}
struct point* point_copy(struct point* p){
    struct point* res = (struct point*) malloc(sizeof(struct point));
    if(res == NULL){
        return NULL;
    }
    res->x = p->x;
    res->y = p->y;
    return res;
}

struct circle {
    struct point center;
    double radius;
};

void foo_two(){
    struct circle c;
    c.center.x = 7.0;
    c.radius = 8.0;

}

int main(){

}