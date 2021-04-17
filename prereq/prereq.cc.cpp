#include <iostream>
#include <math.h>

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
    ny = ny;
    y0 = y0;
    x0 = x0;
    nx = nx;
    y1 = y1;
    x1 = x1;



    // Take every third element of data (b as in blue)

    float b[sizeof(data)/sizeof(data[0])];
    int bx = 0;
    float sum_b = 0;
    for ( int ax = 0; ax < sizeof(data); ax += 2 )
    {   
        b[bx++] = data[ax];  
        sum_b += data[ax];
    }

    float g[sizeof(data)/sizeof(data[0])];
    int gx = 0;
    float sum_g = 0;
    for ( int ax = 0; ax < sizeof(data); ax += 2 )
    {   
        g[gx++] = data[ax];
        sum_g += data[ax];
    }

    float r[sizeof(data)/sizeof(data[0])];
    int rx = 0;
    float sum_r = 0;
    for ( int ax = 0; ax < sizeof(data); ax += 2 )
    {   
        r[rx++] = data[ax];  
        sum_r += data[ax];
    }


    Result result{{(sum_r/(ny*nx)), sum_g/(ny*nx), sum_b/(ny*nx)}};
    
    return result;
}

int main()
{
    float data[6]{1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f};
    Result res = calculate(2, 2, data, 0, 0, 5, 5);
    std::cout << res.avg[3] << std::endl;

    return 0;
}