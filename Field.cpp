#включить "Field.h"

Поле::Поле(окно sf::Vector2f) {
 *mSize = окно;
 *mSizeOfOnceSquare = sf::Vector2f((*mSize).x / static_cast<float>(*mSquareOfSideCount), (*mSize).y / static_cast<float>(*mSquareOfSideCount));
 (*mBackgroundTexture).LoadFromFile("..\\square0.png");
 (*mBackgroundTexture).setRepeated(true);
 (*mBackgroundTexture).setSmooth(true);
 (*mWinTexture).LoadFromFile("..\\win.png");
 (*mWinTexture).setSmooth(true);
 (*mLoseTexture).LoadFromFile("..\\потерять.png");
 (*mLoseTexture).setSmooth(true);
 (*mBackground).setSize(*mSize);
 (*mWIN).setSize(*mSize);
 (*mWIN).setTexture(mWinTexture);
 (*mLOSE).setSize(*Msize);
 (*mLOSE).setTexture(mLoseTexture);
 (*mSquareTime).restart();
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        mSquares[i] = новый квадрат[*mSquareOfSideCount];
        mIsEmpty[i] = новый bool;
    }

 *mIsWin = ложь;
 *mIsLose = false;
}

 поле void::init() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            mIsEmpty[i][j] = true;
        }
    }
 (*mBackground).setTexture(mBackgroundTexture);
 (*mBackground).setTextureRect(sf::IntRect(0, 0, (*mSize).x, (*mSize).y));
    addSquare();
    addSquare();
}


пустое поле::addSquare() {
    std::srand(std::time(0));
    сделать {
 *mPositionX = std::rand() % *mSquareOfSideCount;
 *mPositionY = std::rand() % *mSquareOfSideCount;
 } в то времякак(!mIsEmpty[*mPositionY][*mPositionX]);
    mSquares[*mPositionY][*mPositionX] = *(новый квадрат(*mSizeOfOnceSquare));
    mSquares[*mPositionY][*mPositionX].setPosition(
            sf::Vector2f(static_cast<float >(*mPositionX) * (*mSizeOfOnceSquare).x,
                         static_cast<float>(*mPositionY) * (*mSizeOfOnceSquare).y));
    mIsEmpty[*mPositionY][*mPositionX] = false;
}

 поле void::draw(sf::RenderTarget& target, sf::RenderStates states) const {
 цель.ничья(*mBackground);
    for(int i = 0; i < *mSquareOfSideCount; ++i) {
        for(int j = 0; j < *mSquareOfSideCount; ++j) {
            if (!mIsEmpty[i][j]) {
 цель.ничья(mSquares[i][j]);
            }
        }
    }
    если(*mIsWin) {
 цель.ничья(*mWIN);
    }
    if(*mIsLose){
 цель.ничья(*mLOSE);
    }
}

пустое поле::moveDown() {
 *mIsMoved = false;
    for (int j = 0; j < *mSquareOfSideCount; ++j) {
        shiftDownInOnceLine(j);
        for (int i = *mSquareOfSideCount - 1; i > 0; --i) {
            if (!mIsEmpty[i][j] &&!mIsEmpty[i - 1][j] && mSquares[i][j].getLevel() == mSquares[i - 1][j].getLevel()) {
                mSquares[i][j].LevelUp();
                mIsEmpty[i - 1][j] = true;
 *mIsMoved = true;
            }
        }
        shiftDownInOnceLine(j);
    }
    if (*mIsMoved) addSquare();
}

пустое поле::MoveUp() {
 *mIsMoved = false;
    for (int j = 0; j < *mSquareOfSideCount; ++j) {
        Shiftupinoncel(j);
        for (int i = 0; i < *mSquareOfSideCount - 1; ++i) {
            if (!mIsEmpty[i][j] &&!mIsEmpty[i + 1][j] && mSquares[i][j].getLevel() == mSquares[i + 1][j].getLevel()) {
                mSquares[i][j].LevelUp();
                mIsEmpty[i + 1][j] = true;
 *mIsMoved = true;
            }
        }
        Shiftupinoncel(j);
    }
    if (*mIsMoved) addSquare();
}

пустое поле::moveLeft() {
 *mIsMoved = false;
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        shiftLeftInOnceLine(i);
        for (int j = 0; j < *mSquareOfSideCount - 1; ++j) {
            if (!mIsEmpty[i][j] &&!mIsEmpty[i][j + 1] && mSquares[i][j].getLevel() == mSquares[i][j + 1].getLevel()) {
                mSquares[i][j].LevelUp();
                mIsEmpty[i][j + 1] = true;
 *mIsMoved = true;
            }
        }
        shiftLeftInOnceLine(i);
    }
    if (*mIsMoved) addSquare();
}


 Поле void::moveRight() {
 *mIsMoved = false;
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        shiftRightInOnceLine(i);
        for (int j = *mSquareOfSideCount - 1; j > 0; --j) {
            if (!mIsEmpty[i][j] &&!mIsEmpty[i][j - 1] && mSquares[i][j].getLevel() == mSquares[i][j - 1].getLevel()) {
                mSquares[i][j].LevelUp();
                mIsEmpty[i][j - 1] = true;
 *mIsMoved = true;
            }
        }
        shiftRightInOnceLine(i);
    }
    if (*mIsMoved) addSquare();
}

Поле::~Поле() {
    for(int i = 0; i < *mSquareOfSideCount; ++i) {
        удалить mSquares[i];
        удалить пустое[i];
    }
    удалить[] mSquares;
    удалить[] Неправильно;
    удалить mSquaresCountMoved;
    удалить mSizeOfOnceSquare;
    удалить mSize;
    удалить mPositionX;
    удалить mBackground;
    удалить mBackgroundTexture;
    удалить mSquareTime;
    удалить mPositionY;
    удалить mSquareOfSideCount;
    удалить mIsWin;
    удалить mWinTexture;
    удалить mWIN;
    удалить mIsLose;
    удалить mLoseTexture;
    удалить mLOSE;
}

пустое поле::isWin() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            if (!mIsEmpty[i][j] и mSquares[i][j].getLevel() == 11) {
 *mIsWin = истина;
            }
        }
    }
}

 Поле bool::isLose() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            if(mIsEmpty[i][j]) {
 *mIsLose = false;
                возврат false;
            }
        }
    }
 std::stack<int>* previous = новый std::stack<int>;
    int** status = new int*[*mSquareOfSideCount];
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
 status[i] = new int[*mSquareOfSideCount];
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
 статус[i][j] = 0;
        }
    }
    int i = 0, j = 0;
 std::cout << "try: ";
    в то время как (!(* предыдущий).пусто() || статус[0][0] != 2) {
 std::cout << "Я здесь: ";
        переключатель (состояние [i][j]) {
            случай 0:
 std::cout << "0, ";
 ++статус[i][j];
                if (i != *mSquareOfSideCount - 1) {
                    if (mSquares[i][j].getLevel() == mSquares[i + 1][j].getLevel()) {
 *mIsLose = false;
                        возврат false;
                    }
                    if (status[i + 1][j] != 2) {
 предыдущий->push(1);
 ++я;
                    }
                }
                перерыв;
            случай 1:
 std::cout << "1, ";
 ++статус[i][j];
                if (j != *mSquareOfSideCount - 1) {
                    if (mSquares[i][j].getLevel() == mSquares[i][j + 1].getLevel()) {
 *mIsLose = false;
                        возврат false;
                    }
                    if (status[i][j + 1] != 2) {
 предыдущий->push(2);
 ++j;
                    }
                }
                перерыв;
            случай 2:
 std::cout << "2, ";
                if (previous->top() == 1) {
 --я;
 } еще {
 --j;
                }
 предыдущий->pop();
                перерыв;
            По умолчанию:
 std::cout << "БЕСКОНЕЧНОСТЬ";
                перерыв;
        }
 std::cout << std::endl;
    }
    удалить предыдущий;
    for (int k = 0; k < *mSquareOfSideCount; ++k) {
        удалить статус[k];
    }
    удалить[] статус;
 *mIsLose = true;
    верните true;
}

 Поле void::shiftdowninoncel(int j) {
 *mSquaresCountMoved = 0;
    for (int i = *mSquareOfSideCount - 1; i >= 0; --i) {
        если(!mIsEmpty[i][j]) {
            if (*mSquareOfSideCount - 1 - *mSquaresCountMoved != i) *mIsMoved = true;
            mIsEmpty[i][j] = true;
            mIsEmpty[*mSquareOfSideCount - 1 - *mSquaresCountMoved][j] = false;
            mSquares[*mSquareOfSideCount - 1 - *mSquaresCountMoved][j] = mSquares[i][j];
            mSquares[*mSquareOfSideCount - 1 - *mSquaresCountMoved][j].переместить(
                    sf::Vector2f(mSquares[*mSquareOfSideCount - 1 - *mSquaresCountMoved][j].GetPosition().x,
 (float) (*mSquareOfSideCount - 1 - *mSquaresCountMoved) *
 (*mSizeOfOnceSquare).y));
 ++(*mSquaresCountMoved);
        }
    }
}

 поле void::shiftRightInOnceLine(int i) {
 *mSquaresCountMoved = 0;
    for (int j = *mSquareOfSideCount - 1; j >= 0; --j) {
        если(!mIsEmpty[i][j]) {
            if (*mSquareOfSideCount - 1 - *mSquaresCountMoved != j) *mIsMoved = true;
            mIsEmpty[i][j] = true;
            mIsEmpty[i][*mSquareOfSideCount - 1 - *mSquaresCountMoved] = false;
            mSquares[i][*mSquareOfSideCount - 1 - *mSquaresCountMoved] = mSquares[i][j];
            mSquares[i][*mSquareOfSideCount - 1 - *mSquaresCountMoved].переместить(
                    sf::Vector2f(
 (float) (*mSquareOfSideCount - 1 - *mSquaresCountMoved) * (*mSizeOfOnceSquare).x,
                            mSquares[i][*mSquareOfSideCount - 1 - *mSquaresCountMoved].GetPosition().y));
 ++(*mSquaresCountMoved);
        }
    }
}

 поле void::shiftupinoncel(int j) {
 *mSquaresCountMoved = 0;
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        если(!mIsEmpty[i][j]) {
            if (*mSquaresCountMoved != i) *mIsMoved = true;
            mIsEmpty[i][j] = true;
            mIsEmpty[*mSquaresCountMoved][j] = false;
            mSquares[*mSquaresCountMoved][j] = mSquares[i][j];
            mSquares[*mSquaresCountMoved][j].переместить(
                    sf::Vector2f(mSquares[*mSquaresCountMoved][j].GetPosition().x,
 (float) (*mSquaresCountMoved) * (*mSizeOfOnceSquare).y));
 ++(*mSquaresCountMoved);
        }
    }
}

 поле void::shiftLeftInOnceLine(int i) {
 *mSquaresCountMoved = 0;
    for (int j = 0; j < *mSquareOfSideCount; ++j) {
        если(!mIsEmpty[i][j]) {
            if (*mSquaresCountMoved != j) *mIsMoved = true;
            mIsEmpty[i][j] = true;
            mIsEmpty[i][*mSquaresCountMoved] = false;
            mSquares[i][*mSquaresCountMoved] = mSquares[i][j];
            mSquares[i][*mSquaresCountMoved].переместить(
                    sf::Vector2f((float) (*mSquaresCountMoved) * (*mSizeOfOnceSquare).x,
                                 mSquares[i][*mSquaresCountMoved].GetPosition().y));
 ++(*mSquaresCountMoved);
        }
    }
}


