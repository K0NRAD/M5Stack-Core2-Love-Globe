
#include <Arduino.h>
#include <M5Core2.h>

#include "heart_image.h"
#include "background_image.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SPRITE_COLOR_DEPTH 8
#define HEARTS_MAX 100
struct Heart
{
  int32_t x;
  int32_t y;
  float speed;
};

Heart hearts[HEARTS_MAX];

TFT_eSprite sprite = TFT_eSprite(&M5.Lcd);

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

void setup(void)
{
  M5.begin();
  M5.IMU.Init();

  for (int i = 0; i < HEARTS_MAX; i++)
  {
    hearts[i].x = random(SCREEN_WIDTH);
    hearts[i].y = SCREEN_HEIGHT - random(20);
    hearts[i].speed = (random(80) + 20) / 100.0;
  }

  sprite.setColorDepth(SPRITE_COLOR_DEPTH);
  sprite.createSprite(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void loop()
{
  M5.update();

  if (M5.Touch.changed)
  {
    M5.shutdown();
  }

  sprite.pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backgroundImage);

  M5.IMU.getAccelData(&accX, &accY, &accZ);

  for (int i = 0; i < HEARTS_MAX; i++)
  {
    Heart &heart = hearts[i];

    if (fabs(accX) > 2 || fabs(accY) > 2)
    {
      heart.x = random(SCREEN_WIDTH);
      heart.y = random(SCREEN_HEIGHT);
    }
    else
    {
      float dx = (accX * -10.0) + (round(accX) * random(5)) + (round(accY) * (random(10) - 5));
      float dy = (accY * 10.0) + (round(accX) * random(5)) + (round(accY) * (random(10) - 5));

      heart.x = heart.x + round(dx * heart.speed);
      heart.y = heart.y + round(dy * heart.speed);
    }

    if (heart.x < 0)
      heart.x = 0;
    if (heart.x > SCREEN_WIDTH)
      heart.x = SCREEN_WIDTH;

    if (heart.y < 0)
      heart.y = 0;

    if (heart.y > SCREEN_HEIGHT)
      heart.y = SCREEN_HEIGHT;

    sprite.drawXBitmap(heart.x - HEART_IMAGE_WIDTH,
                       heart.y - HEART_IMAGE_HEIGHT,
                       heartImage, HEART_IMAGE_WIDTH, HEART_IMAGE_HEIGHT, TFT_RED);
  }
  sprite.pushSprite(0, 0);
  delay(5);
}