#include <iostream>
#include <math.h>
#include <vector>

struct Result {
    float avg[3];
};

/*
This is the function you need to implement. Quick reference:
- x coordinates: 0 <= x < nx
- y coordinates: 0 <= y < ny
- horizontal position: 0 <= x0 < x1 <= nx
- vertical position: 0 <= y0 < y1 <= ny
- color components: 0 <= c < 3
- input: data[c + 3 * x + 3 * nx * y]
- output: avg[c]
*/

Result calculate(int ny, int nx, const float *data, int y0, int x0, int y1, int x1) {
    //Result result{{0.0f, 0.0f, 0.0f}};
    float sum_r = 0;
    float sum_g = 0;
    float sum_b = 0;
    int height = ny;


    for(int c = 0; c < 3 ;c++)
    {
        for(int x = x0; x < x1; x++)
        {
            for(int y = y0; y < y1; y++)
            {
                if (c==0) {sum_r += data[c+3*x+3*nx*y];}
                if (c==1) {sum_g += data[c+3*x+3*nx*y];}
                if (c==2) {sum_b += data[c+3*x+3*nx*y];}
            }
        }
    }

    Result result{{sum_r/((y1-y0)*(x1-x0)), sum_g/((y1-y0)*(x1-x0)), sum_b/((y1-y0)*(x1-x0))}};
    return result;
}