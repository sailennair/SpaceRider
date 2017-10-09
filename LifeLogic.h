#ifndef LIFELOGIC_H
#define LIFELOGIC_H

class LifeLogic
{
public:
LifeLogic();
    LifeLogic(float x, float y);

    float getXpos() const;

    float getYpos() const;

    void setPosition(float x, float y);

    int getNumberOfLivesRemaining(int health);

private:
    float _xpos;

    float _ypos;
};

#endif