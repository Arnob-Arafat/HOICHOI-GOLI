#ifndef TILE_H
#define TILE_H

enum class Type
{
    EMPTY,
    WALL,
    TOKEN,
    START,
    EXIT,
    SAFE_ZONE,
    RISK_ZONE,
};

class Brick
{
    private:
    Type type;

    public:
    Brick(Type t)
    {
        type = t;
    }

    Type getBrick()
    {
        return type;
    }

    void setBrick(Type t)
    {
        type = t;
    }

    bool HasCollision()
    {
        return (type != Type::EMPTY);
    }
};

#endif