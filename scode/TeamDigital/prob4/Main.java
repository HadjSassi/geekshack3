package doWhileLoops;

import java.util.Scanner;

public class Ex {

void getPositionXAtHeight(float height, Vec2 pos, Vec2 vel, float gravityForce = 9.8f, float gameWidth, float& positionX)
{
    float a = gravityForce / 2.0f;
    float b = vel.y;
    float c = pos.y - height;

    float t = (sqrtf((b * b) - (4.0f * a * c)) - b) / (2.0f * a);

    positionX = pos.x + (vel.x*t);
}