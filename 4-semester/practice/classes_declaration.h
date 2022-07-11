#pragma once

#include "Utility.h"

inline bool operator<(const POINT& p1, const POINT& p2)
{
    return (p1.x < p2.x) && (p1.y < p2.y);
}
inline bool operator==(const POINT& p1, const POINT& p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}
template <class T>
void hash_combine(std::size_t& s, const T& v)
{
    std::hash<T> h;
    s ^= h(v) + 0x9e3779b9 + (s << 6) + (s >> 2);
}
struct hash_POINT {
    size_t operator()(const POINT& point) const
    {
        size_t res = 0;
        hash_combine(res, point.x);
        hash_combine(res, point.y);
        return res;
    }
};


template <class T>
class MyHash;
template<>
struct MyHash<POINT>
{
    std::size_t operator()(POINT const& p) const
    {
        std::size_t res = 0;
        hash_combine(res, p.x);
        hash_combine(res, p.y);
        return res;
    }
};

/*
*   Класс:          Location
*   Описание:       Абстрактное положение в пространстве без возможности отображения
*   Наследован от:  -
*/

class Location {
protected:
    int x = 0;
    int y = 0;
public:
    Location();
    Location(const int new_x, const int new_y);
    virtual ~Location();
    int GetX() const;
    int GetY() const;
    void SetX(const int new_x);
    void SetY(const int new_y);
    void SetPos(const int new_x, const int new_y);
    void SetPos(const POINT new_location);
    POINT GetLocation() const;
};

/*
*   ============ Конец объявления класса Location ============
*/

/*
*   Класс:          Point
*   Описание:       Точка в пространстве. Один пиксель, к которому привязываются более сложные объекты
*   Наследован от:  Location
*/

class Point : public Location {
protected:
    bool visibility = false;
    COLORREF color = RGB(255, 255, 255);
public:
    Point();
    Point(const Location& location);
    Point(const int x, const int y);
    ~Point() override;
    COLORREF GetColor() const;
    void SetColor(COLORREF new_color);
    virtual void Show();
    virtual void Hide();
    void MoveTo(const int new_x, const int new_y);
    bool IsVisible() const;
};

/*
*   ============ Конец объявления класса Point ============
*/

/*
*   Класс:          Food
*   Описание:       Еда Пакмана в виде оранжевых точек
*   Наследован от:  Point

*/

class Food : public Point {
private:
    int type_id = 0;
protected:
    int radius = 6;
public:
    Food();
    Food(const int new_x, const int new_y);
    ~Food() override;
    int GetRadius() const;
    void SetRadius(const int new_radius);
    void Show() override;
    void Hide() override;
    virtual int GetTypeId() const;
    friend hash<Food*>;
    bool operator==(const Food& rhs);
};

struct hash_Food {
    size_t operator()(const Food* food) const
    {
        size_t res = 0;
        hash_combine(res, food->GetX());
        hash_combine(res, food->GetY());
        return res;
    }
};
/*
*   ============ Конец объявления класса Food ============
*/

/*
*   Класс:          ImmortalFood
*   Описание:       Еда в виде вишенки делает пакмана неуязвимым для приведений
*   Наследован от:  Food
*/

class ImmortalFood : public Food {
private:
    int type_id = 1;
public:
    ImmortalFood();
    ImmortalFood(const int new_x, const int new_y);
    ~ImmortalFood() override;
    void Show() override;
    void Hide() override;
    int GetTypeId() const override;

};

/*
*   ============ Конец объявления класса ImmortalFood ============
*/

/*
*   Класс:          Pacman
*   Описание:       Классический Pacman
*   Наследован от:  Point
*/

class Pacman : public Point {
private:
    const int type_id = 0;
protected:
    int radius = 25;
    bool openning_mouth = false;
    int delta_mouth = 16;
    
    POINT eye_coord = { x, y - 15 };
    const int eye_radius = 5;
    POINT mouth[3] = {
                    x - 5, y,
                    x + radius + 5, y - delta_mouth,
                    x + radius + 5, y + delta_mouth
    };
public:
    Pacman();
    Pacman(const int new_x, const int new_y);
    ~Pacman() override;
    int GetRadius() const;
    void SetRadius(const int new_radius);
    bool Touch(const int AnotherObjX, const int AnotherObjY) const;
    bool Touch(const POINT AnotherObj) const;
    void Show() override;
    void Hide() override;
    void TurnUp();
    void TurnDown();
    void TurnLeft();
    void TurnRight();
    void Die();
    void Won();
    virtual int GetTypeId() const;
};

/*
*   ============ Конец объявления класса Pacman ============
*/

/*
*   Класс:          ImmortalPacman
*   Описание:       Неуязвимый для приведений Pacman
*   Наследован от:  Pacman
*/


class ImmortalPacman : public Pacman {
private:
    const int type_id = 1;
public:
    ImmortalPacman();
    ImmortalPacman(const int new_x, const int new_y);
    ~ImmortalPacman() override;
    void Show() override;
    void Hide() override;
    int GetTypeId() const override;
};

/*
*   ============ Конец объявления класса ImmortalPacman ============
*/

/*
*   Класс:          Cast
*   Описание:       Интерфейс класса приведения
*   Наследован от:  Point
*/

class Cast : public Point {
protected:
    virtual void Body() = 0;
    virtual void Wawes() = 0;
    virtual void Eyes() = 0;
public:
    Cast() = default;
    Cast(const int new_x, const int new_y);
    ~Cast() override;
    virtual void Show() = 0;
    virtual void Hide() = 0;
    virtual int GetTypeId() const = 0;
};

/*
*   ============ Конец определения класса Cast ============
*/

/*
*   Класс:          ClassicCast
*   Описание:       Одноцветное приведение, двигается горизонтально
*   Наследован от:  Cast
*/

class ClassicCast : public Cast {
private:
    const int type_id = 0;
protected:
    void Body() override;
    void Wawes() override;
    void Eyes() override;
public:
    ClassicCast();
    ClassicCast(const int new_x, const int new_y);
    ~ClassicCast();
    virtual void Show();
    virtual void Hide();
    int GetTypeId() const override;

};

/*
*   ============ Конец объявления класса ClassicCast ============
*/

/*
*   Класс:          RainbowCast
*   Описание:       Приведение, меняющее цвет, двигается по вертикали
*   Наследован от:  Cast
*/

class RainbowCast : public Cast {
private:
    int color_r, color_g, color_b;
    int type_id = 1;
protected:
    void Body() override;
    void Wawes() override;
    void Eyes() override;
public:
    RainbowCast();
    RainbowCast(const int new_x, const int new_y);
    ~RainbowCast();
    virtual void Show();
    virtual void Hide();
    int GetTypeId() const override;
};

/*
*   ============ Конец определения  класса RainbowCast ============
*/

/*
*   Класс:          Wall
*   Описание:       Представляет собой экземпляр стены
*   Наследован от:  Point
*/

class Wall : public Point {
protected:
    int x_beg = 0, y_beg = 0;
    int x_end = 30, y_end = 30;
public:
    Wall();
    Wall(int new_x_beg, int new_y_beg, int new_x_end, int new_y_end);
    ~Wall() override;
    COLORREF GetColor() const;
    void SetColor(COLORREF new_color);
    virtual void Show();
    virtual void Hide();
    void ChangeParams(int new_x_beg, int new_y_beg, int new_x_end, int new_y_end);
    int GetXBeg() const;
    int GetYBeg() const;
    int GetXEnd() const;
    int GetYEnd() const;

};

/*
*   ============ Конец объявления класса Wall ============
*/

/*
*   Класс:          GameManager
*   Описание:       Средство управления игрой (генерация уровня, игровая механика)
*   Наследован от:  -
*/

class GameManager {
private:
    LOGFONT font = { 35, 0, 0, 0, 100, 0, 0, 0, RUSSIAN_CHARSET , 0, 0, 0, 0 };
    HFONT hfont = ::CreateFontIndirect(&font);

    int score = 0;
    /*
    *           _________________________________________________
    *           |               |           |                    |
    *           |               |  Food     |   ImmortalFood     |
    *           |_______________|___________|____________________|
    *           |               |           |                    |
    *           |   Pacman      | Pacman    |   ImmortalPacman   |
    *           |_______________|___________|____________________|
    *           |               |           |                    |
    *           |ImmortalPacman | Pacman    |   ImmortalPacman   |
    *           |_______________|___________|____________________|
    *
    */

    Pacman* pacman_transition[PACMANS_COUNT][FOOD_COUNT] = {
        {new Pacman, new ImmortalPacman},
        {new Pacman, new ImmortalPacman}
    };
    Pacman* pacman;

    vector<Wall> walls;
    unordered_set<Food*, hash_Food> food;
    vector<Cast*> casts;

    vector<short> casts_direction;

    unordered_set<POINT, hash_POINT> points;
    void WallsBuilder();
    void FindWallCoord();
    int PacmanEatFood();
    void MoveAllCasts();
    void MoveCast(Cast& cast, short& direction);
public:
    void CreateFirstLevel();
    void Play();
    void End();
};

/*
*   ============ Конец объявления класса GameManager ============
*/

