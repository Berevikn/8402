#ifndef EVENTS_FIELD_H
#define EVENTS_FIELD_H

#включить <SFML/Graphics.hpp>
#включить "Square.h"
#включить <стек>
#включить <iostream>

 поле класса: public sf::Drawable {
публичный:

    явное поле(окно sf::Vector2f);

    void init();

    void moveDown();
    void moveRight();
    void MoveUp();
    void moveLeft();

    void isWin();

    bool isLose();

    ~Переопределение Field();

Частное:

    void Shiftdowninoncel(int j);
    void Shiftrightinoncel(int i);
    void Shiftupinoncel(int j);
    void Shiftleftinoncel(int i);

    void addSquare();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 sf::RectangleShape* mBackground = новый sf::RectangleShape;
 sf::RectangleShape* mWIN = новый sf::RectangleShape;
 sf::RectangleShape* mLOSE = новый sf::RectangleShape;
 sf::Vector2f* mSize = новый sf::Vector2f;
 sf::Vector2f* mSizeOfOnceSquare = новый sf::Vector2f;
 sf::Clock* mSquareTime = новый sf::Часы;
 sf::Texture* mBackgroundTexture = новая sf::Текстура;
 sf::Текстура* mWinTexture = новая sf::Текстура;
 sf::Texture* mLoseTexture = новый sf::Текстура;
    int* mPositionX = новый int;
    int* mPositionY = новый int;
    int* mSquareOfSideCount = new int(4);
    int* mSquaresCountMoved = новый int;
 Квадрат** mSquares = новый квадрат*[*mSquareOfSideCount];
    bool** mIsEmpty = new bool*[*mSquareOfSideCount];
    bool* mIsWin = новый bool;
    bool* mIsLose = новый bool;
    bool* mIsMoved = новый bool;
};
#endif //EVENTS_FIELD_H
