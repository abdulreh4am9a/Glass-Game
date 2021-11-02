#ifndef GLASS_H
#define GLASS_H

class Glass
{
private:
    char breakable;
public:
    Glass();
    void setBreakable(char b);
    char getBreakable() const;
};

#endif // GLASS_H
