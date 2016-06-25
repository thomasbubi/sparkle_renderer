#ifndef UV_H
#define UV_H


class UV
{
    float _u;
    float _v;
public:
    UV(float u, float v);
    virtual ~UV();
    inline float u(){return _u;}
    inline float v(){return _v;}
    void set_u(float u);
    void set_v(float v);
};

#endif // UV_H
